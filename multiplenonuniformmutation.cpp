#include "multiplenonuniformmutation.h"

MultipleNonUniformMutation::MultipleNonUniformMutation(double rate, Generation *generation, RealIndividualConstraint *realIndividualConstraint, NumericConstraint *iterationsConstraint, uint *iteration): NonUniformMutation(rate, generation, realIndividualConstraint, iterationsConstraint, iteration)
{

}

void MultipleNonUniformMutation::mutation(const uint &gene, RealIndividual *mutant)
{
    do{
        mutantGene = mutant->getGene(gene);
        NonUniformMutation::mutation(gene);
    }while(!realIndividualConstraint->isGeneFeasible(gene, mutantGene));
    mutant->setGene(gene, mutantGene);
}

void MultipleNonUniformMutation::mutation(RealIndividual *mutant)
{
    uint t = mutant->getGenes().size();
    for(gene = 0; gene < t; gene++){
        mutation(gene, mutant);
    }
}
