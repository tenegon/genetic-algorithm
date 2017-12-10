#ifndef REALINDIVIDUALCRONSTRAINT_H
#define REALINDIVIDUALCRONSTRAINT_H
#include "individualconstraint.h"
#include "realindividual.h"

class RealIndividualConstraint : public IndividualConstraint
{
protected:
    NumericConstraint<double> *sumConstraint;
    RealIndividual *minimum = 0;
    RealIndividual *maximum = 0;
public:
    RealIndividualConstraint(NumericConstraint<uint> *tConstraint, NumericConstraint<double> *fitnessConstraint, NumericConstraint<double> *sumConstraint, RealIndividual *minimum, RealIndividual *maximum);
    ~RealIndividualConstraint();
    bool isSumFeasible(const double &sum);
    bool isGeneFeasible(const uint &i, const double &gene);
    bool areGenesFeasible(const std::vector<double> &genes);
    bool isFeasible();
    bool isFeasible(const RealIndividual *individual);
    RealIndividual *getMinimum() const;
    void setMinimum(RealIndividual *value);
    RealIndividual *getMaximum() const;
    void setMaximum(RealIndividual *value);
    NumericConstraint<double> *getSumConstraint() const;
    void setSumConstraint(NumericConstraint<double> *value);
};

#endif // REALINDIVIDUALCRONSTRAINT_H
