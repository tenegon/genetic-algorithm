#include "valuer.h"

Valuer::Valuer(uint *calculateCount, Function *function): evaluations(calculateCount), function(function)
{

}

void Valuer::evaluate(Individual *individual)
{
    function->calcule(individual);
    *evaluations++;
    individual->setEvaluated(true);
    individual->setModified(false);
}

void Valuer::evaluate(Population *population)
{
    Individual *individual;
    uint t = population->getPopulation()->size();
    for(uint i = 0; i < t; i++){
        individual = population->get(i);
        if(individual->isModified() || !individual->isEvaluated()){
            evaluate(individual);
        }
    }
}

Function *Valuer::getFunction() const
{
    return function;
}

void Valuer::setFunction(Function *value)
{
    function = value;
}
