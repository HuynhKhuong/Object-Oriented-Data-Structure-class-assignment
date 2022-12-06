#ifndef __PAIR_H__
#define __PAIR_H__

namespace my_own_space{
class Pair{
  public: 
  Pair(void) = default;
  ~Pair(void) = default;
  int sum(void); 

  public:
  int a;
  int b;
};
}

#endif