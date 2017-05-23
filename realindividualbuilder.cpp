#include "realindividualbuilder.h"

RealIndividualBuilder::RealIndividualBuilder(uint t): IndividualBuilder(t)
{

}

RealIndividual *RealIndividualBuilder::build()
{
    RealIndividual *individual = new RealIndividual(t);
    return individual;
}
