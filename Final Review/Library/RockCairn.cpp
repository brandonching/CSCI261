#include "Stack.hpp"

class RockCairn {
 public:
  RockCairn();
  bool push(int);
  int pop();
  int size();

 private:
  Stack<int> cairn;
};