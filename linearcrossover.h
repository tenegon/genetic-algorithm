#ifndef LINEARCROSSOVER_H
#define LINEARCROSSOVER_H
#include "realcrossover.h"
#include "realindividualpopulationbuilder.h"
#include "realindividualbuilder.h"

class LinearCrossover : public RealCrossover
{
protected:
    Population *cs;
    Valuer *valuer;
public:
    LinearCrossover(double rate, Generation *generation, RealIndividualConstraint *realIndividualConstraint, Valuer *valuer);
    void crossing(RealIndividual *dad, RealIndividual *mom, RealIndividual *child);
};

#endif // LINEARCROSSOVER_H
