#pragma once

#include <RtAudio.h>
#include <vector>

#include "Note.h"


class SoundGenerator
{
    static auto play(Note note) -> void;
    static auto getFrequency(Pitch pitch, int octave) -> double;
    static int audioCallback(void* outputBuffer, void* inputBuffer, unsigned int nBufferFrames,
                             double streamTime, RtAudioStreamStatus status, void* data);
public:
    static auto playMelody(const std::vector<Note>& melody) -> void;
};
