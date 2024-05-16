#pragma once

#include <stdexcept>

#include "Duration.h"
#include "Pitch.h"

constexpr int MIN_OCTAVE{0};
constexpr int MAX_OCTAVE{8};

class Note
{
    Pitch pitch;
    int octave;
    Duration duration;

public:
    [[nodiscard]] Note(Pitch pitch, int octave, Duration duration);

    [[nodiscard]] auto getPitch() const -> Pitch;
    auto setPitch(Pitch pitch) -> void;

    [[nodiscard]] auto getOctave() const -> int;
    auto setOctave(int octave) -> void;

    [[nodiscard]] auto getDuration() const -> Duration;
    auto setDuration(Duration duration) -> void;

    friend std::ostream& operator<<(std::ostream& os, const Note& note);
};
