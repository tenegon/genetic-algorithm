#ifndef UNARYBOUNDARYMUTATION_H
#define UNARYBOUNDARYMUTATION_H
#include "boundarymutation.h"

class UnaryBoundaryMutation : public BoundaryMutation
{
public:
    UnaryBoundaryMutation(double rate, Generation *generation, IndividualConstraint *individualConstraint);
    ~UnaryBoundaryMutation();
    void mutation(const uint &gene, Individual *mutant);
    void mutation(Individual *mutant);
    void print(std::ostream& os) const;
};

#endif // UNARYBOUNDARYMUTATION_H
