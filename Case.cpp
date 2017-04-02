// ===========================================================================
//                          Includes
// ===========================================================================
#include "Case.h"

// ===========================================================================
//                             Constructors
// ===========================================================================
Case::Case()
{
    bac = NULL;
    A_out = 0;
    B_out = 0;
    C_out = 0;
}

Case::Case(float a_init)
{
    bac = NULL;
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
    else
    {
        bac = NULL;
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
    //If the lines below are being used, seg fault appears at the very end
    //of our program,
    //and the grid doesn't print well (but it does in valgrind)

    /*cout << "Case destructor called" << endl;
    if (bac != NULL) {
        delete bac;
    } else {
        cout << "Was empty" << endl;
    }*/
}

// ===========================================================================
//                             Public Methods
// ===========================================================================
bool Case::amI_Empty()
{
    return (bac == NULL);
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
        bac = NULL;
    } else {
        cout << "Bacteria is alive, can't apply bac_IsDead()..." << endl;
    }
}
