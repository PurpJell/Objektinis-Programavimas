main: v04_funk.o
	g++ -o main -O3 v04.cpp  v04_funk.o
func:
	g++ -c v04_funk.cpp -O3
clean:
	del *.o main.exe
