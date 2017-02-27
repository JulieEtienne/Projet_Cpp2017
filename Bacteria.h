#ifndef BACTERIA_H
#define BACTERIA_H

class Bacteria {

    public :
        // ===================================================================
        //                          Constructors
        // ===================================================================
        Bacteria();

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

};

#endif // BACTERIA_H
