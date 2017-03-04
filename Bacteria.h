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
        int get_genotype() const;
        float get_A() const;
        float get_B() const;
        float get_C() const;

        // ===================================================================
        //                          Public Methods
        // ===================================================================
        virtual void metabolism(float& out) = 0;
        virtual void fitness() = 0;
        virtual void display();

    protected :
        // ===================================================================
        //                           Attributes
        // ===================================================================
        static float w_min; // Minimum allowed fitness value
        static float p_mut;
        static float p_death;

        float w; // Bacteria's fitness
        int genotype; // Bacteria's genotype
        float A; // Internal concentration of Glucose
        float B; // Internal concentration of Acetate
        float C; // Internal concentration of Ethanol

};

#endif // BACTERIA_H
