//
//  fraction.h
//  CMPE320-Assignment2
//
//  Created by Ethan Silver on 2022-10-18.
//

#include <stdexcept>


#ifndef fraction_h
#define fraction_h

class FractionException:public exception {
  public:
  const char * what() const throw();
};

class Fraction {
public:
  Fraction();
  Fraction(int num);
  Fraction(int num, int denom);
  
  int numerator();
  int denominator();
  
private:
  int num;
  int denom;
  
  int gcd(int num, int denom);
};

#endif /* fraction_h */
