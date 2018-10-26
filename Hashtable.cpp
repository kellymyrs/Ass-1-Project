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


void Hashtable::Insert_Hashtable(struct Item<int>* it,uint32_t& t_size){

	//cout << "Creating f function!" << endl;	
	int64_t f = g_h->g_f_function(it->coordinates,t_size); //calculate f
	//cout << "f number is :" << f << endl;


	//cout << "Inserting an item !" << endl;
	Hash_Member* h_member = new Hash_Member(g_h,it);
	hashtable[f].push_back(h_member);
}

void Hashtable::Search_Hashtable(vector<int>& c,uint32_t t_size,struct Item<int>* min_item,double& dist){
	double temp_dist;

	cout << endl << endl << "Searching Hashtable" << endl;
	int64_t f = g_h->g_f_function(c,t_size); //calculate f
	cout << "f = " << f << endl;
	struct Item <int>* temp_item;

	//search bucket
	auto search = hashtable.find(f);	
	if(search != hashtable.end()){
		cout << "Searching bucket" << endl;
		for (int i = 0; i < search->second.size(); ++i){
			
			cout << "Combining" << endl;
			temp_item = search->second[i]->Combine(c,g_h,temp_dist);
		
			cout << "Temp Item coordinates : ";
			int temp = 0;
			for (int j = 0; j < temp_item->coordinates.size() ; ++j){
				cout << temp_item->coordinates[i] << " " ;
			}
			cout << endl;

			cout <<"Found distance : "<< temp_dist << endl;
			cout <<"Min distance : "<< dist << endl;
			if (temp_dist < dist){
				cout << "Change minimum" << endl;
				dist = temp_dist;
				min_item = temp_item;
			}
		}
	}
	else{
		cout << "Empty bucket" << endl;
	}
}

struct Item<int>* Hash_Member::Combine(vector<int>& c,G *g_h,double& temp_dist){
	int flag = 1; //checks if the two G functions are equal

	//g_m->Calculate_G(c,g_h); //calculate hash memeber G
	//g_h->Calculate_G(c,g_t); //calculate hashtable G

	//combine hash member G and hashtable G
	//vector<int64_t>::iterator itv = g_h.begin();
	//for (vector<int64_t>::iterator it = g_t.begin(); it != g_t.end(); ++it){

	//	cout << "Hash memeber G = " << *itv << endl;
	//	cout << "Hashtable G = " << *it << endl;
		
	//	if(*itv != *it){ //case the two function aren't equal
	//		temp_dist = 100000000;
	//		flag = 0;
	//		break;
	//	}
		
	//	++itv;
	//}

	//calculate distance
	if(flag){
		item->Distance(c,temp_dist);
		return item;

		//cout << "Temp Item coordinates : ";
		//int temp = 0;
		//for (int i = 0; i < temp_item->coordinates.size() ; ++i){
		//	cout << temp_item->coordinates[i] << " " ;
		//}
		//cout << endl;
	}

}