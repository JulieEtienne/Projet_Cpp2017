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
int Bacteria::w_min = 0.001;
float Bacteria::p_mut = 0;
float Bacteria::p_death = 0.02;

// ===========================================================================
//                             Constructors
// ===========================================================================
Bacteria::Bacteria() {
    w = new float(0);
    genotype = 0;
    A = new float(0);
    B = new float(0);
    C = new float(0);
}

Bacteria::Bacteria(int genotype_) {
    w = new float(0);
    genotype = genotype_;
    A = new float(0);
    B = new float(0);
    C = new float(0);
}

// ===========================================================================
//                              Destructor
// ===========================================================================
Bacteria::~Bacteria() {
    delete A;
    delete B;
    delete C;
}
