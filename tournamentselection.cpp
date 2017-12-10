#include "tournamentselection.h"

TournamentSelection::TournamentSelection(double rate, Generation *generation, bool withSorting, uint tournamentSize): Selection(rate, generation, withSorting), tournamentSize(tournamentSize)
{

}

TournamentSelection::~TournamentSelection()
{

}

void TournamentSelection::select()
{
    uint t = population->getPopulation()->size();
    currentSelected = rand() % t;
    Individual *selected = population->get(currentSelected);
    Individual *dad = parents->get(currentParent);
    for(uint i = 1; i < tournamentSize; i++){
        currentChallenger = rand() % t;
        Individual *challenger = population->get(currentChallenger);
        if(challenger->isBetter(selected)){
            selected = challenger;
            currentSelected = currentChallenger;
        }
    }
    dad->set(selected);
    selected->setSelected(true);
}

uint TournamentSelection::getTournamentSize() const
{
    return tournamentSize;
}

void TournamentSelection::setTournamentSize(const uint &value)
{
    tournamentSize = value;
}

void TournamentSelection::print(std::ostream &os) const
{
    os << "Tournament Selection ";
    GeneticOperator::print(os);
}
