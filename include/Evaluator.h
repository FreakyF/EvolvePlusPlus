#pragma once
#include <vector>

#include "Individual.h"
#include "Note.h"


class Evaluator
{
    static auto evaluateHarmonicContent(const std::vector<Note>& melody) -> double;
    static auto evaluateRhythmicVariety(const std::vector<Note>& melody) -> double;

public:
    static auto evaluateIndividual(const Individual& individual) -> double;
};
