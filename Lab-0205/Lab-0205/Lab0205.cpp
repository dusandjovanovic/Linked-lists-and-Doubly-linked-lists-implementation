// Lab0205.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "linkedList.h"

int main()
{
	linkedList list;
	list.addToHead(11);
	list.addToHead(12);
	list.addToHead(20);
	list.addToTail(9);
	list.addToTail(2);
	list.addToTail(88);
	list.addToTail(1);
	list.showAll();

	list.insertionSort();
	list.showAll();

	system("pause");
	return 0;
}

