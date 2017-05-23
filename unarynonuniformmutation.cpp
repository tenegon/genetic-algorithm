#include "unarynonuniformmutation.h"

UnaryNonUniformMutation::UnaryNonUniformMutation(double rate, Generation *generation, RealIndividualConstraint *realIndividualConstraint, NumericConstraint *iterationsConstraint, uint *iteration): NonUniformMutation(rate, generation, realIndividualConstraint, iterationsConstraint, iteration)
{

}

void UnaryNonUniformMutation::mutation(const uint &gene, RealIndividual *mutant)
{
    do{
        mutantGene = mutant->getGene(gene);
        NonUniformMutation::mutation(gene);
    }while(!realIndividualConstraint->isGeneFeasible(gene, mutantGene));
    mutant->setGene(gene, mutantGene);
}

void UnaryNonUniformMutation::mutation(RealIndividual *mutant)
{
    uint t = mutant->getGenes().size();
    gene = rand() % t;
    mutation(gene, mutant);
}
