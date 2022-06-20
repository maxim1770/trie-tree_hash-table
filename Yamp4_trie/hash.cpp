#pragma once
#include "hash.h"

template<class Data>
inline int hashTable<Data>::hashFunc(Data obj)
{
	int temp = obj.hash() % size;
	return abs(temp);
}

template<class Data>
void hashTable<Data>::add(Data obj)
{
	int place = hashFunc(obj);
	table[place].addToHead(obj);
}

template<class Data>
int hashTable<Data>::search(Data obj)
{
	int place = hashFunc(obj);
	DList<Data>::template Iterator it_end = table[place].end();
	it_end++;
	if (table[place].search(obj) != it_end)
		return hashFunc(obj);
	else
		return -1;
}

template<class Data>
void hashTable<Data>::remove(Data obj)
{
	int place = hashFunc(obj);
	if (!table[place].is_empty()) {
		table[place].remove(obj);
	}
}

template<class Data>
void hashTable<Data>::print(std::ostream& out)
{
	for (int i = 0; i < size; i++) {
		if (!(table[i].is_empty())) {
			out << i << ": ";
			table[i].print(out);
			out << '\n';
		}
	}
}

//template<class Data>
//std::ostream& operator<<(std::ostream& out, hashTable<Data> a)
//{
//	for (int i = 0; i < a.size; i++) {
//		if (!a.table[i].is_empty()) {
//			DList<Data>::Iterator it = a.table[i].begin();
//			DList<Data>::Iterator it_end = a.table[i].end();
//			it_end++;
//			out << i << ": ";
//			for (; it != it_end; it++) {
//				out << *it;
//				out << " ";
//			}
//			out << '\n';
//		}
//	}
//	return out;
//}
