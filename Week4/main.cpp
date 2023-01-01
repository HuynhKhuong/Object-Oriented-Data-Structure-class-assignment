#include "Game.hpp"
#include <iostream>
//No need to include Cube or Stack as Gampe.hpp contains all these includes

//Create temporary stacks:
stack::Stack middle_stack;
stack::Stack final_stack;

int main(){
  Game _mygame;
  Game _testgame = _mygame;
  std::cout << "check length: "<< (_mygame.get_Stack_length()) << std::endl;

  std::cout << "check result: "<< (_mygame.get_top_stack()).get_color() << std::endl;
  _mygame.remove_top_Stack();
  std::cout << "check result: "<< (_mygame.get_top_stack()).get_color() << std::endl;
  _mygame.remove_top_Stack();
  std::cout << "check result: "<< (_mygame.get_top_stack()).get_color() << std::endl;
  _mygame.remove_top_Stack();
  std::cout << "check result: "<< (_mygame.get_top_stack()).get_color() << std::endl;
  _mygame.remove_top_Stack();

  std::cout <<  "check length: " << _mygame.get_Stack_length() << std::endl;
  _mygame.solve(_testgame, middle_stack, final_stack);
  
  std::cout << "check result: "<< (_testgame.get_top_stack()).get_color() << std::endl;
  _testgame.remove_top_Stack();
  std::cout << "check result: "<< (_testgame.get_top_stack()).get_color() << std::endl;
  _testgame.remove_top_Stack();
  std::cout << "check result: "<< (_testgame.get_top_stack()).get_color() << std::endl;
  _testgame.remove_top_Stack();

  std::cout << "check length: " <<  _testgame.get_Stack_length() << std::endl;
  return 0;
}
