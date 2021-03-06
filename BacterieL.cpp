// ===========================================================================
//                             Includes
// ===========================================================================
#include "BacterieL.h"


// ===========================================================================
//                             Constructors
// ===========================================================================
BacterieL::BacterieL() : Bacteria(0)
{
    rAA = 0.1;
    rAB = 0.1;
}

// ===========================================================================
//                             Destructor
// ===========================================================================
BacterieL::~BacterieL() {}

// ===========================================================================
//                             Public Methods
// ===========================================================================
void BacterieL::metabolism(float &A_out)
{
    A_out -= A_out * 0.1 * rAA;
    A += A_out * 0.1 * rAA - A * 0.1 * rAB;
    B += A * 0.1 * rAB;
}
