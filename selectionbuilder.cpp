#include "selectionbuilder.h"

SelectionBuilder::SelectionBuilder()
{

}

SelectionBuilder::~SelectionBuilder()
{

}

GeneticOperator *SelectionBuilder::buildRankSelection(double rate, Generation *generation, bool withSorting, PROGRAMATION programation, uint threadsNumber)
{
    GeneticOperator *sel = 0;
    switch (programation) {
    case PROGRAMATION::Parallel:
        sel =  new ParallelSelection(rate, generation, threadsNumber, SELECTION::Rank, withSorting, 0);
        break;
    case PROGRAMATION::Sequential:
        sel = new RankSelection(rate, generation, withSorting);
        break;
    }
    return sel;
}

GeneticOperator *SelectionBuilder::buildRouletteSelection(double rate, Generation *generation, bool withSorting, PROGRAMATION programation, uint threadsNumber)
{
    GeneticOperator *sel = 0;
    switch (programation) {
    case PROGRAMATION::Parallel:
        sel = new ParallelSelection(rate, generation, threadsNumber, SELECTION::Roulette, withSorting, 0);
        break;
    case PROGRAMATION::Sequential:
        sel = new RouletteSelection(rate, generation, withSorting);
        break;
    }
    return sel;
}

GeneticOperator *SelectionBuilder::buildTournamentSelection(double rate, Generation *generation, bool withSorting, uint tournamentSize, PROGRAMATION programation, uint threadsNumber)
{
    GeneticOperator *sel = 0;
    switch (programation) {
    case PROGRAMATION::Parallel:
        sel = new ParallelSelection(rate, generation, threadsNumber, SELECTION::Tournament, withSorting, tournamentSize);
        break;
    case PROGRAMATION::Sequential:
        sel = new TournamentSelection(rate, generation, withSorting, tournamentSize);
        break;
    }
    return sel;
}
