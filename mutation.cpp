#include "mutation.h"

Mutation::Mutation(Population *childs): childs(childs)
{
    
}

Population *Mutation::getChilds() const
{
    return childs;
}

void Mutation::setChilds(Population *value)
{
    childs = value;
}

double Mutation::getMutantGene() const
{
    return mutantGene;
}

void Mutation::setMutantGene(double value)
{
    mutantGene = value;
}

uint Mutation::getGene() const
{
    return gene;
}

void Mutation::setGene(const uint &value)
{
    gene = value;
}
