#ifndef PARALLEL_H
#define PARALLEL_H
#include <thread>
#include <iostream>
#include <vector>

template<class T>
class Parallel
{
protected:
    uint threadsNumber;
    std::vector<std::thread*> *threads;
    std::vector<T*> *tasks;
public:
    Parallel(uint threadsNumber): threadsNumber(threadsNumber), threads(new std::vector<std::thread*>), tasks(new std::vector<T*>)
    {

    }
    ~Parallel()
    {
        delete threads;
        delete tasks;
    }
    void execute()
    {
        for(uint i = 0; i < threads->size(); i++){
            if(threads->at(i)->joinable()){
                threads->at(i)->join();
            }
        }
    }
    friend std::ostream& operator<<(std::ostream& os, const Parallel<T>& p)
    {
        p.print(os);
        return os;
    }
    void print(std::ostream& os) const
    {
        os << "Parallel";
    }
};

#include "parallel.cpp"

#endif // PARALLEL_H
