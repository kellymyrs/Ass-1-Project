#include "Cosine_G.h"

Cosine_G::Cosine_G(int& k,int& d){
    g.reserve(k);
	Cosine_Hash_Function* h;

	cout << "Creating a Cosine G Hash function : " << endl;

	for (int i = 0; i < k; ++i){
		h = new Cosine_Hash_Function(d);
		g.push_back(h);
	}
}

Cosine_G::~Cosine_G(){
	cout << "Destroying Cosine G Hash function : " << endl;
	for (vector<Cosine_Hash_Function*>::iterator it = g.begin(); it != g.end(); ++it)
		delete *it;
	//g.clear();
}

uint32_t Cosine_G::Calculate_G(vector<int>& c){
	int h;
    uint32_t concat = 0;

	vector<Cosine_Hash_Function*>::iterator it;
	//cout << "Calculating Cosine G" << endl;
	for ( it = g.begin() ; it != g.end() ; ++it ){

		h = (*it)->cosine_h_function(c);

        concat = (concat << 1) | h;

	}

    return concat;
}
