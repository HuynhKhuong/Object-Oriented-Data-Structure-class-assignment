#ifndef __GAME_SOLUTION2_HPP__
#define __GAME_SOLUTION2_HPP__

#include "Game.hpp"

class Game_solution2 : public Game{

public: 
  Game_solution2():Game(){};
  void solve(); //override with distinct logic

protected:
  void _strategy_move_cube(stack::Stack &source_cont, stack::Stack &destination);

};

#endif 