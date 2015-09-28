Craps : Labass3.o
	g++ Labass3.o -o Craps


Labass2.o : Labass3.cpp
	g++ -c Labass3.cpp

clean:
	rm *.o Labass3
