#include "parallelselection.h"

ParallelSelection::ParallelSelection(double rate, Generation *generation, uint threadsNumber, SELECTION selection, bool withSorting, uint tournamentSize): Parallel<GeneticOperator>(threadsNumber), GeneticOperator(rate, generation), selection(selection), withSorting(withSorting)
{
    SelectionBuilder *selectionBuilder = new SelectionBuilder();
    uint u = generation->getParents()->getT();
    for(uint i = 0, begin = 0, end = 0; end < u - 1; i++){
        begin = (i * (u / threadsNumber));
        end = std::min(u - 1, ((i + 1) * (u / threadsNumber) - 1));
        GeneticOperator *go = 0;
        switch (selection) {
        case SELECTION::Rank:
            go = selectionBuilder->buildRankSelection(rate, generation, false);
            break;
        case SELECTION::Roulette:
            go = selectionBuilder->buildRouletteSelection(rate, generation, false);
            break;
        case SELECTION::Tournament:
            go = selectionBuilder->buildTournamentSelection(rate, generation, false, tournamentSize);
            break;
        }
        go->setRange(begin, end);
        tasks->push_back(go);
        threads->push_back(new std::thread);
    }
    delete selectionBuilder;
}

ParallelSelection::~ParallelSelection()
{

}

void ParallelSelection::apply()
{
    if(withSorting){
        generation->getPopulation()->sort();
    }
    for(uint i = 0; i < threads->size(); i++){
        GeneticOperator *go = tasks->at(i);
        Selection *sgo = dynamic_cast<Selection*>(go);
        delete threads->at(i);
        threads->at(i) = new std::thread(&Selection::apply, sgo);
    }
    Parallel<GeneticOperator>::execute();
}

void ParallelSelection::print(std::ostream &os) const
{
    Parallel<GeneticOperator>::print(os);
    os << " " << *tasks->front();
}
