// ===========================================================================
//                             Includes
// ===========================================================================
#include "BacterieL.h"


// ===========================================================================
//                             Constructors
// ===========================================================================
BacterieL::BacterieL() : Bacteria(1) {
    cout << "BacterieL's genotype : " << genotype << "\n" << endl;
}

// ===========================================================================
//                             Destructor
// ===========================================================================
BacterieL::~BacterieL() {
}

// ===========================================================================
//                             Public Methods
// ===========================================================================
void BacterieL::metabolism(float& a_out) {
    a_out *= (1 - rAA);
    *A = a_out * rAA - (*A) * (1 - rAB);
    *B = (*A) * rAB + (*B);
}
