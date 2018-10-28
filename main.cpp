#include "Item.h"
#include "G.h"
#include "Lsh_Hashtable.h"


bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

// Add id to the already existed DataSet
int add_id_to_data(ifstream &input_file,string name, string& new_input_fn) {
    new_input_fn = name + "_id";

    //ifstream input_file(input_fn);
    ofstream new_file(new_input_fn);
    string line;
    string curr_line;
    string new_line;
    string temp_str;
    uint32_t id = 1;
    if (input_file.is_open() && new_file.is_open()) {
        if (getline(input_file, line)) {
            istringstream curr_line(line);

            getline(curr_line, temp_str, ' ');

            // If line has metric just copy it or radious
            if (((!temp_str.compare("euclidean")) || (!temp_str.compare("cosine")) || temp_str.empty()) || (!temp_str.compare("Radius:")) ) {
                cout << "RADIUS" << endl;
                new_file << line;
                new_file << '\n';
            }
            else {
            	new_file << '\n';
            	 // If we are here mean that the line has a point
            	new_line = "item_id" + std::to_string(id)  + ' ' + line + '\n';
            	new_file << new_line;
            	id++;
            }
        }
    }
    else return 1;

    if (input_file.is_open() && new_file.is_open()) {
        while (getline(input_file, line)) {
            istringstream curr_line(line);

            getline(curr_line, temp_str, ' ');

            // If line has metric just copy it
            if (temp_str.empty()) continue;

            // If we are here mean that the line has a point
            new_line = "item_id" + std::to_string(id)  + ' ' + line + '\n';
            new_file << new_line;
            id++;
        }
        new_file.close();
        input_file.close();
    }
    else return 1;

    return 0;
}


int main(int argc,char* argv[]){
	ifstream input_file, query_file;
	ofstream output_file;
	int i,j,k = 4 ,L = 5, N,d; // N = number of items(lines) in the file, d = number of coordinates (dimension)
	char* com;
	string line,temp_str;
	int ident;
	vector<struct Item <int>*> items,range;
	vector<int> c; //coordinates
	struct Item <int>* item,* nn = NULL;
	double min_dist, R = 0;

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

	//modify input file
	string new_input_file;

	add_id_to_data(input_file,"input", new_input_file);
	ifstream new_in_file(new_input_file);


	//create the table items[] with the coordinates we get from the file
    i = 1;
	while(getline(new_in_file,line)) {
		ident = i;

        istringstream curr_line(line);
        d = 0;
        while (getline(curr_line, temp_str, ' ')) {

        	if(is_number(temp_str) == false) {
        		continue;
        	}

            c.push_back(atoi(temp_str.c_str()));
            d++;
		}

		item = new struct Item<int>(ident , c);
		items.push_back(item);
		c.clear();
		i++;
    }
    new_in_file.close();
    N = i-1;

    //cout << "--------------------------------------> " << N << endl;
    uint32_t t_size = (uint32_t) floor(N/2);

    //Create Lsh_Hashtable
    Lsh_Hashtable* h = new Lsh_Hashtable(k,d,L);
    for (int i = 0; i < N; ++i){
    	h->Insert_Lsh_Hashtable(items[i],t_size,L);
    }

	//read from prompt
	if(!query_file.is_open()){
		cout << "Please enter a query file !" << endl ;
		cin >> com;           //get the input file
		query_file.open(com); //open the input file
	}

	//modify query file
	string new_query_file;

	add_id_to_data(query_file,"query", new_query_file);

	ifstream new_q_file(new_query_file);

	//read from prompt
	if(!output_file.is_open()){
		cout << "Please enter an output_file file !" << endl ;
		cin >> com;           //get the output file
		output_file.open(com); //open the output file
	}


    //Search queries
    int q = 1;
	while(getline(new_q_file,line)) {

        istringstream curr_line(line);

	    getline(curr_line, temp_str, ' ');

		// Check radious
		if (!temp_str.compare("Radius:")) {
			getline(curr_line, temp_str, ' ');
			R = atof(temp_str.c_str());
			continue;
		}
		else if(temp_str.empty()) {
			R = 0;
			continue;
		}

		// Move pointer to the coordinates
		getline(curr_line, temp_str, ' ');

        while (getline(curr_line, temp_str, ' ')) {
            c.push_back(atoi(temp_str.c_str()));
		}

		output_file << "Query number " << q <<  ": ";
		q++;

		for(j = 0 ; j < d ; j++ ){
			output_file << c[j] << " " ;
		}
		output_file << endl;


		//Range(r,c)-Neighbor search
		if( R != 0)
			h->Range_Lsh(c,L,t_size,R,range);

        //find nearest neighbor
        nn = h->NN_Lsh(c,L,t_size,min_dist);

        //cout << "Search OK!!!" << endl;

		if(!range.empty()){
			cout << "Result Range!!" << endl;
			output_file << "R-near neighbors:  " << endl;
			for( j = 0 ; j < range.size() ; j++){
				output_file <<"item_id"<< range[j]->id << " ";
				for( int k = 0 ; k < d ; k++){
					output_file << range[j]->coordinates[k] << " ";
				}
				output_file << endl;
			}
		}

		if(nn != NULL){
			cout << "Result NN!!" << endl;
			//write on the file
			output_file << "Nearest neighbor : " <<"item_id"<< nn->id << " ";
			//cout << "CORDS SIZE -- > " << nn->coordinates.size() << endl;
			for (j = 0; j < d ; j++)
				output_file << nn->coordinates[j] << " ";
			output_file << endl;
			output_file << "distanceLSH : "<< min_dist << endl;
		}
        cout << endl;
        range.clear();
		c.clear();
		//break;
    }

    new_q_file.close();


	//print items
	//for ( i = 0 ; i < N ; i++  ){
	//	cout << "Items' elements are: ";
	//if(result != NULL){
	//	for (vector<int>::const_iterator j = result->coordinates.begin(); j != result->coordinates.end(); ++j)
	//		    cout << *j << " ";
	//}
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

    output_file.close();
    return 0;
}
