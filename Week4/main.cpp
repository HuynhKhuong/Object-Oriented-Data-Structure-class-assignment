#include "Game_solution2.hpp"
#include <iostream>
//No need to include Cube or Stack as Gampe.hpp contains all these includes

//Create temporary stacks:
stack::Stack middle_stack;
stack::Stack final_stack;

int main(){
  Game_solution2 _mygame;
  _mygame.solve();

  Game _mygame2;
  _mygame2.solve();
  return 0;
}
