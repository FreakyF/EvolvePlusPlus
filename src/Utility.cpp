#include "../include/Utility.h"

#include <random>

auto Utility::randomPitch() -> Pitch
{
    return static_cast<Pitch>(xorshift128plus() % 7);
}

auto Utility::randomOctave() -> int
{
    return static_cast<int>(MIN_OCTAVE + (xorshift128plus() % (MAX_OCTAVE - MIN_OCTAVE + 1)));
}

auto Utility::randomDuration() -> Duration
{
    switch (xorshift128plus() % 5)
    {
    case 0:
        return Duration::whole;
    case 1:
        return Duration::half;
    case 2:
        return Duration::quarter;
    case 3:
        return Duration::eighth;
    default:
        return Duration::sixteenth;
    }
}

auto Utility::generateRandomIndividual(const int melodyLength) -> Individual
{
    std::vector<Note> melody;
    for (int i{0}; i < melodyLength; ++i)
    {
        Pitch pitch = randomPitch();
        int octave = randomOctave();
        Duration duration = randomDuration();
        melody.emplace_back(pitch, octave, duration);
    }
    constexpr double initialFitness{0.0};
    return Individual{melody, initialFitness};
}

auto Utility::initializePopulation(const int populationSize, const int melodyLength) -> std::vector<Individual>
{
    std::vector<Individual> population;
    for (int i{0}; i < populationSize; ++i)
    {
        population.push_back(generateRandomIndividual(melodyLength));
    }

    return population;
}

auto Utility::initializeSeed() -> void
{
    std::random_device rd;
    state[0] = {rd()};
    state[1] = {rd()};
}

uint64_t Utility::state[2] = {0, 0};

auto Utility::xorshift128plus() -> uint64_t
{
    uint64_t firstPart{state[0]};
    const uint64_t secondPart{state[1]};
    state[0] = secondPart;
    firstPart ^= firstPart << 23;
    firstPart ^= firstPart >> 17;
    firstPart ^= secondPart ^ (secondPart >> 26);
    state[1] = {firstPart};
    return state[1] + secondPart;
}
