#include "unaryuniformmutation.h"

UnaryUniformMutation::UnaryUniformMutation(double rate, Generation *generation, IndividualConstraint *individualConstraint): UniformMutation(rate, generation, individualConstraint)
{

}

UnaryUniformMutation::~UnaryUniformMutation()
{

}

void UnaryUniformMutation::mutation(const uint &gene, Individual *mutant)
{
    RealIndividual *realMutant = dynamic_cast<RealIndividual*>(mutant);
    RealIndividualConstraint *realIndividualConstraint = dynamic_cast<RealIndividualConstraint*>(individualConstraint);
    do{
        UniformMutation::mutation(gene);
    }while(!realIndividualConstraint->isGeneFeasible(gene, mutantGene));
    realMutant->setGene(gene, mutantGene);
}

void UnaryUniformMutation::mutation(Individual *mutant)
{
    RealIndividual *realMutant = dynamic_cast<RealIndividual*>(mutant);
    uint t = realMutant->getGenes().size();
    gene = rand() % t;
    mutation(gene, mutant);
}

void UnaryUniformMutation::print(std::ostream &os) const
{
    os << "Unary Non-Uniform Mutation ";
    GeneticOperator::print(os);
}
