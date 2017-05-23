#include "tournamentselection.h"

TournamentSelection::TournamentSelection(double rate, Generation *generation, uint tournamentSize): Selection(rate, generation), tournamentSize(tournamentSize)
{

}

void TournamentSelection::select()
{
    uint t = population->getPopulation()->size();
    currentSelected = rand() % t;
    Individual *selected = population->get(currentSelected);
    for(uint i = 1; i < tournamentSize; i++){
        currentChallenger = rand() % t;
        Individual *challenger = population->get(currentChallenger);
        if(challenger->isBetter(selected)){
            selected = challenger;
            currentSelected = currentChallenger;
        }
    }
    parents->set(currentParent, selected);
}

void TournamentSelection::apply()
{
    uint u = parents->getPopulation()->size();
    for(currentParent = 0; currentParent < u; currentParent++){
        if(r() <= rate){
            select();
        }
    }
}

uint TournamentSelection::getTournamentSize() const
{
    return tournamentSize;
}

void TournamentSelection::setTournamentSize(const uint &value)
{
    tournamentSize = value;
}
