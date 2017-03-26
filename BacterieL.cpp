// ===========================================================================
//                             Includes
// ===========================================================================
#include "BacterieL.h"


// ===========================================================================
//                             Constructors
// ===========================================================================
BacterieL::BacterieL() : Bacteria(0){
}

// ===========================================================================
//                             Destructor
// ===========================================================================
BacterieL::~BacterieL(){}

// ===========================================================================
//                             Public Methods
// ===========================================================================
void BacterieL::metabolism(float &out)
{
    out *= (1 - rAA);
    A = out * rAA + A * (1 - rAB);
    B += A * rAB;
}