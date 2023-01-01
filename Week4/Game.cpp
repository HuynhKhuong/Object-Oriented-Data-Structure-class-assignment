#include "Game.hpp"

Game::Game():Stack(){
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

  Push_Stack(blue_cube);
  Push_Stack(orange_cube);
  Push_Stack(purple_cube);
  Push_Stack(yellow_cube);

}

void Game::solve(){
  //pre-declaration, no logic inside
}