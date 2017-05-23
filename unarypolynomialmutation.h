#ifndef UNARYPOLYNOMIALMUTATION_H
#define UNARYPOLYNOMIALMUTATION_H
#include "polynomialmutation.h"

class UnaryPolynomialMutation : public PolynomialMutation
{
public:
    UnaryPolynomialMutation(double rate, Generation *generation, RealIndividualConstraint *realIndividualConstraint, double U = 0, double L = 0, double nm = 20);
    void mutation(const uint &gene, RealIndividual *mutant);
    void mutation(RealIndividual *mutant);
};

#endif // UNARYPOLYNOMIALMUTATION_H
