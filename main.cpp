#include <iostream> 
#include <vector> 
#include <fstream>
#include <cstring>
#include <cstdlib> 
#include <cstdio> 
#include <sstream>      
#include <string>
#include "lsh.h"
#include <random>

using namespace std; 

struct Item {
	int id;
	vector<int> coordinates;
};

int main(int argc,char* argv[]){
	ifstream input_file, query_file;
	ofstream output_file;
	int i,k = 4 ,L = 5, N,d; // N = number of items(lines) in the file, d = number of coordinates (dimension)
	char* com;
	string line,temp_str;
	Item* item;
	vector<Item> items;

	//using command line
	for( i = 1 ; i < argc - 1 ; i++) {
		if(!strcmp(argv[i],"-d"))          //input file
			input_file.open(argv[i+1]);    

		if(!strcmp(argv[i],"-q"))         //query file
			query_file.open(argv[i+1]); 

		if(!strcmp(argv[i],"-k"))        //k = number of h
			k = atoi(argv[i+1]); 

		if(!strcmp(argv[i],"-L"))      //L = number of hashtables
			L = atoi(argv[i+1]); 

		if(!strcmp(argv[i],"-o"))        //output file	
			output_file.open(argv[i+1]); 
	}	

	//read from prompt
	com = new char[100];
	if(!input_file.is_open()){ 
		cout << "Please enter an input file !" << endl ;
		cin >> com;           //get the input file
		input_file.open(com); //open the input file
	}
	
	//create the table items[] with the coordinates we get from the file
    i = 1;	
	while(getline(input_file,line)) { 	
		item = new Item;
		item->id = i;
		
        istringstream curr_line(line);
        d = 0; 
        while (getline(curr_line, temp_str, ' ')) {
            item->coordinates.push_back(atoi(temp_str.c_str()));
            d++;
		}
		items.push_back(*item);
		delete item;
		i++;
    }
    N = i-1;

	//print items
	for ( i = 0 ; i < N ; i++  ){
		cout << "Vector elements are: "; 
		for (vector<int>::const_iterator j = items[i].coordinates.begin(); j != items[i].coordinates.end(); ++j) 
		    cout << *j << " "; 
		cout << endl;
	}

    cout << "Do you want to repeat search ? " << endl ;
    cin >> com;
    if(strcmp(com,"yes")==0){
    	cout << "WAIT" << endl;
    }
    else
    	cout << "BYE" << endl;
    	

    delete[] com;
    input_file.close();
    query_file.close();
    output_file.close();

    return 0;
}
