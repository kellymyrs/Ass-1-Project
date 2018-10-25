#include "Lsh_Hashtable.h"

Lsh_Hashtable::Lsh_Hashtable(int& k,int& d,int& L){
	Hashtable* h;
	cout << "Creating Lsh_Hashtable !!!" << endl;
	for ( int i = 0; i < L; ++i ){
		h = new Hashtable(k,d);
		lsh_hashtable.push_back(h);
	}
}

Lsh_Hashtable::~Lsh_Hashtable(){
	cout << "Destroying Lsh_Hashtable"<< endl;

	//delete lsh_hashtable
	if(!lsh_hashtable.empty()){ 
		for ( auto it = lsh_hashtable.begin(); it != lsh_hashtable.end(); ++it ){
			delete *it;
		}
	}
		
}

void Lsh_Hashtable::Insert_Lsh_Hashtable(struct Item<int>* item,int& k,int& d,uint32_t& t_size,int& L){
	// for loop for every hashtable
	for ( int i = 0; i < L; ++i ){
		lsh_hashtable[i]->Insert_Hashtable(item,k,d,t_size);
	}
}
