#ifndef TOURNAMENTSELECTION_H
#define TOURNAMENTSELECTION_H
#include "selection.h"

class TournamentSelection : public Selection
{
protected:
    uint tournamentSize;
public:
    TournamentSelection(double rate, Generation *generation, bool withSorting, uint tournamentSize);
    ~TournamentSelection();
    virtual void select();
    uint getTournamentSize() const;
    void setTournamentSize(const uint &value);
    void print(std::ostream& os) const;
};

#endif // TOURNAMENTSELECTION_H
