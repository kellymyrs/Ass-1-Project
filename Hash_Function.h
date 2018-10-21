#ifndef H_F
#define H_F
#define W 4

class Hash_Function
{
	private :
		double t;
		vector<double> v;
	public :
		Hash_Function();
		~Hash_Function();
		void hash_function_v(int d);
};

#endif