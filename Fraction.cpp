#include "Fraction.h"
#include "gcd.h"

// Constructors
Fraction::Fraction(): numerator_(0), denominator_(1) {
  normalize();
}

Fraction::Fraction(int numerator, int denominator): numerator_(numerator), denominator_(denominator) {
  normalize();
}

// Member functions
Fraction& Fraction::operator*=(int multiplier) {
  numerator_ *= multiplier;
  return *this;
}

Fraction& Fraction::operator*=(const Fraction& other) {
  numerator_ *= other.numerator();
  denominator_ *= other.denominator();

  return *this;
}

Fraction Fraction::operator*(int multiplier) const {
  return Fraction(numerator_ * multiplier, denominator_);
}

Fraction Fraction::operator*(const Fraction& other) const {
  return Fraction(numerator_ * other.numerator(), denominator_ * other.denominator());
}

Fraction& Fraction::operator+=(int number) {
  numerator_ += number * denominator_;
  return *this;
}

Fraction& Fraction::operator+=(const Fraction& other) {
  numerator_ = numerator_ * other.denominator() + other.numerator() * denominator_;
  denominator_ *= other.denominator();
  return *this;
}

Fraction Fraction::operator+(int number) const {
  return Fraction(numerator_ + number * denominator_, denominator_);
}

Fraction Fraction::operator+(const Fraction& other) const {
  return Fraction(numerator_ * other.denominator() + other.numerator() * denominator_, denominator_ * other.denominator());
}

Fraction& Fraction::operator-=(int number) {
  numerator_ -= number * denominator_;
  return *this;
}

Fraction& Fraction::operator-=(const Fraction& other) {
  numerator_ = numerator_ * other.denominator() - other.numerator() * denominator_;
  denominator_ *= other.denominator();
  return *this;
}

Fraction Fraction::operator-(int number) const {
  return *this + number * -1;
}

Fraction Fraction::operator-(const Fraction& other) const {
  return *this + (other * -1);
}

Fraction& Fraction::operator/=(int number) {
  *this *= Fraction(1, number);
  return *this;
};

Fraction& Fraction::operator/=(const Fraction& other) {
  *this *= other.inverse();
  return *this;
};

Fraction Fraction::operator/(int number) const {
  return *this * Fraction(1, number);
};

Fraction Fraction::operator/(const Fraction& other) const {
  return *this * other.inverse();
};

bool Fraction::operator==(const Fraction& other) const {
  return numerator_ == other.numerator() && denominator_ == other.denominator();
}

bool Fraction::operator!=(const Fraction& other) const {
  return !(*this == other);
}

Fraction Fraction::inverse() const {
  return Fraction(denominator_, numerator_);
}

void Fraction::normalize() {
  int gcd_ = gcd(numerator_, denominator_);

  numerator_ /= gcd_;
  denominator_ /= gcd_;

  if (denominator_ < 0) {
    numerator_ *= -1;
    denominator_ *= -1;
  }
}

ostream& operator<<(ostream& os, const Fraction& fraction) {
  if (fraction.denominator() == 1) {
    os << fraction.numerator();
  } else {
    os << "(" << fraction.numerator() << "/" << fraction.denominator() << ")";
  }
  return os;
}
