#ifndef PARALLELSELECTION_H
#define PARALLELSELECTION_H
#include "parallel.h"
#include "geneticoperator.h"
#include "selectionbuilder.h"

union SelectionParameter{
    uint tournamentSize;
    bool withSorting;
};

class ParallelSelection : public Parallel<GeneticOperator>, public GeneticOperator
{
private:
    SELECTION selection;
    bool withSorting;
public:
    ParallelSelection(double rate, Generation *generation,  uint threadsNumber, SELECTION selection, bool withSorting, uint tournamentSize);
    ~ParallelSelection();
    void apply();
    void print(std::ostream& os) const;
};

#endif // PARALLELSELECTION_H
