#include "realindividualbuilder.h"

RealIndividualBuilder::RealIndividualBuilder(uint t): IndividualBuilder(t)
{

}

RealIndividualBuilder::~RealIndividualBuilder()
{

}

RealIndividual *RealIndividualBuilder::build()
{
    RealIndividual *individual = new RealIndividual(t);
    return individual;
}
