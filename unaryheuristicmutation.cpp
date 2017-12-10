#include "unaryheuristicmutation.h"

UnaryHeuristicMutation::UnaryHeuristicMutation(double rate, Generation *generation, IndividualConstraint *individualConstraint, Valuer *valuer, NumericConstraint<uint> *attemptsConstraint): HeuristicMutation(rate, generation, individualConstraint, valuer, attemptsConstraint)
{
    attemptsStopCriter->setValue(&attempts);
}

UnaryHeuristicMutation::~UnaryHeuristicMutation()
{

}

void UnaryHeuristicMutation::mutation(const uint &gene, Individual *mutant)
{
    RealIndividual *realMutant = dynamic_cast<RealIndividual*>(mutant);
    RealIndividualConstraint *realIndividualConstraint = dynamic_cast<RealIndividualConstraint*>(individualConstraint);
    attempts = 0.0f;
    do{
        mutantGene = realMutant->getGene(gene);
        HeuristicMutation::mutation(gene);
        attempts++;
        if(attemptsStopCriter->meets()){
            mutantGene = realMutant->getGene(gene);
            break;
        }
    }while(!realIndividualConstraint->isGeneFeasible(gene, mutantGene));
    realMutant->setGene(gene, mutantGene);
}

void UnaryHeuristicMutation::mutation(Individual *mutant)
{
    RealIndividual *realMutant = dynamic_cast<RealIndividual*>(mutant);
    uint y = childs->getPopulation()->size();
    childY = dynamic_cast<RealIndividual*>(childs->get(rand() % y));
    if(realMutant->isBetter(childY)){
        childX = realMutant;
        uint t = realMutant->getGenes().size();
        gene = rand() % t;
        mutation(gene, mutant);
    }
}

void UnaryHeuristicMutation::print(std::ostream &os) const
{
    os << "Unary Heristic Mutation ";
    GeneticOperator::print(os);
}
