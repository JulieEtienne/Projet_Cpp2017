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

int main() {

    Bacteria* bacL = new BacterieL();
    Bacteria* bacS = new BacterieS();

    delete bacL;
    delete bacS;

    return EXIT_SUCCESS;
}
