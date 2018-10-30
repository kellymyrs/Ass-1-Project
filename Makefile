make:
	g++ -std=c++11 -g3 cube.cpp Hash_Function.cpp G.cpp Cosine_G.cpp Cosine_Hash_Function.cpp Search.cpp

clean:
	rm a.out
