#ifndef REALINDIVIDUALCRONSTRAINT_H
#define REALINDIVIDUALCRONSTRAINT_H
#include "individualconstraint.h"
#include "realindividual.h"

class RealIndividualConstraint : public IndividualConstraint
{
protected:
    NumericConstraint *sumConstraint;
    RealIndividual *minimum;
    RealIndividual *maximum;
public:
    RealIndividualConstraint(NumericConstraint *tConstraint, NumericConstraint *fitnessConstraint, NumericConstraint *sumConstraint, RealIndividual *minimum, RealIndividual *maximum);
    bool isSumFeasible(const double &sum);
    bool isGeneFeasible(const uint &i, const double &gene);
    bool areGenesFeasible(const std::vector<double> &genes);
    bool isFeasible(const RealIndividual *individual);
    RealIndividual *getMinimum() const;
    void setMinimum(RealIndividual *value);
    RealIndividual *getMaximum() const;
    void setMaximum(RealIndividual *value);
    NumericConstraint *getSumConstraint() const;
    void setSumConstraint(NumericConstraint *value);
};

#endif // REALINDIVIDUALCRONSTRAINT_H
