#ifndef MICHAELEWICZFUNCTION_H
#define MICHAELEWICZFUNCTION_H
#include "realfunction.h"

class MichaelewiczFunction : public RealFunction
{
protected:
    double m;
public:
    MichaelewiczFunction();
    void calcule(Individual *individual);
};

#endif // MICHAELEWICZFUNCTION_H
