#ifndef ITEM
#define ITEM
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
#include <cstdint>
#include <time.h> 

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
		coordinates.clear();
	}
	int Distance(vector<int>& c){
		
	}
};

#endif