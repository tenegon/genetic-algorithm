#ifndef UNARYNONUNIFORMMUTATION_H
#define UNARYNONUNIFORMMUTATION_H
#include "nonuniformmutation.h"

class UnaryNonUniformMutation : public NonUniformMutation
{
public:
    UnaryNonUniformMutation(double rate, Generation *generation, IndividualConstraint *individualConstraint, NumericConstraint<uint> *iterationsConstraint);
    ~UnaryNonUniformMutation();
    void mutation(const uint &gene, Individual *mutant);
    void mutation(Individual *mutant);
    void print(std::ostream& os) const;
};

#endif // UNARYNONUNIFORMMUTATION_H
