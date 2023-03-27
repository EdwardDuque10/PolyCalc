//
//  Polynomial.cpp
//  
//
//  Created by Edward Duque on 2/16/23.
//

#include <stdio.h>
#include "Polynomial.hpp"
#include <math.h>
#include <iostream>

using namespace std;

//Implementing addPolynomials function.
Polynomial
Polynomial::addPolynomials(Polynomial first)
{
    Polynomial *answer= new Polynomial();//Polynomial to store the answer.
    //goes through the terms in the polynomial.
    for(Term t1: poly)
    {
        answer->poly.push_back(t1);//each term is added to answer.
    }
    //goes through each term in polynomial "first".
    for(Term t2: first.poly)
    {
        bool isinside = false;//Initializing a bool variable to false.
        //goes through each term in Polynomial answer.
        for(Term &t3: answer->poly)
        {
            if(t2.degree() == t3.degree())//if both terms have same degree.
            {   //add the coefficients.
                t3.coefficient()= t2.coefficient() + t3.coefficient();
                isinside = true;//if this operation happens, isinside becomes true.
            }
        }
        //if terms don't have same coefficient.
        if(!isinside)
            //add t2 to answer.
            answer->poly.push_back(t2);
    }
    return *answer;//return answer.
}

//Implementing subtractPoly function.
Polynomial
Polynomial::subtractPoly(Polynomial first)
{
    Polynomial *answer= new Polynomial();//Polynomial to store the answer.
    
    //goes through the terms in the polynomial "first".
    for(Term t1: first.poly)
    {   //creating a new Term.
        Term t;
        t.coefficient() = t1.coefficient()*-1;/*multiplying the term by -1, so the
                                               subtraction can be performed.*/
        t.degree() = t1.degree();//T degree equals to t1 degree.
        answer->poly.push_back(t);//storing each term in Polynomial answer.
    }
    //goes through each term in Polynomial.
    for(Term t2: poly)
    {
        bool isinside = false;//Initializing a bool variable to false.
        //goes through each term in Polynomial answer.
        for(Term &t3: answer->poly)
        {
            if(t2.degree() == t3.degree())//if both terms have same degree.
            {
                t3.coefficient()= t2.coefficient() + t3.coefficient();//add the coefficients.
                isinside = true;//if this operation happens, isinside becomes true.
            }
        }
        //if terms don't have same coefficient.
        if(!isinside)
            answer->poly.push_back(t2);//add t2 to answer.
    }
    return *answer;//return answer.
}

//function to sort terms inside the Polynomial.
void
Polynomial::order()
{
    poly.sort();//sort function.
}

//addTerm function to avoid dulicates.
void
Polynomial::addTerm(Term addition)
{
    bool insert = true;//Initializing a bool variable to true.
    //goint through each term in the polynomial.
    for(Term &t1: poly)
    {   //if both terms have the same degree.
        if(t1.degree() == addition.degree())
        {
            t1.coefficient() += addition.coefficient();//add their coefficients.
            insert = false;//insert becomes false.
        }
    }
    //if insert.
    if(insert)
    {
        poly.push_back(addition);//add term "addition" to Polynomial.
    }
}

//Implementing the multiplyPoly function.
Polynomial
Polynomial::multiplyPoly(Polynomial first)
{
    Polynomial *answer= new Polynomial();//Polynomial to store the answer.
    
    Term t3;//Creating a new term.
    
    for(Term t1: first.poly)//Going through each term in the first Polynomial.
    {
        for(Term t2: poly)//Going through each term in the second Polynomial.
        {
                t3.coefficient()= t1.coefficient() * t2.coefficient();//Multiply both terms coefficients.
                t3.degree()= t1.degree() + t2.degree();//add both term degrees.
                answer->addTerm(t3);//add term to the list.
        }
        
    }
    return *answer;//return answer.
}

//implementing evaluatePoly function.
float
Polynomial::evaluatePoly(float nu)
{
    float suma = 0;//float variable sum.
    //go through each term in the polynomial.
    for(Term t: poly)
    {
        float potence = 0;
        potence = pow(nu, t.degree());//Potence equal nu to the power of t.degree().
        
        float coef = potence * t.coefficient();//coefficient equal to potence times coefficient.
        suma += coef;//sum equals sum plus coefficient.
    }
    return suma;//returns the total of the operation.
}

//implementing readPoly function.
istream&
Polynomial::readPoly(istream &is)
{
    Term t;
    is>>t; // read first term from polynomial
    
    while(t.coefficient()!= 0)// as long as term just read was not the "terminating" term (";") ...
    {
        poly.push_back(t);// add the new term to the list
        is>>t;// try to read another term ...
    }
    return is;
}

//Prints the list of terms(Polynomial).
ostream&
Polynomial::printPoly(ostream &os) const
{
    bool firstTerm=true;
    for(Term nextTerm:poly)
    {
        if (nextTerm.coefficient()>0 && !firstTerm)
            os << '+';
        os << nextTerm;
        firstTerm=false;
    }
    os << endl;
    return os;
}

// overload << for output using print() to do so.
ostream& operator<<(ostream &os, const Polynomial &p)
{
  return p.printPoly(os);
}

// overload >> for input using read() to do so.
istream& operator>>(istream &is, Polynomial &p)
{
  return p.readPoly(is);
}
    
    
    
    



