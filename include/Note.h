#ifndef NOTE_H
#define NOTE_H

#include "Duration.h"
#include "Pitch.h"

constexpr int MIN_OCTAVE = 0;
constexpr int MAX_OCTAVE = 8;

class Note
{
    Pitch pitch;
    int octave;
    Duration duration;
};


#endif //NOTE_H
