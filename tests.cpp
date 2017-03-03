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

int main() {

    Bacteria* bacL = new BacterieL();
    Bacteria* bacS = new BacterieS();

    Case case_ = Case(1);

    delete bacL;
    delete bacS;

    return EXIT_SUCCESS;
}
