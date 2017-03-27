// ===========================================================================
//                          Includes
// ===========================================================================
#include "Case.h"


// ===========================================================================
//                             Constructors
// ===========================================================================
Case::Case()
{
    bac = nullptr;
    A_out = 0;
    B_out = 0;
    C_out = 0;
}

Case::Case(float a_init)
{
    bac = nullptr;
    A_out = a_init;
    B_out = 0;
    C_out = 0;
}

Case::Case(int b_genotype, float a_init)
{
    if (b_genotype == 0)
    {
        bac = new BacterieL();
    }
    else if (b_genotype == 1)
    {
        bac = new BacterieS();
    }
    A_out = a_init;
    B_out = 0;
    C_out = 0;
}



// ===========================================================================
//                             Destructor
// ===========================================================================
Case::~Case()
{
}

// ===========================================================================
//                              Getters
// ===========================================================================
float Case::get_Aout() const
{
    return A_out;
}

float Case::get_Bout() const
{
    return B_out;
}

float Case::get_Cout() const
{
    return C_out;
}

// ===========================================================================
//                             Public Methods
// ===========================================================================
bool Case::amI_Empty()
{
    return (bac == nullptr);
}

void Case::manage_metabolism()
{
    if (bac->genotype == 0) //If bacteria L...
    {
        bac->metabolism(A_out);
    }
    else if (bac->genotype == 1) //If bacteria S...
    {
        bac->metabolism(B_out);
    }
}

void Case::bac_IsDead()
{
    if (bac->is_alive == false)
    {
        A_out += bac->A;
        B_out += bac->B;
        C_out += bac->C;
        delete bac;
        bac = nullptr;
    }
}
