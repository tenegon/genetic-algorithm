#include "boundarymutation.h"

BoundaryMutation::BoundaryMutation(double rate, Generation *generation, RealIndividualConstraint *realIndividualConstraint): RealMutation(rate, generation, realIndividualConstraint)
{

}

void BoundaryMutation::mutation(const uint &gene)
{
    double minGene = realIndividualConstraint->getMinimum()->getGene(gene);
    double maxGene = realIndividualConstraint->getMaximum()->getGene(gene);
    if(r() <= 0.5f){
        mutantGene = maxGene;
    }
    else{
        mutantGene = minGene;
    }
}
