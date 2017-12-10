#ifndef PARALLELVALUER_H
#define PARALLELVALUER_H
#include "parallel.h"
#include "valuerbuilder.h"

class ParallelValuer : public Parallel<Valuer>, public Valuer
{
private:
    VALUER valuer;
public:
    ParallelValuer(uint *evaluations, Function *function, Population *population, uint threadsNumber, VALUER valuer, std::vector<PenaltyFunction*> *penality = 0);
    ~ParallelValuer();
    void apply();
    //Valuer *clone();
    void setFunction(Function *value);
    void setEvaluations(uint *value);
    void setPopulation(Population *value);
    void print(std::ostream& os) const;
};

#endif // PARALLELVALUER_H
