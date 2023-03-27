//
//  main.cpp
//  Project2
//
//  Created by Edward Duque on 2/13/23.
//
#include <cstdlib>
#include <iostream>
#include "Polynomial.hpp"
#include "Stack.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    Stack myStack;//myStack used for the main.
    
    cout<< "Welcome to polyCalc!"<< endl;
    
    char operation;//char variable used for the operations.
    
    cout<< ">>>";
    cin>> operation;//input char.
    
    //while operation is not q, the program will run.
    while(operation!= 'q')
    {   //if operation is d, delete all elements from the accumulator
        if(operation == 'd')
        {
            myStack.isEmpty();//empties stack
        }
        //if operation is 's', a new polynomial will be stored.
        else if(operation == 's')
        {
            Polynomial p1;//Creating Polynomial.
            cout<< "Enter Polynomial to push: ";
            cin>> p1;//Input p1;
            p1.order();//sort the polynomial.
            myStack.push(p1);//add the polynomial on top.
            cout << myStack.top();//prints the top of the stack.
            
        }
        //if operation is '+', addPolynomials will be performed.
        else if(operation == '+')
        {
            Polynomial sum;//Polynomial to store the sum.
            Polynomial first = myStack.top();//equals top of the stack.
            myStack.pop();//deletes top of the stack.
            sum = first.addPolynomials(myStack.top());//Polynomial 'first' plus top of the stack.
            sum.order();//sorts the polynomial.
            myStack.pop();//deletes top of the stack.
            myStack.push(sum);//adds the sum to top of the stack.
            cout<<sum;//prints the sum.

        }
        //if operation is '-', subtractPoly will be performed.
        else if(operation == '-')
        {
            Polynomial sub;//Polynomial to store the subtraction.
            Polynomial first = myStack.top();//equals top of the stack.
            myStack.pop();//deletes top of the stack.
            sub = first.subtractPoly(myStack.top());//Polynomial 'first' minus top of the stack.
            sub.order();//sorts the polynomial.
            myStack.pop();//deletes top of the stack.
            myStack.push(sub);//adds the result to top of the stack.
            cout<<sub;//prints the subtraction.
            
        }
        //if operation is '*', multiplyPoly will be performed.
        else if(operation == '*')
        {
            Polynomial mul;//Polynomial to store the multiplication.
            Polynomial first= myStack.top();//equals top of the stack.
            myStack.pop();//deletes top of the stack.
            mul= first.multiplyPoly(myStack.top());//Polynomial 'first' multiplied by top of the stack.
            mul.order();//sorts the polynomial.
            myStack.pop();//deletes top of the stack.
            myStack.push(mul);//adds the result to top of the stack.
            cout<< mul;//prints the multiplication.
            
        }
        
        //if operation is 'e', evaluatePoly will be performed.
        else if(operation == 'e')
        {
            cout<< "Enter a value to evaluate: ";
            float nu;//value to evaluate.
            cin>> nu;//input nu
            
            cout << myStack.top().evaluatePoly(nu)<< endl;//evaluates polynomial of the top of the stack.
            cout<<myStack.top();//prints the result.
        }
        //if operation is 'p', the program prints the top of the stack.
        else if(operation == 'p')
        {
            cout<< myStack.top();
        }
        //any other character is not valid.
        else
            cout<<"Not a valid operation."<<endl;
        
        cout<< ">>>";
        cin>> operation;
    }
    
    cout<< "Thanks for using polyCalc! "<<endl;
    return 0;
    
  
}
