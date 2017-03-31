// ===========================================================================
//                          Includes
// ===========================================================================
#include <iostream>

using std::cout;
using std::endl;

#include "Bacteria.h"
#include <ctime>

// ===========================================================================
//                    Definition of static attributes
// ===========================================================================
float Bacteria::w_min = 0.001;
float Bacteria::p_mut = 0;
float Bacteria::p_death = 0.02;

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
//                              Getters
// ===========================================================================
int Bacteria::get_genotype() const {
    return genotype;
}

float Bacteria::get_fitness() const {
    return w;
}

float Bacteria::get_A() const {
    return A;
}

float Bacteria::get_B() const {
    return B;
}

float Bacteria::get_C() const {
    return C;
}

// ===========================================================================
//                              Setters
// ===========================================================================
void Bacteria::set_A(float a) {
    A = a;
}

void Bacteria::set_B(float b) {
    B = b;
}

void Bacteria::set_C(float c) {
    C = c;
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

void Bacteria::dead_or_alive()
{
    double probability;     // probability is a float between 0 and 1 drawn randomly
    for(auto i = 0;  i < 2; i++){ //for i = 0, probability doesn't change significatively
        probability = static_cast <double>(rand()) / static_cast <double> (RAND_MAX);
    }

    cout << "Probabilité : " << probability << endl;

    if (probability <= p_death)
    {
        is_alive = false;
    }
}

int Bacteria::mutation()
{
    int mutation_ = 0;
    genotype == 0 ? mutation_ = 1 : mutation_ = 0;
    return mutation_;
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
