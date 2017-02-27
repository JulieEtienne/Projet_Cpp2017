#ifndef BACTERIA_H
#define BACTERIA_H

class Bacteria {

    public :
        // ===================================================================
        //                          Constructors
        // ===================================================================
        Bacteria();
        Bacteria(int genotype_);

        // ===================================================================
        //                          Destructor
        // ===================================================================
        virtual ~Bacteria();

    protected :
        // ===================================================================
        //                           Attributes
        // ===================================================================
        static int w_min; // Minimum allowed fitness value
        static float p_mut;
        static float p_death;

        float w; // Bacteria's fitness
        int genotype; // Bacteria's genotype

};

#endif // BACTERIA_H
