// ===========================================================================
//                          Includes
// ===========================================================================
#include "Environment.h"

// ===========================================================================
//                             Constructors
// ===========================================================================
Environment::Environment()
{
    W = 0;
    H = 0;
    a_init = 0.0;
    cout << "La grille est vide.\n" << endl;
}

Environment::Environment(int W_, int H_, float a_initial, float diff_coeff)
{
    W = W_;
    H = H_;
    a_init = a_initial;
    D = diff_coeff;

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

    //Filling it randomly with same amount of bacteria L and S :

    // Total number of Case in grid divided by 2
    int num = (W * H) / 2;
    // Counts the number of bacterieL
    int zero = 0;
    // Counts the number of bacterieS
    int one = 0;
    // Probability to be a bacterieL or bacterieS
    double p = 0;

    // Filling the grid :
    for (int i = 0; i < W; ++i)
    {
        for (int j = 0; j < H; ++j)
        {
            // Random number within [0, 100]
            p = rand()%101;
            // To simplify our if...else... content
            int a = 0;

            // If p < 50, or if there are too many bacterieS, fill with an L
            // otherwise, if p > 50, or if there are too many L, fill with an S
            if ((p < 50 && zero < num) || (p >= 50 && one >= num))
            {
                a = 0;
            }
            else if ((p >= 50 && one < num) || (p < 50 && zero >= num))
            {
                a = 1;
            }

            //Filling, depending on the value taken by a :
            if (a == 0)
            {
                // A bacteria of type L is created
                grid[i][j] = Case(0, a_init);
                zero++;
            }
            else if (a == 1)
            {
                // A bacteria of type S is created
                grid[i][j] = Case(1, a_init);
                one++;
            }
            else
            {
                cout << "Too many cells, not enough space." << endl;
            }
        }
    }
    // Check total number of bacteria created
    cout << "Nb 0 : " << zero << " Nb 1 : "<< one << endl;
    cout << "Grille initialisée." << endl;
}

// Scans the grid, and when if finds an empty Case, keeps its coordinates
// in a vector that will shuffled afterwards ;
// each empty Case will then be filled.
void Environment::search_and_fill_gaps()
{
    // Will store the coords of empty Cases
    vector<pair <int, int>> coords;
    // Search for empty Cases
    for (int i = 0; i < W; ++i)
    {
        for (int j = 0; j < H; ++j)
        {
            if (grid[i][j].amI_Empty())
            {
                // Adds its coordinates to the vector
                coords.push_back(make_pair(i, j));
            }
        }
    }

    // Filling randomly the empty Cases :

    // will store a random number
    int r = 0;
    // Will store the x coord of the empty Case
    int x = 0;
    // Will store the y coord of the empty Case
    int y = 0;
    // Initial number of coordinates = number of empty Cases
    unsigned int size_initial = coords.size();
    for (int n = 0; n < size_initial; n++)
    {
        // Random number within [0,coords.size())
        r = rand()%(coords.size());
        // Get the coordinates :
        x = coords[r].first;
        y = coords[r].second;
        // Filling :
        fill_gaps(x, y);
        // Deletes the coords of the Case that just got filled
        // so that we can't choose it again in the loop
        coords.erase(coords.begin() + r);
    }
    cout << "Toutes les cases vides ont été remplies." << endl;
}

// This function browses all the Cases around the empty cell which coordinates
// are given as parameters, and compare their fitness to find the best one.
// It returns the coordinates of the cell which bacteria has the best fitness
vector<int> Environment::search_BestFitness(int x, int y)
{
    cout << "BEGIN BEST_FITNESS" << endl;
    // Temporary maximum fitness
    float max_fit = 0;
    int a = 0;
    // Will receive the coord of the best bacteria
    vector<int> best(2);
    // Search for the best fitnes :
    for (int k = x - 1; k <= x + 1; ++k)
    {
        for (int m = y - 1; m <= y + 1; ++m)
        {
            // Will store the fitness of the current bacteria
            float fit = 0;
            a++;

            // Check conditions of toroidal grid
            int temp_k = k;
            int temp_m = m;
            k == -1 ? (temp_k = W-1) : 0;
            k == W ? (temp_k = 0) : 0;
            m == -1 ? (temp_m = H-1) : 0;
            m == H ? (temp_m = 0) : 0;

            if (grid[temp_k][temp_m].amI_Empty())
            {
                cout << "empty" << temp_k << " - " << temp_m << endl;
            }
            else
            {
                cout << "hi" << endl;
                cout << temp_k << " - " << temp_m << endl;
                fit = grid[temp_k][temp_m].bac->get_fitness();
            }

            // Compares the fitnesses
            if (fit > max_fit)
            {
                max_fit = fit;
                best[0] = temp_k;
                best[1] = temp_m;
            }
            cout << best[0] << " - " << best[1]<< endl;

        }
    }

    if (grid[0][0].bac == NULL) cout << "..." << endl;
    cout << grid[best[0]][best[1]].bac->get_fitness() << endl;
    // Returns the coordinates
    return best;

}

// The parameters are those of the empty cell
void Environment::fill_gaps(int x, int y)
{
    // Retrieves the coordinates of the bacteria who will be considered
    // as a "Mum" = the one with the best fitness around
    vector<int> coord_best = search_BestFitness(x, y);
    int x_mum = coord_best[0];
    int y_mum = coord_best[1];
    // Retrieves its concentrations data
    float new_A = grid[x_mum][y_mum].bac->get_A();
    float new_B = grid[x_mum][y_mum].bac->get_B();
    float new_C = grid[x_mum][y_mum].bac->get_C();
    int new_genotype = grid[x_mum][y_mum].bac->get_genotype();

    // Fill the empty case by creating a bacteria L or S,
    // depending on this stored genotype
    if (new_genotype == 0)
    {
        grid[x][y].bac = new BacterieL();
    }
    else if (new_genotype == 1)
    {
        grid[x][y].bac = new BacterieS();
    }
    else
    {
    cout << "Wrong genotype." << endl;
    }

    // The "Mum" is going to divide herself into 2 daughter cells :
    // First, check we have concentrations != 0
    new_A = new_A / 2.0;
    new_B = new_B / 2.0;
    new_C = new_C / 2.0;
    // Set the new concentrations in the bacteria "Mum"
    grid[x_mum][y_mum].bac->set_A(new_A);
    grid[x_mum][y_mum].bac->set_B(new_B);
    grid[x_mum][y_mum].bac->set_C(new_C);

    if (choose_Mum_or_baby_to_mutate() == 1)
    {
        grid[x][y].bac->mutation();
    }
    else if (choose_Mum_or_baby_to_mutate() == 0)
    {
        grid[x_mum][y_mum].bac->mutation();
    }

    //Set the concentration inside the new bacteria
    grid[x][y].bac->set_A(new_A);
    grid[x][y].bac->set_B(new_B);
    grid[x][y].bac->set_C(new_C);
}

int Environment::choose_Mum_or_baby_to_mutate()
{
    int p = rand()%2;
    return(p);
}

// Diffuse metabolites (diffusion is applied to all cells at the same time)
void Environment::diffusion()
{
    // Copy initial grid : "copy" will keep the concentration at time t
    // Grid will store them at (t + 1)
    vector<vector<Case>> copy = grid;
    // m and k are needed to check the toroidal conditions

    int m = 0;
    int k = 0;

    // Scan all the cells
    for (int x = 0; x < W; ++x)
    {
        for (int y = 0; y < H; ++y)
        {
        // Around the cells :
            for (int i = -1; i <= 1; ++i)
            {
                for (int j = - 1; j <= 1; ++j)
                {
                    k = x + i;
                    m = y + i;

                    // Check conditions of toroidal grid
                    k == -1 ? (k = W-1) : 0;
                    k == W ? (k = 0) : 0;
                    m == -1 ? (m = H-1) : 0;
                    m == H ? (m = 0) : 0;

                    copy[x][y].A_out += D * grid[x][y].A_out;
                    copy[x][y].B_out += D * grid[x][y].B_out;
                    copy[x][y].C_out += D * grid[x][y].C_out;
                }
            }
            // End computations and update in grid :
            grid[x][y].A_out = copy[x][y].A_out - 9 * D * grid[x][y].A_out;
            grid[x][y].B_out = copy[x][y].B_out - 9 * D * grid[x][y].B_out;
            grid[x][y].C_out = copy[x][y].C_out - 9 * D * grid[x][y].C_out;
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
            // If the Bacteria is dead, do the necessary things to deal with it
            if (grid[i][j].bac->get_is_alive() == false)
            {
                grid[i][j].bac_IsDead();
            }
        }
    }
}

void Environment::metabolism_of_cells()
{
    for (int i = 0; i < W; ++i)
    {
        for (int j = 0; j < H; ++j)
        {
            grid[i][j].manage_metabolism();
        }
    }
}

void Environment::clean_envir()
{
    for (int i = 0; i < W; ++i)
    {
        for (int j = 0; j < H; ++j)
        {
            // Reinitializes the concentrations
            grid[i][j].A_out = a_init;
            grid[i][j].B_out = 0;
            grid[i][j].C_out = 0;
        }
    }
    cout << "La grille a été vidée et nettoyée." << endl;
}

// Display grid and check if a Case is empty
void Environment::display()
{
    cout << "Genotypes : " << endl;
    for (int i = 0; i < W; ++i)
    {
        for (int j = 0; j < H; ++j)
        {
            if(grid[i][j].amI_Empty()) cout << "Empty Case" << endl;
            cout << grid[i][j].bac->get_genotype() << "\t";
        }
        cout << endl;
    }

    cout << "A concentration : " << endl;
    for (int i = 0; i < W; ++i)
    {
        for (int j = 0; j < H; ++j)
        {
            cout << grid[i][j].A_out << "\t";
        }
        cout << endl;
    }

    // cout << "B concentration : " << endl;
    // for (int i = 0; i < W; ++i)
    // {
    //     for (int j = 0; j < H; ++j)
    //     {
    //         cout << grid[i][j].B_out << "\t";
    //     }
    //     cout << endl;
    // }

    // cout << "C concentration : " << endl;
    // for (int i = 0; i < W; ++i)
    // {
    //     for (int j = 0; j < H; ++j)
    //     {
    //         cout << grid[i][j].C_out << "\t";
    //     }
    //     cout << endl;
    // }
}
