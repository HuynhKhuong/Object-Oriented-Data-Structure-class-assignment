#ifndef __GAME_HPP__
#define __GAME_HPP__

#include "Stack.hpp"

class Game : public stack::Stack{

public: 
  //Default constructor: 
  Game();
  void solve(stack::Stack &source_cont, stack::Stack &middle_cont);

private: 
  stack::Stack _stack;

};

#endif