#ifndef VALUERBUILDER_H
#define VALUERBUILDER_H
#include "penaltyvaluer.h"
#include "parallelvaluer.h"

class ValuerBuilder
{
public:
    ValuerBuilder();
    ~ValuerBuilder();
    Valuer *buildValuer(uint *evaluations, Function *function, PROGRAMATION programation = PROGRAMATION::Sequential, uint threadsNumber = 2, Population *population = 0);
    Valuer *buildPenaltyValuer(uint *evaluations, Function *function, PROGRAMATION programation = PROGRAMATION::Sequential, uint threadsNumber = 2, Population *population = 0, std::vector<PenaltyFunction*> *penality = 0);
};

#endif // VALUERBUILDER_H
