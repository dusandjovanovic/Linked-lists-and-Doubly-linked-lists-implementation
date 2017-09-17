#pragma once
#include <iostream>
using namespace std;

class Node {
public:
	double data;
	bool swapped;
	Node* next;
public:
	Node() {
		next = nullptr;
	}

	Node(double newData) {
		data = newData;
		next = nullptr;
		swapped = false;
	}

	Node(double newData, Node* succesor) {
		data = newData;
		next = succesor;
		swapped = false;
	}

	~Node() {
		next = nullptr;
	}

	double returnInfo() {
		return data;
	}

	void changeNode(double newData) {
		data = newData;
	}

	Node* getNext() {
		return next;
	}

	void show() {
		cout << data << " | ";
	}
};

class linkedList {
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

	Node deleteFromHead() {
		if (isEmpty())
			throw new exception("Empty");
		Node element = *head;
		Node* tmp = head;
		if (head == tail)
			head = tail = nullptr;
		else
			head = head->getNext();
		delete tmp;
		return element;
	}

	void addToHead(double data) {
		head = new Node(data, head);
		if (tail == nullptr)
			tail = head;
	}

	void addToTail(double data) {
		tail->next = new Node(data, nullptr);
		tail = tail->next;
		if (head == nullptr)
			head = tail;
	}

	void showAll() {
		Node* tmp = head;
		while (tmp != nullptr) {
			tmp->show();
			tmp = tmp->next;
		}
		cout << endl;
	}

	void selectionSort() {
		Node* tmp = head;
		Node* succesor;

		while(tmp != nullptr)
		{
			succesor = tmp->next;
			Node* max = succesor;

			while (succesor != nullptr) {
				if (succesor->data > max->data)
					max = succesor;
				succesor = succesor->next;
			}
			if (max > tmp) {
				swapNodes(tmp, max);
			}

			showAll();	// debug after bubble-pass
			cout << "head: " << head->data << "  " << "tail: " << tail->data << endl;
			tmp = tmp->next;
		}
		
	}

	void swapNodes(Node* current, Node* successor) {
		Node tmp = *current;
		current->data = successor->data;
		successor->data = tmp.data;
	}
};