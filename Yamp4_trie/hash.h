#pragma once
#include "dList.cpp"
#include <string>
#include <iostream>

template <class Data>
class hashTable {

	int size;
	DList<Data>* table;

	int hashFunc(Data obj);

public:
	hashTable() :size(10) {
		table = new DList<Data>[size];
	}
	hashTable(int N) :size(N) {
		table = new DList<Data>[size];
	}
	void add(Data obj);
	int search(Data obj);
	void remove(Data obj);
	Data operator[](int i) {
		return table[i][0];
	}
	void operator=(hashTable<Data> a) {
		size = a.size;
		delete[] table;
		table = new DList<Data>[size];
		for (int i = 0; i < a.size; i++) {
			DList<Data>::template Iterator it = a.table[i].begin();
			DList<Data>::template Iterator it_end = a.table[i].end();
			it_end++;
			while (it != it_end) {
				table[i].addToEnd(*it);
				it++;
			}
		}
	}


	void print(std::ostream& out);
	/*friend std::ostream& operator<<(std::ostream& out, hashTable a);*/
};