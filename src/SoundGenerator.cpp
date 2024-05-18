#include "../include/SoundGenerator.h"

#include <thread>
#include <chrono>
#include <iostream>
#include <map>
#include <cmath>
#include <RtAudio.h>
#include <stk/Plucked.h> =

struct AudioData
{
    stk::Plucked* instrument;
    unsigned int sampleRate;
    unsigned int samplesLeft;
    double phase;
    double frequency;
};

auto SoundGenerator::play(const Note note) -> void
{
    RtAudio dac(RtAudio::WINDOWS_WASAPI);
    if (dac.getDeviceCount() < 1)
    {
        std::cerr << "No audio devices found!\n";
        exit(1);
    }

    unsigned int bufferFrames = 256;
    constexpr unsigned int sampleRate = 44100;
    stk::Plucked plucked(getFrequency(note.getPitch(), note.getOctave()));

    plucked.noteOn(getFrequency(note.getPitch(), note.getOctave()), 0.5);

    AudioData data = {
        &plucked, sampleRate,
        static_cast<unsigned int>((1000.0 * 4.0 / static_cast<int>(note.getDuration())) * sampleRate / 1000),
        0.0,
        getFrequency(note.getPitch(), note.getOctave())
    };

    RtAudio::StreamParameters parameters;
    parameters.deviceId = dac.getDefaultOutputDevice();
    parameters.nChannels = 1;
    parameters.firstChannel = 0;

    try
    {
        dac.openStream(&parameters, nullptr, RTAUDIO_FLOAT32, sampleRate, &bufferFrames, &audioCallback, &data);
        std::cout << "Stream opened successfully.\n";
        dac.startStream();
        std::cout << "Stream started successfully.\n";

        while (data.samplesLeft > 0)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }

        dac.stopStream();
        if (dac.isStreamOpen())
        {
            dac.closeStream();
            std::cout << "Stream stopped and closed successfully.\n";
        }
    }
    catch (RtAudioErrorType&)
    {
        if (dac.isStreamOpen())
        {
            dac.closeStream();
        }
    }
    catch (std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        if (dac.isStreamOpen())
        {
            dac.closeStream();
        }
    }
}

auto SoundGenerator::getFrequency(const Pitch pitch, const int octave) -> double
{
    std::map<Pitch, double> baseFrequencies = {
        {Pitch::C, 16.35}, {Pitch::D, 18.35}, {Pitch::E, 20.60},
        {Pitch::F, 21.83}, {Pitch::G, 24.50}, {Pitch::A, 27.50}, {Pitch::B, 30.87}
    };
    return baseFrequencies[pitch] * std::pow(2.0, octave);
}

auto SoundGenerator::playMelody(const std::vector<Note>& melody) -> void
{
    for (const auto& note : melody)
    {
        play(note);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int SoundGenerator::audioCallback(void* outputBuffer, void* /*inputBuffer*/, const unsigned int nBufferFrames,
                                  double /*streamTime*/, const RtAudioStreamStatus status, void* data)
{
    auto* audioData = static_cast<AudioData*>(data);
    auto* buffer = static_cast<float*>(outputBuffer);

    if (status)
    {
        std::cerr << "Stream underflow detected!" << std::endl;
    }

    for (unsigned int i = 0; i < nBufferFrames; ++i)
    {
        if (audioData->samplesLeft == 0)
        {
            buffer[i] = 0.0;
        }
        else
        {
            // Use the Plucked instrument
            buffer[i] = static_cast<float>(audioData->instrument->tick());
            audioData->samplesLeft--;
        }
    }

    return audioData->samplesLeft == 0 ? 1 : 0;
}
