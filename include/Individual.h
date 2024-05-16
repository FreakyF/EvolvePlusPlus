#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H
#include <vector>

#include "Note.h"


class Individual
{
    std::vector<Note> melody;
    double fitness;
};


#endif //INDIVIDUAL_H
