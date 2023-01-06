#include "Game.hpp"
#include <iostream>

void Game::move_cube(stack::Stack &source_cont, stack::Stack &destination){
  //create temporary containers for transporting cubes between 3 stacks
  my_cube::Cube temp_cont;
  temp_cont = source_cont.get_top_stack();

  destination.Push_Stack(temp_cont);
  source_cont.remove_top_Stack(); //only remove the top stack once the push stack is done
}

Game::Game():_stack_des(),_stack_trans(){
  
  /*default constructor, creates 4 defaults cubes on stack
    Cube info: 
    - Blue, length = 4
    - Orange, length = 3
    - Purple, length = 2
    - Yellow, length = 1
    Cube is place in the order as follow: Blue has the lowest index, following is Orange, Purple, Yellow
  */
  
  //temporary cubes, their values would be stored in Game stack
  my_cube::Cube blue_cube(4,BLUE);
  my_cube::Cube orange_cube(3, ORANGE);
  my_cube::Cube purple_cube(2, PURPLE);
  my_cube::Cube yellow_cube(1, YELLOW);

  //_stack_scr declaration
  _stack_scr.Push_Stack(blue_cube);
  _stack_scr.Push_Stack(orange_cube);
  _stack_scr.Push_Stack(purple_cube);
  _stack_scr.Push_Stack(yellow_cube);

  //Other stack are kept as stack's default constructor 
}

void Game::solve(){
  //pre-declaration, no logic inside
  /*
    This problems require 3 stacks: 
    - Source stack (GAME)
    - Destination stack (created via heap)
    - Temp_stack (temporarily store cubes)
  */
  std::cout << "Solution 1" << std::endl;
  /*
    Solution description: 
    step 1:
    yellow -> middle
    purple -> destination
    yellow -> destination 
  */
  move_cube(this->_stack_scr, this->_stack_trans);
  move_cube(this->_stack_scr, this->_stack_des);
  move_cube(this->_stack_trans, this->_stack_des);
  /*
    step 2: 
    orange -> middle 
    yellow -> source
    purple -> middle
    yellow -> middle
  */
  move_cube(this->_stack_scr, this->_stack_trans);
  move_cube(this->_stack_des, this->_stack_scr);
  move_cube(this->_stack_des, this->_stack_trans);
  move_cube(this->_stack_scr, this->_stack_trans);

  /*
    step 3: 
    blue -> destination
    yellow -> destination
    purple -> source
    yellow -> source 
    orange -> destination
  */
  move_cube(this->_stack_scr, this->_stack_des);
  move_cube(this->_stack_trans, this->_stack_des);
  move_cube(this->_stack_trans, this->_stack_scr);
  move_cube(this->_stack_des, this->_stack_scr);
  move_cube(this->_stack_trans, this->_stack_des);

  /*
    step 4: 
    yellow -> middle
    purple -> destination
    yellow -> destination
  */
  move_cube(this->_stack_scr, this->_stack_trans);
  move_cube(this->_stack_scr, this->_stack_des);
  move_cube(this->_stack_trans, this->_stack_des);
  print_m_stack();
}

void Game::print_m_stack(){
  std::cout << "source stack's length is: " << std::endl;
  _stack_scr.print_stack();
  std::cout << "trans stack's length is: " << std::endl;
  _stack_trans.print_stack();
  std::cout << "destination stack's length is: " << std::endl;
  _stack_des.print_stack();
}
