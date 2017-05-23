#ifndef RASTRIGINFUNCTION_H
#define RASTRIGINFUNCTION_H
#include "realfunction.h"

class RastriginFunction : public RealFunction
{
public:
    RastriginFunction();
    void calcule(Individual *individual);
};

#endif // RASTRIGINFUNCTION_H
