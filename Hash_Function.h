#ifndef H_F
#define H_F
#define W 4
#include <iostream> 
#include <vector> 
#include <fstream>
#include <cstring>
#include <cstdlib> 
#include <cstdio> 
#include <sstream>      
#include <string>
#include <random>
#include <cstdint>
#include <time.h> 

using namespace std; 

class Hash_Function{
	private :
		double t;
		vector<double> v;
	public :
		Hash_Function(int d);
		~Hash_Function();
		void hash_function_v(int d);
		int64_t g_h_function(vector <int>& p);
};

#endif