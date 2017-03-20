// ===========================================================================
//                          Includes
// ===========================================================================
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

#include "Bacteria.h"
#include "BacterieL.h"
#include "BacterieS.h"
#include "Case.h"
#include "Environment.h"


int main() {

    Bacteria *bacL = new BacterieL(); // Pointeur car classe virtuelle pure.
    Bacteria *bacS = new BacterieS();

    bacL->P_death();
    bacS->P_death();

    bacL->display();
    bacS->display();

    Case case_ = Case(1);

    int W = 6;
    int H = 6;
    Environment environment_ = Environment(W, H);

    delete bacL;
    delete bacS;

    return EXIT_SUCCESS;
}
