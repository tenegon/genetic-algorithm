#include "stopcriteria.h"

StopCriteria::StopCriteria(): stopCriteria(new std::vector<StopCriter*>)
{

}

bool StopCriteria::meets()
{
    for(uint i = 0; i < stopCriteria->size(); i++){
        if(stopCriteria->at(i)->meets()){
            return true;
        }
    }
    return false;
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
