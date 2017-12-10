#ifndef ZAKHAROVFUNCTION_H
#define ZAKHAROVFUNCTION_H
#include "realfunction.h"

class ZakharovFunction : public RealFunction
{
public:
    ZakharovFunction();
    ~ZakharovFunction();
    void calcule(Individual *individual);
    void print(std::ostream& os) const;
};

#endif // ZAKHAROVFUNCTION_H
