#ifndef __PAIR_HPP__
#define __PAIR_HPP__

namespace pair{

class Pair{

public: 
  Pair(int a, int b);
  ~Pair();
  Pair(const Pair &other);
private: 
  int* pa;
  int* pb;
}

}


#endif