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
ofstream fs2;
// Create a name for the file output
string filename1 = "Lresultats.csv";
string filename2 = "Sresultats.csv";

int W;
int H;
float D;
Environment environment_;
vector <float> d(3);

vector<float> simulation(float T, float a_init, Environment &env);

int main() {
	srand(time(NULL));

	// Create and open the .csv file
	fs.open(filename1);
	fs2.open(filename2);
	// Check the good opening of the file
	if (fs.is_open() && fs2.is_open())
	{
		cout << "File successfully opened" << endl;
		// Write the headers :
		//fs << "L" << "," << "S" << "," << "A_init" << "," << "T" << endl;
	}
	else
	{
		cout << "Error while opening" << endl;
		return -1;
	}

    W = 32;
    H = 32;
	D = 0;

	for (float a = 0; a <= 50; a += 10)
	{
		environment_ = Environment(W, H, a, D);
		for (float T = 1; T <= 1500; T += 100)
		{
			/*for (int time = 0; time < 1; ++time)
			{*/
				d = simulation(T, a, environment_);
				if(T == 1401)
				{
					fs << d[0] << endl;
					fs2 << d[1] << endl;
				}
				else
				{
					fs << d[0] << ",";
					fs2 << d[1] << ",";
				}
				cout << "T : " << T << "   \t a : " << a << "\t BacterieL : " << d[0] << endl;
			//}
		}
	}

	// Close the file
	fs.close();

	const char system_str[] = "Rscript results.R";
	std::system(system_str);

    return EXIT_SUCCESS;
}

vector<float> simulation(float T, float a_init, Environment &env)
{
	vector<float> data(4);
	vector<float> bacterias(2);
	int clean = 0;
	for (int t = 0 ; t <= 1000; ++t)
	{
		env.diffusion(); // --> OK
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
