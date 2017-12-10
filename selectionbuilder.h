#ifndef SELECTIONBUILDER_H
#define SELECTIONBUILDER_H
#include "rankselection.h"
#include "rouletteselection.h"
#include "tournamentselection.h"
#include "parallelselection.h"

class SelectionBuilder
{
public:
    SelectionBuilder();
    ~SelectionBuilder();
    GeneticOperator *buildRankSelection(double rate, Generation *generation, bool withSorting, PROGRAMATION programation = PROGRAMATION::Sequential, uint threadsNumber = 4);
    GeneticOperator *buildRouletteSelection(double rate, Generation *generation, bool withSorting, PROGRAMATION programation = PROGRAMATION::Sequential, uint threadsNumber = 4);
    GeneticOperator *buildTournamentSelection(double rate, Generation *generation, bool withSorting, uint tournamentSize, PROGRAMATION programation = PROGRAMATION::Sequential, uint threadsNumber = 4);
};

#endif // SELECTIONBUILDER_H
