//
//  fraction.h
//  CMPE320-Assignment2
//
//  Created by Ethan Silver on 2022-10-18.
//

#include <stdexcept>
#include <iostream>
#ifndef fraction_h
#define fraction_h

using namespace std;

class FractionException:public exception {
  public:
  const char * what() const throw();
};

class Fraction {
private:
  int num;
  int denom;
  
  int gcd(int n, int d);
  
public:
  Fraction();
  Fraction(int n);
  Fraction(int n, int d);
  
  int numerator();
  int denominator();

  // Unary Overloads
  friend Fraction &operator+(Fraction &F);
  friend Fraction &operator-(Fraction &F);
  friend Fraction &operator++(Fraction);       // Prefix
  friend Fraction &operator++(Fraction, int);  // Postfix
  
  // Equality (Covering all reasonably comparable types)
  friend bool operator==(const Fraction &F1, const Fraction &F2);
  friend bool operator==(int i, const Fraction &F);
  friend bool operator==(const Fraction &F1, int i);
  friend bool operator==(float i, const Fraction &F);
  friend bool operator==(const Fraction &F1, float i);
  friend bool operator==(double i, const Fraction &F);
  friend bool operator==(const Fraction &F1, double i);
  friend bool operator==(long i, const Fraction &F);
  friend bool operator==(const Fraction &F1, long i);
  friend bool operator==(short i, const Fraction &F);
  friend bool operator==(const Fraction &F1, short i);
  friend bool operator==(long long i, const Fraction &F);
  friend bool operator==(const Fraction &F1, long long i);

  // Inequality
  friend bool operator!=(const Fraction &F1, const Fraction &F2);
  friend bool operator!=(int i, const Fraction &F);
  friend bool operator!=(const Fraction &F1, int i);
  friend bool operator!=(float i, const Fraction &F);
  friend bool operator!=(const Fraction &F1, float i);
  friend bool operator!=(double i, const Fraction &F);
  friend bool operator!=(const Fraction &F1, double i);
  friend bool operator!=(long i, const Fraction &F);
  friend bool operator!=(const Fraction &F1, long i);
  friend bool operator!=(short i, const Fraction &F);
  friend bool operator!=(const Fraction &F1, short i);
  friend bool operator!=(long long i, const Fraction &F);
  friend bool operator!=(const Fraction &F1, long long i);
  
  // Greater
  friend bool operator>(const Fraction &F1, const Fraction &F2);
  friend bool operator>(int i, const Fraction &F);
  friend bool operator>(const Fraction &F1, int i);
  friend bool operator>(float i, const Fraction &F);
  friend bool operator>(const Fraction &F1, float i);
  friend bool operator>(double i, const Fraction &F);
  friend bool operator>(const Fraction &F1, double i);
  friend bool operator>(long i, const Fraction &F);
  friend bool operator>(const Fraction &F1, long i);
  friend bool operator>(short i, const Fraction &F);
  friend bool operator>(const Fraction &F1, short i);
  friend bool operator>(long long i, const Fraction &F);
  friend bool operator>(const Fraction &F1, long long i);
  
  // Equality or Greater
  friend bool operator>=(const Fraction &F1, const Fraction &F2);
  friend bool operator>=(int i, const Fraction &F);
  friend bool operator>=(const Fraction &F1, int i);
  friend bool operator>=(float i, const Fraction &F);
  friend bool operator>=(const Fraction &F1, float i);
  friend bool operator>=(double i, const Fraction &F);
  friend bool operator>=(const Fraction &F1, double i);
  friend bool operator>=(long i, const Fraction &F);
  friend bool operator>=(const Fraction &F1, long i);
  friend bool operator>=(short i, const Fraction &F);
  friend bool operator>=(const Fraction &F1, short i);
  friend bool operator>=(long long i, const Fraction &F);
  friend bool operator>=(const Fraction &F1, long long i);
  
  // Equality or Lesser
  friend bool operator<=(const Fraction &F1, const Fraction &F2);
  friend bool operator<=(int i, const Fraction &F);
  friend bool operator<=(const Fraction &F1, int i);
  friend bool operator<=(float i, const Fraction &F);
  friend bool operator<=(const Fraction &F1, float i);
  friend bool operator<=(double i, const Fraction &F);
  friend bool operator<=(const Fraction &F1, double i);
  friend bool operator<=(long i, const Fraction &F);
  friend bool operator<=(const Fraction &F1, long i);
  friend bool operator<=(short i, const Fraction &F);
  friend bool operator<=(const Fraction &F1, short i);
  friend bool operator<=(long long i, const Fraction &F);
  friend bool operator<=(const Fraction &F1, long long i);
  
  // Lesser
  friend bool operator<(const Fraction &F1, const Fraction &F2);
  friend bool operator<(int i, const Fraction &F);
  friend bool operator<(const Fraction &F1, int i);
  friend bool operator<(float i, const Fraction &F);
  friend bool operator<(const Fraction &F1, float i);
  friend bool operator<(double i, const Fraction &F);
  friend bool operator<(const Fraction &F1, double i);
  friend bool operator<(long i, const Fraction &F);
  friend bool operator<(const Fraction &F1, long i);
  friend bool operator<(short i, const Fraction &F);
  friend bool operator<(const Fraction &F1, short i);
  friend bool operator<(long long i, const Fraction &F);
  friend bool operator<(const Fraction &F1, long long i);

  /* Binary Overloads */
  
  // Stream overloads
  friend ostream &operator<<(ostream &output, const Fraction &F);
  friend istream &operator>>(istream  &input, Fraction &F);
  
  // Assignment Overloads (Added sensible extras)
  Fraction operator+=(Fraction &F2);
  Fraction operator-=(Fraction &F2);
  Fraction operator*=(Fraction &F2);
  Fraction operator/=(Fraction &F2);
  
  // Addition overloads
  friend Fraction &operator+(const Fraction &F1, const Fraction &F2);
  friend Fraction &operator+(int i, const Fraction &F);
  friend Fraction &operator+(const Fraction &F1, int i);
  friend Fraction &operator+(float i, const Fraction &F);
  friend Fraction &operator+(const Fraction &F1, float i);
  friend Fraction &operator+(double i, const Fraction &F);
  friend Fraction &operator+(const Fraction &F1, double i);
  friend Fraction &operator+(long i, const Fraction &F);
  friend Fraction &operator+(const Fraction &F1, long i);
  friend Fraction &operator+(short i, const Fraction &F);
  friend Fraction &operator+(const Fraction &F1, short i);
  friend Fraction &operator+(long long i, const Fraction &F);
  friend Fraction &operator+(const Fraction &F1, long long i);
  
  // Subtraction overloads
  friend Fraction &operator-(const Fraction &F1, const Fraction &F2);
  friend Fraction &operator-(int i, const Fraction &F);
  friend Fraction &operator-(const Fraction &F1, int i);
  friend Fraction &operator-(float i, const Fraction &F);
  friend Fraction &operator-(const Fraction &F1, float i);
  friend Fraction &operator-(double i, const Fraction &F);
  friend Fraction &operator-(const Fraction &F1, double i);
  friend Fraction &operator-(long i, const Fraction &F);
  friend Fraction &operator-(const Fraction &F1, long i);
  friend Fraction &operator-(short i, const Fraction &F);
  friend Fraction &operator-(const Fraction &F1, short i);
  friend Fraction &operator-(long long i, const Fraction &F);
  friend Fraction &operator-(const Fraction &F1, long long i);

  // Multiplication overloads
  friend Fraction &operator*(const Fraction &F1, const Fraction &F2);
  friend Fraction &operator*(int i, const Fraction &F);
  friend Fraction &operator*(const Fraction &F1, int i);
  friend Fraction &operator*(float i, const Fraction &F);
  friend Fraction &operator*(const Fraction &F1, float i);
  friend Fraction &operator*(double i, const Fraction &F);
  friend Fraction &operator*(const Fraction &F1, double i);
  friend Fraction &operator*(long i, const Fraction &F);
  friend Fraction &operator*(const Fraction &F1, long i);
  friend Fraction &operator*(short i, const Fraction &F);
  friend Fraction &operator*(const Fraction &F1, short i);
  friend Fraction &operator*(long long i, const Fraction &F);
  friend Fraction &operator*(const Fraction &F1, long long i);
  
  // Division overloads
  friend Fraction &operator/(const Fraction &F1, const Fraction &F2);
  friend Fraction &operator/(int i, const Fraction &F);
  friend Fraction &operator/(const Fraction &F1, int i);
  friend Fraction &operator/(float i, const Fraction &F);
  friend Fraction &operator/(const Fraction &F1, float i);
  friend Fraction &operator/(double i, const Fraction &F);
  friend Fraction &operator/(const Fraction &F1, double i);
  friend Fraction &operator/(long i, const Fraction &F);
  friend Fraction &operator/(const Fraction &F1, long i);
  friend Fraction &operator/(short i, const Fraction &F);
  friend Fraction &operator/(const Fraction &F1, short i);
  friend Fraction &operator/(long long i, const Fraction &F);
  friend Fraction &operator/(const Fraction &F1, long long i);
  
};

#endif /* fraction_h */
