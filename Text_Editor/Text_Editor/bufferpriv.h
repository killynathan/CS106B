private: 
	int capacity;
	int stackOneEnd;
	int stackTwoStart;
	char *array;
	std::string copiedText;

	EditorBuffer(const EditorBuffer & value) { }
	const EditorBuffer & operator=(const EditorBuffer & rhs) { return *this; }

	void expandCapacity();