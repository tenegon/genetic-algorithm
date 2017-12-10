#include "unaryboundarymutation.h"

UnaryBoundaryMutation::UnaryBoundaryMutation(double rate, Generation *generation, IndividualConstraint *realIndividualConstraint): BoundaryMutation(rate, generation, realIndividualConstraint)
{
    setRange(0, generation->getChilds()->getT() - 1);
}

UnaryBoundaryMutation::~UnaryBoundaryMutation()
{

}

void UnaryBoundaryMutation::mutation(const uint &gene, Individual *mutant)
{
    RealIndividual *realMutant = dynamic_cast<RealIndividual*>(mutant);
    RealIndividualConstraint *realIndividualConstraint = dynamic_cast<RealIndividualConstraint*>(individualConstraint);
    do{
        mutantGene = realMutant->getGene(gene);
        BoundaryMutation::mutation(gene);
    }while(!realIndividualConstraint->isGeneFeasible(gene, mutantGene));
    realMutant->setGene(gene, mutantGene);
}

void UnaryBoundaryMutation::mutation(Individual *mutant)
{
    RealIndividual *realMutant = dynamic_cast<RealIndividual*>(mutant);
    uint t = realMutant->getGenes().size();
    gene = rand() % t;
    mutation(gene, mutant);
}

void UnaryBoundaryMutation::print(std::ostream &os) const
{
    os << "Unary Boundary Mutation ";
    GeneticOperator::print(os);
}
