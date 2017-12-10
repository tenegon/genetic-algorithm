#include "stopcriteria.h"

StopCriteria::StopCriteria(): stopCriteria(new std::vector<StopCriter*>)
{

}

StopCriteria::~StopCriteria()
{
    delete stopCriteria;
}
bool StopCriteria::meets()
{
    for(uint i = 0; i < stopCriteria->size(); i++){
        if(!stopCriteria->at(i)->meets()){
            return false;
        }
    }
    return true;
}

bool StopCriteria::insert(StopCriter *stopCriter)
{
    if(!search(stopCriter)){
        stopCriteria->push_back(stopCriter);
        return true;
    }
    return false;
}

bool StopCriteria::remove(StopCriter *stopCriter)
{
    for(uint i = 0; i < stopCriteria->size(); i++){
        if(stopCriteria->at(i) == stopCriter){
            stopCriteria->erase(stopCriteria->begin() + i);
            return true;
        }
    }
    return false;
}

bool StopCriteria::search(StopCriter *stopCriter)
{
    for(uint i = 0; i < stopCriteria->size(); i++){
        if(stopCriteria->at(i) == stopCriter){
            return true;
        }
    }
    return false;
}

void StopCriteria::print(std::ostream &os) const
{
    os << "Stop Criteria"  << std::endl;
    for(uint i = 0; i < stopCriteria->size(); i++){
        os << "i[" << i << "] " << *stopCriteria->at(i);
        if(i < stopCriteria->size() - 1){
            os  << std::endl;
        }
    }
}

std::vector<StopCriter *> *StopCriteria::getStopCriteria() const
{
    return stopCriteria;
}

void StopCriteria::setStopCriteria(std::vector<StopCriter *> *value)
{
    stopCriteria = value;
}

