#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

// ===========================================================================
//                          Includes
// ===========================================================================
#include "Case.h"
#include <vector>
#include <algorithm>
#include <time.h>

using std::vector;
using std::cout;
using std::endl;
using std::random_shuffle;

class Environment {

    public :
        // ===================================================================
        //                          Constructors
        // ===================================================================
        Environment();
        Environment(int W_, int H_, float a_initial);

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
        void diffusion(int x, int y, float D);
        void display();

    protected :
        // ===================================================================
        //                          Attributes
        // ===================================================================
        int W;
        int H;
        float a_init;
        vector<vector<Case>> grid;

};

#endif // CASE_H
