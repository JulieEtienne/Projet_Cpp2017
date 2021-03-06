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
    // The Case is empty if the pointer to a bacteria is a null pointer
    return (bac == NULL); // return 0 if False and 1 if True
}

// Depending on the type of bacteria, calls a metabolism or the other
void Case::manage_metabolism()
{
    //If bacteria L...
    if (bac->genotype == 0)
    {
        bac->metabolism(A_out);
    }
    //If bacteria S...
    else if (bac->genotype == 1)
    {
        bac->metabolism(B_out);
    }
}

void Case::bac_IsDead()
{
    // When bac dies, it releases its metabolites into the Case it was in
    A_out += bac->A;
    B_out += bac->B;
    C_out += bac->C;
    delete bac;
    bac = NULL;
}
