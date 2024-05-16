#include "../include/Note.h"

Note::Note(const Pitch pitch, const int octave, const Duration duration): pitch{pitch},
                                                                          octave{octave},
                                                                          duration{duration}
{
    if (octave < MIN_OCTAVE || octave > MAX_OCTAVE)
    {
        throw std::out_of_range("Octave out of valid range");
    }
}

auto Note::getPitch() const -> Pitch
{
    return pitch;
}

auto Note::setPitch(const Pitch pitch) -> void
{
    this->pitch = pitch;
}

auto Note::getOctave() const -> int
{
    return octave;
}

auto Note::setOctave(const int octave) -> void
{
    if (octave < MIN_OCTAVE || octave > MAX_OCTAVE)
    {
        throw std::out_of_range("Octave out of valid range");
    }
    this->octave = octave;
}

auto Note::getDuration() const -> Duration
{
    return duration;
}

auto Note::setDuration(const Duration duration) -> void
{
    this->duration = duration;
}
