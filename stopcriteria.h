#ifndef STOPCRITERIA_H
#define STOPCRITERIA_H
#include <vector>
#include <cstdlib>
#include "stopcriter.h"

class StopCriteria : public StopCriter
{
protected:
    std::vector<StopCriter*> *stopCriteria;
public:
    StopCriteria();
    bool meets();
    bool insert(StopCriter *stopCriter);
    bool remove(StopCriter *stopCriter);
    bool search(StopCriter *stopCriter);

};

#endif // STOPCRITERIA_H
