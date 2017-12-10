#ifndef ROSENBROCKFUNCTION_H
#define ROSENBROCKFUNCTION_H
#include "realfunction.h"

class RosenbrockFunction : public RealFunction
{
public:
    RosenbrockFunction();
    ~RosenbrockFunction();
    void calcule(Individual *individual);
    void print(std::ostream& os) const;
};

#endif // ROSENBROCKFUNCTION_H
