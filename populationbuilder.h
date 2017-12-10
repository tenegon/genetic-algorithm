#ifndef POPULATIONBUILDER_H
#define POPULATIONBUILDER_H
#include "individualbuilder.h"
#include "population.h"

class PopulationBuilder
{
public:
    PopulationBuilder();
    virtual ~PopulationBuilder();
    virtual void initiate(IndividualBuilder *individualBuilder, Population *population) = 0;
};

#endif // POPULATIONBUILDER_H
