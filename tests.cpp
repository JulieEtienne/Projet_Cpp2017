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
    bacL->display();
    bacS->display();

    Case case_ = Case(1);

    Environment environment_ = Environment();
    environment_.set_W(32);
    environment_.set_H(32);

    delete bacL;
    delete bacS;

    return EXIT_SUCCESS;
}
