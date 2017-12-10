#ifndef RANKINGSELECTION_H
#define RANKINGSELECTION_H
#include "selection.h"
#include "realindividual.h"

class RankingSelection : public Selection
{
protected:
    double S;
    double sum;
    double limit;
public:
    RankingSelection(double rate, Generation *generation, bool withSorting);
    ~RankingSelection();
    virtual void makeRanking() = 0;
    virtual double slice() = 0;
    void roll();
    void select();
    void apply();
    double getS() const;
    void setS(double value);
    double getSum() const;
    void setSum(double value);
    double getLimit() const;
    void setLimit(double value);
};

#endif // RANKINGSELECTION_H
