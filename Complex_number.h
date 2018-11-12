#ifndef COMPLEX_NUMBER_H
#define COMPLEX_NUMBER_H
#include "Fraction.h"
#include <iostream>

using std::ostream;

class Complex_number {
public:
  // Constructors
  Complex_number() {};
  Complex_number(Fraction, Fraction);
  Complex_number(int, int, int, int);

  // Accessor functions
  Fraction re() const {
    return re_;
  }
  Fraction im() const {
    return im_;
  }

  // Member functions
  Complex_number& operator+=(const Complex_number&);
  Complex_number operator+(const Complex_number&) const;

  Complex_number& operator-=(const Complex_number&);
  Complex_number operator-(const Complex_number&) const;

  Complex_number& operator*=(const Complex_number&);
  Complex_number operator*(const Complex_number&) const;

  Complex_number& operator/=(const Complex_number&);
  Complex_number operator/(const Complex_number&) const;

  bool operator==(const Complex_number&) const;
  bool operator!=(const Complex_number&) const;
  Complex_number inverse() const;
private:
  Fraction re_, im_;
};

ostream& operator<<(ostream&, const Complex_number&);

#endif
