// ===========================================================================
//                          Includes
// ===========================================================================
#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::pair;
using std::vector;
using std::string;
using std::ofstream;

#include "Bacteria.h"
#include "BacterieL.h"
#include "BacterieS.h"
#include "Case.h"
#include "Environment.h"

// Create an ofstream for the file output
//ofstream output;
ofstream fs;
// Create a name for the file output
string filename = "resultats.csv";

int W;
int H;
float D;
Environment environment_;
vector <float> d(3);

vector<float> simulation(float T, float a_init, Environment &env);

int main() {
	srand(time(NULL));

	// Create and open the .csv file
	fs.open(filename);
	// Write the headers :
	fs << "L" << "," << "S" << "," << "A_init" << "," << "T" << endl;

    W = 10;
    H = 10;
	D = 0.1;

	for (float a = 0; a <= 50; a += 10)
	{
		environment_ = Environment(W, H, a, D);
		for (float T = 1; T <= 1500; T += 100)
		{
			for (int time = 0; time < 1; ++time)
			{
				d = simulation(T, a, environment_);
				//for (auto &i:donnees) cout << i << endl;
				fs << d[0] << "," << d[1] << "," << d[2] << "," << d[3] << endl;
			}
		}
	}

	// Close the file
	fs.close();

	//std::system(std::to_string("results.R ./filename"));

    return EXIT_SUCCESS;
}

vector<float> simulation(float T, float a_init, Environment &env)
{
	vector<float> data(4);
	vector<float> bacterias(2);
	int clean = 0;
	for (int t = 0 ; t <= 100; ++t)
	{
		env.diffusion();
		env.death_of_cells();
    	env.search_and_fill_gaps();
    	env.metabolism_of_cells();
    	env.maj_fitness();
		//env.display();
		if (clean == T)
		{
    		env.clean_envir();
    		clean = 0;
		}
		else
		{
			clean++;
		}
	}
    bacterias = env.count_cells();
    data[0] = bacterias[0];
    data[1] = bacterias[1];
    data[2] = a_init;
    data[3] = T;
	return(data);
}
