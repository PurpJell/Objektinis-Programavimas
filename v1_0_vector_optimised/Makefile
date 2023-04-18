main: v1_0_vector_funk.o
	g++ -o main -O3 v1_0_vector.cpp  v1_0_vector_funk.o


vector: v1_0_vector_funk.o
	g++ -o main -O3 v1_0_vector.cpp  v1_0_vector_funk.o
vc_func:
	g++ -c v1_0_vector_funk.cpp -O3


deque: v1_0_deque_funk.o
	g++ -o main -O3 v1_0_deque.cpp  v1_0_deque_funk.o
dq_func:
	g++ -c v1_0_deque_funk.cpp -O3


list: v1_0_list_funk.o
	g++ -o main -O3 v1_0_list.cpp  v1_0_list_funk.o
ls_func:
	g++ -c v1_0_list_funk.cpp -O3


optimised: v1_0_vector_opt_funk.o
	g++ -o main -O3 v1_0_vector_opt.cpp  v1_0_vector_opt_funk.o
opt_func:
	g++ -c v1_0_vector_opt_funk.cpp -O3

clean:
	del *.o main.exe
