#include "pdeeefunction.h"

PdeeeFunction::PdeeeFunction(RealIndividual *minimum, std::vector<double> a, std::vector<double> b, std::vector<double> c, std::vector<double> e, std::vector<double> f): minimum(minimum), a(a), b(b), c(c), e(e), f(f)
{

}

PdeeeFunction::~PdeeeFunction()
{

}

void PdeeeFunction::calcule(Individual *individual)
{
    RealIndividual *real  = dynamic_cast<RealIndividual*>(individual);
    uint t = real->getGenes().size();
    double fitness = 0.0;
    double pi = 0.0;
    for (uint i = 0; i < t; i++) {
        pi = real->getGene(i);
        fitness += a.at(i) * pow(pi, 2.0) + b.at(i) * pi + c.at(i) + abs(e.at(i) * sin(f.at(i) * (minimum->getGene(i) - pi)));
    }
    individual->setFitness(fitness);
}

void PdeeeFunction::print(std::ostream &os) const
{
    os << "PDEEE ";// << std::endl;
    //os << "a\tb\tc\te\tf" << std::endl;
    //for (uint i = 0; i < minimum->getGenes().size(); ++i) {
        //os << a.at(i) << "\t" << b.at(i) << "\t" << c.at(i) << "\t" << e.at(i) << "\t" << f.at(i) << std::endl;
    //}
    Function::print(os);
}

RealIndividual *PdeeeFunction::getMinimum() const
{
    return minimum;
}

void PdeeeFunction::setMinimum(RealIndividual *value)
{
    minimum = value;
}

std::vector<double> PdeeeFunction::getF() const
{
    return f;
}
