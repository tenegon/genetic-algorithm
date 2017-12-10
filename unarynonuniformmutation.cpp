#include "unarynonuniformmutation.h"

UnaryNonUniformMutation::UnaryNonUniformMutation(double rate, Generation *generation, IndividualConstraint *individualConstraint, NumericConstraint<uint> *iterationsConstraint): NonUniformMutation(rate, generation, individualConstraint, iterationsConstraint)
{

}

UnaryNonUniformMutation::~UnaryNonUniformMutation()
{

}

void UnaryNonUniformMutation::mutation(const uint &gene, Individual *mutant)
{
    RealIndividual *realMutant = dynamic_cast<RealIndividual*>(mutant);
    RealIndividualConstraint *realIndividualConstraint = dynamic_cast<RealIndividualConstraint*>(individualConstraint);
    do{
        mutantGene = realMutant->getGene(gene);
        NonUniformMutation::mutation(gene);
    }while(!realIndividualConstraint->isGeneFeasible(gene, mutantGene));
    realMutant->setGene(gene, mutantGene);
}

void UnaryNonUniformMutation::mutation(Individual *mutant)
{
    RealIndividual *realMutant = dynamic_cast<RealIndividual*>(mutant);
    uint t = realMutant->getGenes().size();
    gene = rand() % t;
    mutation(gene, mutant);
}

void UnaryNonUniformMutation::print(std::ostream &os) const
{
    os << "Unary Non-Uniform Mutation ";
    GeneticOperator::print(os);
}
