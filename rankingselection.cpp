#include "rankingselection.h"

RankingSelection::RankingSelection(double rate, Generation *generation, bool withSorting): Selection(rate, generation, withSorting), S(0.0f), sum(0.0f), limit(0.0f)
{

}

RankingSelection::~RankingSelection()
{

}

void RankingSelection::roll()
{
    uint t = population->getPopulation()->size();
    limit = S * r();
    sum = 0.0f;
    for(currentIndividual = 0; currentIndividual < t && sum < limit; currentIndividual++){
        sum += slice();
    }
    currentIndividual--;
}

void RankingSelection::select()
{
    roll();
    Individual *dad = population->get(currentIndividual);
    Individual *ind = parents->get(currentParent);
    ind->set(dad);
    dad->setSelected(true);
}

void RankingSelection::apply()
{
    makeRanking();
    Selection::apply();
}

double RankingSelection::getS() const
{
    return S;
}

void RankingSelection::setS(double value)
{
    S = value;
}

double RankingSelection::getSum() const
{
    return sum;
}

void RankingSelection::setSum(double value)
{
    sum = value;
}

double RankingSelection::getLimit() const
{
    return limit;
}

void RankingSelection::setLimit(double value)
{
    limit = value;
}
