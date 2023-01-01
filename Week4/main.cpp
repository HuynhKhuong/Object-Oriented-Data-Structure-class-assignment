#include "Game.hpp"
#include <iostream>
//No need to include Cube or Stack as Gampe.hpp contains all these includes

//Create temporary stacks:
stack::Stack middle_stack;
stack::Stack final_stack;

int main(){
  Game _mygame;

  _mygame.solve(_mygame, middle_stack, final_stack);
  
  std::cout <<  "after solve length: " << _mygame.get_Stack_length() << std::endl;

  std::cout << "check result: "<< (final_stack.get_top_stack()).get_color() << std::endl;
  final_stack.remove_top_Stack();
  std::cout << "check result: "<< (final_stack.get_top_stack()).get_color() << std::endl;
  final_stack.remove_top_Stack();
  std::cout << "check result: "<< (final_stack.get_top_stack()).get_color() << std::endl;
  final_stack.remove_top_Stack();
  std::cout << "check result: "<< (final_stack.get_top_stack()).get_color() << std::endl;
  final_stack.remove_top_Stack();
  std::cout << "check length: " <<  final_stack.get_Stack_length() << std::endl;

  return 0;
}
