#pragma once
#include <iostream>
using namespace std;

class Node {
public:
	double info;
	int next;
	bool swapped = false;
public:
	Node() {
		next = 0;
	}

	Node(double newData) {
		info = newData;
		next = 0;
	}

	Node(double newData, int succesor) {
		info = newData;
		next = succesor;
	}

	~Node() {
		next = 0;
	}

	double returnInfo() {
		return info;
	}

	void changeNode(double newData) {
		info = newData;
	}

	int getNext() {
		return next;
	}

	void show() {
		cout << info << " | ";
	}
};

class linkedList {
protected:
	int size = 0;
	int head;
	int tail;

	int lrmp = 0;
	Node* data = nullptr;
public:
	linkedList() {
		head = tail = 0;
	}

	linkedList(int length) {
		size = length;
		head = tail = 0;
		lrmp = 1;
		data = new Node[size + 1];

		for (int i = 1; i < size; i++)
			data[i].next = i + 1;

		data[size].next = 0;
	}

	~linkedList() {
		if (data != nullptr)
			delete[] data;
	}

	bool isEmpty() {
		return head == 0;
	}

	double deleteFromHead() {
		if (head == 0)
			throw new std::exception();

		int tmp = head;

		if (head == tail)
			head = tail = 0;
		else 
			head = data[head].next;
		
		double toReturn = data[tmp].info;
		data[tmp].next = lrmp;
		lrmp = tmp;

		return toReturn;
	}

	double deleteFromTail() {
		if (head == 0)
			throw new std::exception();

		int tmp = tail;

		if (head == tail)
			head = tail = 0;
		else {

		}

		double toReturn = data[tmp].info;
		data[tmp].next = lrmp;
		lrmp = tmp;
			
		return toReturn;
	}

	void addToHead(double element) {
		if (lrmp == 0)
			return;

		int tmp = lrmp;
		lrmp = data[lrmp].next;

		data[tmp].info = element;
		data[tmp].next = head;

		if (head == 0)
			tail = head = tmp;
		else {
			head = tmp;
		}
	}

	void addToTail(double element) {
		if (lrmp == 0)
			return;

		int tmp = lrmp;
		lrmp = data[lrmp].next;

		data[tmp].info = element;
		data[tmp].next = 0;

		if (tail == 0)
			tail = head = tmp;
		else {
			data[tail].next = tmp;
			tail = tmp;
		}
	}

	void showAll() {
		int tmp = head;
		while (tmp != 0) {
			data[tmp].show();
			tmp = data[tmp].next;
		}
		cout << endl;
	}

	void bubbleSort() {
		int predecessor = NULL;
		int tmp = head;
		int succesor = data[head].next;

		while (data[succesor].swapped != true) {

			while (succesor != NULL) {
				if (data[tmp].info > data[succesor].info) {
					double backup = data[tmp].info;
					data[tmp].info = data[succesor].info;
					data[succesor].info = backup;
				}
				
				tmp = data[tmp].next;
				succesor = data[succesor].next;

				if (predecessor == NULL)
					predecessor = head;
				else
					predecessor = data[predecessor].next;

				if (succesor == NULL || data[succesor].swapped == true) {
					data[tmp].swapped = true;
					break;
				}
			}

			showAll();	// debug after bubble-pass
			cout << "head: " << data[head].info << "  " << "tail: " << data[tail].info << endl;

			predecessor = NULL;
			tmp = head;
			succesor = data[head].next;
		}
	}
};