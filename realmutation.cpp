#include "realmutation.h"

RealMutation::RealMutation(double rate, Generation *generation, IndividualConstraint *individualConstraint): RealGeneticOperator(rate, generation, individualConstraint), Mutation(generation->getChilds())
{
    setRange(0, generation->getChilds()->getT() - 1);
}

RealMutation::~RealMutation()
{
    mutant = 0;
}

void RealMutation::mutate()
{
    mutant = dynamic_cast<RealIndividual*>(childs->get(currentChild));
    mutation(mutant);
    mutant->setModified(true);
    mutant->setEvaluated(false);
}

void RealMutation::apply()
{
    for(currentChild = range->getMinimum(); currentChild <= range->getMaximum(); currentChild++){
        if(r() <= rate){
            mutate();
        }
    }
}

