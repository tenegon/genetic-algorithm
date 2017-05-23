#ifndef VALUERBUILDER_H
#define VALUERBUILDER_H
#include "valuer.h"

class ValuerBuilder
{
public:
    ValuerBuilder();
    Valuer *build(uint *evaluations, Function *function);
};

#endif // VALUERBUILDER_H
