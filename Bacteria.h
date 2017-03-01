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

        // ===================================================================
        //                        Getters
        // ===================================================================
        float get_fitness() const;

        // ===================================================================
        //                          Public Methods
        // ===================================================================
        virtual void metabolism(float& out) = 0;
        virtual void fitness() = 0;

    protected :
        // ===================================================================
        //                           Attributes
        // ===================================================================
        static int w_min; // Minimum allowed fitness value
        static float p_mut;
        static float p_death;

        float* w; // Bacteria's fitness
        int genotype; // Bacteria's genotype
        float* A;
        float* B;
        float* C;

};

#endif // BACTERIA_H
