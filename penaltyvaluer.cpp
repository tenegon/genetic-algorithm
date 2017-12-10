#include "penaltyvaluer.h"

PenaltyValuer::PenaltyValuer(uint *evaluations, Function *function, Population *population, std::vector<PenaltyFunction *> *penality): Valuer(evaluations, function, population), penality(penality)
{
    if(!penality){
        penality = new std::vector<PenaltyFunction*>;
    }
}

PenaltyValuer::~PenaltyValuer()
{
    delete penality;
}

void PenaltyValuer::evaluate(Individual *individual)
{
    Valuer::evaluate(individual);
    PenaltyFunction *pf = 0;
    for(uint i = 0; i < penality->size(); i++){
        pf = penality->at(i);
        pf->penalize(individual);
    }
}

Valuer *PenaltyValuer::clone()
{
    return  new PenaltyValuer(evaluations, function, population, penality);
}

void PenaltyValuer::insertPenalty(PenaltyFunction *value)
{
    if(!search(value)){
        penality->push_back(value);
    }
}

bool PenaltyValuer::search(PenaltyFunction *value)
{
    PenaltyFunction *pf = 0;
    for(uint i = 0; i < penality->size(); i++){
        pf = penality->at(i);
        if(pf == value){
            return true;
        }
    }
    return false;
}

void PenaltyValuer::removePenalty(PenaltyFunction *value)
{
    PenaltyFunction *pf = 0;
    for(uint i = 0; i < penality->size(); i++){
        pf = penality->at(i);
        if(pf == value){
            penality->erase(penality->begin() + i);
        }
    }
}

void PenaltyValuer::print(std::ostream &os) const
{
    Valuer::print(os);
    os << std::endl << "\tPenalty Functions" << std::endl;
    for(uint i = 0; i < penality->size(); i++){
        os << "i[" << i << "] " << *penality->at(i);
        if(i < penality->size() - 1){
            os << std::endl;
        }
    }
}

std::vector<PenaltyFunction *> *PenaltyValuer::getPenality() const
{
    return penality;
}

void PenaltyValuer::setPenality(std::vector<PenaltyFunction *> *value)
{
    penality = value;
}
