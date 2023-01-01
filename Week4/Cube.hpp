#ifndef __CUBE_HPP__
#define __CUBE_HPP__

#include "Datatype.hpp"

namespace my_cube{

class Cube{
  public:
    Cube(double length, color_type color):_length(length),_color(color){};
    Cube() = default;

    double get_length() const {return this->_length;};
    color_type get_color() const {return this->_color;};

    double get_volume() {return ((this->_length)*(this->_length)*(this->_length));};
    double get_surface() {return ((this->_length)*(this->_length));};

    void set_length(int length) {this->_length = length;};
    void set_color(color_type color) {this->_color = color;};
    
  private: 
    double _length;
    color_type _color;
};

}
#endif