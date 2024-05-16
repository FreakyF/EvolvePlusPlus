#ifndef NOTE_H
#define NOTE_H

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
    [[nodiscard]] Note(const Pitch pitch, const int octave, const Duration duration)
        : pitch(pitch),
          octave(octave),
          duration(duration)
    {
        if (octave < MIN_OCTAVE || octave > MAX_OCTAVE)
        {
            throw std::out_of_range("Octave out of valid range");
        }
    }

    [[nodiscard]] auto getPitch() const -> Pitch;
    auto setPitch(Pitch pitch) -> void;

    [[nodiscard]] auto getOctave() const -> int;
    auto setOctave(int octave) -> void;

    [[nodiscard]] auto getDuration() const -> Duration;
    auto setDuration(Duration duration) -> void;
};


#endif //NOTE_H
