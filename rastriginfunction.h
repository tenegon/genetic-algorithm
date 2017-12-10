#ifndef RASTRIGINFUNCTION_H
#define RASTRIGINFUNCTION_H
#include "realfunction.h"

class RastriginFunction : public RealFunction
{
public:
    RastriginFunction();
    ~RastriginFunction();
    void calcule(Individual *individual);
    void print(std::ostream& os) const;
};

#endif // RASTRIGINFUNCTION_H
