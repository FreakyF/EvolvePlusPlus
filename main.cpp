#include <iostream>

#include "include/SoundGenerator.h"
#include "include/Utility.h"

auto main() -> int
{
    Utility::initializeSeed();

    constexpr int melodyLength = 16;
    const Individual randomIndividual = Utility::generateRandomIndividual(melodyLength);
    std::vector<Note> melody = randomIndividual.getMelody();

    std::cout << "Generated Melody: \n";
    for (const auto& note : melody)
    {
        std::cout << note << '\n';
    }

    SoundGenerator::playMelody(melody);
}
