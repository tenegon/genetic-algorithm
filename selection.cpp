#include "selection.h"

Selection::Selection(double rate, Generation *generation): GeneticOperator(rate, generation)
{
    population = generation->getPopulation();
    parents = generation->getParents();
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
