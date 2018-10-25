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
		//Combine(vector<int>& c,G *g_h);
};

class Hashtable{
	private :
		G* g_h;
		unordered_map<int,vector <Hash_Member*>> hashtable;
	public : 
		Hashtable(int& k,int& d);
		~Hashtable();
		void Insert_Hashtable(struct Item<int>* item,int& k,int& d,uint32_t& t_size);
		//void Search_Hashtable(vector<int>& c,int& k,int& d,vector<struct Item<int>*>& results);
};

#endif