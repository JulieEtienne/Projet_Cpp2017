#ifndef BACTERIA_H
#define BACTERIA_H

class Bacteria
{

    //class Case can now access data directly
    friend class Case;

    public :
        // ===================================================================
        //                          Constructors
        // ===================================================================
        // Default constructor
        Bacteria();
        // Constructor with the genotype as parameter
        Bacteria(int genotype_);

        // ===================================================================
        //                          Destructor
        // ===================================================================
        virtual ~Bacteria() {};

        // ===================================================================
        //                          Getters
        // ===================================================================
        int get_genotype() const;
        float get_fitness() const;
        float get_A() const;
        float get_B() const;
        float get_C() const;
        bool get_is_alive() const;

        // ===================================================================
        //                          Setters
        // ===================================================================
        void set_A(float a);
        void set_B(float b);
        void set_C(float c);

        // ===================================================================
        //                          Public Methods
        // ===================================================================
        // Code for the metabolisme of the bacteria :
        // will differ depending on the type of bacteria
        // Parameter is a reference, to keep it update after the fonction's done
        virtual void metabolism(float &conc_out);
        // Computes the fitness of the Bacteria, depending on its type
        void fitness();
        // Check if the fitness is above the minimum value required
        void check_fitness();
        // Uses a probability of death to make the bacteria die or not
        void dead_or_alive();
        // Uses a probability of mutation to make
        // the bacteria's genotype change or not
        void mutation();

        // ===================================================================
        //                           Display
        // ===================================================================
        void display();

    protected :
        // ===================================================================
        //                           Attributes
        // ===================================================================
        // Minimum allowed fitness value
        static float w_min;
        // Mutation probability
        static float p_mut;
        // Death probability
        static float p_death;

        // Bacteria's fitness
        float w;
         // Bacteria's genotype : 0 ( = L) or 1 (= S)
        int genotype;
        // Internal concentration of Glucose
        float A;
        // Internal concentration of Acetate
        float B;
        // Internal concentration of Ethanol
        float C;
        // Tells if the bacteria is alive (True) or not (False)
        bool is_alive;

};

#endif // BACTERIA_H
