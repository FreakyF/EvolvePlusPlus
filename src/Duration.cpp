#include "../include/Duration.h"

std::ostream& operator<<(std::ostream& os, Duration duration)
{
    switch (duration)
    {
    case Duration::whole: os << "whole";
        break;
    case Duration::half: os << "half";
        break;
    case Duration::quarter: os << "quarter";
        break;
    case Duration::eighth: os << "eighth";
        break;
    case Duration::sixteenth: os << "sixteenth";
        break;
    }
    return os;
}
