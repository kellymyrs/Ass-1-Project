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
#include <cstdint>
#include <time.h>
#include <math.h>
#include <utility>
#include <cmath>
#include <unordered_map>

#define W 400

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
	void Distance(vector<T>& c,double& temp_dist){
		int temp = 0;
		//cout << "Item coordinates : ";
		for (int i = 0; i < coordinates.size() ; ++i){
			temp += (coordinates[i] - c[i])*(coordinates[i] - c[i]) ;
		//	cout << coordinates[i] << " " ;
		}
		temp_dist = sqrt(temp);
		//cout << " ********************************sqrt--->" << temp_dist << "\n";
		//cout << endl;
	}

};

#endif
