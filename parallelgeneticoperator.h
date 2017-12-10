#ifndef PARALLELGENETICOPERATOR_H
#define PARALLELGENETICOPERATOR_H
#include <thread>
#include "geneticoperator.h"

class ParallelGeneticOperator : public GeneticOperator
{
protected:
    uint threadsNumber;
    std::vector<std::thread*> *threads;
    std::vector<GeneticOperator*> *geneticOperators;
public:
    ParallelGeneticOperator(double rate, Generation *generation, uint threadsNumber);
    virtual ~ParallelGeneticOperator();
    void apply();
    friend std::ostream& operator<<(std::ostream& os, const ParallelGeneticOperator& pgo);
    virtual void print(std::ostream& os) const;

};

#endif // PARALLELGENETICOPERATOR_H
