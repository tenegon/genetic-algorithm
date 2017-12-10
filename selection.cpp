#include "selection.h"

Selection::Selection(double rate, Generation *generation, bool withSorting): GeneticOperator(rate, generation), withSorting(withSorting)
{
    population = generation->getPopulation();
    parents = generation->getParents();
    setRange(0, generation->getParents()->getT() - 1);
}

Selection::~Selection()
{
    population = 0;
    parents = 0;
}

void Selection::apply()
{
    if(withSorting){
        population->sort();
    }
    for(currentParent = range->getMinimum(); currentParent <= range->getMaximum(); currentParent++){
        if(r() <= rate){
            select();
        }
    }
}

Population *Selection::getPopulation() const
{
    return population;
}

void Selection::setPopulation(Population *value)
{
    population = value;
}

Population *Selection::getParents() const
{
    return parents;
}

void Selection::setParents(Population *value)
{
    parents = value;
}

uint Selection::getCurrentSelected() const
{
    return currentSelected;
}

void Selection::setCurrentSelected(const uint &value)
{
    currentSelected = value;
}

uint Selection::getCurrentChallenger() const
{
    return currentChallenger;
}

void Selection::setCurrentChallenger(const uint &value)
{
    currentChallenger = value;
}

bool Selection::getWithSorting() const
{
    return withSorting;
}

void Selection::setWithSorting(bool value)
{
    withSorting = value;
}
