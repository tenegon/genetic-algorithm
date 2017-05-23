#include "uniformmutation.h"

UniformMutation::UniformMutation(double rate, Generation *generation, RealIndividualConstraint *realIndividualConstraint): RealMutation(rate, generation, realIndividualConstraint)
{

}

void UniformMutation::mutation(const uint &gene)
{
    double minGene = realIndividualConstraint->getMinimum()->getGene(gene);
    double maxGene = realIndividualConstraint->getMaximum()->getGene(gene);
    mutantGene = r() * (maxGene - minGene) + minGene;
}
