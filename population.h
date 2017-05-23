#ifndef POPULATION_H
#define POPULATION_H
#include <algorithm>
#include "individual.h"

bool lessThen(const Individual *left, const Individual *right);
bool moreThen(const Individual *left, const Individual *right);
bool egual(const Individual *left, const Individual *right);
bool different(const Individual *left, const Individual *right);

class Population
{
protected:
    uint t;
    std::vector<Individual*> *population;
public:
    Population(uint t);
    virtual ~Population();
    virtual Individual *best() const;
    virtual Individual *worst() const;
    virtual void sort();
    virtual Individual *get(const uint &i) const;
    virtual void set(const uint &i, Individual *individual);
    uint getT() const;
    void setT(const uint &value);
    virtual std::vector<Individual *> *getPopulation() const;
    virtual void setPopulation(std::vector<Individual *> *value);
};

#endif // POPULATION_H
