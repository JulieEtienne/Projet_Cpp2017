#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

// ===========================================================================
//                          Includes
// ===========================================================================
#include "Case.h"
#include <vector>
#include <time.h>
// To use std::pair and make_pair :
#include <utility>

using std::vector;
using std::cout;
using std::endl;
using std::pair;
using std::make_pair;

class Environment
{

    public :
        // ===================================================================
        //                          Constructors
        // ===================================================================
        // Default constructor
        Environment();
        // Constructor with, as parameters :
        // the width and height of the grid ;
        // the initial concentration of glucose in the cells ;
        // the diffusion coefficient
        Environment(int W_, int H_, float a_initial, float diff_coeff);

        // ===================================================================
        //                          Destructor
        // ===================================================================
        ~Environment();

        // ===================================================================
        //                          Public Methods
        // ===================================================================
        // Initiliazes the grid
        void initialize_grid();
        // Searches the empty Case and fills them with a divided bacteria
        void search_and_fill_gaps();
        // Searches the bacteria with the best fitness among the ones that are
        // around the empty cell, which coordinates are given as parameters
        vector<int> search_BestFitness(int x, int y);
        // Fills the gap created by the empty cell,
        // the coordinates of the best-fit bacteria are given as parameters
        void fill_gaps(int x, int y);
        // Manages the diffusion of the 3 metabolites around the grid
        int choose_Mum_or_baby_to_mutate();
        void diffusion();
        // Check if a bacteria is dead, and deals with it if it is the case
        void death_of_cells();
        // Applies the metabolism for each cell
        void metabolism_of_cells();
        // In order to have a good environment for the bacterias, the
        // grid must be cleaned sometimes, this is why this function is here
        void clean_envir();
        // Shows the grid under different angles of parameters
	    void display();

    protected :
        // ===================================================================
        //                          Attributes
        // ===================================================================
        // Width of the grid
        int W;
        // Its height
        int H;
        // Initial glucose concentration
        float a_init;
        // Diffusion coefficient
        float D;
        // The grid
        vector<vector<Case>> grid;

};

#endif // CASE_H
