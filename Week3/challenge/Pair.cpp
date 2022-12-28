#include "Pair.hpp"

using namespace pair;

Pair::Pair(int a, int b){
  this->pa = new int;
  this->pb = new int;

  *(this->pa) = a;
  *(this->pb) = b;
}

Pair::Pair(const Pair & other){
  this->pa = new int;
  this->pb = new int;
  *(this->pa) = other.pa;
  *(this->pb) = other.pb;
}
Pair::~Pair(){
  delete pa;
  delete pb;
}
