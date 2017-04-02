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
	srand(time(NULL));     // srand (static_cast <unsigned> (time(NULL)));

    int W = 6;
    int H = 6;
    float a_init = 0.2;
	float D = 0.1;
    Environment environment_ = Environment(W, H, a_init, D);
	environment_.display();
	environment_.search_and_fill_gaps();
	//environment_.death_of_cells();
	environment_.diffusion();
	environment_.clean_envir();
	environment_.display();

    return EXIT_SUCCESS;
}
