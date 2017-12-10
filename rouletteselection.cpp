#include "rouletteselection.h"

RouletteSelection::RouletteSelection(double rate, Generation *generation, bool withSorting): RankingSelection(rate, generation, withSorting), shift(0.0f)
{

}

RouletteSelection::~RouletteSelection()
{

}

void RouletteSelection::makeRanking()
{
    S = 0.0f;
    shift = population->best()->getFitness();
    if(shift <= 0.0f){
        shift += fabs(shift) + 1.0f;
    }
    else{
        shift = 0.0f;
    }
    for(currentIndividual = 0; currentIndividual < population->getPopulation()->size(); currentIndividual++){
        S += slice();
    }
}

double RouletteSelection::slice()
{
    return 1.0f / (double(population->get(currentIndividual)->getFitness() + shift));
}

double RouletteSelection::getShift() const
{
    return shift;
}

void RouletteSelection::setShift(double value)
{
    shift = value;
}

void RouletteSelection::print(std::ostream &os) const
{
    os << "Roulette Selection ";
    GeneticOperator::print(os);
}
