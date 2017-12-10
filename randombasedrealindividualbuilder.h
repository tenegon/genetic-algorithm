#ifndef RANDOMBASEDREALINDIVIDUALBUILDER_H
#define RANDOMBASEDREALINDIVIDUALBUILDER_H
#include "boundarybasedrealindividualbuilder.h"

class RandomBasedRealIndividualBuilder : public BoundaryBasedRealIndividualBuilder
{
public:
    RandomBasedRealIndividualBuilder(uint t, IndividualConstraint *individualConstraint);
    ~RandomBasedRealIndividualBuilder();
    double generateGene(const uint &i);
};

#endif // RANDOMBASEDREALINDIVIDUALBUILDER_H
