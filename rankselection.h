#ifndef RANKSELECTION_H
#define RANKSELECTION_H
#include "rankingselection.h"

class RankSelection : public RankingSelection
{
public:
    RankSelection(double rate, Generation *generation, bool withSorting);
    ~RankSelection();
    void makeRanking();
    double slice();
    void print(std::ostream& os) const;
};

#endif // RANKSELECTION_H
