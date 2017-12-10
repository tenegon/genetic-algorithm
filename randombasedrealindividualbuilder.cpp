#include "randombasedrealindividualbuilder.h"

RandomBasedRealIndividualBuilder::RandomBasedRealIndividualBuilder(uint t, IndividualConstraint *individualConstraint): BoundaryBasedRealIndividualBuilder(t, individualConstraint)
{

}

RandomBasedRealIndividualBuilder::~RandomBasedRealIndividualBuilder()
{

}

double RandomBasedRealIndividualBuilder::generateGene(const uint &i)
{
    min = minimum->getGene(i);
    max = maximum->getGene(i);
    return  min + r() *(max - min);
}
