#include <iostream>
#include "Fraction.h"
#include "Complex_number.h"

using std::cout; using std::cin; using std::endl;

int main() {
  Fraction f0(2, 3);
  Fraction f1(4, 5);

  Complex_number cn0(f0, f1);
  Complex_number cn1(2, 1, 0, 1);

  cout << cn0 << " + " << cn1 << " = " << cn0 + cn1 << endl;

  return 0;
}
