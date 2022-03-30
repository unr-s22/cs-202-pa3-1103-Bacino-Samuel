pa3: main.o Money.o 
	g++ -std=c++11 -o pa3 main.o Money.o
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
Money.o: Money.cpp Money.h
	g++ -std=c++11 -c Money.cpp
clean:
	rm *.o pa3