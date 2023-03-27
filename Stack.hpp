//
//  Stack.hpp
//  
//
//  Created by Edward Duque on 2/20/23.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>
#include <list>
#include "Polynomial.hpp"

//Creating Stack class.
class Stack
{
private:
    std::list<Polynomial> accu;//list of Polynomials called accu.
public:
    //stack constructor.
  Stack(): accu() {}

    //top function.
  Polynomial top() const;
    //defining pop function.
  Polynomial pop();
    //defining push function.
  void push(Polynomial newPoly);
    //defining is empty function.
  bool isEmpty() const;
};

#endif /* Stack_hpp */
