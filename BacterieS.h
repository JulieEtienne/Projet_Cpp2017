#ifndef BACTERIES_H
#define BACTERIES_H

// ===========================================================================
//                          Includes
// ===========================================================================
#include <iostream>

using std::cout;
using std::endl;

#include "Bacteria.h"

class BacterieS : public Bacteria {

    public :
        // ===================================================================
        //                          Constructors
        // ===================================================================
        BacterieS();

        // ===================================================================
        //                            Destructors
        // ===================================================================
        ~BacterieS();

        // ===================================================================
        //                          Public Methods
        // ===================================================================
        void metabolism(float B_out) override;

    protected :
        // ===================================================================
        //                          Attributes
        // ===================================================================
        float rBB;
        float rBC;

};

#endif // BACTERIES_H
