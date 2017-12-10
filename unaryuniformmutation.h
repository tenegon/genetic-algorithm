#ifndef UNARYUNIFORMMUTATION_H
#define UNARYUNIFORMMUTATION_H
#include "uniformmutation.h"

class UnaryUniformMutation : public UniformMutation
{
public:
    UnaryUniformMutation(double rate, Generation *generation, IndividualConstraint *individualConstraint);
    ~UnaryUniformMutation();
    void mutation(const uint &gene, Individual *mutant);
    void mutation(Individual *mutant);
    void print(std::ostream& os) const;
};

#endif // UNARYUNIFORMMUTATION_H
