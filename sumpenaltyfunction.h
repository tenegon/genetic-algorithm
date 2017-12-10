#ifndef SUMPENALTYFUNCTION_H
#define SUMPENALTYFUNCTION_H
#include "penaltyfunction.h"
#include "realindividual.h"
#include "numericconstraint.h"

class SumPenaltyFunction : public PenaltyFunction
{
private:
    double exp;
    NumericConstraint<double> *sumConstraint;
public:
    SumPenaltyFunction(int signal, double modifier, double exp, NumericConstraint<double> *sumConstraint);
    ~SumPenaltyFunction();
    void penalize(Individual *individual);
    double penalty(const double &sum);
    void print(std::ostream& os) const;
    NumericConstraint<double> *getSumConstraint() const;
    void setSumConstraint(NumericConstraint<double> *value);
    double getExp() const;
    void setExp(double value);
};

#endif // SUMPENALTYFUNCTION_H
