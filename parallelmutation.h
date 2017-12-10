#ifndef PARALLELMUTATION_H
#define PARALLELMUTATION_H
#include "parallel.h"
#include "geneticoperator.h"
#include "mutationbuilder.h"

class ParallelMutation : public Parallel<GeneticOperator>, public GeneticOperator
{
private:
    CODIFICATION codification;
    MUTATION mutation;
    MUTATIONMODE mode;
public:
    ParallelMutation(double rate, Generation *generation, IndividualConstraint *individualConstraint, uint threadsNumber, CODIFICATION codification, MUTATION mutation, MUTATIONMODE mode, GeneticOperatorParameter *gop1 = 0, GeneticOperatorParameter *gop2 = 0);
    ~ParallelMutation();
    void apply();
    void print(std::ostream& os) const;
};

#endif // PARALLELMUTATION_H
