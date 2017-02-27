// ===========================================================================
//                          Includes
// ===========================================================================
#include <cstdlib>
#include "Bacteria.h"
#include "BacterieL.h"

int main() {

    Bacteria* bac = new Bacteria();
    Bacteria* bacL = new BacterieL();

    delete bac;
    delete bacL;

    return EXIT_SUCCESS;
}
