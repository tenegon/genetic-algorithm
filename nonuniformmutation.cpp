#include "nonuniformmutation.h"

NonUniformMutation::NonUniformMutation(double rate, Generation *generation, RealIndividualConstraint *realIndividualConstraint, NumericConstraint *iterationsConstraint, uint *iteration): RealMutation(rate, generation, realIndividualConstraint), iterationsConstraint(iterationsConstraint), iteration(iteration)
{

}

void NonUniformMutation::mutation(const uint &gene)
{
    double minGene = realIndividualConstraint->getMinimum()->getGene(gene);
    double maxGene = realIndividualConstraint->getMaximum()->getGene(gene);
    if(r() <= 0.5f){
        mutantGene += (maxGene - mutantGene) * fg();
    }
    else{
        mutantGene -= (mutantGene - minGene) * fg();
    }
}

double NonUniformMutation::fg()
{
    return pow(r() * (1.0f - ((double)*iteration/double(iterationsConstraint->getMaximum()))), b);
}
