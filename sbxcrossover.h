#ifndef SBXCROSSOVER_H
#define SBXCROSSOVER_H
#include "realcrossover.h"

class SbxCrossover : public RealCrossover
{
protected:
    double a, b = 2.0f, n;
public:
    SbxCrossover(double rate, Generation *generation, IndividualConstraint *individualConstraint);
    ~SbxCrossover();
    void crossing(Individual *dad, Individual *mom, Individual *child);
    void print(std::ostream& os) const;
};

#endif // SBXCROSSOVER_H
