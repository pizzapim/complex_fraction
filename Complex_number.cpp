#include "Complex_number.h"
// Constructors
Complex_number::Complex_number(Fraction re, Fraction im) {
  re_ = re;
  im_ = im;
}

Complex_number::Complex_number(int re1, int re2, int im1, int im2) {
  re_ = Fraction(re1, re2);
  im_ = Fraction(im1, im2);
}

// Member functions
Complex_number& Complex_number::operator+=(const Complex_number& other) {
  re_ += other.re();
  im_ += other.im();

  return *this;
}

Complex_number Complex_number::operator+(const Complex_number& other) const {
  return Complex_number(re_ + other.re(), im_ + other.im());
}

Complex_number& Complex_number::operator*=(const Complex_number& other) {
  Fraction re_tmp = re_;

  re_ = re_ * other.re() - im_ * other.im();
  im_ = re_tmp * other.im() + im_ * other.re();

  return *this;
}

Complex_number Complex_number::operator*(const Complex_number& other) const {
  return Complex_number(re_ * other.re() - im_ * other.im(), re_ * other.im() + im_ * other.re());
}

Complex_number& Complex_number::operator-=(const Complex_number& other) {
  re_ += other.re() * -1;
  im_ += other.im() * -1;

  return *this;
}

Complex_number Complex_number::operator-(const Complex_number& other) const {
  return *this + Complex_number(other.re() * -1, other.im() * -1);
}

Complex_number& Complex_number::operator/=(const Complex_number& other) {
  *this *= other.inverse();

  return *this;
}

Complex_number Complex_number::operator/(const Complex_number& other) const {
  return *this * other.inverse();
}

bool Complex_number::operator==(const Complex_number& other) const {
  return re_ == other.re() && im_ == other.im();
}

bool Complex_number::operator!=(const Complex_number& other) const {
  return !(*this == other);
}

Complex_number Complex_number::inverse() const {
  Fraction tmp = re_ * re_ + im_ * im_;

  return Complex_number(re_ / tmp, im_ / tmp * -1);
}

ostream& operator<<(ostream& os, const Complex_number& cn) {
  return os << "(" << cn.re() << " + " << cn.im() << "i)";
}
