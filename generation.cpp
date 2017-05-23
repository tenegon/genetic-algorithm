#include "generation.h"

Generation::Generation(Population *population, Population *parents, Population *childs): population(population), parents(parents), childs(childs)
{

}

void Generation::initiate(IndividualBuilder *individualGenerator, PopulationBuilder *populationGenerator)
{
    populationGenerator->initiate(individualGenerator, population);
    uint u = parents->getT();
    uint y = childs->getT();
    Individual *base = population->get(0);
    parents->getPopulation()->clear();
    for(uint i = 0; i < u; i++){
        parents->getPopulation()->push_back(base->clone());
    }
    childs->getPopulation()->clear();
    for(uint i = 0; i < y; i++){
        childs->getPopulation()->push_back(base->clone());
    }
}

void Generation::evaluate(Valuer *valuer)
{
    valuer->evaluate(population);
}

Population *Generation::getParents() const
{
    return parents;
}

void Generation::setParents(Population *value)
{
    parents = value;
}

Population *Generation::getChilds() const
{
    return childs;
}

void Generation::setChilds(Population *value)
{
    childs = value;
}

Population *Generation::getPopulation() const
{
    return population;
}

void Generation::setPopulation(Population *value)
{
    population = value;
}
