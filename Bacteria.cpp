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
int Bacteria::get_genotype() const
{
    return genotype;
}

float Bacteria::get_fitness() const
{
    return w;
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

bool Bacteria::get_is_alive() const
{
    return is_alive;
}

// ===========================================================================
//                              Setters
// ===========================================================================
void Bacteria::set_A(float a)
{
    A = a;
}

void Bacteria::set_B(float b)
{
    B = b;
}

void Bacteria::set_C(float c)
{
    C = c;
}

// ===========================================================================
//                          Public Methods
// ===========================================================================
void Bacteria::metabolism(float &conc_out) {}

void Bacteria::fitness()
{
    // If it is a bacteria of type L...
    if(genotype == 0)
    {
        w = B;
    }
    // If it is a bacteria of type S...
    else if(genotype == 1)
    {
        w = C;
    }
}

void Bacteria::check_fitness()
{
    if ( w < w_min)
    {
        // If its fitness if lower than w_min, the bacteria will die
        is_alive = false;
    }
}

void Bacteria::dead_or_alive()
{
    // Probability p is a float between 0 and 1 drawn randomly
    double p = 0.0;
    // For i = 0, proba doesn't change significatively
    for(auto i = 0;  i < 2; i++)
    {
        p = static_cast <double>(rand()) / static_cast <double> (RAND_MAX);
    }

    // If p is lower or equal the p_death, the bacteria will die
    if (p <= p_death)
    {
        is_alive = false;
    }
}

void Bacteria::mutation()
{
    double p = 0.0;

    for(auto i = 0; i < 2; i++)
    {
        p = static_cast <double>(rand()) / static_cast <double> (RAND_MAX);
    }

    // If p is lower or equal the p_death, the bac's genotype will change
    if (p <= p_mut)
    {
        if (genotype == 0)
        {
            genotype = 1;
        }
        else if (genotype == 1)
        {
            genotype = 0;
        }
    }
}

// ===========================================================================
//                              Display
// ===========================================================================
void Bacteria::display()
{
    cout << "Bactérie de genotype : " << genotype << endl;
    cout << "Alive ? " << is_alive << endl;
    cout << "Fitness : " << w << endl;
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
