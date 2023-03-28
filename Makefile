main: v05_vector_funk.o
	g++ -o main -O3 v05_vector.cpp  v05_vector_funk.o


vector: v05_vector_funk.o
	g++ -o main -O3 v05_vector.cpp  v05_vector_funk.o
vc_func:
	g++ -c v05_vector_funk.cpp -O3


deque: v05_deque_funk.o
	g++ -o main -O3 v05_deque.cpp  v05_deque_funk.o
dq_func:
	g++ -c v05_deque_funk.cpp -O3


list: v05_list_funk.o
	g++ -o main -O3 v05_list.cpp  v05_list_funk.o
ls_func:
	g++ -c v05_list_funk.cpp -O3

clean:
	del *.o main.exe
