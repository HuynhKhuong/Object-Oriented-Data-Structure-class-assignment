#include "Game.hpp"
#include <iostream>
//No need to include Cube or Stack as Gampe.hpp contains all these includes

//Create temporary stacks:
stack::Stack middle_stack;
stack::Stack final_stack;

int main(){
  Game _mygame;

  _mygame.solve(_mygame, middle_stack, final_stack);

  // std::cout << "check result: stack[4]" << (final_stack.get_top_stack()).get_color() << std::endl;
  // final_stack.remove_top_Stack();
  // std::cout << "check result: stack[3]" << (final_stack.get_top_stack()).get_color() << std::endl;
  // final_stack.remove_top_Stack();
  // std::cout << "check result: stack[2]" << (final_stack.get_top_stack()).get_color() << std::endl;
  // final_stack.remove_top_Stack();
  // std::cout << "check result: stack[1]" << (final_stack.get_top_stack()).get_color() << std::endl;
  // final_stack.remove_top_Stack();
  return 0;
}
