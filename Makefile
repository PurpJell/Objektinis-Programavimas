main: v041_funk.o
	g++ -o main -O3 v041.cpp  v041_funk.o
func:
	g++ -c v041_funk.cpp -O3
clean:
	del *.o main.exe
