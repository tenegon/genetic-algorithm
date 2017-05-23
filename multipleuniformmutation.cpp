#include "multipleuniformmutation.h"

MultipleUniformMutation::MultipleUniformMutation(double rate, Generation *generation, RealIndividualConstraint *realIndividualConstraint): UniformMutation(rate, generation, realIndividualConstraint)
{

}

void MultipleUniformMutation::mutation(const uint &gene, RealIndividual *mutant)
{
    do{
        UniformMutation::mutation(gene);
    }while(!realIndividualConstraint->isGeneFeasible(gene, mutantGene));
    mutant->setGene(gene, mutantGene);
}

void MultipleUniformMutation::mutation(RealIndividual *mutant)
{
    uint t = mutant->getGenes().size();
    for(gene = 0; gene < t; gene++){
        mutation(gene, mutant);
    }
}
