#include "multipleboundarymutation.h"

MultipleBoundaryMutation::MultipleBoundaryMutation(double rate, Generation *generation, RealIndividualConstraint *realIndividualConstraint): BoundaryMutation(rate, generation, realIndividualConstraint)
{

}

void MultipleBoundaryMutation::mutation(const uint &gene, RealIndividual *mutant)
{
    do{
        mutantGene = mutant->getGene(gene);
        BoundaryMutation::mutation(gene);
    }while(!realIndividualConstraint->isGeneFeasible(gene, mutantGene));
    mutant->setGene(gene, mutantGene);
}

void MultipleBoundaryMutation::mutation(RealIndividual *mutant)
{
    uint t = mutant->getGenes().size();
    for(gene = 0; gene < t; gene++){
        mutation(gene, mutant);
    }
}
