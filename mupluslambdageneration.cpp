#include "mupluslambdageneration.h"

MuPlusLambdaGeneration::MuPlusLambdaGeneration(Population *population, Population *parents, Population *childs): Generation(population, parents, childs)
{

}

void MuPlusLambdaGeneration::generate()
{
    uint y = childs->getPopulation()->size();
    uint u = parents->getPopulation()->size();
    uint t = population->getPopulation()->size();
    for(uint i = 0; i < y && i < t; i++){
        Individual *individual = population->get(i);
        Individual *child = childs->get(i);
        individual->set(child);
    }
    for(uint i = y, j = 0; i < t && j < u; i++, j++){
        Individual *individual = population->get(i);
        Individual *parent = parents->get(j);
        individual->set(parent);
    }
}
