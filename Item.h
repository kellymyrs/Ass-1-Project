#ifndef ITEM
#define ITEM
#include <iostream> 
#include <vector> 
#include <fstream>
#include <cstring>
#include <cstdlib> 
#include <cstdio> 
#include <sstream>      
#include <string>
#include <random>

using namespace std;

template <typename T>
struct Item{
	int id;
	vector <T> coordinates;
	Item(int i,vector<T>& c){
		id = i;
		coordinates = c;
	}	
	~Item(){
		cout << "DELETE" << endl;
		coordinates.clear();
	}
};

#endif