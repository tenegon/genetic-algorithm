#ifndef BLXCROSSOVER_H
#define BLXCROSSOVER_H
#include "realcrossover.h"

class BlxCrossover : public RealCrossover
{
protected:
    double a = 0.5f, b;
public:
    BlxCrossover(double rate, Generation *generation, RealIndividualConstraint *realIndividualConstraint);
    void crossing(RealIndividual *dad, RealIndividual *mom, RealIndividual *child);
};

#endif // BLXCROSSOVER_H
