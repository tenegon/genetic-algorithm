#ifndef MULTIPLEUNIFORMMUTATION_H
#define MULTIPLEUNIFORMMUTATION_H
#include "uniformmutation.h"

class MultipleUniformMutation : public UniformMutation
{
public:
    MultipleUniformMutation(double rate, Generation *generation, RealIndividualConstraint *realIndividualConstraint);
    void mutation(const uint &gene, RealIndividual *mutant);
    void mutation(RealIndividual *mutant);
};

#endif // MULTIPLEUNIFORMMUTATION_H
