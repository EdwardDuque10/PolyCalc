//
//  Polynomial.h
//  
//
//  Created by Edward Duque on 2/14/23.
//

#ifndef Polynomial_hpp
#define Polynomial_hpp
#include "Term.hpp"

#include <iostream>
#include <list>

using namespace std;
//Creating Polynomial class.
class Polynomial
{
private:
    
    list<Term> poly;// list of terms to create Polynomial.
    
public:
    //Polynomial constructor.
    Polynomial(): poly() {};
    
    //Defining function to add two polynomials.
    Polynomial addPolynomials(Polynomial first);
    //Defining function to subtract two polynomials.
    Polynomial subtractPoly(Polynomial first);
    //Defining function to multiply two polynomials.
    Polynomial multiplyPoly(Polynomial first);
    //add term function.
    void addTerm(Term addition);
    //function to sort a polynomial.
    void order();
    //Defining function to evaluate a polynomial.
    float evaluatePoly(float nu);
    //methods for performing I/O.
    std::ostream& printPoly(std::ostream &os) const;
    std::istream& readPoly(std::istream &is);
    //overload << and >> for terms.
    friend std::ostream& operator<<(std::ostream &os, const Polynomial &p);
    friend std::istream& operator>>(std::istream &is, Polynomial &p);
   
    
    
    
    
    
    
};

#endif /* Polynomial_h */
