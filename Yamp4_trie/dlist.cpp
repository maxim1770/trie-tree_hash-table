#pragma once

#include "dlist.h"

template<class Data>
void DList<Data>::addToHead(Data elem)
{
	Node<Data>* pNode = new Node<Data>;
	pNode->data = elem;
	pNode->next = head;
	pNode->prev = nullptr;
	if (head != nullptr)
		head->prev = pNode;
	else {
		tail = pNode;
	}
	head = pNode;
}

template<class Data>
void DList<Data>::remove(Data elem)
{
	Iterator iter = begin();
	Iterator i_end = end();
	i_end++;
	while (iter != i_end && *iter != elem) {
		iter++;
	}
	if (iter != i_end) {
		deleteNode(iter);
	}
}

template<class Data>
void DList<Data>::addToEnd(Data elem)
{
	if (tail == nullptr) {
		addToHead(elem);
	}
	else {
		Node<Data>* pNode = new Node<Data>;
		pNode->data = elem;
		pNode->next = nullptr;
		pNode->prev = tail;
		tail->next = pNode;
		tail = pNode;
	}
}

template<class Data>
void DList<Data>::addAfter(Iterator ZXC, Data el)
{
	if (ZXC == end())
		addToEnd(el);
	else
	{
		Node<Data>* pNode = new Node<Data>;
		Node<Data>* p = ZXC.getNode();

		pNode->data = el;
		pNode->next = p->next;
		pNode->prev = p;
		p->next = pNode;
		pNode->next->prev = pNode;
	}
}

template<class Data>
void DList<Data>::deleteFromHead()
{
	if (head) {
		Node<Data>* p = head;
		head = head->next;
		if (head)
			head->prev = nullptr;
		p->next = nullptr;
		p->prev = nullptr;
		p = nullptr;
		delete p;
	}
}


template<class Data>
void DList<Data>::deleteFromEnd()
{
	if (tail) {
		Node<Data>* p = tail;
		tail = tail->prev;
		if (tail)
			tail->next = nullptr;
		p->next = nullptr;
		p->prev = nullptr;
		p = nullptr;
		delete p;
	}
}

template<class Data>
void DList<Data>::listClear()
{
	if (head != nullptr) {
		while (head != nullptr)
			deleteFromHead();
	}
	tail = head;
	delete head;
	delete tail;
}

template<class Data>
Data DList<Data>::operator[](int i)
{
	Iterator iter = begin();
	Iterator i_end = end();
	i_end++;
	while (iter != i_end && i > 0) {
		iter++;
		i--;
	}
	if (iter != i_end) return *iter;
	else return Data();
}

template<class Data>
void DList<Data>::operator=(DList<Data> A)
{
	listClear();
	Iterator iter = A.begin();
	Iterator i_end = A.end();
	i_end++;
	while (iter != i_end)
	{
		addToEnd(*iter);
		iter++;
	}
}

template<class Data>
void DList<Data>::deleteNode(Iterator iter)
{
	Node<Data>* p = iter.getNode();
	if (p == head)
		deleteFromHead();
	else
		if (p == tail)
			deleteFromEnd();
		else {
			p->prev->next = p->next;
			p->next->prev = p->prev;
			p->next = nullptr;
			p->prev = nullptr;
			p = nullptr;
			delete p;
		}
}