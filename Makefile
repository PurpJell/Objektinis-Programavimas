main: v03_funk.o
	g++ -o main v03.cpp  v03_funk.o
func:
	g++ -c v03_funk.cpp
clean:
	del *.o main.exe
