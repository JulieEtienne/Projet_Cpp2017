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

Environment::Environment(int W_, int H_, float a_initial)
{
    W = W_;
    H = H_;
    a_init = a_initial;
    grid.resize(W);
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
//                              Getters
// ===========================================================================
int Environment::get_W() const
{
    return W;
}

int Environment::get_H() const
{
    return H;
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

void Environment::search_gaps()
{
    //Parcourir la grille, quand une case est vide,
    //get ses coordonnées, et appeler fill_gaps
}

void Environment::search_BestFitness(int x, int y)
{
    //avec les coordonnées en argument (?),
    //regarder la fitness des cases autour
    //la comparer aux autres et renvoyer les coord de la meilleure
    //si case autour est vide => fitness = 0
}

void Environment::fill_gaps()
{
    //parcourir les cases, si une est empty :
    //trouver cellule avec meilleure fitness
    //se divise et fille prend la case vide et l'autre prend la place
    //de la mère
}

void Environment::diffusion()
{
    //diffusion des composés (code dans .pdf)
}
