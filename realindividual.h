#ifndef REALINDIVIDUAL_H
#define REALINDIVIDUAL_H
#include "individual.h"

class RealIndividual : public Individual
{
protected:
    std::vector<double> genes;
    double sum;
public:
    RealIndividual(uint t);
    ~RealIndividual();
    double getGene(const uint &i) const;
    void setGene(const uint &i, const double &gene);
    void updateSum();
    void set(Individual *individual);
    Individual *clone();
    bool isBetter(Individual *individual);
    virtual bool operator< (const RealIndividual &right) const;
    virtual bool operator== (const RealIndividual &right) const;
    virtual bool operator!= (const RealIndividual &right) const;
    virtual bool operator> (const RealIndividual &right) const;
    void print(std::ostream &os) const ;
    std::string header() const;
    double getSum() const;
    void setSum(double value);
    std::vector<double> getGenes() const;
    void setGenes(const std::vector<double> &value);
};

#endif // REALINDIVIDUAL_H
