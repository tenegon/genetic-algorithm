#include "rankselection.h"

RankSelection::RankSelection(double rate, Generation *generation, bool withSorting): RankingSelection(rate, generation, withSorting)
{

}

RankSelection::~RankSelection()
{

}

void RankSelection::makeRanking()
{
    S = 0.0f;
    for(currentIndividual = 0; currentIndividual < population->getPopulation()->size(); currentIndividual++){
        S += slice();
    }
}

double RankSelection::slice()
{
    return 1.0f / (double(currentIndividual + 1.0f));
}

void RankSelection::print(std::ostream &os) const
{
    os << "Rank Selection ";
    GeneticOperator::print(os);
}
