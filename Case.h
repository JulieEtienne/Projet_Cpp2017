#ifndef CASE_H
#define CASE_H

// ===========================================================================
//                          Includes
// ===========================================================================
#include "Bacteria.h"
#include "BacterieL.h"
#include "BacterieS.h"

using std::cout;
using std::endl;

class Case
{

    friend class Environment;

    public :
        // ===================================================================
        //                          Constructors
        // ===================================================================
        // Default constructor
        Case();
        // Constructor with initial glucose concentration in this case
        Case(float a_init);
        // Constructor with initial [glucose] and type S or L of bacteria
        Case(int b_genotype, float a_init);

        // ===================================================================
        //                          Destructor
        // ===================================================================
        ~Case();

        // ===================================================================
        //                          Public Methods
        // ===================================================================
        // Returns if a Case is containing a bacteria (not empty) or not (empty)
        bool amI_Empty();
        // Will manage the metabolism of the bacteria the Case is containing
        void manage_metabolism();
        // Manages the fact that the bacteria is dead or not :
        // makes it die if needed
        void bac_IsDead();

    protected :
        // ===================================================================
        //                          Attributes
        // ===================================================================
        // bac is the Bacteria contained in the Case
        Bacteria *bac;
        // Concentration of glucose in the Case
        float A_out;
        // Concentration of acetate in the Case
        float B_out;
        // Concentration of ethanol in the Case
        float C_out;

};

#endif // CASE_H
