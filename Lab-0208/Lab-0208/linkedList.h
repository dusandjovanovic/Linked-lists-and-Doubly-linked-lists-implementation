#pragma once
#include <iostream>
using namespace std;

class Node {
public:
	double info;
	Node* prev;
	Node* next;

public:
	Node() {
		prev = next = nullptr;
	}

	Node(double element) {
		info = element;
		prev = next = nullptr;
	}

	Node(double element, Node* predecessor, Node* successor) {
		info = element;
		prev = predecessor;
		next = successor;
	}

	~Node() {

	}

	void show() {
		cout << " " << info << " ";
	}
};


class linkedList{
protected:
	Node* head;
	Node* tail;
public:

	linkedList() {
		head = tail = nullptr;
	}

	~linkedList() {
		while (!isEmpty())
			deleteFromHead();
	}

	bool isEmpty() {
		return head == nullptr;
	}

	double deleteFromHead() {
		Node *tmp = head;

		if (head == nullptr)
			throw new std::exception();

		if (head == tail)
			head = tail = nullptr;
		else {
			head = head->next;
			head->prev = nullptr;
		}
		
		double backup = tmp->info;
		delete tmp;

		return backup;
	}

	void addToHead(double element) {
		if (isEmpty()) {
			head = tail = new Node(element, nullptr, nullptr);
			return;
		}
		Node* node = new Node(element, nullptr, head);
		head->prev = node;
		head = node;
	}

	void addToTail(double element) {
		if (isEmpty()) {
			head = tail = new Node(element, nullptr, nullptr);
			return;
		}
		Node* node = new Node(element, tail, nullptr);
		tail->next = node;
		tail = node;
	}

	void deleteElement(double element) {
		if (isEmpty())
			return;

		if (head == tail && head->info == element) {
			delete head;
			head = tail = nullptr;
		}
		else if (head->info == element) {
			Node* tmp = head;
			head = head->next;
			head->prev = nullptr;
			delete tmp;
		}
		else {
			Node* tmp = head;
			while (tmp != nullptr && tmp->info != element)
				tmp = tmp->next;
			if (tmp != nullptr) {
				tmp->prev->next = tmp->next;
				if (tmp->next != nullptr)
					tmp->next->prev = tmp->prev;
				if (tmp == tail)
					tail = tmp->prev;
				delete tmp;
			}
		}
	}

	void getToStart(double element) {
		Node* tmp = findPointer(element);
		if (tmp != nullptr) {
			cout << endl << "Read: " << tmp->info << endl;
			deleteElement(element);
			addToHead(element);
			showAll();
		}
		else
			cout << endl << "Not present in list." << endl;
	}

	void getTransp(double element) {
		Node* tmp = findPointer(element);
		if (tmp != nullptr) {
			cout << endl << "Read: " << tmp->info << endl;
			
			if (tmp != head) {
				Node* predecessor = tmp->prev;
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;

				tmp->next = predecessor;
				predecessor->prev->next = tmp;
				
				tmp->prev = predecessor->prev;
				predecessor->prev = tmp;
			}

			showAll();
		}
		else
			cout << endl << "Not present in list." << endl;
	}

	Node* findPointer(double element) {
		Node* tmp = head;
		while (tmp != nullptr && tmp->info != element)
			tmp = tmp->next;
		return tmp;
	}

	void showAll() {
		Node* tmp = head;
		while (tmp != nullptr) {
			tmp->show();
			tmp = tmp->next;
		}
		cout << endl << endl;
	}
};