#pragma once

#include <vector>

#include "Note.h"

class Individual
{
    std::vector<Note> melody;
    double fitness;

public:
    [[nodiscard]] Individual(const std::vector<Note>& melody, const double fitness)
        : melody(melody),
          fitness(fitness)
    {
    }

    [[nodiscard]] auto getMelody() const -> const std::vector<Note>&;

    auto setMelody(const std::vector<Note>& melody) -> void;

    [[nodiscard]] double getFitness() const;
    auto setFitness(double fitness) -> void;
};
