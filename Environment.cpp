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
    initialize_grid();
}

// ===========================================================================
//                             Destructor
// ===========================================================================
Environment::~Environment()
{
    for (int i = 0; i < W; ++i)
    {
        delete[] grid[i];
    }
    delete[] grid;
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
void Environment::initialize_grid()
{
    grid = new Case*[W];
    for (int i = 0; i < W; ++i)
    {
        grid[i] = new Case[H];
    }
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
