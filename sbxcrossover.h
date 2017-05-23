#ifndef SBXCROSSOVER_H
#define SBXCROSSOVER_H
#include "realcrossover.h"

class SbxCrossover : public RealCrossover
{
protected:
    double a, b = 2.0f, n;
public:
    SbxCrossover(double rate, Generation *generation, RealIndividualConstraint *realIndividualConstraint);
    void crossing(RealIndividual *dad, RealIndividual *mom, RealIndividual *child);
};

#endif // SBXCROSSOVER_H
