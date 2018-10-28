#include "Cosine_Hash_Function.h"

Cosine_Hash_Function::Cosine_Hash_Function(int& d){
	cout << "Creating a Cosine Hash function : "<< endl;

    default_random_engine generator;
	normal_distribution<double> distribution(0.0,1.0);

	r.reserve(d);
	for ( int i = 0 ; i < d ; i++){
		double number = distribution(generator);
		r.push_back(number);
		//cout << "r" << i << " = " << number << endl;
	}
}

Cosine_Hash_Function::~Cosine_Hash_Function(){
	cout << "Destroying Cosine Hash Function" << endl;
	r.clear();
}

//calculates h(p)
int Cosine_Hash_Function::cosine_h_function(vector <int>& p){
    int c = 0;

    //cout << "Calculating h(p) !" << endl;
	vector<double>::iterator itv = r.begin();
	for (vector<int>::iterator it = p.begin(); it != p.end(); ++it){
		//cout << "vi = " << *itv << endl;
		//cout << "p = " << *it << endl;
		c += *itv + *it;
		++itv;
	}

    if( c >= 0)
        return 1;
    else
        return 0;

}
