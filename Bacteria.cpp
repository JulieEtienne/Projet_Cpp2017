// ===========================================================================
//                          Includes
// ===========================================================================
#include <iostream>

using namespace std;

#include "Bacteria.h"
#include <ctime>

// ===========================================================================
//                    Definition of static attributes
// ===========================================================================
float Bacteria::w_min = 0.001;
float Bacteria::p_mut = 0;
float Bacteria::p_death_ = 0.02;

// ===========================================================================
//                             Constructors
// ===========================================================================
Bacteria::Bacteria()
{
    w = 0;
    genotype = 0;
    A = 0;
    B = 0;
    C = 0;
    is_alive = true;
}

Bacteria::Bacteria(int genotype_)
{
    w = 0;
    genotype = genotype_;
    A = 0;
    B = 0;
    C = 0;
    is_alive = true;
}

// ===========================================================================
//                              Destructor
// ===========================================================================
Bacteria::~Bacteria(){}

// ===========================================================================
//                              Getters
// ===========================================================================
float Bacteria::get_fitness() const
{
    return w;
}

int Bacteria::get_genotype() const
{
    return genotype;
}

float Bacteria::get_A() const
{
    return A;
}

float Bacteria::get_B() const
{
    return B;
}

float Bacteria::get_C() const
{
    return C;
}

// ===========================================================================
//                          Public Methods
// ===========================================================================
void Bacteria::metabolism(float &out)
{

}
void Bacteria::fitness()
{

}

void Bacteria::P_death()
{
    float probability = 0;
    // srand (static_cast <unsigned> (time(NULL)));
    srand(time(NULL));
    // probability is a float between 0 and 1 drawn randomly
    probability = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    cout << "Probabilité : " << probability << endl;

    if (probability <= p_death_)
    {
        is_alive = false;
    }
}


// ===========================================================================
//                              Display
// ===========================================================================
void Bacteria::display()
{
    cout << "Alive ? " << is_alive << endl;

    if (genotype == 0)
    {
        cout << "Bacteria's genotype is L " << endl;
    }
    else if (genotype == 1)
    {
        cout << "Bacteria's genotype is S " << endl;
    }
    else
    {
        cout << "Unknown bacteria's genotype" << endl;
    }
}

