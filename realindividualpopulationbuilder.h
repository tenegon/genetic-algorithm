#ifndef REALINDIVIDUALPOPULATIONBUILDER_H
#define REALINDIVIDUALPOPULATIONBUILDER_H
#include "populationbuilder.h"

class RealIndividualPopulationBuilder : public PopulationBuilder
{
public:
    RealIndividualPopulationBuilder();
    ~RealIndividualPopulationBuilder();
    void initiate(IndividualBuilder *individualBuilder, Population *population);
};

#endif // REALINDIVIDUALPOPULATIONBUILDER_H
