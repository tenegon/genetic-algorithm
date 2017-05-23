#include "rankselection.h"

RankSelection::RankSelection(double rate, Generation *generation, bool withSorting): RankingSelection(rate, generation, withSorting)
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
