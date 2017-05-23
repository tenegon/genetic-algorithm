#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H
#include <cstdlib>
#include <vector>

class Individual
{
protected:
    uint t;
    double fitness;
    bool evaluated;
    bool modified;
public:
    explicit Individual(uint t);
    virtual void set(Individual *individual);
    virtual Individual *clone() = 0;
    virtual bool isBetter(Individual *individual) = 0;
    virtual bool operator< (const Individual &right) const;
    virtual bool operator== (const Individual &right) const;
    virtual bool operator!= (const Individual &right) const;
    virtual bool operator> (const Individual &right) const;
    uint getT() const;
    void setT(const uint &value);
    double getFitness() const;
    void setFitness(const double &fitness);
    bool isEvaluated() const;
    void setEvaluated(bool value);
    bool isModified() const;
    void setModified(bool value);
};

#endif // INDIVIDUAL_H
