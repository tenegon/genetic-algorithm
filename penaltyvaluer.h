#ifndef PENALTYVALUER_H
#define PENALTYVALUER_H
#include "valuer.h"
#include "penaltyfunction.h"

class PenaltyValuer : public Valuer
{
protected:
    std::vector<PenaltyFunction*> *penality;
public:
    PenaltyValuer(uint *evaluations, Function *function, Population *population = 0, std::vector<PenaltyFunction*> *penality = 0);
    ~PenaltyValuer();
    void evaluate(Individual *individual);
    Valuer *clone();
    void insertPenalty(PenaltyFunction *value);
    bool search(PenaltyFunction *value);
    void removePenalty(PenaltyFunction *value);
    void print(std::ostream& os) const;
    std::vector<PenaltyFunction *> *getPenality() const;
    void setPenality(std::vector<PenaltyFunction *> *value);
};

#endif // PENALTYVALUER_H
