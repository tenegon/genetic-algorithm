#ifndef REALGENETICOPERATOR_H
#define REALGENETICOPERATOR_H
#include "geneticoperator.h"
#include "realindividualconstraint.h"

class RealGeneticOperator : public GeneticOperator
{
protected:
    RealIndividualConstraint *realIndividualConstraint;
public:
    RealGeneticOperator(double rate, Generation *generation, RealIndividualConstraint *realIndividualConstraint);
    RealIndividualConstraint *getRealIndividualConstraint() const;
    void setRealIndividualConstraint(RealIndividualConstraint *value);
};

#endif // REALGENETICOPERATOR_H
