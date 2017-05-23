#include "unaryboundarymutation.h"

UnaryBoundaryMutation::UnaryBoundaryMutation(double rate, Generation *generation, RealIndividualConstraint *realIndividualConstraint): BoundaryMutation(rate, generation, realIndividualConstraint)
{

}

void UnaryBoundaryMutation::mutation(const uint &gene, RealIndividual *mutant)
{
    do{
        mutantGene = mutant->getGene(gene);
        BoundaryMutation::mutation(gene);
    }while(!realIndividualConstraint->isGeneFeasible(gene, mutantGene));
    mutant->setGene(gene, mutantGene);
}

void UnaryBoundaryMutation::mutation(RealIndividual *mutant)
{
    uint t = mutant->getGenes().size();
    gene = rand() % t;
    mutation(gene, mutant);
}
