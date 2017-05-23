#include "realmutation.h"

RealMutation::RealMutation(double rate, Generation *generation, RealIndividualConstraint *realIndividualConstraint): RealGeneticOperator(rate, generation, realIndividualConstraint), Mutation(generation->getChilds())
{

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
    uint y = childs->getPopulation()->size();
    for(currentChild = 0; currentChild < y; currentChild++){
        if(r() <= rate){
            mutate();
        }
    }
}

