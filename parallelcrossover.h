#ifndef PARALLELCROSSOVER_H
#define PARALLELCROSSOVER_H
#include "parallel.h"
#include "geneticoperator.h"
#include "crossoverbuilder.h"

class ParallelCrossover : public Parallel<GeneticOperator>, public GeneticOperator
{
private:
    CODIFICATION codification;
    CROSSOVER crossover;
public:
    ParallelCrossover(double rate, Generation *generation, IndividualConstraint *individualConstraint, uint threadsNumber, CODIFICATION codification, CROSSOVER crossover, GeneticOperatorParameter *geneticOperatorParameter = 0);
    ~ParallelCrossover();
    void apply();
    void print(std::ostream& os) const;
};

#endif // PARALLELCROSSOVER_H
