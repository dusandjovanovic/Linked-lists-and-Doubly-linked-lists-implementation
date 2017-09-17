#pragma once

#include <iostream>
using namespace std;

template <typename type>
class Node {
protected:
	type info;
	int level;
	Node<type>** link;
public:
	Node() {
		level = 0;
		link = nullptr;
	}
	Node(type element, int newLevel) {
		info = element;
		level = newLevel;
		link = new Node<type>*[level];
		int i = 0;
		while (i < level) {
			link[i] = nullptr;
			i++;
		}
	}
	~Node() {
		delete[] level;
	}

	type nodeValue() {
		return info;
	}

	bool isEqual(type element) {
		return info == element;
	}
};

template <typename type>
class skipList {
protected:
	int maxLevel;
	Node<type>* root;
	long noElements;
public:
	skipList(int newLevel) {
		maxLevel = newLevel;
		root = nullptr;
		noElements = 0;
	}

	~skipList() {
		while (root != nullptr) {
			Node<type>* tmp = root;
			root = root->link[0];
			delete tmp;
		}
	}

	void updateLinks(Node<type>* node) {
		if (node == nullptr)
			return;
		updateLinks(node->link[0]);
		Node<type>* tmp = node->link[0];
		int level = 1;
		while (level < node->level && tmp != nullptr)
			node->link[level] = node->link[tmp->level - 1];
			level++;
	}

	bool isInList(type element) {
		Node<type>* curr;
		Node<type>* prev;
		int level;
		curr = root;
		prev = nullptr;
		for (level = maxLevel - 1; level >= 0; level--) {
			while (curr != nullptr && curr->info < element) {
				prev = curr;
				curr = curr->link[level];
			}
			if (curr != nullptr && curr->info == info)
				return true;
			if (level > 0) {
				if (prev == nullptr)
					curr = root->link[level - 1];
				else
					curr = prev->link[level - 1];
			}
		}
		return false;
	}

	bool isEmpty() {
		return root == nullptr;
	}
};