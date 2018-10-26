#ifndef G_F
#define G_F
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
#include "Hash_Function.h"

using namespace std;

class G{
	private :
		vector<Hash_Function*> g;
	public :
		G(int& k,int& d);
		~G();
		int64_t g_f_function(vector <int>& p,uint32_t& t_size);
		void Calculate_G(vector<int>& c,vector<int64_t>& g_numbers);
};

#endif