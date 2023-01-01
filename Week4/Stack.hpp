#ifndef __STACK_HPP__
#define __STACK_HPP__

#include "Cube.hpp"
#include <vector>

namespace stack{

class Stack{
  public:
    Stack():ownCUBE(0, my_cube::Cube()){};

    void Push_Stack(const my_cube::Cube & additional_cube);
    my_cube::Cube& get_top_stack();
    void remove_top_Stack();
    int get_Stack_length();

  private:
    std::vector<my_cube::Cube> ownCUBE; //as designed, top cube on stack has the biggest index, the lower ones have the index descending

};

}

#endif