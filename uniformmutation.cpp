#include "uniformmutation.h"

UniformMutation::UniformMutation(double rate, Generation *generation, IndividualConstraint *individualConstraint): RealMutation(rate, generation, individualConstraint)
{

}

UniformMutation::~UniformMutation()
{

}

void UniformMutation::mutation(const uint &gene)
{
    RealIndividualConstraint *realIndividualConstraint = dynamic_cast<RealIndividualConstraint*>(individualConstraint);
    double minGene = realIndividualConstraint->getMinimum()->getGene(gene);
    double maxGene = realIndividualConstraint->getMaximum()->getGene(gene);
    mutantGene = r() * (maxGene - minGene) + minGene;
}
