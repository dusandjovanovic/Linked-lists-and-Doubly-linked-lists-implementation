// Lab0206.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "linkedList.h"

int main()
{
	linkedList list(10);
	list.addToHead(11);
	list.addToHead(12);
	list.addToHead(14);
	list.addToTail(9);
	list.addToTail(2);
	list.addToTail(88);
	list.addToTail(1);
	list.showAll();

	list.bubbleSort();
	list.showAll();

	system("pause");
	return 0;
}

