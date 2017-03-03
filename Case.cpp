// ===========================================================================
//                          Includes
// ===========================================================================
#include "Case.h"
#include "Bacteria.h"
#include "BacterieL.h"
#include "BacterieS.h"

// ===========================================================================
//                             Constructors
// ===========================================================================
Case::Case(){
    bac = nullptr;
    A_out = 0;
    B_out = 0;
    C_out = 0;
}

Case::Case(int b_genotype){
    if (b_genotype == 1) {
        bac = new BacterieL();
    } else {
        bac = new BacterieS();
    }
}

// ===========================================================================
//                             Destructor
// ===========================================================================
Case::~Case(){
    delete bac;
}
