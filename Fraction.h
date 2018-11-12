#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>

using std::ostream;

class Fraction {
public:
  // Constructors
  Fraction();
  Fraction(int, int);

  // Accessor functions
  int numerator() const {
    return numerator_;
  }
  int denominator() const {
    return denominator_;
  }

  // Member functions
  Fraction& operator*=(int);
  Fraction& operator*=(const Fraction&);
  Fraction operator*(int) const;
  Fraction operator*(const Fraction&) const;

  Fraction& operator+=(int);
  Fraction& operator+=(const Fraction&);
  Fraction operator+(int) const;
  Fraction operator+(const Fraction&) const;

  Fraction& operator-=(int);
  Fraction& operator-=(const Fraction&);
  Fraction operator-(int) const;
  Fraction operator-(const Fraction&) const;

  Fraction& operator/=(int);
  Fraction& operator/=(const Fraction&);
  Fraction operator/(int) const;
  Fraction operator/(const Fraction&) const;

  bool operator==(const Fraction&) const;
  bool operator!=(const Fraction&) const;
  Fraction inverse() const;
private:
  int numerator_, denominator_;
  void normalize();
};

ostream& operator<<(ostream&, const Fraction&);

#endif
