// ===========================================================================
//                          Includes
// ===========================================================================
#include <cstdlib>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::pair;
using std::vector;

#include "Bacteria.h"
#include "BacterieL.h"
#include "BacterieS.h"
#include "Case.h"
#include "Environment.h"

vector<float> simulation(float T, float a_init, Environment &env);

int main() {
	srand(time(NULL));     // srand (static_cast <unsigned> (time(NULL)));

    int W = 10;
    int H = 10;
    float a_init = 0.2;
	float D = 0.1;
	Environment environment_ = Environment(W, H, a_init, D);
	environment_.display();
	vector <float> donnees = simulation(1500, a_init, environment_);
	for (auto &i:donnees) cout << i << endl;


    return EXIT_SUCCESS;
}

vector<float> simulation(float T, float a_init, Environment &env)
{
	vector<float> data(4);
	vector<float> bacterias(2);
	for (int t = 0 ; t <= 100; ++t)
	{
		env.diffusion();
		env.death_of_cells();
		env.display();
    	env.search_and_fill_gaps();
    	env.metabolism_of_cells();
    	env.clean_envir();
	}
    bacterias = env.count_cells();
    data[0] = bacterias[0];
    data[1] = bacterias[1];
    data[2] = a_init;
    data[3] = T;
	return(data);
}

