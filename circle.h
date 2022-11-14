#ifndef CIRCLE_H
#define CIRCLE_H

#define PI 3.14159265

class Circle {
    public:
        Circle(float radius); //Constructor Declaration
        // only accessors and mutators are public in this example
        float get_area();
        float get_circumference();
    private:
        // member variables are private and set/get via accessor/mutator
        float _radius;
        float _area;
};


#endif