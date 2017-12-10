#include "pdeeeheuristicbasedrealindividualbuilder.h"

PdeeeHeuristicBasedRealIndividualBuilder::PdeeeHeuristicBasedRealIndividualBuilder(uint t, IndividualConstraint *individualConstraint, std::vector<double> f): BoundaryBasedRealIndividualBuilder(t, individualConstraint), f(f)
{

}

PdeeeHeuristicBasedRealIndividualBuilder::~PdeeeHeuristicBasedRealIndividualBuilder()
{

}

double PdeeeHeuristicBasedRealIndividualBuilder::generateGene(const uint &i)
{
    min = minimum->getGene(i);
    max = maximum->getGene(i);
    gene = r() * (max - min) + min;
    fi = f.at(i);
    n = -(gene - min) * fi / PI;
    return  min - (PI * n) / fi;
}

