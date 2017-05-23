#include "zakharovfunction.h"

ZakharovFunction::ZakharovFunction(): RealFunction()
{

}

void ZakharovFunction::calcule(Individual *individual)
{
    RealIndividual *real  = dynamic_cast<RealIndividual*>(individual);
    uint t = real->getGenes().size();
    double f1 = 0.0f, f2 = 0.0f, f3 = 0.0f;
    double fitness = 0.0f;
    for (unsigned int i = 0; i < t; i++) {
        f1 += pow(real->getGene(i), 2.0f);
        f2 += 0.5f * (i + 1.0f) * real->getGene(i);
    }
    f3 = f2;
    fitness = f1 + pow(f2, 2.0f) + pow(f3, 4.0f);
    individual->setFitness(fitness);
}
