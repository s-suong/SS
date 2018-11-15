/** Link-based implementation of the ADT binary search tree.
@file BinarySearchTree.h */
#pragma once
#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include "BinaryNodeTree.h"
#include "NotFoundException.h"
#include "PrecondViolatedExcep.h"

template <class ItemType>
class BinarySearchTree :public BinaryNodeTree <ItemType>
{
private:
	BinaryNode < ItemType > *rootPtr;
protected:
	//------------------------------------------------------------
	// Protected Utility Methods Section:
	// Recursive helper methods for the public methods.
	//------------------------------------------------------------
	// Recursively finds where the given node should be placed and
	// inserts it in a leaf at that point.
	BinaryNode < ItemType > *insertInorder(BinaryNode < ItemType > *subTreePtr,
		BinaryNode < ItemType > *newNode);

	// Removes the given target value from the tree while maintaining a
	// binary search tree.
	BinaryNode < ItemType > *removeValue(BinaryNode < ItemType > *subTreePtr,
		const ItemType target, bool & success);

	// Removes a given node from a tree while maintaining a
	// binary search tree.
	BinaryNode < ItemType > *removeNode(BinaryNode < ItemType > *nodePtr);
	// Removes the leftmost node in the left subtree of the node
	// pointed to by nodePtr.
	// Sets inorderSuccessor to the value in this node.
	// Returns a pointer to the revised subtree.
	BinaryNode < ItemType > *removeLeftmostNode(BinaryNode < ItemType > *subTreePtr,
		ItemType & inorderSuccessor);
	// Returns a pointer to the node containing the given value,
	// or nullptr if not found.
	BinaryNode < ItemType > *findNode(BinaryNode < ItemType > *treePtr,
		const ItemType & target) const;

public:
	//------------------------------------------------------------
	// Constructor and Destructor Section.
	//------------------------------------------------------------
	BinarySearchTree();
	BinarySearchTree(const ItemType & rootItem);

	BinarySearchTree(const BinarySearchTree < ItemType > &tree);

	virtual ~BinarySearchTree();
	//------------------------------------------------------------
	// Public Methods Section.
	//------------------------------------------------------------
	bool isEmpty() const;

	int getHeight() const;

	int getNumberOfNodes() const;

	ItemType getRootData() const throw (PrecondViolatedExcep);

	void setRootData(const ItemType & newData) const throw (PrecondViolatedExcep);

	bool add(const ItemType & newEntry);

	bool remove(const ItemType & anEntry);

	void clear();

	ItemType getEntry(const ItemType & anEntry) const throw (NotFoundException);

	bool contains(const ItemType & anEntry) const;

	//------------------------------------------------------------
	// Public Traversals Section.
	//------------------------------------------------------------
	void preorderTraverse(void visit(ItemType &)) const;

	void inorderTraverse(void visit(ItemType &)) const;

	void postorderTraverse(void visit(ItemType &)) const;

	//------------------------------------------------------------
	// Overloaded Operator Section.
	//------------------------------------------------------------
	BinarySearchTree < ItemType > &operator= (const BinarySearchTree < ItemType > &rightHandSide);
};  // end BinarySearchTree





//------------------------------------------------------------
// Protected Utility Methods Section:
// Recursive helper methods for the public methods.
//------------------------------------------------------------
template <class ItemType>
BinaryNode < ItemType > * BinarySearchTree<ItemType>::insertInorder(BinaryNode < ItemType > *subTreePtr,
	BinaryNode < ItemType > *newNode)
{
	if (subTreePtr == nullptr)
	{
		return newNode;
	}
	else if (subTreePtr->getItem() > newNode->getItem())
	{
		BinaryNode<ItemType>* tempPtr = insertInorder(subTreePtr->getLeftChildPtr(), newNode);
		subTreePtr->setLeftChildPtr(tempPtr);
	}
	else
	{
		BinaryNode<ItemType>* tempPtr = insertInorder(subTreePtr->getRightChildPtr(), newNode);
		subTreePtr->setRightChildPtr(tempPtr);
	}
	return subTreePtr;
}

template <class ItemType>
BinaryNode < ItemType > * BinarySearchTree<ItemType>::removeValue(BinaryNode < ItemType > *subTreePtr,
	const ItemType target, bool & success)
{
	if (subTreePtr == nullptr)
	{
		success = false;
		return nullptr;
	}
	else if (subTreePtr->getItem() == target)
	{

	}
}

template <class ItemType>
BinaryNode < ItemType > * BinarySearchTree<ItemType>::removeNode(BinaryNode < ItemType > *nodePtr)
{

}

template <class ItemType>
BinaryNode < ItemType > * BinarySearchTree<ItemType>::removeLeftmostNode(BinaryNode < ItemType > *subTreePtr,
	ItemType & inorderSuccessor)
{

}

template <class ItemType>
BinaryNode < ItemType > * BinarySearchTree<ItemType>::findNode(BinaryNode < ItemType > *treePtr,
	const ItemType & target) const
{

}

//------------------------------------------------------------
// Constructor and Destructor Section.
//------------------------------------------------------------
template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree()
{

}

template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType & rootItem)
{

}

template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree < ItemType > &tree)
{

}

template <class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree()
{

}

//------------------------------------------------------------
// Public Methods Section.
//------------------------------------------------------------
template <class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const
{

}

template <class ItemType>
int BinarySearchTree<ItemType>::getHeight() const
{

}

template <class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const
{

}

template <class ItemType>
ItemType BinarySearchTree<ItemType>::getRootData() const throw (PrecondViolatedExcep)
{

}

template <class ItemType>
void BinarySearchTree<ItemType>::setRootData(const ItemType & newData) const throw (PrecondViolatedExcep)
{

}

template <class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType & newEntry)
{
	BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newEntry);
	rootPtr = insertInorder(rootPtr, newNodePtr);
	
	return true;
}

template <class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType & anEntry)
{

}

template <class ItemType>
void BinarySearchTree<ItemType>::clear()
{

}

template <class ItemType>
ItemType BinarySearchTree<ItemType>::getEntry(const ItemType & anEntry) const throw (NotFoundException)
{

}

template <class ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType & anEntry) const
{

}

//------------------------------------------------------------
// Public Traversals Section.
//------------------------------------------------------------
template <class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse(void visit(ItemType &)) const
{

}

template <class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse(void visit(ItemType &)) const
{

}

template <class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse(void visit(ItemType &)) const
{

}

//------------------------------------------------------------
// Overloaded Operator Section.
//------------------------------------------------------------
template <class ItemType>
BinarySearchTree < ItemType > & BinarySearchTree<ItemType>::operator= (const BinarySearchTree < ItemType > &rightHandSide)
{

}