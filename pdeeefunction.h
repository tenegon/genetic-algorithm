#ifndef PDEEEFUNCTION_H
#define PDEEEFUNCTION_H
#include "realfunction.h"

class PdeeeFunction : public RealFunction
{
protected:
    RealIndividual *minimum = 0;
    std::vector<double> a;
    std::vector<double> b;
    std::vector<double> c;
    std::vector<double> e;
    std::vector<double> f;
public:
    PdeeeFunction(RealIndividual *minimum, std::vector<double> a, std::vector<double> b, std::vector<double> c, std::vector<double> e, std::vector<double> f);
    ~PdeeeFunction();
    void calcule(Individual *individual);
    void print(std::ostream& os) const;
    RealIndividual *getMinimum() const;
    void setMinimum(RealIndividual *value);
    std::vector<double> getF() const;
};

#endif // PDEEEFUNCTION_H
