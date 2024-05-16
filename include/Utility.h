#pragma once

#include <cstdint>

#include "Duration.h"
#include "Individual.h"
#include "Pitch.h"

class Utility
{
    static auto xorshift128Plus() -> uint64_t;
    static uint64_t state[2];
    static auto initializeSeed() -> void;

public:
    static auto randomPitch() -> Pitch;
    static auto randomOctave() -> int;
    static auto randomDuration() -> Duration;

    static auto generateRandomIndividual(int melodyLength) -> Individual;
    static auto initializePopulation(int populationSize, int melodyLength) -> std::vector<Individual>;
};
