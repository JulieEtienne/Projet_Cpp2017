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
        // Default constructor
        BacterieL();

        // ===================================================================
        //                            Destructors
        // ===================================================================
        ~BacterieL();

        // ===================================================================
        //                          Public Methods
        // ===================================================================
        // Metabolism of the L-type bacteria
        // A_out is the concentration of A in the environment cell
        void metabolism(float &A_out) override;

    protected :
        // ===================================================================
        //                          Attributes
        // ===================================================================
        // Metabolic rate A-A
        float rAA;
        // Metabolic rate A-B
        float rAB;
};

#endif // BacterieL_H
