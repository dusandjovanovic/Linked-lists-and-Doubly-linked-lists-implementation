#pragma once

#include <iostream>
using namespace std;

template <typename type>
class Node {
protected:
	type info;
	Node<type>* next;
	Node<type>* prev;
public:
	Node() {
		prev = nullptr;
		next = nullptr;
	}
	Node(type element) {
		info = element;
		prev = nullptr;
		next = nullptr;
	}
	Node(type element, Node<type>* newPrev, Node<type>* newNext) {
		info = element;
		prev = newPrev;
		next = newNext;
	}
	~Node() {
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
class DLList {
protected:
	Node<type>* head;
	Node<type>* tail;
public:
	DLList() {
		head = tail = nullptr;
	}
	~DLList() {
		while (!isEmmpty())
			type tmp = deleteFromHead();
	}

	bool isEmpty() {
		return head == tail;
	}

	Node<type>* returnHead() {
		return head;
	}

	void addToHead(type element) {
		if (!isEmpty()) {
			head = new Node<type>(element, nullptr, head);
			head->next->prev = head;
		}
		else
			head = tail = new Node(element);
	}

	void addToTail(type element) {
		if (!isEmpty()) {
			tail = new Node<type>(element, tail, nullptr);
			tail->prev->next = tail;
		}
		else
			head = tail = new Node<type>(element);
	}

	void deleteElement(type element) {
		if (isEmpty())
			throw new std::exception("Empty list.");
		if (head == tail && head->info.isEqual(element)) {
			Node<type>* tmp = head;
			delete tmp;
			head = tail = nullptr;
		}
		else if (head->info == element) {
			Node<type>* tmp = head;
			head = head->next;
			head->prev = nullptr;
			delete tmp;
		}
		else {
			Node<type>* tmp = head;
			while (tmp != nullptr && !tmp->info.isEqual(element))
				tmp = tmp->next;
			if (tmp != nullptr) {
				tmp->prev->next = tmp->next;
				if (tmp->next == nullptr)
					tail = tmp->prev;
				delete tmp;
			}
		}
	}
};