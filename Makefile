make:
	g++ -std=c++11 -g3 main.cpp Hash_Function.cpp G.cpp Hashtable.cpp Lsh_Hashtable.cpp Cosine_Lsh_Hashtable.cpp Cosine_Hashtable.cpp Cosine_G.cpp Cosine_Hash_Function.cpp

clean:
	rm a.out

