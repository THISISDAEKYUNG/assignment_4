#include "circle.h"

#include <iostream>
using std::cout;
using std::endl;


//Fill this implementation file.
void Circle::add_inner_point(Point *p) {
    inner_points[num_inner_points] = *p
    Point::n_inclusion++; //?
}

void Circle::check_within(Point *p) {
    if (get_distance(*p) < radius) {
        add_inner_point(*p);
        num_inner_points++;
    }
}

void change_color(string color) {
    for (int i = 0; i < num_inner_points; i++) {
        change_color(color);
    }
}


// DO NOT TOUCH!!!
void Circle::print_inner_points() {
    for (int i=0; i<num_inner_points; i++) {
      cout << "(" << (inner_points[i])->get_x() << ", ";
      cout << (inner_points[i])->get_y() << ", ";
      cout << (inner_points[i])->get_color() << ")";
      
      if (i < num_inner_points-1) cout << ", ";
    }
  cout << endl;
}