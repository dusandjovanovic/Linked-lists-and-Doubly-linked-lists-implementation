#pragma once

#include <iostream>
using namespace std;

template <typename type>
class Node {
protected:
	type info;
	Node<type>* next;
public:
	Node() {
		next = nullptr;
	}
	Node(type element) {
		info = element;
		next = nullptr;
	}
	Node(type element, Node<type>* newNext) {
		info = element;
		next = newNext;
	}
	~Node(){
		info = nullptr;
	}

	type nodeValue() {
		return info;
	}

	bool isEqual(type element) {
		return info == element;
	}
};

template <typename type>
class LList {
protected:
	Node<type>* head;
	Node<type>* tail;
public:
	LList() {
		head = tail = nullptr;
	}
	~LList() {
		while (!isEmpty())
			type tmp = deleteFromHead();
	}

	void showAll() {
		Node<type>* tmp = head;
		while (tmp != nullptr) {
			cout << tmp->nodeValue() << endl;
			tmp = tmp->next;
		}
	}

	bool isEmpty() {
		return head == nullptr;
	}

	void addToHead(type element) {
		head = new Node<type>(element, head);
		if (tail == nullptr)
			tail = head;
	}

	void addToTail(type element) {
		if (!isEmpty()) {
			tail->next = new Node<type>(element);
			tail = tail->next;
		}
		else
			head = tail = new Node<type>(element, nullptr);
	}

	type deleteFromHead() {
		if (isEmpty())
			throw new std::exception("Empty list.");
		type element = head->info;
		Node<type>* tmp = head;
		if (head == tail)
			head = tail = nullptr;
		else
			head = head->next;
		delete tmp;
		return element;
	}

	type deleteFromTail() {
		if (isEmpty())
			throw new std::exception("Empty list.");
		type element = tail->info;
		Node<type>* tmp = tail;
		if (head == tail)
			head = tail = nullptr;
		else {
			Node<type>* search = head;
			while (search->next != tail)		// finding new tail element, current tail's predecessor
				search = search->next;
			tail = search;
			tail->next = nullptr;
		}
		delete tmp;
		return element;
	}

	void deleteElement(type element) {
		if (isEmpty())
			throw new std::exception("Empty list.");

		if (head == tail && head->info.isEqual(element)) {
			delete head;
			head = tail = nullptr;
		}
		else if (head->info == element) {
			Node<type>* tmp = head;
			head = head->next;
			delete tmp;
		}
		else {
			Node<type>* pred = head;
			Node<type>* tmp = head->next;
			
			while (tmp != nullptr && !(tmp->info.isEqual(element))) {
				pred = pred->next;
				tmp = tmp->next;
			}
			if (tmp != nullptr) {
				pred->next = tmp->next;
				if (tmp == tail)
					tail = pred;
				delete tmp;
			}
		}
	}
};