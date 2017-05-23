#include "rosenbrockfunction.h"

RosenbrockFunction::RosenbrockFunction(): RealFunction()
{

}

void RosenbrockFunction::calcule(Individual *individual)
{
    RealIndividual *real  = dynamic_cast<RealIndividual*>(individual);
    uint t = real->getGenes().size();
    double fitness = 0.0f;
    for (unsigned int i = 0; i < t - 1; i++) {
        fitness += 100.0f * pow(real->getGene(i + 1) - pow(real->getGene(i), 2.0f), 2.0f) + pow(real->getGene(i) - 1.0f, 2.0f);
    }
    individual->setFitness(fitness);
}
