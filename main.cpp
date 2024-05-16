#include <iostream>

#include "include/Utility.h"

auto main() -> int
{

    Utility::initializeSeed();
    for (const auto x = Utility::initializePopulation(2, 16); const auto& i : x)
    {
        std::cout << "Fitness: " << i.getFitness() << std::endl;
        for (const auto& melody = i.getMelody(); const auto& note : melody)
        {
            std::cout << note << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
