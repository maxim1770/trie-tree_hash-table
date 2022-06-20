#pragma once
#include <iostream>
#include <string>

template <class Data>
class DList {

	template <class Data>
	struct Node {
		Data data;
		Node* next;
		Node* prev;
	};


	Node<Data>* head;
	Node<Data>* tail;

public:

	DList() {
		head = nullptr;
		tail = nullptr;
	}

	class Iterator {
		Node<Data>* p;
	public:
		Iterator() :p(nullptr) {}
		Iterator(Node<Data>* node) :p(node) {}
		Node<Data>* getNode() { return p; }
		bool operator==(Iterator other) { return other.p == p; }
		bool operator!=(Iterator other) { return other.p != p; }
		Data operator*() { return p->data; }
		Iterator operator++() {
			if (p)	p = p->next;
			return *this;
		}
		Iterator operator++(int) {
			Iterator q(p);
			if (p)p = p->next;
			return q;
		}
		Iterator operator--() {
			if (p)	p = p->prev;
			return *this;
		}
		Iterator operator--(int) {
			Iterator q(p);
			if (p)p = p->prev;
			return q;
		}
	};

	Iterator begin() { return Iterator(head); }
	Iterator end() { return Iterator(tail); }

	bool is_empty() {
		return head == nullptr;
	}
	Data operator[](int i);
	void operator=(DList<Data> A);
	void addToHead(Data elem);
	void addToEnd(Data elem);
	void addAfter(Iterator ZXC, Data el);
	void deleteFromHead();
	void deleteFromEnd();
	void deleteNode(Iterator iter);
	void remove(Data elem);
	void listClear();

	Iterator search(Data elem) {
		Iterator iter = begin();
		Iterator i_end = end();
		i_end++;
		while (iter != i_end && *iter != elem) {
			iter++;
		}
		return iter;
	}
	bool find(Data elem) {
		Iterator iter = begin();
		Iterator i_end = end();
		i_end++;
		while (iter != i_end && *iter != elem) {
			iter++;
		}
		return iter != i_end;
	}

	void print(std::ostream& out) {
		Iterator iter = begin();
		Iterator i_end = end();
		i_end++;
		while (iter != i_end) {
			out << *iter;
			out << ' ';
			iter++;
		}
	}
};