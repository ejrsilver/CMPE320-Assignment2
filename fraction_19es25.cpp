//
//  main.cpp
//  CMPE320-Assignment2
//
//  Created by Ethan Silver on 2022-10-18.
//

#include "fraction_19es25.h"
#include <stdexcept>
#include <iostream>

using namespace std;

const char * FractionException::what() const throw() {
  return "Invalid Fraction!";
}

int Fraction::gcd(int a, int b) {
  if (a == b) {
    return a;
  }
  else if (a > b) {
    int rem = a % b;
    while(rem != 0) {
      a = b;
      b = rem;
      rem = a%b;
    }
  }
  else {
    int rem = b % a;
    while(rem != 0) {
      b = a;
      a = rem;
      rem = b%a;
    }
  }
  
  return b;
}

Fraction::Fraction() {
  num = 0;
  denom = 1;
}
Fraction::Fraction(int n) {
  num = n;
  denom = 1;
}
Fraction::Fraction(int n, int d){
  if (d == 0) {
    throw FractionException();
  }
  // If the denominator is negative, move the negative to the numerator.
  else if(d < 0) {
    d = +d;
    n = -n;
  }
  int div = gcd(n,d);
  num = n/div;
  denom = d/div;
}

int Fraction::numerator(){
  return num;
}
int Fraction::denominator(){
  return denom;
}

/* Overloads */
// Unary Overloads
Fraction &Fraction::operator+(Fraction &F) {
  F.num = +F.num;
  return F;
}
Fraction &Fraction::operator-(Fraction &F) {
  F.num = -F.num;
  return F;
}
// Prefix
Fraction &Fraction::operator++() {
  this->num+=this->denom;
  return *this;
}
// Postfix
Fraction &Fraction::operator++(int) {
  Fraction * temp = this;
  this->num+=this->denom;
  return *temp;
}

ostream &operator<<( ostream &output, const Fraction &F ) {
  output << F.num << "/" << F.denom;
  return output;
}
istream &operator>>( istream  &input, Fraction &F ) {
  input >> F.num >> F.denom;
  return input;
}

// Compare num and denom and return equality.
bool operator==(const Fraction &F1, const Fraction &F2) {
  return ((F1.num == F2.num) && (F1.denom == F2.denom));
}
bool operator==(int i, const Fraction &F)       {  return F.num == i*F.denom;  }
bool operator==(const Fraction &F, int i)       {  return F.num == i*F.denom;  }
bool operator==(double d, const Fraction &F)    {  return F.num == d*F.denom;  }
bool operator==(const Fraction &F, double d)    {  return F.num == d*F.denom;  }

// Inequality
bool operator!=(const Fraction &F1, const Fraction &F2) {
  return ((F1.num != F2.num) && (F1.denom != F2.denom));
}
bool operator!=(int i, const Fraction &F)       {  return F.num != i*F.denom;  }
bool operator!=(const Fraction &F, int i)       {  return F.num != i*F.denom;  }
bool operator!=(double d, const Fraction &F)    {  return F.num != d*F.denom;  }
bool operator!=(const Fraction &F, double d)    {  return F.num != d*F.denom;  }

// Greater
bool operator>(const Fraction &F1, const Fraction &F2) {
  return (F1.num*F2.denom > F2.num*F1.denom);
}
bool operator>(int i, const Fraction &F)        {  return F.num > i*F.denom;  }
bool operator>(const Fraction &F, int i)        {  return F.num > i*F.denom;  }
bool operator>(double d, const Fraction &F)     {  return F.num > d*F.denom;  }
bool operator>(const Fraction &F, double d)     {  return F.num > d*F.denom;  }

// Equality or Greater
bool operator>=(const Fraction &F1, const Fraction &F2) {
  return (F1.num*F2.denom >= F2.num*F1.denom);
}
bool operator>=(int i, const Fraction &F)       {  return F.num >= i*F.denom;  }
bool operator>=(const Fraction &F, int i)       {  return F.num >= i*F.denom;  }
bool operator>=(double d, const Fraction &F)    {  return F.num >= d*F.denom;  }
bool operator>=(const Fraction &F, double d)    {  return F.num >= d*F.denom;  }

// Equality or Lesser
bool operator<=(const Fraction &F1, const Fraction &F2) {
  return (F1.num*F2.denom <= F2.num*F1.denom);
}
bool operator<=(int i, const Fraction &F)       {  return F.num >= i*F.denom;  }
bool operator<=(const Fraction &F, int i)       {  return F.num >= i*F.denom;  }
bool operator<=(double d, const Fraction &F)    {  return F.num >= d*F.denom;  }
bool operator<=(const Fraction &F, double d)    {  return F.num >= d*F.denom;  }

// Lesser
bool operator<(const Fraction &F1, const Fraction &F2) {
  return (F1.num*F2.denom < F2.num*F1.denom);
}
bool operator<(int i, const Fraction &F)        {  return F.num >= i*F.denom;  }
bool operator<(const Fraction &F, int i)        {  return F.num >= i*F.denom;  }
bool operator<(double d, const Fraction &F)     {  return F.num >= d*F.denom;  }
bool operator<(const Fraction &F, double d)     {  return F.num >= d*F.denom;  }

// Assignment Overloads (Added sensible extras)
Fraction& Fraction::operator+=(Fraction &F) {
  return (*this + F);
}
Fraction& Fraction::operator-=(Fraction &F) {
  return (*this - F);
}
Fraction& Fraction::operator*=(Fraction &F) {
  return (*this * F);
}
Fraction& Fraction::operator/=(Fraction &F) {
  return (*this / F);
}

Fraction& Fraction::operator+=(int i) {
  this->num += i*this->denom;
  return *this;
}
Fraction& Fraction::operator-=(int i) {
  this->num -= i*this->denom;
  return *this;
}
Fraction& Fraction::operator*=(int i) {
  this->num *=i;
  return *this;
}
Fraction& Fraction::operator/=(int i) {
  this->denom *=i;
  return *this;
}

// Addition overloads
Fraction &operator+(const Fraction &F1, const Fraction &F2) {
  Fraction * temp = nullptr;
  *temp = Fraction(F1.num*F2.denom + F2.num*F1.denom, F1.denom*F2.denom);
  return *temp;
}
Fraction &operator+(int i, const Fraction &F) {
  Fraction * temp = nullptr;
  *temp = Fraction(F.num + i*F.denom, F.denom);
  return *temp;
}
Fraction &operator+(const Fraction &F, int i) {
  Fraction * temp = nullptr;
  *temp = Fraction(F.num + i*F.denom, F.denom);
  return *temp;
}

// Subtraction overloads
Fraction &operator-(const Fraction &F1, const Fraction &F2) {
  Fraction * temp = nullptr;
  *temp = Fraction(F1.num*F2.denom - F2.num*F1.denom, F1.denom*F2.denom);
  return *temp;
}
Fraction &operator-(int i, const Fraction &F) {
  Fraction * temp = nullptr;
  *temp = Fraction(F.num - i*F.denom, F.denom);
  return *temp;
}
Fraction &operator-(const Fraction &F, int i) {
  Fraction * temp = nullptr;
  *temp = Fraction(F.num - i*F.denom, F.denom);
  return *temp;
}

// Multiplication overloads
Fraction &operator*(const Fraction &F1, const Fraction &F2) {
  Fraction * temp = nullptr;
  *temp = Fraction(F1.num*F2.num, F1.denom*F2.denom);
  return *temp;
}
Fraction &operator*(int i, const Fraction &F) {
  Fraction * temp = nullptr;
  *temp = Fraction(F.num*i, F.denom);
  return *temp;
}
Fraction &operator*(const Fraction &F, int i) {
  Fraction * temp = nullptr;
  *temp = Fraction(F.num*i, F.denom);
  return *temp;
}

// Division overloads
Fraction &operator/(const Fraction &F1, const Fraction &F2) {
  Fraction * temp = nullptr;
  *temp = Fraction(F1.num*F2.denom, F1.denom*F2.num);
  return *temp;
}
Fraction &operator/(int i, const Fraction &F) {
  Fraction * temp = nullptr;
  *temp = Fraction(F.num, F.denom*i);
  return *temp;
}
Fraction &operator/(const Fraction &F, int i) {
  Fraction * temp = nullptr;
  *temp = Fraction(F.num, F.denom*i);
  return *temp;
}
