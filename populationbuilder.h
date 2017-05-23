#ifndef POPULATIONBUILDER_H
#define POPULATIONBUILDER_H
#include "individualbuilder.h"
#include "population.h"
enum class INITIALPOPULATION{Random, Boundary};

class PopulationBuilder
{
public:
    PopulationBuilder();
    virtual void initiate(IndividualBuilder *individualGenerator, Population *population) = 0;
};

#endif // POPULATIONBUILDER_H
