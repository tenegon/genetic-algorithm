#ifndef RANKSELECTION_H
#define RANKSELECTION_H
#include "rankingselection.h"

class RankSelection : public RankingSelection
{
public:
    RankSelection(double rate, Generation *generation, bool withSorting);
    void makeRanking();
    double slice();
};

#endif // RANKSELECTION_H
