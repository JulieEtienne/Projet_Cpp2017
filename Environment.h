#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

// ===========================================================================
//                          Includes
// ===========================================================================
#include "Case.h"
#include <vector>
#include <algorithm>
#include <time.h>
#include <utility>

using std::vector;
using std::cout;
using std::endl;
using std::pair;
using std::make_pair;

class Environment {

    public :
        // ===================================================================
        //                          Constructors
        // ===================================================================
        Environment();
        Environment(int W_, int H_, float a_initial, float diff_coeff);

        // ===================================================================
        //                          Destructor
        // ===================================================================
        ~Environment();

        // ===================================================================
        //                        Getters
        // ===================================================================

        // ===================================================================
        //                          Public Methods
        // ===================================================================
        void initialize_grid();
        vector<Case> random_cells();
        void search_and_fill_gaps();
        vector<int> search_BestFitness(int x, int y);
        void fill_gaps(int x, int y);
        void diffusion(int x, int y);
        void death_of_cells();
	void display();

    protected :
        // ===================================================================
        //                          Attributes
        // ===================================================================
        int W; // Width of the grid
        int H; // Height
        float a_init; // Initial glucose concentration
        float D; // Diffusion constant
        vector<vector<Case>> grid;

};

#endif // CASE_H
