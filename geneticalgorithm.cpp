#include "geneticalgorithm.h"

GeneticAlgorithm::GeneticAlgorithm(IndividualBuilder *individualBuilder, PopulationBuilder *Builder, Valuer *valuer, Generation *generation, GeneticOperator *selection, GeneticOperator *crossover, GeneticOperator *mutation, GeneticAlgorithmConstraint *constraint, StopCriteria *stopCriteria): individualBuilder(individualBuilder), populationBuilder(Builder), valuer(valuer), generation(generation), selection(selection), crossover(crossover), mutation(mutation), constraint(constraint), stopCriteria(stopCriteria), geneticOperators(new std::vector<GeneticOperator*>)
{
    if(selection){
        geneticOperators->push_back(selection);
    }
    if(crossover){
        geneticOperators->push_back(crossover);
    }
    if(mutation){
        geneticOperators->push_back(mutation);
    }
}

void GeneticAlgorithm::initiate()
{
    generation->initiate(individualBuilder, populationBuilder);
    generation->evaluate(valuer);
}

void GeneticAlgorithm::iterate()
{
    uint gos = geneticOperators->size();
    for(uint i = 0; i < gos; i++){
        GeneticOperator *go = geneticOperators->at(i);
        go->apply();
    }
    generation->generate();
    generation->evaluate(valuer);
}

void GeneticAlgorithm::run()
{
    initiate();
    while (stopCriteria->meets()) {
        iterate();
    }
}

IndividualBuilder *GeneticAlgorithm::getIndividualBuilder() const
{
    return individualBuilder;
}

void GeneticAlgorithm::setIndividualBuilder(IndividualBuilder *value)
{
    individualBuilder = value;
}

PopulationBuilder *GeneticAlgorithm::getPopulationBuilder() const
{
    return populationBuilder;
}

void GeneticAlgorithm::setPopulationBuilder(PopulationBuilder *value)
{
    populationBuilder = value;
}

Valuer *GeneticAlgorithm::getValuer() const
{
    return valuer;
}

void GeneticAlgorithm::setValuer(Valuer *value)
{
    valuer = value;
}

Generation *GeneticAlgorithm::getGeneration() const
{
    return generation;
}

void GeneticAlgorithm::setGeneration(Generation *value)
{
    generation = value;
}

GeneticOperator *GeneticAlgorithm::getSelection() const
{
    return selection;
}

void GeneticAlgorithm::setSelection(GeneticOperator *value)
{
    selection = value;
}

GeneticOperator *GeneticAlgorithm::getCrossover() const
{
    return crossover;
}

void GeneticAlgorithm::setCrossover(GeneticOperator *value)
{
    crossover = value;
}

GeneticOperator *GeneticAlgorithm::getMutation() const
{
    return mutation;
}

void GeneticAlgorithm::setMutation(GeneticOperator *value)
{
    mutation = value;
}

GeneticAlgorithmConstraint *GeneticAlgorithm::getConstraint() const
{
    return constraint;
}

void GeneticAlgorithm::setConstraint(GeneticAlgorithmConstraint *value)
{
    constraint = value;
}

StopCriteria *GeneticAlgorithm::getStopCriteria() const
{
    return stopCriteria;
}

void GeneticAlgorithm::setStopCriteria(StopCriteria *value)
{
    stopCriteria = value;
}

std::vector<GeneticOperator *> *GeneticAlgorithm::getGeneticOperators() const
{
    return geneticOperators;
}

void GeneticAlgorithm::setGeneticOperators(std::vector<GeneticOperator *> *value)
{
    geneticOperators = value;
}
