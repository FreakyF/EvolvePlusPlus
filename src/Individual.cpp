#include "../include/Individual.h"

Individual::Individual(const std::vector<Note>& melody, const double fitness): melody{melody},
                                                                               fitness{fitness}
{
}

auto Individual::getMelody() const -> const std::vector<Note>&
{
    return melody;
}

auto Individual::setMelody(const std::vector<Note>& melody) -> void
{
    this->melody = melody;
}

double Individual::getFitness() const
{
    return fitness;
}

auto Individual::setFitness(const double fitness) -> void
{
    this->fitness = fitness;
}
