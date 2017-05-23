#ifndef MULTIPLENONUNIFORMMUTATION_H
#define MULTIPLENONUNIFORMMUTATION_H
#include "nonuniformmutation.h"

class MultipleNonUniformMutation : public NonUniformMutation
{
public:
    MultipleNonUniformMutation(double rate, Generation *generation, RealIndividualConstraint *realIndividualConstraint, NumericConstraint *iterationsConstraint, uint *iteration);
    void mutation(const uint &gene, RealIndividual *mutant);
    void mutation(RealIndividual *mutant);
};

#endif // MULTIPLENONUNIFORMMUTATION_H
