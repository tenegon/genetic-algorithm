#ifndef MULTIPLEPOLYNOMIALMUTATION_H
#define MULTIPLEPOLYNOMIALMUTATION_H
#include "polynomialmutation.h"

class MultiplePolynomialMutation : public PolynomialMutation
{
public:
    MultiplePolynomialMutation(double rate, Generation *generation, RealIndividualConstraint *realIndividualConstraint, double U = 0, double L = 0, double nm = 20);
    void mutation(const uint &gene, RealIndividual *mutant);
    void mutation(RealIndividual *mutant);
};

#endif // MULTIPLEPOLYNOMIALMUTATION_H
