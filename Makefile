make:
	g++ -std=c++11 -O3 -g3  main.cpp Hash_Function.cpp G.cpp Hashtable.cpp Lsh_Hashtable.cpp

clean:
	rm a.out

