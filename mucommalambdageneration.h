#ifndef MUCOMMALAMBDAGENERATION_H
#define MUCOMMALAMBDAGENERATION_H
#include "generation.h"

class MuCommaLambdaGeneration : public Generation
{
public:
    MuCommaLambdaGeneration(Population *population, Population *parents, Population *childs);
    void generate();
};

#endif // MUCOMMALAMBDAGENERATION_H
