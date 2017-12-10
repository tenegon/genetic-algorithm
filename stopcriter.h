#ifndef STOPCRITER_H
#define STOPCRITER_H
#include "enums.h"

class StopCriter
{
protected:
    STOPCRITER stopCriter;
public:
    StopCriter(STOPCRITER stopCriter = STOPCRITER::Iterations);
    virtual ~StopCriter();
    virtual bool meets() = 0;
    friend std::ostream& operator<<(std::ostream& os, const StopCriter& sc);
    virtual void print(std::ostream& os) const;
    STOPCRITER getStopCriter() const;
    void setStopCriter(const STOPCRITER &value);
};

#endif // STOPCRITER_H
