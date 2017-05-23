#include "population.h"

Population::Population(uint t): t(t), population(new std::vector<Individual*>)
{
}

Population::~Population()
{
    delete population;
}

Individual *Population::best() const
{
    Individual *better = population->at(0);
    for(uint i = 1; i < population->size(); i++){
        Individual *selected = population->at(i);
        if(selected->isBetter(better)){
            better = selected;
        }
    }
    return better;
}

Individual *Population::worst() const
{
    Individual *worse = population->at(0);
    for(uint i = 1; i < population->size(); i++){
        Individual *selected = population->at(i);
        if(!selected->isBetter(worse)){
            worse = selected;
        }
    }
    return worse;
}

void Population::sort()
{
    std::sort(population->begin(), population->end(), lessThen);
}

Individual *Population::get(const uint &i) const
{
    if(i < population->size()){
        return population->at(i);
    }
    else{
        return 0;
    }
}

void Population::set(const uint &i, Individual *individual)
{
    if(i < population->size()){
        population->at(i)->set(individual);
    }
}

bool lessThen(const Individual *left, const Individual *right)
{
    return *left < *right;
}

bool moreThen(const Individual *left, const Individual *right)
{
    return *left > *right;
}

bool egual(const Individual *left, const Individual *right)
{
    return *left == *right;
}

bool different(const Individual *left, const Individual *right)
{
    return *left != *right;
}

uint Population::getT() const
{
    return t;
}

void Population::setT(const uint &value)
{
    t = value;
}

std::vector<Individual *> *Population::getPopulation() const
{
    return population;
}

void Population::setPopulation(std::vector<Individual *> *value)
{
    population = value;
}
