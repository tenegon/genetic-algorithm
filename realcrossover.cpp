#include "realcrossover.h"

RealCrossover::RealCrossover(double rate, Generation *generation, RealIndividualConstraint *realIndividualConstraint): RealGeneticOperator(rate, generation, realIndividualConstraint), Crossover(generation->getParents(), generation->getChilds())
{

}

void RealCrossover::cross()
{
    uint u = parents->getPopulation()->size();
    currentDad = rand() % u;
    currentMom = rand() % u;
    RealIndividual* dad = dynamic_cast<RealIndividual*>(parents->get(currentDad));
    RealIndividual* mom = dynamic_cast<RealIndividual*>(parents->get(currentMom));
    RealIndividual* child = dynamic_cast<RealIndividual*>(childs->get(currentChild));
    crossing(dad, mom, child);

}

void RealCrossover::apply()
{
    uint y = childs->getPopulation()->size();
    uint u = parents->getPopulation()->size();
    for(currentChild = 0; currentChild < y; currentChild++){
        if(r() <= rate){
            cross();
        }
        else{
            Individual* dad = parents->get(rand() % u);
            childs->set(currentChild, dad);
        }
    }
}
