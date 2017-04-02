#ifndef BACTERIES_H
#define BACTERIES_H

// ===========================================================================
//                          Includes
// ===========================================================================
#include <iostream>

using std::cout;
using std::endl;

#include "Bacteria.h"

class BacterieS : public Bacteria
{

    public :
        // ===================================================================
        //                          Constructors
        // ===================================================================
        // Default constructor
        BacterieS();

        // ===================================================================
        //                            Destructors
        // ===================================================================
        ~BacterieS();

        // ===================================================================
        //                          Public Methods
        // ===================================================================
        // Metabolism of the S-type bacteria
        // B_out is the concentration of B in the environment cell
        void metabolism(float &B_out) override;

    protected :
        // ===================================================================
        //                          Attributes
        // ===================================================================
        // Metabolic rate B-B
        float rBB;
        // Metabolic rate B-C
        float rBC;

};

#endif // BACTERIES_H
