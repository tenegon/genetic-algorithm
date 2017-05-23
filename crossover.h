#ifndef CROSSOVER_H
#define CROSSOVER_H
#include "population.h"
enum class CROSSOVER{Arithmetic, Blx, Geometric, Mean, Sbx, Linear};

class Crossover
{
protected:
    Population *parents;
    Population *childs;
    uint currentDad;
    uint currentMom;
    double gene;
public:
    Crossover(Population *parents, Population *childs);
    virtual void crossing(Individual *dad, Individual *mom, Individual *child) = 0;
    virtual void cross() = 0;
    Population *getParents() const;
    void setParents(Population *value);
    Population *getChilds() const;
    void setChilds(Population *value);
    uint getCurrentDad() const;
    void setCurrentDad(const uint &value);
    uint getCurrentMom() const;
    void setCurrentMom(const uint &value);
    double getGene() const;
    void setGene(double value);
};

#endif // CROSSOVER_H
