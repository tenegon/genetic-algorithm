#include "sbxcrossover.h"

SbxCrossover::SbxCrossover(double rate, Generation *generation, IndividualConstraint *realIndividualConstraint): RealCrossover(rate, generation, realIndividualConstraint)
{

}

SbxCrossover::~SbxCrossover()
{

}


void SbxCrossover::crossing(Individual *dad, Individual *mom, Individual *child)
{
    RealIndividual *realDad = dynamic_cast<RealIndividual*>(dad);
    RealIndividual *realMom = dynamic_cast<RealIndividual*>(mom);
    RealIndividual *realChild = dynamic_cast<RealIndividual*>(child);
    RealIndividualConstraint *realIndividualConstraint = dynamic_cast<RealIndividualConstraint*>(individualConstraint);
    uint t = realChild->getGenes().size();
    for(uint i = 0; i < t; i++){
        do{
            a = r();
            if(a <= 0.5f){
                b = pow(2.0f * a, 1.0f / (n + 1.0f));
            }
            else{
                b = pow(1.0f / (2.0f * (1.0f - a)), 1.0f / (n + 1.0f));
            }
            gene = 0.5f * ((1.0f + b) * realDad->getGene(i) + (1.0f - b) * realMom->getGene(i));
        }while(!realIndividualConstraint->isGeneFeasible(i, gene));
        realChild->setGene(i, gene);
    }
    child->setModified(true);
    child->setEvaluated(false);
}

void SbxCrossover::print(std::ostream &os) const
{
    os << "SBX Crossover ";
    GeneticOperator::print(os);
}
