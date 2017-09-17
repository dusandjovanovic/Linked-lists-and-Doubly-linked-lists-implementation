// Lab0201.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "linkedList.h"

int main()
{
	linkedList list;
	list.addToHead(0, 11);
	list.addToHead(1, 12);
	list.addToHead(2, 14);
	list.addToTail(5, 9);
	list.showAll();

	linkedList list2;
	list2.addToHead(0, 1);
	list2.addToHead(3, 0);
	list2.addToHead(2, 13);
	list2.addToTail(5, 8);
	list2.showAll();

	list.multiplyPolynomials(&list2);

	system("pause");
	return 0;
}

