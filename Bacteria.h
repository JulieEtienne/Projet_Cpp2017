#ifndef BACTERIA_H
#define BACTERIA_H

class Bacteria {

    friend class Case; //class Case can now access data directly

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
        //                          Getters
        // ===================================================================


        // ===================================================================
        //                          Public Methods
        // ===================================================================
        virtual void metabolism(float &out);
        virtual void fitness();
        virtual void dead_or_alive();

        // ===================================================================
        //                           Display
        // ===================================================================
        virtual void display();

    protected :
        // ===================================================================
        //                           Attributes
        // ===================================================================
        static float w_min; // Minimum allowed fitness value
        static float p_mut;
        static float p_death;

        float w; // Bacteria's fitness
        int genotype; // Bacteria's genotype : 0 or 1
        float A; // Internal concentration of Glucose
        float B; // Internal concentration of Acetate
        float C; // Internal concentration of Ethanol
        bool is_alive; //True or False

};

#endif // BACTERIA_H
