#ifndef SELECTION_H
#define SELECTION_H
#include "geneticoperator.h"
enum class SELECTION{Tournament, Roulette, Rank};

class Selection : public GeneticOperator
{
protected:
    Population *population;
    Population *parents;
    uint currentSelected;
    uint currentChallenger;
public:
    Selection(double rate, Generation *generation);
    virtual void select() = 0;
    Population *getPopulation() const;
    void setPopulation(Population *value);
    Population *getParents() const;
    void setParents(Population *value);
    uint getCurrentSelected() const;
    void setCurrentSelected(const uint &value);
    uint getCurrentChallenger() const;
    void setCurrentChallenger(const uint &value);
};

#endif // SELECTION_H
