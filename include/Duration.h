#pragma once
#include <ostream>

enum class Duration
{
    whole = 1,
    half = 2,
    quarter = 4,
    eighth = 8,
    sixteenth = 16
};

std::ostream& operator<<(std::ostream& os, Duration duration);

