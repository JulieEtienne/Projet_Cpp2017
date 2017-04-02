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

Environment::Environment(int W_, int H_, float a_initial, float diff_coeff)
{
    W = W_;
    H = H_;
    a_init = a_initial;
    D = diff_coeff;
    srand(time(NULL)); // rand initialization

    initialize_grid();
}

// ===========================================================================
//                             Destructor
// ===========================================================================
Environment::~Environment() {}

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
    //Parcourir la grille, quand une case est vide, garder ses coord dans un
    //vecteur, mélanger ce vecteur et puis appeler fill_gaps pour chaque case
    vector<pair <int, int>> coords; // Will store the coords of empty Case
    // Search for empty Case
    for (int i = 0; i < W; ++i) {
        for (int j = 0; j < H; ++j) {
            if (grid[i][j].amI_Empty()) {
                coords.push_back(make_pair(i, j)); // Add the coords to the vector
            }
        }
    }

    int r = 0; // will store a random number
    int x = 0; // Will store the x coord of the empty Case
    int y = 0; // Will store the y coord of the empty Case
    unsigned int size_initial = coords.size(); // Initial number of coords
    for (int n = 0; n < size_initial; n++) {
        // Random number within [0,coords.size())
        r = rand()%(coords.size());
        x = coords[r].first;
        y = coords[r].second;
        fill_gaps(x, y);
        coords.erase(coords.begin() + r); // Deletes the coords of the Case that just got filled
    }
    cout << "Toutes les cases vides ont été remplies." << endl;
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

// Diffuse metabolites (applied to all cells at the same time)
void Environment::diffusion()
{
    // Copy initial grid : "copy" will keep the concentration at time t
    // Grid will store them at (t + 1)
    vector<vector<Case>> copy = grid;
    int temp_m = 0;
    int temp_k = 0;

    // Parcourir toutes les cases
    for (int x = 0; x < W; ++x) {
        for (int y = 0; y < H; ++y) {
        // Autour de la case :
            for (int i = -1; i <= 1; ++i) {
                for (int j = - 1; j <= 1; ++j) {

                    int k = x + i;
                    int m = y + i;

                    //Conditions aux bords
                    k == -1 ? (temp_k = W-1) : 0;
                    k == W ? (temp_k = 0) : 0;
                    m == -1 ? (temp_m = H-1) : 0;
                    m == H ? (temp_m = 0) : 0;

                    copy[x][y].A_out += D * copy[x][y].A_out;
                    copy[x][y].B_out += D * copy[x][y].B_out;
                    copy[x][y].C_out += D * copy[x][y].C_out;

                }
            }

            // End computations and update in grid :
            grid[x][y].A_out = copy[x][y].A_out - 9 * D * copy[x][y].A_out;
            grid[x][y].B_out = copy[x][y].B_out - 9 * D * copy[x][y].B_out;
            grid[x][y].C_out = copy[x][y].C_out - 9 * D * copy[x][y].C_out;

        }
    }
    display();
    cout << "La diffusion est terminée." << endl;

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
            }
        }
    }
}

// Cleans the environnement's solution
void Environment::clean_envir()
{

    for (int i = 0; i < W; ++i)
    {
        for (int j = 0; j < H; ++j)
        {
            grid[i][j].A_out = a_init;
            grid[i][j].B_out = 0;
            grid[i][j].C_out = 0;
        }
    }
    cout << "La grille a été vidée et nettoyée." << endl;
    display();
}

// Display grid and check if a Case if empty
void Environment::display()
{
    cout << "Genotypes : " << endl;
    for (int i = 0; i < W; ++i) {
        for (int j = 0; j < H; ++j) {
            if(grid[i][j].amI_Empty()) cout << "Empty Case" << endl;
            cout << grid[i][j].bac->get_genotype();
        }
        cout << endl;
    }

    cout << "A concentration : " << endl;
    for (int i = 0; i < W; ++i) {
        for (int j = 0; j < H; ++j) {
            cout << grid[i][j].A_out;
        }
        cout << endl;
    }

    cout << "B concentration : " << endl;
    for (int i = 0; i < W; ++i) {
        for (int j = 0; j < H; ++j) {
            cout << grid[i][j].B_out;
        }
        cout << endl;
    }

    cout << "C concentration : " << endl;
    for (int i = 0; i < W; ++i) {
        for (int j = 0; j < H; ++j) {
            cout << grid[i][j].C_out;
        }
        cout << endl;
    }

    // SEG FAULT DE TEMPS EN TEMPS, IL DIT QU'UNE CASE EST EMPTY
}
