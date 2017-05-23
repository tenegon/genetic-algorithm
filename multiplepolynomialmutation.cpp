#include "multiplepolynomialmutation.h"

MultiplePolynomialMutation::MultiplePolynomialMutation(double rate, Generation *generation, RealIndividualConstraint *realIndividualConstraint, double U, double L, double nm): PolynomialMutation(rate, generation, realIndividualConstraint, U, L, nm)
{

}

void MultiplePolynomialMutation::mutation(const uint &gene, RealIndividual *mutant)
{
    do{
        mutantGene = mutant->getGene(gene);
        PolynomialMutation::mutation(gene);
    }while(!realIndividualConstraint->isGeneFeasible(gene, mutantGene));
    mutant->setGene(gene, mutantGene);
}

void MultiplePolynomialMutation::mutation(RealIndividual *mutant)
{
    uint t = mutant->getGenes().size();
    for(gene = 0; gene < t; gene++){
        mutation(gene, mutant);
    }
}
