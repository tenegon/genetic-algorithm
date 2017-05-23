#ifndef VALUER_H
#define VALUER_H
#include "function.h"
#include "population.h"

class Valuer
{
protected:
    uint *evaluations;
    Function *function;
public:
    Valuer(uint *evaluations, Function *function);
    void evaluate(Individual *individual);
    void evaluate(Population *population);
    Function *getFunction() const;
    void setFunction(Function *value);
};

#endif // VALUER_H
