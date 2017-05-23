#ifndef MUPLUSLAMBDAGENERATION_H
#define MUPLUSLAMBDAGENERATION_H
#include "generation.h"

class MuPlusLambdaGeneration : public Generation
{
public:
    MuPlusLambdaGeneration(Population *population, Population *parents, Population *childs);
    void generate();
};

#endif // MUPLUSLAMBDAGENERATION_H
