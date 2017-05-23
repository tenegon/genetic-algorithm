#ifndef ZAKHAROVFUNCTION_H
#define ZAKHAROVFUNCTION_H
#include "realfunction.h"

class ZakharovFunction : public RealFunction
{
public:
    ZakharovFunction();
    void calcule(Individual *individual);
};

#endif // ZAKHAROVFUNCTION_H
