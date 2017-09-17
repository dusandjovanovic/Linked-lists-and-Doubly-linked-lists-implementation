#pragma once
#include <iostream>
using namespace std;

class Node {
public:
	int exponent;
	double coefficent;
	Node* next;
public:
	Node() {
		next = nullptr;
	}

	Node(int exp, double coef) {
		exponent = exp;
		coefficent = coef;
		next = nullptr;
	}

	Node(int exp, double coef, Node* succesor) {
		exponent = exp;
		coefficent = coef;
		next = succesor;
	}

	~Node() {
		next = nullptr;
	}

	double returnCoefficent() {
		return coefficent;
	}

	int returnExponent() {
		return exponent;
	}

	void changeNode(int exp, double coef) {
		exponent = exp;
		coefficent = coef;
	}

	void enlargeNode(int exp, double coef) {
		if (exponent == exp)
			coefficent += coef;
	}

	Node* getNext() {
		return next;
	}

	void show() {
		if (coefficent == 0)
			return;
		if (coefficent > 0)
			cout << " + " << coefficent << "x^" << exponent << " ";
		else
			cout << " - " << fabs(coefficent) << "x^" << exponent << " ";
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

	void addToHead(int exp, double coef) {
		if (coef == 0)	// non-zero polynomial members
			return;
		head = new Node(exp, coef, head);
		if (tail == nullptr)
			tail = head;
	}

	void addToTail(int exp, double coef) {
		if (coef == 0)	// non-zero polynomial members
			return;
		tail->next = new Node(exp, coef, nullptr);
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

	void multiplyPolynomials(linkedList* poly) {
		linkedList* list = new linkedList();
		Node* tmp = head;
		while (tmp != nullptr) {
			
			Node* probe = poly->head;
			while (probe != nullptr) {
				double multiplication = probe->coefficent * tmp->coefficent;
				int exponential = probe->exponent + tmp->exponent;

				Node* check = list->head;
				while (check != nullptr && check->exponent != exponential)
					check = check->next;

				if (check == nullptr)
					list->addToHead(exponential, multiplication);
				else
					check->enlargeNode(exponential, multiplication);

				probe = probe->next;
			}

			tmp = tmp->next;
		}
		list->showAll();
	}
};