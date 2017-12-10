#ifndef MUTATION_H
#define MUTATION_H
#include "population.h"

class Mutation
{
protected:
    Population *childs = 0;
    double mutantGene;
    uint gene;
public:
    Mutation(Population *childs);
    virtual ~Mutation();
    virtual void mutation(const uint &gene) = 0;
    virtual void mutation(const uint &gene, Individual *mutant) = 0;
    virtual void mutation(Individual *mutant) = 0;
    virtual void mutate() = 0;
    Population *getChilds() const;
    void setChilds(Population *value);
    double getMutantGene() const;
    void setMutantGene(double value);
    uint getGene() const;
    void setGene(const uint &value);
};

#endif // MUTATION_H
