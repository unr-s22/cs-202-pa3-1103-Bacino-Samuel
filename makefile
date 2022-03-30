<<<<<<< HEAD
program: main.cpp Money.o Account.o
	g++ -std=c++11 -o program Money.o Account.o main.cpp

Money.o: Money.cpp Money.h
	g++ -std=c++11 -c Money.cpp

Account.o: Account.cpp Account.h
	g++ -std=c++11 -c Account.cpp

clean:
	rm *.o program
=======
pa3: main.o Money.o 
	g++ -std=c++11 -o pa3 main.o Money.o
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
Money.o: Money.cpp Money.h
	g++ -std=c++11 -c Money.cpp
clean:
	rm *.o pa3
>>>>>>> 4ebc7846a4c8f7208cdeefef35c70f23d9ce98b9
