#ifndef PDEEEHEURISTICBASEDREALINDIVIDUALBUILDER_H
#define PDEEEHEURISTICBASEDREALINDIVIDUALBUILDER_H
#include "boundarybasedrealindividualbuilder.h"

class PdeeeHeuristicBasedRealIndividualBuilder : public BoundaryBasedRealIndividualBuilder
{
private:
    double fi;
    int n;
    std::vector<double> f;
public:
    PdeeeHeuristicBasedRealIndividualBuilder(uint t, IndividualConstraint *individualConstraint, std::vector<double> f);
    ~PdeeeHeuristicBasedRealIndividualBuilder();
    double generateGene(const uint &i);
};

#endif // PDEEEHEURISTICBASEDREALINDIVIDUALBUILDER_H
