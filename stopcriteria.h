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
    ~StopCriteria();
    bool meets();
    bool insert(StopCriter *stopCriter);
    bool remove(StopCriter *stopCriter);
    bool search(StopCriter *stopCriter);
    void print(std::ostream& os) const;
    std::vector<StopCriter *> *getStopCriteria() const;
    void setStopCriteria(std::vector<StopCriter *> *value);
};

#endif // STOPCRITERIA_H
