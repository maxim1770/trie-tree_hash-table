#pragma once
#include <iostream>
#include <string>
#include "hash.cpp"
#include <map>

using namespace std;

class word {
public:
	char s;
	word() :s('a') {};
	word(char s1) :s(s1) {};
	bool operator==(word a) { return s == a.s; }
	bool operator!=(word a) { return s != a.s; }
	int hash() {
		return int(s - 'a');
	}
	friend std::ostream& operator<<(std::ostream& out, word a) {
		out << a.s;
		return out;
	}
};

class trieTree {
	struct Node {
		map <char, Node*> children; // пример
	};
	hashTable<word> a;
	Node* root;

	bool isEmpty(Node* it) {
		bool flag = 1;
		for (int i = 0; i < 27; i++) {
			if (it->alph[i] != nullptr)
				flag = 0;
		}
		return flag;
	}

	bool recurseRemove(std::string word1, Node*& it, int i) {
		if (i == word1.size() && it->alph[26] != nullptr) {
			it->alph[26] = nullptr;
			if (isEmpty(it)) {
				delete it;
				it = nullptr;
			}
			return 1;
		}
		else {
			if (it == nullptr) {
				return 0;
			}
			if (i > word1.size()) {
				return 0;
			}
			word temp(word1[i]);
			int h = a.search(temp);
			if (recurseRemove(word1, it->alph[h], i + 1)) {
				if (isEmpty(it)) {
					delete it;
					it = nullptr;
				}
				return 1;
			}
			else {
				return 0;
			}
		}
	}
	void recurseWords(std::string s, std::string& words, Node* it) {
		if (it != nullptr) {
			if (it->alph[26] != nullptr) {
				words = words + s + " ";
			}
			for (int i = 0; i < 26; i++) {
				recurseWords(s + a[i].s, words, it->alph[i]);
			}
		}
	}

public:
	trieTree(hashTable<word> a_) {
		a = a_;
		root = new Node;
	}
	void add(std::string word1) {
		Node* temp = root;
		for (int i = 0; i < word1.size(); i++) {
			word temp1(word1[i]);
			char x = word1[i];
			int h = a.search(temp1);
			Node* el = temp->children.find(x)->second;
			if (el != nullptr) {
				temp = el;
			}
			else {
				temp->children.insert(make_pair(x,new Node));
				temp = temp->children.find(x)->second;	

			}
		}
		char endd = '\0';
		temp->children.insert(make_pair(endd, new Node));
		temp = temp->children.find(endd)->second;
	}
	void remove(std::string word) {
		recurseRemove(word, root, 0);
	}
	bool find(std::string word1) {
		bool flag = 1;
		Node* temp = root;
		if (root == nullptr) return 0;
		for (int i = 0; flag && i < word1.size(); i++) {
			word temp1(word1[i]);
			int h = a.search(temp1);
			if (temp->alph[h] != nullptr) {
				temp = temp->alph[h];
			}
			else {
				flag = 0;
			}
		}
		return flag && temp->alph[26] != nullptr;
	}

	std::string allWords() {
		std::string temp;
		recurseWords("", temp, root);
		return temp;
	}

	trieTree merge(trieTree b) {
		trieTree res(a);
		std::string SSS = allWords();
		std::string check = " ";
		while (!SSS.empty())
		{
		std::string ss = SSS.substr(0, SSS.find_first_of(" ") - 1);
		if (ss == check) return res;
		check = ss;
		if (b.find(ss)) res.add(ss);
		SSS.erase(0, SSS.find_first_of(" "));
		}
		return res;
	}
	
};