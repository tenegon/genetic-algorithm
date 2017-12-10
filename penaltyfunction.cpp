#include "penaltyfunction.h"

PenaltyFunction::PenaltyFunction(int signal, double modifier): signal(signal), modifier(modifier)
{
    
}

PenaltyFunction::~PenaltyFunction()
{

}

void PenaltyFunction::print(std::ostream &os) const
{
    os << "Penalty Function";
}

std::ostream &operator<<(std::ostream &os, const PenaltyFunction &pf)
{
    pf.print(os);
    return os;
}

int PenaltyFunction::getSignal() const
{
    return signal;
}

void PenaltyFunction::setSignal(int value)
{
    signal = value;
}

double PenaltyFunction::getModifier() const
{
    return modifier;
}

void PenaltyFunction::setModifier(double value)
{
    modifier = value;
}
