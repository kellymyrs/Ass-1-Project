#include "Hash_Function.h"


Hash_Function::Hash_Function(int d){
	cout << "Creating a Hash function : "<< endl;
	hash_function_v(d);
	
	//initialize the double t of the hash function 
	double t = W * ((double)rand() / (RAND_MAX + 1.0));
	//cout << "t = " << t << endl;
}

//creates the vector v for the hash function
void Hash_Function::hash_function_v(int d){ 
    default_random_engine generator;
	normal_distribution<double> distribution(0.0,1.0);

	v.reserve(d);
	for ( int i = 0 ; i < d ; i++){
		double number = distribution(generator);
		v.push_back(number);
		//cout << "v" << i << " = " << number << endl;
	}
}

Hash_Function::~Hash_Function(){
	cout << "Destroying Hash Function" << endl;
	v.clear();
}

//calculates h(p)
int64_t Hash_Function::g_h_function(vector <int>& p){
	int c = 0; //cross product of p and v vectors

	//cout << "Calculating h(p) !" << endl;
	vector<double>::iterator itv = v.begin();
	for (vector<int>::iterator it = p.begin(); it != p.end(); ++it){
		//cout << "vi = " << *itv << endl;
		//cout << "p = " << *it << endl;
		c += *itv + *it;
		++itv;
	}
	//cout << "Ok with p * v !" << endl;
	
	return (int64_t) floor((c + t)/W);
}