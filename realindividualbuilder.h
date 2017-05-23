#ifndef REALINDIVIDUALBUILDER_H
#define REALINDIVIDUALBUILDER_H
#include "individualbuilder.h"
#include "realindividual.h"

class RealIndividualBuilder : public IndividualBuilder
{
public:
    RealIndividualBuilder(uint t);
    RealIndividual *build();
};

#endif // REALINDIVIDUALGENERATOR_H
