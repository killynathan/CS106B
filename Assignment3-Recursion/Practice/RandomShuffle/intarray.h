class IntArray {
	public: 
		IntArray(int n);

		IntArray(const IntArray & arr);
	
		~IntArray();

		int size();
	
		int get(int k);

		void put(int k, int value);

		int & operator[](int k);

		IntArray & operator=(const IntArray & rhs);

		

	private:
		int length;

		int *array;

	
};