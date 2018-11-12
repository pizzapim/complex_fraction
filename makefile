CXX = g++-7
CC = g++-7
CXXFLAGS = -Wall -Wextra

all: main

gcd.o: gcd.cpp gcd.h

Fraction.o: Fraction.cpp Fraction.h gcd.h

Complex_number.o: Complex_number.cpp Complex_number.h Fraction.h

main.o: main.cpp Fraction.h Complex_number.h
	$(CXX) $(CXXFLAGS) -c main.cpp

main: main.o Fraction.o gcd.o Complex_number.o

clean:
	rm -f *.o *.h.gch *.exe main

run: all
	./main
