#include <iostream> 
#include <vector> 
#include <fstream>
#include <cstring>
#include <cstdlib> 
#include <cstdio> 
#include <sstream>      
#include <string>
#include <random>
#include "Hash_function.h"

using namespace std; 

Hash_function::hash_function_v(int d){
    default_random_engine generator;
	normal_distribution<double> distribution(0.0,1.0);

	cout << "Hash function : ";
	v.reserve(d);
	for ( int i = 0 ; i < d ; i++){
		double number = distribution(generator);
		v.push_back(number);
		cout << "v" << i << " = " << number << endl;
	}
}