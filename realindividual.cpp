#include "realindividual.h"

RealIndividual::RealIndividual(uint t):  Individual(t), genes(std::vector<double>(t, 0.0f)), sum(0.0f)
{
    
}

double RealIndividual::getGene(const uint &i) const
{
    if(i < t){
        return genes.at(i);
    }
    else{
        return 0.0f;
    }
}

void RealIndividual::setGene(const uint &i, const double &gene)
{
    if(i < t){
        sum += std::max(genes.at(i), gene) - std::min(genes.at(i), gene);
        genes.at(i) = gene;
    }
}

void RealIndividual::set(RealIndividual *individual)
{
    Individual::set(individual);
    for(uint i = 0; i < t && i < individual->getT(); i++){
        setGene(i, individual->getGene(i));
    }
    t = individual->getT();
    sum = individual->getSum();
}

Individual *RealIndividual::clone()
{
    RealIndividual *individual = new RealIndividual(t);
    individual->set(this);
    return individual;
}

bool RealIndividual::isBetter(Individual *individual)
{
    return fitness < individual->getFitness();
}

bool RealIndividual::operator<(const RealIndividual &right) const
{
    return Individual::operator <(right);
}

bool RealIndividual::operator==(const RealIndividual &right) const
{
    if(Individual::operator ==(right)){
        for(uint i = 0; i < t && i < right.getT(); i++){
            if(genes.at(i) != right.getGene(i)){
                return false;
            }
        }
        return true;
    }
    else{
        return false;
    }
}

bool RealIndividual::operator!=(const RealIndividual &right) const
{
    if(Individual::operator !=(right)){
        for(uint i = 0; i < t && i < right.getT(); i++){
            if(genes.at(i) == right.getGene(i)){
                return false;
            }
        }
        return true;
    }
    else{
        return false;
    }
}

bool RealIndividual::operator>(const RealIndividual &right) const
{
    return Individual::operator >(right);
}

double RealIndividual::getSum() const
{
    return sum;
}

void RealIndividual::setSum(double value)
{
    sum = value;
}

std::vector<double> RealIndividual::getGenes() const
{
    return genes;
}

void RealIndividual::setGenes(const std::vector<double> &value)
{
    genes = value;
}
