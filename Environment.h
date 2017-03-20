#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

// ===========================================================================
//                          Includes
// ===========================================================================
#include "Case.h"
#include <vector>


class Environment {

    public :
        // ===================================================================
        //                          Constructors
        // ===================================================================
        Environment();
        // ===================================================================
        //                          Destructor
        // ===================================================================
        ~Environment();
        // ===================================================================
        //                        Getters
        // ===================================================================
        int get_W() const;
        int get_H() const;

        // ===================================================================
        //                        Setters
        // ===================================================================
        void set_W(int W_);
        void set_H(int H_);

        // ===================================================================
        //                          Public Methods
        // ===================================================================

    protected :
        // ===================================================================
        //                          Attributes
        // ===================================================================
        int W;
        int H;
        std::vector<Case> grid;
};

#endif // CASE_H