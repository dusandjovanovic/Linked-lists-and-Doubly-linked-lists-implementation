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

	void insertionSort() {
		Node* probe = head->next;
		Node* tmp;

		while (probe != nullptr) {
			Node swap = *probe;
			tmp = findPredecessor(probe);
			while (tmp->data >= swap.data && findPredecessor(tmp) != nullptr) {
				moveNode(tmp);
				tmp = findPredecessor(tmp);
			}

			if (tmp == head && tmp->data >= swap.data) {		// edge case head-pointer->data is bigger and should be displaced
				moveNode(tmp);
				tmp->data = swap.data;
			}
			else
				tmp->next->data = swap.data;

			showAll();	// debug after bubble-pass
			cout << "head: " << head->data << "  " << "tail: " << tail->data << endl;

			probe = probe->next;
		}
	}

	Node* findPredecessor(Node* element) {
		Node* tmp = head;
		while (tmp != nullptr && tmp->next != element)
			tmp = tmp->next;
		return tmp;
	}

	void swapNodes(Node* predecessor, Node* current, Node* successor) {
		Node tmp = *successor;

		if (predecessor != nullptr)
			predecessor->next = successor;
		else
			head = successor;

		if (successor->next != nullptr)
			successor->next = current;
		else {
			successor->next = current;
			tail = current;
		}

		current->next = tmp.next;
	}

	void swapSimple(Node* current, Node* successor) {
		Node tmp = *current;
		current->data = successor->data;
		successor->data = tmp.data;
	}

	void moveNode(Node* toMove) {
		toMove->next->data = toMove->data;
	}
};