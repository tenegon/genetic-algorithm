#ifndef UNARYPOLYNOMIALMUTATION_H
#define UNARYPOLYNOMIALMUTATION_H
#include "polynomialmutation.h"

class UnaryPolynomialMutation : public PolynomialMutation
{
public:
    UnaryPolynomialMutation(double rate, Generation *generation, IndividualConstraint *individualConstraint, double U = 0, double L = 0, double nm = 20);
    ~UnaryPolynomialMutation();
    void mutation(const uint &gene, Individual *mutant);
    void mutation(Individual *mutant);
    void print(std::ostream& os) const;
};

#endif // UNARYPOLYNOMIALMUTATION_H
