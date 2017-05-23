#ifndef STOPCRITER_H
#define STOPCRITER_H
enum class STOPCRITER{FitnessEvaluetions, FitnessValue, Iterations, Time, Sum};

class StopCriter
{
public:
    StopCriter();
    virtual bool meets() = 0;
};

#endif // STOPCRITER_H
