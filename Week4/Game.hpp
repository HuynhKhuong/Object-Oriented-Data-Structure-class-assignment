#ifndef __GAME_HPP__
#define __GAME_HPP__

#include "Stack.hpp"

class Game { 
public: 
  //Default constructor: 
  Game();
  void solve();
  void print_m_stack();
  
protected: 
  void move_cube(stack::Stack &source_cont, stack::Stack &destination);
  stack::Stack _stack_scr;
  stack::Stack _stack_trans;
  stack::Stack _stack_des;

};

#endif