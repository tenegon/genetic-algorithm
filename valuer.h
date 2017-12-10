#ifndef VALUER_H
#define VALUER_H
#include "function.h"
#include "population.h"
#include "numericconstraint.h"

class Valuer
{
protected:
    uint *evaluations = 0;
    Function *function = 0;
    Population *population = 0;
    NumericConstraint<uint> *range = 0;
public:
    Valuer(uint *evaluations, Function *function, Population *population = 0);
    virtual ~Valuer();
    virtual void evaluate(Individual *individual);
    virtual void evaluate(Population *population);
    virtual void apply();
    virtual Valuer *clone();
    friend std::ostream& operator<<(std::ostream& os, const Valuer& v);
    virtual void print(std::ostream& os) const;
    Function *getFunction() const;
    virtual void setFunction(Function *value);
    uint *getEvaluations() const;
    virtual void setEvaluations(uint *value);
    Population *getPopulation() const;
    virtual void setPopulation(Population *value);
    void setRange(const uint &begin, const uint &end);
    NumericConstraint<uint> *getRange() const;
};

#endif // VALUER_H
