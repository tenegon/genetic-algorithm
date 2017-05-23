#include "mucommalambdageneration.h"

MuCommaLambdaGeneration::MuCommaLambdaGeneration(Population *population, Population *parents, Population *childs): Generation(population, parents, childs)
{
}

void MuCommaLambdaGeneration::generate()
{
    uint y = childs->getPopulation()->size();
    uint u = population->getPopulation()->size();
    for(uint i = 0; i < y && i < u; i++){
        Individual *individual = population->get(i);
        Individual *child = childs->get(i);
        individual->set(child);
    }
}
