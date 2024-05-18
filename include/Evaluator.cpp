#include "Evaluator.h"

#include <set>

auto Evaluator::evaluateHarmonicContent(const std::vector<Note>& melody) -> double
{
    if (melody.size() < 2)
    {
        return 0.0;
    }

    double score{0.0};
    for (size_t i{0}; i < melody.size() - 1; ++i)
    {
        const int pitch1{static_cast<int>(melody[i].getPitch())};
        const int pitch2{static_cast<int>(melody[i + 1].getPitch())};
        int interval = {std::abs(pitch2 - pitch1)};
        interval = interval % 12;

        switch (interval)
        {
        case 0: // Unison
        case 3: // Minor third
        case 4: // Major third
        case 5: // Perfect fourth
        case 7: // Perfect fifth
        case 8: // Minor sixth
        case 9: // Major sixth
        case 12: // Octave
            score += 1.0;
            break;
        default:
            score -= 0.5; // Penalize dissonance
        }
    }
    return score;
}

auto Evaluator::evaluateRhythmicVariety(const std::vector<Note>& melody) -> double
{
    std::set<Duration> durations;
    for (const auto& note : melody)
    {
        durations.insert(note.getDuration());
    }
    const double score = {static_cast<double>(durations.size())};
    return score;
}

auto Evaluator::evaluateIndividual(const Individual& individual) -> double
{
    const auto& melody{individual.getMelody()};
    const double harmonicScore{evaluateHarmonicContent(melody)};
    const double rhytmicScore{evaluateRhythmicVariety(melody)};

    return (harmonicScore + rhytmicScore) / 2;
}
