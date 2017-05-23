#ifndef ROSENBROCKFUNCTION_H
#define ROSENBROCKFUNCTION_H
#include "realfunction.h"

class RosenbrockFunction : public RealFunction
{
public:
    RosenbrockFunction();
    void calcule(Individual *individual);
};

#endif // ROSENBROCKFUNCTION_H
