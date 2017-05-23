#include "unaryuniformmutation.h"

UnaryUniformMutation::UnaryUniformMutation(double rate, Generation *generation, RealIndividualConstraint *realIndividualConstraint): UniformMutation(rate, generation, realIndividualConstraint)
{

}

void UnaryUniformMutation::mutation(const uint &gene, RealIndividual *mutant)
{
    do{
        UniformMutation::mutation(gene);
    }while(!realIndividualConstraint->isGeneFeasible(gene, mutantGene));
    mutant->setGene(gene, mutantGene);
}

void UnaryUniformMutation::mutation(RealIndividual *mutant)
{
    uint t = mutant->getGenes().size();
    gene = rand() % t;
    mutation(gene, mutant);
}
