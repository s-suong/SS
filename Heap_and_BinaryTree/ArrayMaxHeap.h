/** Array-based implementation of the ADT heap.
@file ArrayMaxHeap.h */
#pragma once
#include "HeapInterface.h"
#include "PrecondViolatedExcep.h"

template <class ItemType>
class ArrayMaxHeap :public HeapInterface < ItemType >
{
private:
	static const int ROOT_INDEX = 0;	// Helps with readability

	static const int DEFAULT_CAPACITY = 21;	// Small capacity to test for a full heap

	ItemType *items;		// Array of heap items

	int itemCount;		// Current count of heap items

	int maxItems;			// Maximum capacity of the heap

  // ---------------------------------------------------------------------
  // Most of the private utility methods use an array index as a parameter
  // and in calculations. This should be safe, even though the array is an
  // implementation detail, since the methods are private.
  // ---------------------------------------------------------------------
  // Returns the array index of the left child (if it exists).
	int getLeftChildIndex(const int nodeIndex) const;

	// Returns the array index of the right child (if it exists).
	int getRightChildIndex(int nodeIndex) const;

	// Returns the array index of the parent node.
	int getParentIndex(int nodeIndex) const;

	// Tests whether this node is a leaf.
	bool isLeaf(int nodeIndex) const;

	// Converts a semiheap to a heap.
	void heapRebuild(int subTreeRootIndex);

	// Creates a heap from an unordered array.
	void heapCreate();

public:
	ArrayMaxHeap();
	ArrayMaxHeap(const ItemType someArray[], const int arraySize);

	virtual ~ArrayMaxHeap();
	// HeapInterface Public Methods:
	bool isEmpty() const;

	int getNumberOfNodes() const;

	int getHeight() const;

	ItemType peekTop() const throw (PrecondViolatedExcep);

	bool add(const ItemType & newData);

	bool remove();

	void clear();
};  // end ArrayMaxHeap






template <class ItemType>
int ArrayMaxHeap<ItemType>::getLeftChildIndex(const int nodeIndex) const
{
	return (2 * nodeIndex + 1);
}

template <class ItemType>
int ArrayMaxHeap<ItemType>::getRightChildIndex(int nodeIndex) const
{
	return (2 * nodeIndex + 2);
}

template <class ItemType>
int ArrayMaxHeap<ItemType>::getParentIndex(int nodeIndex) const
{
	return ((nodeIndex - 1) / 2);
}

template <class ItemType>
bool ArrayMaxHeap<ItemType>::isLeaf(int nodeIndex) const
{
	if (this->getLeftChildIndex(nodeIndex) >= itemCount)
	{
		return true;
	}
	return false;
}

template <class ItemType>
void ArrayMaxHeap<ItemType>::heapRebuild(int subTreeRootIndex)
{
	if (!this->isLeaf(subTreeRootIndex))
	{
		int largerChildIndex = 2 * subTreeRootIndex + 1;
		if (this->getRightChildIndex(subTreeRootIndex) < itemCount)	//has a right child
		{
			int rightChildIndex = largerChildIndex + 1;
			if (items[rightChildIndex] > items[largerChildIndex])
			{
				largerChildIndex = rightChildIndex;
			}
		}
		if (items[subTreeRootIndex] < items[largerChildIndex])
		{
			//Swap items[subTreeRootIndex] and items[largerChildIndex]
			ItemType temp = items[subTreeRootIndex];
			items[subTreeRootIndex] = items[largerChildIndex];
			items[largerChildIndex] = temp;

			heapRebuild(largerChildIndex);
		}
	}
}

template <class ItemType>
void ArrayMaxHeap<ItemType>::heapCreate()
{
	for (int i = itemCount / 2; i >= 0; i--)
	{
		heapRebuild(i);
	}
}

template <class ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap()
	: itemCount(0), maxItems(DEFAULT_CAPACITY)
{
	items = new ItemType[DEFAULT_CAPACITY];
}

template <class ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap(const ItemType someArray[], const int arraySize)
	: itemCount(arraySize), maxItems(2 * arraySize)
{
	items = new ItemType[2 * arraySize];
	for (int i = 0; i < itemCount; i++)
	{
		items[i] = someArray[i];
	}
	heapCreate();
}

template <class ItemType>
ArrayMaxHeap<ItemType>::~ArrayMaxHeap()
{
	if (items != nullptr)
	{
		delete items;
	}
}

// HeapInterface Public Methods:
template <class ItemType>
bool ArrayMaxHeap<ItemType>::isEmpty() const
{
	if (itemCount == 0)
	{
		return true;
	}
	return false;
}

template <class ItemType>
int ArrayMaxHeap<ItemType>::getNumberOfNodes() const
{
	return itemCount;
}

template <class ItemType>
int ArrayMaxHeap<ItemType>::getHeight() const
{
	if (this->isEmpty())
	{
		return 0;
	}
	else
	{
		int height = 0;
		int index = itemCount - 1;
		while (index != ROOT_INDEX)
		{
			height++;
			index = this->getParentIndex(index);
		}
		return height;
	}
}

template <class ItemType>
ItemType ArrayMaxHeap<ItemType>::peekTop() const throw (PrecondViolatedExcep)
{
	if (this->isEmpty())
	{
		throw PrecondViolatedExcep("Attempted peek into an empty heap.");
	}

	return items[ROOT_INDEX];
}

template <class ItemType>
bool ArrayMaxHeap<ItemType>::add(const ItemType & newData)
{
	if (itemCount == maxItems)
	{
		return false;
	}
	else
	{
		items[itemCount] = newData;
		int newDataIndex = itemCount;
		bool inPlace = false;
		while ((newDataIndex >= 0) && !inPlace)
		{
			int parentIndex = getParentIndex(newDataIndex);
			if ((items[newDataIndex] < items[parentIndex]) || (newDataIndex == parentIndex))
													//when it reaches root (newDataIndex ==parentIndex)
			{
				inPlace = true;
			}
			else
			{
				//Swap items[newDataIndex] and items[parentIndex]
				ItemType temp = items[newDataIndex];
				items[newDataIndex] = items[parentIndex];
				items[parentIndex] = temp;

				newDataIndex = parentIndex;
			}
		}
		itemCount++;
		return true;
	}
}

template <class ItemType>
bool ArrayMaxHeap<ItemType>::remove()
{
	if (itemCount > 0)
	{
		items[ROOT_INDEX] = items[itemCount - 1];
		itemCount--;
		heapRebuild(ROOT_INDEX);
		return true;
	}
	return false;
}

template <class ItemType>
void ArrayMaxHeap<ItemType>::clear()
{
	if (items != nullptr)
	{
		delete items;
	}
}