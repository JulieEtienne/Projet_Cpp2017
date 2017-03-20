// ===========================================================================
//                          Includes
// ===========================================================================
#include <iostream>

using std::cout;
using std::endl;

#include "Bacteria.h"

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
}

Bacteria::Bacteria(int genotype_)
{
    w = 0;
    genotype = genotype_;
    A = 0;
    B = 0;
    C = 0;
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
//                              Display
// ===========================================================================
void Bacteria::display()
{
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

