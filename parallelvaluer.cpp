#include "parallelvaluer.h"

ParallelValuer::ParallelValuer(uint *evaluations, Function *function, Population *population, uint threadsNumber, VALUER valuer, std::vector<PenaltyFunction *> *penality): Parallel<Valuer>(threadsNumber), Valuer(evaluations, function, population), valuer(valuer)
{
    ValuerBuilder *valuerBuilder = new ValuerBuilder();
    uint u = population->getT();
    for(uint i = 0, begin = 0, end = 0; end < u - 1; i++){
        begin = (i * (u / threadsNumber));
        end = std::min(u - 1, ((i + 1) * (u / threadsNumber) - 1));
        Valuer *v = 0;
        switch (valuer) {
        case VALUER::Fitness:
            v = valuerBuilder->buildValuer(evaluations, function, PROGRAMATION::Sequential, 0, population);
            break;
        case VALUER::WithPenalty:
            v = valuerBuilder->buildPenaltyValuer(evaluations, function, PROGRAMATION::Sequential, 0, population, penality);
            break;
        }
        v->setRange(begin, end);
        tasks->push_back(v);
        threads->push_back(new std::thread);
    }
    delete valuerBuilder;
}

ParallelValuer::~ParallelValuer()
{

}

void ParallelValuer::apply()
{
    for(uint i = 0; i < threads->size(); i++){
        Valuer *v = tasks->at(i);
        delete threads->at(i);
        threads->at(i) = new std::thread(&Valuer::apply, v);
    }
    Parallel<Valuer>::execute();
}
/*
Valuer *ParallelValuer::clone()
{
    std::vector<PenaltyFunction*> *penality = 0;
    if(valuer == VALUER::WithPenalty){
        PenaltyValuer *pv = dynamic_cast<PenaltyValuer*>(tasks->front());
        if(pv){
            penality = pv->getPenality();
        }
    }
    return new ParallelValuer(evaluations, function, population, threadsNumber, valuer, penality);
}
*/
void ParallelValuer::setFunction(Function *value)
{
    Valuer::setFunction(value);
    for(uint i= 0; i < tasks->size(); i++){
        Valuer *v = tasks->at(i);
        v->setFunction(value);
    }
}

void ParallelValuer::setEvaluations(uint *value)
{
    Valuer::setEvaluations(value);
    for(uint i= 0; i < tasks->size(); i++){
        Valuer *v = tasks->at(i);
        v->setEvaluations(value);
    }
}

void ParallelValuer::setPopulation(Population *value)
{
    Valuer::setPopulation(value);
    NumericConstraint<uint> *vRange = new NumericConstraint<uint>(0, 0);
    for(uint i= 0; i < tasks->size(); i++){
        Valuer *v = tasks->at(i);
        vRange->setMinMax(v->getRange()->getMinimum(), v->getRange()->getMaximum());
        v->setPopulation(value);
        v->setRange(vRange->getMinimum(), vRange->getMaximum());
    }
}

void ParallelValuer::print(std::ostream &os) const
{
    Parallel<Valuer>::print(os);
    os << " " << *tasks->front();
}

