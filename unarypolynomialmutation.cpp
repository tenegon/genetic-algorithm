#include "unarypolynomialmutation.h"

UnaryPolynomialMutation::UnaryPolynomialMutation(double rate, Generation *generation, IndividualConstraint *individualConstraint, double U, double L, double nm): PolynomialMutation(rate, generation, individualConstraint, U, L, nm)
{

}

UnaryPolynomialMutation::~UnaryPolynomialMutation()
{

}

void UnaryPolynomialMutation::mutation(const uint &gene, Individual *mutant)
{
    RealIndividual *realMutant = dynamic_cast<RealIndividual*>(mutant);
    RealIndividualConstraint *realIndividualConstraint = dynamic_cast<RealIndividualConstraint*>(individualConstraint);
    do{
        mutantGene = realMutant->getGene(gene);
        PolynomialMutation::mutation(gene);
    }while(!realIndividualConstraint->isGeneFeasible(gene, mutantGene));
    realMutant->setGene(gene, mutantGene);
}

void UnaryPolynomialMutation::mutation(Individual *mutant)
{
    RealIndividual *realMutant = dynamic_cast<RealIndividual*>(mutant);
    uint t = realMutant->getGenes().size();
    for(gene = 0; gene < t; gene++){
        mutation(gene, mutant);
    }
}

void UnaryPolynomialMutation::print(std::ostream &os) const
{
    os << "Unary Polynomial Mutation ";
    GeneticOperator::print(os);
}
