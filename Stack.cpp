//
//  Stack.cpp
//  
//
//  Created by Edward Duque on 2/20/23.
//

#include "Stack.hpp"

using namespace std;
//top returns the top of the stack.
Polynomial
Stack::top() const
{
  return accu.front();
}
//deletes the top of the stack.
Polynomial
Stack::pop()
{
  Polynomial answer = top();
  accu.pop_front();
  return answer;
}
//adds a new element to the stack.
void
Stack::push(Polynomial newPoly)
{
  accu.push_front(newPoly);
}
//empties the stack.
bool
Stack::isEmpty() const
{
  return accu.empty();
}
