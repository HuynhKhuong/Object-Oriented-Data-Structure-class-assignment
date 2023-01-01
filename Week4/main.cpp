#include "Game.hpp"
#include <iostream>
//No need to include Cube or Stack as Gampe.hpp contains all these includes

int main(){
  Game _mygame;
  std::cout << "testing purpose" << std::endl;
  std::cout << "length of the initial stack is: " << _mygame.get_Stack_length()<< std::endl;
  std::cout << "color of each cube is " << _mygame.get_top_stack().get_color()<<std::endl;
  _mygame.remove_top_Stack();
  std::cout << "color of each cube is " << _mygame.get_top_stack().get_color()<<std::endl;
  _mygame.remove_top_Stack();
  std::cout << "color of each cube is " << _mygame.get_top_stack().get_color()<<std::endl;
  _mygame.remove_top_Stack();
  std::cout << "color of each cube is " << _mygame.get_top_stack().get_color()<<std::endl;
  _mygame.remove_top_Stack();
  _mygame.solve();
  return 0;
}
