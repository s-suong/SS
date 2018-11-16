/** ADT priority queue: Heap-based implementation.
@file Heap_PriorityQueue.h */
#pragma once
#include "ArrayMaxHeap.h"
#include "PriorityQueueInterface.h"

template <class ItemType> 
class Heap_PriorityQueue: public PriorityQueueInterface < ItemType >, private ArrayMaxHeap <ItemType>
{
public:
  Heap_PriorityQueue ();
  bool isEmpty () const;

  bool add (const ItemType & newEntry);

  bool remove ();

/** @pre The priority queue is not empty. */
  ItemType peek () const throw (PrecondViolatedExcep);
};  // end Heap_PriorityQueue







template <class ItemType>
Heap_PriorityQueue<ItemType>::Heap_PriorityQueue()
{
	ArrayMaxHeap<ItemType>();
}

template <class ItemType>
bool Heap_PriorityQueue<ItemType>::isEmpty() const
{
	return ArrayMaxHeap<ItemType>::isEmpty();
}

template <class ItemType>
bool Heap_PriorityQueue<ItemType>::add(const ItemType & newEntry)
{
	return ArrayMaxHeap<ItemType>::add(newEntry);
}

template <class ItemType>
bool Heap_PriorityQueue<ItemType>::remove()
{
	return ArrayMaxHeap<ItemType>::remove();
}

template <class ItemType>
ItemType Heap_PriorityQueue<ItemType>::peek() const throw (PrecondViolatedExcep)
{
	try
	{
		return ArrayMaxHeap<ItemType>::peekTop();
	}
	catch (PrecondViolatedExcep e)
	{
		throw PrecondViolatedExcep("Attempted peek into an empty priority queue.");
	}
}