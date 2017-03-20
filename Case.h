#ifndef CASE_H
#define CASE_H

// ===========================================================================
//                          Includes
// ===========================================================================
#include "Bacteria.h"
#include "BacterieL.h"
#include "BacterieS.h"

class Case
{

    friend class Environment;

    public :
        // ===================================================================
        //                          Constructors
        // ===================================================================
        Case();
        Case(float a_init); //Initial glucose concentration in this case
        Case(int b_genotype, float a_init); //Initial [glucose] and type S or L of bacteria

        // ===================================================================
        //                          Destructor
        // ===================================================================
        ~Case();

        // ===================================================================
        //                        Getters
        // ===================================================================
        float get_Aout() const;
        float get_Bout() const;
        float get_Cout() const;

        // ===================================================================
        //                          Public Methods
        // ===================================================================
        bool amI_Empty();
        void manage_metabolism();
        void bac_IsDead();

    protected :
        // ===================================================================
        //                          Attributes
        // ===================================================================
        Bacteria *bac; // bac is a Bacteria

        float A_out;
        float B_out;
        float C_out;

};

#endif // CASE_H
