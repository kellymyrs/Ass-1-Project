#include "Hashtable.h"

Hashtable::Hashtable(int& k,int& d){
	//cout << "Creating a hashtable !!!"<< endl;
	g_h = new G(k,d);
}

Hash_Member::Hash_Member(G* g_f,Item<int>* it){
	//cout << "Creating a hashmember !!!"<< endl;
	item = it;
	g_m = g_f;
	//g_f.clear();
}

Hashtable::~Hashtable(){
	cout << "Destroying hashtable"<< endl;

	//delete unordered multimap hashtable
	if(!hashtable.empty()){ 
		for ( auto it = hashtable.begin(); it != hashtable.end(); ++it ){
			for(auto itv = it->second.begin(); itv != it->second.end(); ++itv){
				delete *itv;
			}
		}
	}

	//delete g hash function
	delete g_h; 
}

Hash_Member::~Hash_Member(){
	//cout << "Destroying hashmember"<< endl;
}


void Hashtable::Insert_Hashtable(struct Item<int>* it,int& k,int& d,uint32_t& t_size){

	//cout << "Creating f function!" << endl;	
	int64_t f = g_h->g_f_function(it->coordinates,t_size); //calculate f
	//cout << "f number is :" << f << endl;


	//cout << "Inserting an item !" << endl;
	Hash_Member* h_member = new Hash_Member(g_h,it);
	hashtable[f].push_back(h_member);
}

