#pragma once

inline int getLeftChildIndex(const int& nodeIndex)
{
	return (2 * nodeIndex + 1);
}

inline int getRightChildIndex(const int& nodeIndex)
{
	return (2 * nodeIndex + 2);
}

inline bool isLeaf(const int& nodeIndex, const int& itemCount)
{
	if (getLeftChildIndex(nodeIndex) >= itemCount)
	{
		return true;
	}
	return false;
}

inline bool hasRightChild(int nodeIndex, const int& itemCount)
{
	if (getRightChildIndex(nodeIndex) < itemCount)
	{
		return true;
	}
	return false;
}

template <class ItemType>
void swap(ItemType& a, ItemType& b)
{
	ItemType temp = a;
	a = b;
	b = temp;
}

template <class ItemType>
void heapRebuild(const int& index, ItemType anArray[], const int& n)
{
	if (!isLeaf(index, n))
	{
		int largerChildIndex = 2 * index + 1;
		if (hasRightChild(index, n))	//has a right child
		{
			int rightChildIndex = largerChildIndex + 1;
			if (anArray[rightChildIndex] > anArray[largerChildIndex])
			{
				largerChildIndex = rightChildIndex;
			}
		}
		if (anArray[index] < anArray[largerChildIndex])
		{
			swap(anArray[index], anArray[largerChildIndex]);
			heapRebuild(largerChildIndex, anArray, n);
		}
	}
}

template<class ItemType>
void heapSort(ItemType anArray[], const int& n)
{
	for (int index = n / 2; index >= 0; index--)
	{
		heapRebuild(index, anArray, n);
	}

	swap(anArray[0], anArray[n - 1]);
	int heapSize = n - 1;

	while (heapSize > 1)
	{
		heapRebuild(0, anArray, heapSize);
		swap(anArray[0], anArray[heapSize - 1]);
		heapSize--;
	}
}