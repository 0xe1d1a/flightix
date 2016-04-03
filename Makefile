FlightInfo.o: FlightInfo.cpp FlightInfo.h
	g++ -Wall -c FlightInfo.cpp

Search.o: Search.cpp Search.h
	g++ -Wall -c Search.cpp

main.o: main.cpp FlightInfo.h Search.h macros.h
	g++ -Wall -c main.cpp

p1: FlightInfo.o Search.o main.o
	g++ -Wall FlightInfo.o Search.o main.o -o p1

clean:
	rm *.o
