#include "nonuniformmutation.h"

NonUniformMutation::NonUniformMutation(double rate, Generation *generation, IndividualConstraint *individualConstraint, NumericConstraint<uint> *iterationsConstraint, double b): RealMutation(rate, generation, individualConstraint), iterationsConstraint(iterationsConstraint), b(b)
{

}

NonUniformMutation::~NonUniformMutation()
{
    delete iterationsConstraint;
}

void NonUniformMutation::mutation(const uint &gene)
{
    RealIndividualConstraint *realIndividualConstraint = dynamic_cast<RealIndividualConstraint*>(individualConstraint);
    double minGene = realIndividualConstraint->getMinimum()->getGene(gene);
    double maxGene = realIndividualConstraint->getMaximum()->getGene(gene);
    if(r() <= 0.5){
        mutantGene += (maxGene - mutantGene) * fg();
    }
    else{
        mutantGene -= (mutantGene - minGene) * fg();
    }
}

double NonUniformMutation::fg()
{
    return pow(r() * (1.0f - ((double)(*iterationsConstraint->getValue())/double(iterationsConstraint->getMaximum()))), b);
}
