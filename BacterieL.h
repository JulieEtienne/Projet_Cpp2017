#ifndef BacterieL_H
#define BacterieL_H

// ===========================================================================
//                          Includes
// ===========================================================================
#include <iostream>

using std::cout;
using std::endl;

#include "Bacteria.h"

class BacterieL : public Bacteria
{
    public :
        // ===================================================================
        //                          Constructors
        // ===================================================================
        BacterieL();

        // ===================================================================
        //                            Destructors
        // ===================================================================
        ~BacterieL();

        // ===================================================================
        //                          Public Methods
        // ===================================================================
        void metabolism(float A_out) override;

    protected :
        // ===================================================================
        //                          Attributes
        // ===================================================================
        float rAA;
        float rAB;
};

#endif // BacterieL_H
