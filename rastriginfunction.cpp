#include "rastriginfunction.h"

RastriginFunction::RastriginFunction(): RealFunction()
{

}

RastriginFunction::~RastriginFunction()
{

}

void RastriginFunction::calcule(Individual *individual)
{
    RealIndividual *real  = dynamic_cast<RealIndividual*>(individual);
    uint t = real->getGenes().size();
    double fitness = 10.0f * t;
    for (unsigned int i = 0; i < t; i++) {
        fitness += pow(real->getGene(i), 2.0f) - 10.0f * cos(2.0f * PI * real->getGene(i));
    }
    individual->setFitness(fitness);
}

void RastriginFunction::print(std::ostream &os) const
{
    os << "Rastrigin ";
    Function::print(os);
}
