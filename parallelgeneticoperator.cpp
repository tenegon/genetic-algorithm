#include "parallelgeneticoperator.h"

ParallelGeneticOperator::ParallelGeneticOperator(double rate, Generation *generation, uint threadsNumber): GeneticOperator(rate, generation), threadsNumber(threadsNumber), threads(new std::vector<std::thread*>), geneticOperators(new std::vector<GeneticOperator*>)
{

}

ParallelGeneticOperator::~ParallelGeneticOperator()
{
    delete geneticOperators;
    delete threads;
}

void ParallelGeneticOperator::apply()
{
    for(uint i = 0; i < threads->size(); i++){
        if(threads->at(i)->joinable()){
            threads->at(i)->join();
        }
    }
}

void ParallelGeneticOperator::print(std::ostream &os) const
{
    os << "Parallel";
}

std::ostream &operator<<(std::ostream &os, const ParallelGeneticOperator &pgo)
{
    pgo.print(os);
    return os;
}
