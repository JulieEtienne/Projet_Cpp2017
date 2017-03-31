// ===========================================================================
//                          Includes
// ===========================================================================
#include "Environment.h"
#include <iostream>
#include <cassert>

// ===========================================================================
//                             Constructors
// ===========================================================================
Environment::Environment()
{
    W = 0; // Width = Largeur
    H = 0; // Height = Hauteur
    a_init = 0.0; // Initial concentration of glucose
    cout << "La grille est vide.\n" << endl;
}

Environment::Environment(int W_, int H_, float a_initial)
{
==== BASE ====
    W = W_; // Width
    H = H_; // Height
    a_init = a_initial; // Initial glucose concentration
    srand(time(NULL)); // rand initialization

    initialize_grid();
==== BASE ====

}

// ===========================================================================
//                             Destructor
// ===========================================================================
Environment::~Environment()
{
}

// ===========================================================================
//                             Public Methods
// ===========================================================================

void Environment::initialize_grid()
{
    // Resizes width of grid : will call Case's default constructor
    grid.resize(W);
    for (int i = 0; i < W; ++i) {
        grid[i].resize(H);
    }

    //Filling it randomly with same amount of bacteria L and S
    int num = (W * H) / 2; // Total number of Case in grid divided by 2
    int zero = 0; // Counts the number of bacterieL
    int one = 0; // Counts the number of bacterieS
    double p = 0; // Probability to be a bacterieL or bacterieS

    // Filling the grid
    for (int i = 0; i < W; ++i) {
        for (int j = 0; j < H; ++j) {
            p = rand()%101; // Random number within [0, 100]
            int a = 0; // To simplify our if...else... content

            // If p < 50, or if there are too many bacterieS, fill with an L
            // otherwise, if p > 50, or if there are too many L, fill with an S
            if ((p < 50 && zero < num) || (p >= 50 && one >= num)) {
                a = 1;
            } else if ((p >= 50 && one < num) || (p < 50 && zero >= num)) {
                a = 2;
            }

            //Filling
            if (a == 1) {
                grid[i][j] = Case(0, a_init);
                zero++;
            } else if (a == 2) {
                grid[i][j] = Case(1, a_init);
                one++;
            } else {
                cout << "Too many cells, not enough space." << endl;
            }
        }
    }
    // Check total number of bacteria created
    cout << "Nb 0 : " << zero << " Nb 1 : "<< one << endl;

    cout << "Grille initialisée." << endl;
}

void Environment::search_and_fill_gaps()
{
    //Parcourir la grille, quand une case est vide,
    //appelle fill_gaps
    for (int i = 0; i < W; ++i) {
        for (int j = 0; j < H; ++j) {
            if (grid[i][j].amI_Empty()) {
                cout << "Empty" << endl;
                fill_gaps(i, j);
            }
        }
    }
    cout << "La case vide a été remplie." << endl;
}

vector<int> Environment::search_BestFitness(int x, int y)
{
    //regarder la fitness des cases autour
    //la comparer aux autres et renvoyer les coord de la meilleure
    //si case autour est vide => fitness = 0

    int max_fit = 0;
    vector<int> best(2); // Will receive the coord of the best bacteria
    for (int k = x - 1; k <= x + 1; ++k) {
        for (int m = y - 1; m <= y + 1; ++m) {
            int fit = 0;
            int temp_k = k;
            int temp_m = m;

            // Check conditions of toroidal grid
            k == -1 ? (temp_k = W-1) : 0;
            k == W ? (temp_k = 0) : 0;
            m == -1 ? (temp_m = H-1) : 0;
            m == H ? (temp_m = 0) : 0;

            if (grid[temp_k][temp_m].bac) {
                fit = grid[temp_k][temp_m].bac->get_fitness();
            }

            if (fit > max_fit) {
                max_fit = fit;
                best[0] = temp_k;
                best[1] = temp_m;
            }
        }
    }

    return best;

}

void Environment::fill_gaps(int x, int y)
{
    //se divise et fille prend la case vide et l'autre prend la place
    //de la mère (ne pas oublier de remplier la case avec une bactérie,
    // car nullptr)
    vector<int> coord_best = search_BestFitness(x, y);
    int x_mum = coord_best[0];
    int y_mum = coord_best[1];

    float new_A = grid[x_mum][y_mum].bac->get_A();
    float new_B = grid[x_mum][y_mum].bac->get_B();
    float new_C = grid[x_mum][y_mum].bac->get_C();

    grid[x_mum][y_mum].bac->mutation();

    int new_genotype = grid[x_mum][y_mum].bac->get_genotype();

    new_A == 0 ? 0 : new_A = new_A / 2.0;
    new_B == 0 ? 0 : new_B = new_B / 2.0;
    new_C == 0 ? 0 : new_C = new_C / 2.0;

    grid[x_mum][y_mum].bac->set_A(new_A);
    grid[x_mum][y_mum].bac->set_B(new_B);
    grid[x_mum][y_mum].bac->set_C(new_C);

    if (new_genotype == 0)
    {
        grid[x][y].bac = new BacterieL();
    }
    else if (new_genotype == 1)
    {
        grid[x][y].bac = new BacterieS();
    } else {
	cout << "Wrong genotype." << endl;
	}

    grid[x][y].bac->set_A(new_A);
    grid[x][y].bac->set_B(new_B);
    grid[x][y].bac->set_C(new_C);
}

void Environment::death_of_cells()
{
    for (int i = 0; i < W; ++i)
    {
        for (int j = 0; j < H; ++j)
        {
            grid[i][j].bac->dead_or_alive();
            if (grid[i][j].bac->get_is_alive() == false)
            {
                grid[i][j].bac_IsDead();
                cout << "La bactérie est bien morte" << endl;
                diffusion(i, j);
            }
        }
    }
}

void Environment::diffusion(int x, int y, float D)
{
    //Diffusion des composés
    /**float a_next = grid[x][y].bac->get_A();
    float b_next = grid[x][y].bac->get_B();
    float c_next = grid[x][y].bac->get_C();
    for (int i = -1; i <= 1; ++i) {
        for (int j = - 1; j <= 1; ++j) {
            int k = x + i;
            int m = y + i;

            k == -1 ? (temp_k = W-1) : 0;
            k == W ? (temp_k = 0) : 0;
            m == -1 ? (temp_m = H-1) : 0;
            m == H ? (temp_m = 0) : 0;

            a_next = a_next + D * ;**/
}

// Display grid and check if a Case if empty
void Environment::display()
{
    for (int i = 0; i < W; ++i) {
        for (int j = 0; j < H; ++j) {
            if(grid[i][j].amI_Empty()) cout << "Empty Case" << endl;
            cout << grid[i][j].bac->get_genotype();
        }
        cout << endl;
    }
}
