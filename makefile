CMP=g++ -std=c++14 -Wall
OFILES=main.o suites.o calc.o

all: kata.out

kata.out: $(OFILES)
	$(CMP) -o kata.out $(OFILES)

calc.o: calculator.cpp calculator.h
	$(CMP) -o calc.o -c calculator.cpp

suites.o: calculator_tests.cpp calculator.h
	$(CMP) -o suites.o -c calculator_tests.cpp

main.o: catch_main.cpp catch.hpp
	$(CMP) -o main.o -c catch_main.cpp

clean:
	rm $(OFILES) ksarray
