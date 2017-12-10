#include "valuer.h"

Valuer::Valuer(uint *evaluations, Function *function, Population *population): evaluations(evaluations), function(function), population(population), range(new NumericConstraint<uint>(0, 0))
{
    if(population){
        setRange(0, population->getT() - 1);
    }
}

Valuer::~Valuer()
{
    delete function;
    delete range;
}
void Valuer::evaluate(Individual *individual)
{
    function->calcule(individual);
    (*evaluations)++;
    individual->setEvaluated(true);
    individual->setModified(false);
}

void Valuer::evaluate(Population *population)
{
    Individual *individual;
    for(uint i = range->getMinimum(); i <= range->getMaximum(); i++){
        individual = population->get(i);
        if(individual->isModified() || !individual->isEvaluated()){
            evaluate(individual);
        }
    }
}

void Valuer::apply()
{
    evaluate(population);
}

Valuer *Valuer::clone()
{
    return new Valuer(evaluations, function, population);
}

std::ostream &operator<<(std::ostream &os, const Valuer &v)
{
    v.print(os);
    return os;
}

void Valuer::print(std::ostream &os) const
{
    os << "Valuer [Fitness: " << *function << "]";
}

Function *Valuer::getFunction() const
{
    return function;
}

void Valuer::setFunction(Function *value)
{
    function = value;
}

uint *Valuer::getEvaluations() const
{
    return evaluations;
}

void Valuer::setEvaluations(uint *value)
{
    evaluations = value;
}

Population *Valuer::getPopulation() const
{
    return population;
}

void Valuer::setPopulation(Population *value)
{
    population = value;
    setRange(0, population->getT() - 1);
}

void Valuer::setRange(const uint &begin, const uint &end)
{
    range->setMinimum(begin);
    range->setMaximum(end);
}

NumericConstraint<uint> *Valuer::getRange() const
{
    return range;
}
