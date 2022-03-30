program: main.cpp Money.o Account.o
	g++ -std=c++11 -o program Money.o Account.o main.cpp

Money.o: Money.cpp Money.h
	g++ -std=c++11 -c Money.cpp

Account.o: Account.cpp Account.h
	g++ -std=c++11 -c Account.cpp

clean:
	rm *.o program