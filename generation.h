#ifndef GENERATION_H
#define GENERATION_H
#include "population.h"
#include "populationbuilder.h"
#include "valuer.h"
enum class GENERATIONTYPE{MuCommaLambda, MuPlusLambda};

class Generation
{
protected:
    Population *population;
    Population *parents;
    Population *childs;
public:
    Generation(Population *population, Population *parents, Population *childs);
    virtual void initiate(IndividualBuilder *individualGenerator, PopulationBuilder *populationGenerator);
    virtual void generate() = 0;
    virtual void evaluate(Valuer *valuer);
    Population *getPopulation() const;
    void setPopulation(Population *value);
    Population *getParents() const;
    void setParents(Population *value);
    Population *getChilds() const;
    void setChilds(Population *value);
};

#endif // GENERATION_H
