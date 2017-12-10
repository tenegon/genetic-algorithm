#ifndef ROULETTESELECTION_H
#define ROULETTESELECTION_H
#include "rankingselection.h"

class RouletteSelection : public RankingSelection
{
protected:
    double shift;
public:
    RouletteSelection(double rate, Generation *generation, bool withSorting);
    ~RouletteSelection();
    void makeRanking();
    double slice();
    double getShift() const;
    void setShift(double value);
    void print(std::ostream& os) const;
};

#endif // ROULETTESELECTION_H
