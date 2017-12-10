#ifndef PENALTYFUNCTION_H
#define PENALTYFUNCTION_H
#include "function.h"

class PenaltyFunction
{
protected:
    int signal;
    double modifier;
public:
    PenaltyFunction(int signal, double modifier);
    virtual ~PenaltyFunction();
    virtual void penalize(Individual *individual) = 0;
    friend std::ostream& operator<<(std::ostream& os, const PenaltyFunction& pf);
    virtual void print(std::ostream& os) const;
    int getSignal() const;
    void setSignal(int value);
    double getModifier() const;
    void setModifier(double value);
};

#endif // PENALTYFUNCTION_H
