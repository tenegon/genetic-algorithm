#include "sbxcrossover.h"

SbxCrossover::SbxCrossover(double rate, Generation *generation, RealIndividualConstraint *realIndividualConstraint): RealCrossover(rate, generation, realIndividualConstraint)
{

}

void SbxCrossover::crossing(RealIndividual *dad, RealIndividual *mom, RealIndividual *child)
{
    uint t = child->getGenes().size();
    for(uint i = 0; i < t; i++){
        do{
            a = r();
            if(a <= 0.5f){
                b = pow(2.0f * a, 1.0f / (n + 1.0f));
            }
            else{
                b = pow(1.0f / (2.0f * (1.0f - a)), 1.0f / (n + 1.0f));
            }
            gene = 0.5f * ((1.0f + b) * dad->getGene(i) + (1.0f - b) * mom->getGene(i));
        }while(realIndividualConstraint->isGeneFeasible(i, gene));
        child->setGene(i, gene);
    }
    child->setModified(true);
    child->setEvaluated(false);
}
