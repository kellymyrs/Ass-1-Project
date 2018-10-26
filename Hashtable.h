#ifndef HT
#define HT
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
#include <unordered_map>
#include <cstdint>
#include <time.h> 
#include "G.h"
#include "Item.h"

using namespace std;

class Hash_Member{
	private :
		Item<int>* item;
		G* g_m;
	public:
		Hash_Member(G* g_f,Item<int>* it);
		~Hash_Member();
		struct Item<int>* Combine(vector<int>& c,G *g_h,double& temp_dist);
};

class Hashtable{
	private :
		G* g_h;
		unordered_map<int,vector <Hash_Member*>> hashtable;
	public : 
		Hashtable(int& k,int& d);
		~Hashtable();
		void Insert_Hashtable(struct Item<int>* item,uint32_t& t_size);
		void Search_Hashtable(vector<int>& c,uint32_t t_size,struct Item<int>* min_item,double& dist);
};

#endif