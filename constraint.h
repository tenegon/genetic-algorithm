#ifndef CONSTRAINT_H
#define CONSTRAINT_H
#include <cstdlib>

class Constraint
{
public:
    Constraint();
    virtual bool isFeasible() = 0;
};

#endif // CONSTRAINT_H
