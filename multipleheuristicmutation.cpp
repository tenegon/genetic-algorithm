#include "multipleheuristicmutation.h"

MultipleHeuristicMutation::MultipleHeuristicMutation(double rate, Generation *generation, RealIndividualConstraint *realIndividualConstraint, Valuer *valuer, NumericConstraint *attemptsConstraint): HeuristicMutation(rate, generation, realIndividualConstraint, valuer, attemptsConstraint)
{

}

void MultipleHeuristicMutation::mutation(const uint &gene, RealIndividual *mutant)
{
    attempts = 0.0f;
    do{
        mutantGene = mutant->getGene(gene);
        HeuristicMutation::mutation(gene);
        attempts++;
        if(!attemptsStopCriter->meets()){
            mutantGene - mutant->getGene(gene);
            break;
        }
    }while(!realIndividualConstraint->isGeneFeasible(gene, mutantGene));
    mutant->setGene(gene, mutantGene);
}

void MultipleHeuristicMutation::mutation(RealIndividual *mutant)
{
    uint y = childs->getPopulation()->size();
    childY = dynamic_cast<RealIndividual*>(childs->get(rand() % y));
    if(mutant->isBetter(childY)){
        childX = mutant;
        uint t = mutant->getGenes().size();
        for(gene = 0; gene < t; gene++){
            mutation(gene, mutant);
        }
    }
}
