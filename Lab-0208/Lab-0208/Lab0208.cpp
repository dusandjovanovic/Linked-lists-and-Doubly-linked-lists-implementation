// Lab0208.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "linkedList.h"

int main()
{
	linkedList list;
	list.addToHead(11);
	list.addToHead(12);
	list.addToHead(13);
	list.addToTail(22);
	list.addToTail(24);
	list.addToTail(26);
	list.showAll();

	//list.getToStart(22);
	//list.getToStart(28);
	list.getTransp(22);

	system("pause");
    return 0;
}

