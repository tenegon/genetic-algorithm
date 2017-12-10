#include "realindividual.h"

RealIndividual::RealIndividual(uint t):  Individual(t), genes(std::vector<double>(t, 0.0f)), sum(0.0f)
{
    
}

RealIndividual::~RealIndividual()
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
        sum += gene - genes.at(i);
        genes.at(i) = gene;
    }
}

void RealIndividual::set(Individual *individual)
{
    RealIndividual *real = dynamic_cast<RealIndividual*>(individual);
    Individual::set(individual);
    for(uint i = 0; i < t && i < real->getT(); i++){
        setGene(i, real->getGene(i));
    }
    sum = real->getSum();
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

void RealIndividual::print(std::ostream &os) const
{
    Individual::print(os);
    os << "\t\t";
    uint rt = genes.size();
    for(uint i = 0; i < rt; i++){
        double gene = genes.at(i);
        os  << gene << "\t";
    }
    os << sum;
}

std::string RealIndividual::header() const
{
     std::string os("");
     os += Individual::header() + "\t";
     uint rt = genes.size();
     os += "{";
     for(uint i = 0; i < rt; i++){
         os += "[" + std::to_string(i) + "]";
         if(i < rt - 1){
             os += ",\t";
         }
     }
     os += "}\t";
     os += "sum";
     return os;
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
