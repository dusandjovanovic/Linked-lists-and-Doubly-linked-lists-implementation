#pragma once
#include <iostream>
using namespace std;

class Node {
public:
	double info;
	int next;
	int prev;
	// next/prev: 0 means no next/prev element

	bool swapped = false;
public:
	Node() {
		next = 0;
	}

	Node(double newData) {
		info = newData;
		next = 0;
		prev = 0;
	}

	Node(double newData, int predecessor, int succesor) {
		info = newData;
		prev = predecessor;
		next = succesor;
	}

	~Node() {
		next = 0;
		prev = 0;
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
	int size;
	int head;
	int tail;
	int lrmp;

	Node* data = nullptr;
public:
	linkedList() {
		size = 0;
		lrmp = 0;
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

	void addToHead(double element) {
		if (lrmp == 0)
			return;

		int tmp = lrmp;
		lrmp = data[lrmp].next;

		data[tmp].info = element;
		data[tmp].prev = 0;		// 0: no next/prev element!!!
		data[tmp].next = head;	// 0 first time, index later

		if (head == 0)
			head = tail = tmp;
		else {
			data[head].prev = tmp;
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
		data[tmp].prev = tail;

		if (tail == 0)
			tail = head = tmp;
		else {
			data[tail].next = tmp;
			tail = tmp;
		}
	}

	double deleteFromHead() {
		if (head == 0)
			throw new std::exception();

		int tmp = head;
		if (head == tail)
			head = tail = 0;
		else {
			head = data[head].next;
			data[head].prev = 0;
		}

		double backup = data[tmp].info;
		data[tmp].prev = 0;
		data[tmp].next = lrmp;	// link deleted element to lrmp
		lrmp = tmp;

		return backup;
	}

	double deleteFromTail() {
		if (head == 0)
			throw new std::exception();

		int tmp = tail;
		if (head == tail)
			head = tail = 0;
		else {
			tail = data[tail].prev;
			data[tail].next = 0;
		}

		double backup = data[tmp].info;
		data[tmp].prev = 0;
		data[tmp].next = lrmp;	// link deleted element to lrmp
		lrmp = tmp;

		return backup;
	}

	void showAll() {
		int tmp = head;
		while (tmp != 0) {
			cout << data[tmp].info << " ";
			tmp = data[tmp].next;
		}
		cout << endl << endl;
	}

	void showAllFromTail() {
		int tmp = tail;
		while (tmp != 0) {
			cout << data[tmp].info << " ";
			tmp = data[tmp].prev;
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