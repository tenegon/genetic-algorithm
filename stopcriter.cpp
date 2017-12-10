#include "stopcriter.h"

StopCriter::StopCriter(STOPCRITER stopCriter): stopCriter(stopCriter)
{
    
}

StopCriter::~StopCriter()
{

}

void StopCriter::print(std::ostream &os) const
{
    os << " Stop Criter[";
    switch (stopCriter) {
    case STOPCRITER::Attempts:
        os << "Attempts";
        break;
    case STOPCRITER::EvaluationsWithoutImprovement:
        os << "Evaluations without improvement";
        break;
    case STOPCRITER::FitnessEvaluations:
        os << "Evaluations";
        break;
    case STOPCRITER::FitnessValue:
        os << "Fitness Value";
        break;
    case STOPCRITER::Iterations:
        os << "Iterations";
        break;
    case STOPCRITER::Time:
        os << "Time";
        break;
    default:
        break;
    }
    os << "]";
}

std::ostream &operator<<(std::ostream &os, const StopCriter &sc)
{
    sc.print(os);
    return os;
}

STOPCRITER StopCriter::getStopCriter() const
{
    return stopCriter;
}

void StopCriter::setStopCriter(const STOPCRITER &value)
{
    stopCriter = value;
}
