#include "Item.h"
#include "G.h"
#include "Lsh_Hashtable.h"

int main(int argc,char* argv[]){
	ifstream input_file, query_file;
	ofstream output_file;
	int i,k = 4 ,L = 5, N,d; // N = number of items(lines) in the file, d = number of coordinates (dimension)
	char* com;
	string line,temp_str;
	int ident;
	vector<struct Item <int>*> items,results;
	vector<int> c; //coordinates
	struct Item <int>* item;

	srand (time(NULL));

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
		ident = i;
		
        istringstream curr_line(line);
        d = 0; 
        while (getline(curr_line, temp_str, ' ')) {
            c.push_back(atoi(temp_str.c_str()));
            d++;
		}
		item = new struct Item<int>(ident , c);
		items.push_back(item);
		c.clear();
		i++;
    }
    N = i-1;
    cout << "--------------------------------------> " << N << endl;
    uint32_t t_size = (uint32_t) floor(N/2);

    //create a function G
    //G* g = new G(k,d);
    //delete g;

    //create a hashtable
    //Hashtable* h = new Hashtable(k,d);
	/*
	for (vector<int>::const_iterator j = items[0]->coordinates.begin(); j != items[0]->coordinates.end(); ++j) 
	    cout << *j << " ";
	cout << endl;
	*/
    //h->Insert_Hashtable(items[0],k,d,t_size);
	/*
	for (vector<int>::const_iterator j = items[1]->coordinates.begin(); j != items[1]->coordinates.end(); ++j) 
	    cout << *j << " ";
	cout << endl;
    */
    //h->Insert_Hashtable(items[1],k,d,t_size);
    
    //Create Lsh_Hashtable
    Lsh_Hashtable* h = new Lsh_Hashtable(k,d,L);
    for (int i = 0; i < N; ++i){
    	h->Insert_Lsh_Hashtable(items[i],k,d,t_size,L);
    }

	//read from prompt
	if(!query_file.is_open()){ 
		cout << "Please enter a query file !" << endl ;
		cin >> com;           //get the input file
		query_file.open(com); //open the input file
	}

    //Find queries
    i = 1;	
	while(getline(query_file,line)) { 	

        istringstream curr_line(line);
        while (getline(curr_line, temp_str, ' ')) {
            c.push_back(atoi(temp_str.c_str()));
		}
		for(int j = 0 ; j < d-1 ; j++ ){
			cout << c[j] << " " ;
		}
		cout << endl;
		//h->Search_Lsh( c,k,d,L,results);
		c.clear();
		i++;
		//break;
    }
    int Q = i-1; //number of queries
	

	//print items
	//for ( i = 0 ; i < N ; i++  ){
	//	cout << "Items' elements are: "; 
	//	for (vector<int>::const_iterator j = items[i]->coordinates.begin(); j != items[i]->coordinates.end(); ++j) 
	//	    cout << *j << " "; 
	//	cout << endl;
	//}

	delete h;
	

	//destroy items
	cout << "Destroying array items "<< endl; 
	for ( i = 0 ; i < N ; i++  ){
		//cout << "Destroying item" << i << endl;
		delete items[i];
	}
	items.clear();
	
    cout << "Do you want to repeat search ? " << endl ;
    cin >> com;
    if(strcmp(com, "yes")  ==0){
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
