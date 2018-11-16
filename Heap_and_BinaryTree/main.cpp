#include <iostream>
#include "Heap_PriorityQueue.h"
using namespace std;

int main()
{
	int anArray[] = { 1,2,3,4,5,6,7,8 };
	Heap_PriorityQueue<int> heap;
	for (int i = 0; i < 8; i++)
	{
		heap.add(anArray[i]);
	}

	/*if (heap.isEmpty())
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}*/
}