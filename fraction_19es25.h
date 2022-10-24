//
//  fraction.h
//  CMPE320-Assignment2
//
//  Created by Ethan Silver on 2022-10-18.
//

#include <stdexcept>
#include <iostream>
#ifndef fraction_19es25_h
#define fraction_19es25_h

class FractionException:public std::exception {
  public:
  const char * what() const throw();
};

class Fraction {
private:
  int num;
  int denom;
  
  int gcd(int n, int d);
  
public:
  // Constructors
  Fraction();
  Fraction(int n);
  Fraction(int n, int d);
  
  // Accessors
  int numerator();
  int denominator();

  // Unary Overloads
  Fraction &operator-();
  Fraction &operator++();       // Prefix
  Fraction operator++(int);  // Postfix
  Fraction &operator--();       // Prefix
  Fraction operator--(int);  // Postfix
  
  // Equality (Covering all reasonably comparable types)
  friend bool operator==(const Fraction &F1, const Fraction &F2);
  friend bool operator==(int i, const Fraction &F);
  friend bool operator==(const Fraction &F, int i);
  friend bool operator==(double i, const Fraction &F);
  friend bool operator==(const Fraction &F, double i);

  // Inequality
  friend bool operator!=(const Fraction &F1, const Fraction &F2);
  friend bool operator!=(int i, const Fraction &F);
  friend bool operator!=(const Fraction &F, int i);
  friend bool operator!=(double i, const Fraction &F);
  friend bool operator!=(const Fraction &F, double i);
  
  // Greater
  friend bool operator>(const Fraction &F1, const Fraction &F2);
  friend bool operator>(int i, const Fraction &F);
  friend bool operator>(const Fraction &F, int i);
  friend bool operator>(double i, const Fraction &F);
  friend bool operator>(const Fraction &F, double i);
  
  // Equality or Greater
  friend bool operator>=(const Fraction &F1, const Fraction &F2);
  friend bool operator>=(int i, const Fraction &F);
  friend bool operator>=(const Fraction &F, int i);
  friend bool operator>=(double i, const Fraction &F);
  friend bool operator>=(const Fraction &F, double i);
  
  // Equality or Lesser
  friend bool operator<=(const Fraction &F1, const Fraction &F2);
  friend bool operator<=(int i, const Fraction &F);
  friend bool operator<=(const Fraction &F, int i);
  friend bool operator<=(double i, const Fraction &F);
  friend bool operator<=(const Fraction &F, double i);
  
  // Lesser
  friend bool operator<(const Fraction &F1, const Fraction &F2);
  friend bool operator<(int i, const Fraction &F);
  friend bool operator<(const Fraction &F, int i);
  friend bool operator<(double i, const Fraction &F);
  friend bool operator<(const Fraction &F, double i);

  /* Binary Overloads */
  
  // Stream overloads
  friend std::ostream &operator<<(std::ostream &output, const Fraction &F);
  friend std::istream &operator>>(std::istream  &input, Fraction &F);
  
  // Assignment Overloads (Added sensible extras)
   Fraction &operator+=(Fraction &F);
   Fraction &operator-=(Fraction &F);
   Fraction &operator*=(Fraction &F);
   Fraction &operator/=(Fraction &F);
  
   Fraction &operator+=(int i);
   Fraction &operator-=(int i);
   Fraction &operator*=(int i);
   Fraction &operator/=(int i);

  // Addition overloads
  friend Fraction operator+(const Fraction &F1, const Fraction &F2);
  friend Fraction operator+(int i, const Fraction &F);
  friend Fraction operator+(const Fraction &F1, int i);
  
  // Subtraction overloads
  friend Fraction operator-(const Fraction &F1, const Fraction &F2);
  friend Fraction operator-(int i, const Fraction &F);
  friend Fraction operator-(const Fraction &F1, int i);

  // Multiplication overloads
  friend Fraction operator*(const Fraction &F1, const Fraction &F2);
  friend Fraction operator*(int i, const Fraction &F);
  friend Fraction operator*(const Fraction &F1, int i);
  
  // Division overloads
  friend Fraction operator/(const Fraction &F1, const Fraction &F2);
  friend Fraction operator/(int i, const Fraction &F);
  friend Fraction operator/(const Fraction &F1, int i);
  
};

#endif /* fraction_h */
