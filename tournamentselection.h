#ifndef TOURNAMENTSELECTION_H
#define TOURNAMENTSELECTION_H
#include "selection.h"

class TournamentSelection : public Selection
{
protected:
    uint tournamentSize;
public:
    TournamentSelection(double rate, Generation *generation, uint tournamentSize);
    virtual void select();
    void apply();
    uint getTournamentSize() const;
    void setTournamentSize(const uint &value);
};

#endif // TOURNAMENTSELECTION_H
