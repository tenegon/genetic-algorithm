#ifndef SELECTION_H
#define SELECTION_H
#include "geneticoperator.h"

class Selection : public GeneticOperator
{
protected:
    Population *population = 0;
    Population *parents = 0;
    uint currentSelected;
    uint currentChallenger;
    bool withSorting;
public:
    Selection(double rate, Generation *generation, bool withSorting);
    virtual ~Selection();
    virtual void select() = 0;
    void apply();
    Population *getPopulation() const;
    void setPopulation(Population *value);
    Population *getParents() const;
    void setParents(Population *value);
    uint getCurrentSelected() const;
    void setCurrentSelected(const uint &value);
    uint getCurrentChallenger() const;
    void setCurrentChallenger(const uint &value);
    bool getWithSorting() const;
    void setWithSorting(bool value);
};

#endif // SELECTION_H
