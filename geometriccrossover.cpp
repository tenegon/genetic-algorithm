#include "geometriccrossover.h"

GeometricCrossover::GeometricCrossover(double rate, Generation *generation, RealIndividualConstraint *realIndividualConstraint): RealCrossover(rate, generation, realIndividualConstraint)
{

}

void GeometricCrossover::crossing(RealIndividual *dad, RealIndividual *mom, RealIndividual *child)
{
    uint y = child->getGenes().size();
    for(uint i = 0; i < y; i++){
        do{
            gene = sqrt(dad->getGene(i) * mom->getGene(i));
        } while(realIndividualConstraint->isGeneFeasible(i, gene));
        child->setGene(i, gene);
    }
    child->setModified(true);
    child->setEvaluated(false);
}
