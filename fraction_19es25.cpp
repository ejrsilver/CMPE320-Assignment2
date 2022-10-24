//
//  main.cpp
//  CMPE320-Assignment2
//
//  Created by Ethan Silver on 2022-10-18.
//

#include "fraction_19es25.h"
#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

const char * FractionException::what() const throw() {
  return "Invalid Fraction! Cannot divide by zero!";
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
    return b;
  }
  else {
    int rem = b % a;
    while(rem != 0) {
      b = a;
      a = rem;
      rem = b%a;
    }
    return a;
  }
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
    d = abs(d);
    n = -n;
  }
  int div = gcd(abs(n),d);
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
Fraction &Fraction::operator-() {
  this->num = -this->num;
  return *this;
}
// Define prefix increment operator.
Fraction& Fraction::operator++() {
  num+=denom;
  return *this;
}
// Define postfix increment operator.
Fraction Fraction::operator++(int) {
   Fraction temp = *this;
   ++*this;
   return temp;
}
// Define prefix decrement operator.
Fraction& Fraction::operator--() {
  num-=denom;
  return *this;
}
// Define postfix decrement operator.
Fraction Fraction::operator--(int) {
   Fraction temp = *this;
   --*this;
   return temp;
}

// Overload Stream operators
ostream &operator<<( ostream &output, const Fraction &F ) {
  output << F.num << "/" << F.denom;
  return output;
}
istream &operator>>( istream  &input, Fraction &F ) {
  string sinput;
  input >> sinput;
  
  unsigned long idelim = sinput.find('/');
  
  // If there's no fraction identifier
  if(idelim > sinput.length()) {
    F.num = stoi(sinput);
    F.denom = 1;
  }
  else {
    F.num = stoi(sinput.substr(0, idelim));
    F.denom = stoi(sinput.substr(idelim+1));
  }
  
  return input;
}

// Compare num and denom and return equality.
bool operator==(const Fraction &F1, const Fraction &F2) {
  return ((F1.num == F2.num) && (F1.denom == F2.denom));
}
bool operator==(int i, const Fraction &F)       {  return F.num == i*F.denom;  }
bool operator==(const Fraction &F, int i)       {  return F.num == i*F.denom;  }
bool operator==(double d, const Fraction &F)    {  return ((double)F.num)/((double)F.denom) == d;  }
bool operator==(const Fraction &F, double d)    {  return ((double)F.num)/((double)F.denom) == d;  }

// Inequality
bool operator!=(const Fraction &F1, const Fraction &F2) {
  return ((F1.num != F2.num) && (F1.denom != F2.denom));
}
bool operator!=(int i, const Fraction &F)       {  return F.num != i*F.denom;  }
bool operator!=(const Fraction &F, int i)       {  return F.num != i*F.denom;  }
bool operator!=(double d, const Fraction &F)    {  return ((double)F.num)/((double)F.denom) != d;  }
bool operator!=(const Fraction &F, double d)    {  return ((double)F.num)/((double)F.denom) != d;  }

// Greater
bool operator>(const Fraction &F1, const Fraction &F2) {
  return (F1.num*F2.denom > F2.num*F1.denom);
}
bool operator>(int i, const Fraction &F)        {  return !(F.num > i*F.denom);  }
bool operator>(const Fraction &F, int i)        {  return F.num > i*F.denom;  }
bool operator>(double d, const Fraction &F)     {  return !((double)F.num)/((double)F.denom) > d;  }
bool operator>(const Fraction &F, double d)     {  return ((double)F.num)/((double)F.denom) > d;  }

// Equality or Greater
bool operator>=(const Fraction &F1, const Fraction &F2) {
  return (F1.num*F2.denom >= F2.num*F1.denom);
}
bool operator>=(int i, const Fraction &F)       {  return !(F.num >= i*F.denom);  }
bool operator>=(const Fraction &F, int i)       {  return F.num >= i*F.denom;  }
bool operator>=(double d, const Fraction &F)    {  return !((double)F.num)/((double)F.denom) >= d;  }
bool operator>=(const Fraction &F, double d)    {  return ((double)F.num)/((double)F.denom) >= d;  }

// Equality or Lesser
bool operator<=(const Fraction &F1, const Fraction &F2) {
  return (F1.num*F2.denom <= F2.num*F1.denom);
}
bool operator<=(int i, const Fraction &F)       {  return !(F.num <= i*F.denom);  }
bool operator<=(const Fraction &F, int i)       {  return F.num <= i*F.denom;  }
bool operator<=(double d, const Fraction &F)    {  return !((double)F.num)/((double)F.denom) <= d;  }
bool operator<=(const Fraction &F, double d)    {  return ((double)F.num)/((double)F.denom) <= d;  }

// Lesser
bool operator<(const Fraction &F1, const Fraction &F2) {
  return (F1.num*F2.denom < F2.num*F1.denom);
}
bool operator<(int i, const Fraction &F)        {  return !(F.num < i*F.denom);  }
bool operator<(const Fraction &F, int i)        {  return F.num < i*F.denom;  }
bool operator<(double d, const Fraction &F)     {  return !((double)F.num)/((double)F.denom) < d;  }
bool operator<(const Fraction &F, double d)     {  return ((double)F.num)/((double)F.denom) < d;  }

// Assignment Overloads (Added sensible extras)
Fraction& Fraction::operator+=(Fraction &F) {
  // Get new numerator and denominator.
  this->num = this->num*F.denom + this->denom*F.num;
  this->denom *= F.denom;
  // Get simplest representation.
  int c = gcd(this->num, this->denom);
  if(c == 0) {
    return *this;
  }
  // Simplify fraction
  this->num /= c;
  this->denom /= c;
  return *this;
}
Fraction& Fraction::operator-=(Fraction &F) {
  // Get new numerator and denominator.
  this->num = this->num*F.denom - this->denom*F.num;
  this->denom *= F.denom;
  // Get simplest representation.
  int c = gcd(this->num, this->denom);
  if(c == 0) {
    return *this;
  }
  this->num /= c;
  this->denom /= c;
  return *this;
}
Fraction& Fraction::operator*=(Fraction &F) {
  // Get new numerator and denominator.
  this->num *= F.num;
  this->denom *= F.denom;
  // Get simplest representation.
  int c = gcd(this->num, this->denom);
  if(c == 0) {
    return *this;
  }
  this->num /= c;
  this->denom /= c;
  return *this;
}
Fraction& Fraction::operator/=(Fraction &F) {
  // Get new numerator and denominator.
  this->num *= F.denom;
  this->denom *= F.num;
  // Get simplest representation.
  int c = gcd(this->num, this->denom);
  if(c == 0) {
    return *this;
  }
  this->num /= c;
  this->denom /= c;
  return *this;
}

Fraction& Fraction::operator+=(int i) {
  // Get new numerator and denominator.
  this->num += this->denom*i;
  // Get simplest representation.
  int c = gcd(this->num, this->denom);
  if(c == 0) {
    return *this;
  }
  this->num /= c;
  this->denom /= c;
  return *this;
}
Fraction& Fraction::operator-=(int i) {
  // Get new numerator and denominator.
  this->num -= this->denom*i;
  // Get simplest representation.
  int c = gcd(this->num, this->denom);
  if(c == 0) {
    return *this;
  }
  this->num /= c;
  this->denom /= c;
  return *this;
}
Fraction& Fraction::operator*=(int i) {
  // Get new numerator.
  this->num*=i;
  // Get simplest representation.
  int c = gcd(this->num, this->denom);
  if(c == 0) {
    return *this;
  }
  this->num /= c;
  this->denom /= c;
  return *this;
}
Fraction& Fraction::operator/=(int i) {
  // Get new denominator.
  this->denom *=i;
  // Get simplest representation.
  int c = gcd(this->num, this->denom);
  if(c == 0) {
    return *this;
  }
  this->num /= c;
  this->denom /= c;
  return *this;
  return *this;
}

// Addition overloads
Fraction operator+(const Fraction &F1, const Fraction &F2) {
  return Fraction(F1.num*F2.denom + F2.num*F1.denom, F1.denom*F2.denom);
}
Fraction operator+(int i, const Fraction &F) {
  return Fraction(F.num + i*F.denom, F.denom);
}
Fraction operator+(const Fraction &F, int i) {
  return Fraction(F.num + i*F.denom, F.denom);
}

// Subtraction overloads
Fraction operator-(const Fraction &F1, const Fraction &F2) {
  return Fraction(F1.num*F2.denom - F2.num*F1.denom, F1.denom*F2.denom);
}
Fraction operator-(int i, const Fraction &F) {
  return Fraction(i*F.denom - F.num, F.denom);
}
Fraction operator-(const Fraction &F, int i) {
  return Fraction(F.num - i*F.denom, F.denom);
}

// Multiplication overloads
Fraction operator*(const Fraction &F1, const Fraction &F2) {
  return Fraction(F1.num*F2.num, F1.denom*F2.denom);
}
Fraction operator*(int i, const Fraction &F) {
  return Fraction(F.num*i, F.denom);
}
Fraction operator*(const Fraction &F, int i) {
  return Fraction(F.num*i, F.denom);
}

// Division overloads
Fraction operator/(const Fraction &F1, const Fraction &F2) {
  return Fraction(F1.num*F2.denom, F1.denom*F2.num);
}
Fraction operator/(int i, const Fraction &F) {
  return Fraction(F.denom*i, F.num);
}
Fraction operator/(const Fraction &F, int i) {
  return Fraction(F.num, F.denom*i);
}
