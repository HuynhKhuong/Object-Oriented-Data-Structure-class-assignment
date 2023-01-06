#include "Game_solution2.hpp"
#include <iostream>

void Game_solution2::_strategy_move_cube(stack::Stack &source_cont, stack::Stack &destination){
  double src_cnt_length = source_cont.get_Stack_length();
  double des_cnt_length = destination.get_Stack_length();
  bool empty_both_b = ((src_cnt_length == 0) && (des_cnt_length == 0));

  if(empty_both_b) return;
  
  if(src_cnt_length == 0){
    move_cube(destination, source_cont);
    return;
  }

  if(des_cnt_length == 0){
    move_cube(source_cont, destination);
    return;
  }

  double src_cnt_top_length = source_cont.get_top_stack().get_length();
  double des_cnt_top_length = destination.get_top_stack().get_length();

  if(src_cnt_top_length < des_cnt_top_length ){
    move_cube(source_cont, destination);
    return;
  }
  
  if (src_cnt_top_length > des_cnt_top_length ){
    move_cube(destination, source_cont);
    return;
  }
}

void Game_solution2::solve() {
  std::cout << "Solution 2" << std::endl;
  while(_stack_des.get_Stack_length() < 4){
    std::cout << "-----------------------------" << std::endl;

    _strategy_move_cube(_stack_scr,_stack_trans);
    _strategy_move_cube(_stack_scr,_stack_des);
    _strategy_move_cube(_stack_des,_stack_trans);
    print_m_stack();
  }
}