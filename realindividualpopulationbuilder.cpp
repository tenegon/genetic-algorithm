#include "realindividualpopulationbuilder.h"

RealIndividualPopulationBuilder::RealIndividualPopulationBuilder()
{

}

RealIndividualPopulationBuilder::~RealIndividualPopulationBuilder()
{

}

void RealIndividualPopulationBuilder::initiate(IndividualBuilder *individualBuilder, Population *population)
{
    uint u = population->getT();
    population->getPopulation()->clear();
    for(uint i = 0; i < u; i++){
        population->getPopulation()->push_back(individualBuilder->build());
    }
}

