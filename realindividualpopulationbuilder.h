#ifndef REALINDIVIDUALPOPULATIONBUILDER_H
#define REALINDIVIDUALPOPULATIONBUILDER_H
#include "populationbuilder.h"

class RealIndividualPopulationBuilder : public PopulationBuilder
{
public:
    RealIndividualPopulationBuilder();
    void initiate(IndividualBuilder *individualGenerator, Population *population);
};

#endif // REALINDIVIDUALPOPULATIONBUILDER_H
