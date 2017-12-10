#include "realcrossover.h"

RealCrossover::RealCrossover(double rate, Generation *generation, IndividualConstraint *individualConstraint): RealGeneticOperator(rate, generation, individualConstraint), Crossover(generation->getParents(), generation->getChilds())
{
    setRange(0, generation->getChilds()->getT() - 1);
}

RealCrossover::~RealCrossover()
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
    child->setParent1(dad);
    child->setParent2(mom);

}

void RealCrossover::apply()
{
    for(currentChild = range->getMinimum(); currentChild <= range->getMaximum(); currentChild++){
        if(r() <= rate){
            cross();
        }
    }
}
