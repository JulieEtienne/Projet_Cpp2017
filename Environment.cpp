// ===========================================================================
//                          Includes
// ===========================================================================
#include "Environment.h"

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
    W = W_; // Width
    H = H_; // Height
    a_init = a_initial; // Initial concentration of glucose
    grid.resize(W); // Create a first grid
    vector<Case> cells = random_cells();
    initialize_grid(cells);

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
void Environment::initialize_grid(vector<Case> cells)
{
    for (int i = 0; i < W; ++i) {
        grid[i].resize(H);
    }

    int k = 0;
    int i = 0;
    int j = 0;
    while (k < (W * H)) {
        if (k % W == 0 && k != 0) {
            i = 0; // columns
            ++j; // rows
            cout << endl;
        }
        grid[i][j] = cells[k];
        cout << grid[i][j].bac->get_genotype();
        ++i;
        ++k;
    }
    cout << endl;
    cout << "La grille a été initialisée." << endl;
}

vector<Case> Environment::random_cells()
{
    int num = W * H;
    vector<Case> v;
    v.reserve(num);
    for (int n = 0; n <= num; ++n) {
        if (n < num/2) {
            v.push_back(Case(0, a_init));
        } else {
            v.push_back(Case(1, a_init));
        }
    }
    // Shuffles the Case's instances randomly
    srand(unsigned(time(NULL)));
    std::random_shuffle(v.begin(), v.end());

    return v;
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
    vector<int> best(2);
    for (int k = x - 1; k <= x + 1; ++k) {
        for (int m = y - 1; m <= y + 1; ++m) {
            int fit = 0;
            int temp_k = k;
            int temp_m = m;

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

void Environment::diffusion(int x, int y)
{
    //diffusion des composés (code dans .pdf)

}
