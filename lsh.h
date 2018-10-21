struct Item {
	int id;
	vector<int> coordinates;
};

class Hashtable{
	public :
		unordered_map<Item*> hashtable;
}

class Lsh_Hashtable {
	public :
		vector<Hashtable*> lsh_hashtable;
}
		
vector<double>* hash_function_v(int d);