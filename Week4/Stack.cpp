#include "Stack.hpp"
#include <iostream>
using namespace stack;

int Stack::get_Stack_length(){
  return this->ownCUBE.size();
}

my_cube::Cube& Stack::get_top_stack(){
  //as designed, Cube on the top stack has the biggest index
  int top_index_d = get_Stack_length();

  top_index_d = (top_index_d == 0)?top_index_d:(top_index_d - 1);

  return this->ownCUBE[top_index_d];
}

void Stack::remove_top_Stack(){
  this->ownCUBE.pop_back();
}

  /*
    @Description: Stack::Push_Stack would add an additional_cube on top of the stack
    However, the additional_cube's size must not bigger than the top cube on the stack
  */
void Stack::Push_Stack(const my_cube::Cube & additional_cube){

  bool stack_is_empty_b = (get_Stack_length() == 0); 
  
  if(stack_is_empty_b){
    this->ownCUBE.push_back(additional_cube);
  }
  else {
    my_cube::Cube tmp_Cube = get_top_stack();
    double top_cube_length = tmp_Cube.get_length();
    double additional_cube_length =additional_cube.get_length(); 

    if( top_cube_length > additional_cube_length){
      this->ownCUBE.push_back(additional_cube);
    }
  }
}

void Stack::print_stack(){
  bool stack_is_empty_b = (get_Stack_length() == 0); 
  if(stack_is_empty_b){
    std::cout << "Stack is empty" << std::endl;
  }
  else{
    std::cout << "stack length is: ";
    for(int i = 0; i < (get_Stack_length()); i++){
      std:: cout << this->ownCUBE[i].get_length() << " ";
    }
    std::cout << std::endl;
  }

}