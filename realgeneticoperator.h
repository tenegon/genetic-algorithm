#ifndef REALGENETICOPERATOR_H
#define REALGENETICOPERATOR_H
#include "geneticoperator.h"
#include "realindividualconstraint.h"

class RealGeneticOperator : public GeneticOperator
{
protected:
    IndividualConstraint *individualConstraint;
public:
    RealGeneticOperator(double rate, Generation *generation, IndividualConstraint *individualConstraint);
    virtual ~RealGeneticOperator();
    IndividualConstraint *getRealIndividualConstraint() const;
    void setRealIndividualConstraint(IndividualConstraint *value);
};

#endif // REALGENETICOPERATOR_H
