/** Link-based implementation of the ADT binary search tree.
@file BinarySearchTree.h */
#pragma once
#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include "BinaryNodeTree.h"
#include "NotFoundException.h"
#include "PrecondViolatedExcep.h"

template <class ItemType>
class BinarySearchTree : public BinaryNodeTree <ItemType>
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
		subTreePtr = removeNode(subTreePtr);
		success = true;
		return subTreePtr;
	}
	else if (subTreePtr->getItem() > target)
	{
		BinaryNode<ItemType>* tempPtr = removeValue(subTreePtr->getLeftChildPtr(), target, success);
		subTreePtr->setLeftChildPtr(tempPtr);
		return subTreePtr;
	}
	else
	{
		BinaryNode<ItemType>* tempPtr = removeValue(subTreePtr->getRightChildPtr(), target, success);
		subTreePtr->setRightChildPtr(tempPtr);
		return subTreePtr;
	}
}

template <class ItemType>
BinaryNode < ItemType > * BinarySearchTree<ItemType>::removeNode(BinaryNode < ItemType > *nodePtr)
{
	if ((nodePtr->getLeftChildPtr() == nullptr) && (nodePtr->getRightChildPtr() == nullptr))	//is a leaf
	{
		delete nodePtr;
		nodePtr = nullptr;
		return nodePtr;
	}
	else if ((nodePtr->getLeftChildPtr() == nullptr) || (nodePtr->getRightChildPtr() == nullptr)) //has only a child
	{
		if (nodePtr->getLeftChildPtr() != nullptr)	//has a left child
		{
			BinaryNode<ItemType>* nodeToConnectPtr = nodePtr->getLeftChildPtr();
		}
		else
		{
			BinaryNode<ItemType>* nodeToConnectPtr = nodePtr->getRightChildPtr();
			delete nodePtr;
			nodePtr = nullptr;
			return nodePtr;
		}
	}
	else
	{
		ItemType newNodeValue;
		BinaryNode<ItemType>* tempPtr = removeLeftmostNode(nodePtr->getRightChildPtr(), newNodeValue);
		nodePtr->setRightChildPtr(tempPtr);
		nodePtr->setItem(newNodeValue);
		return nodePtr;
	}
}

template <class ItemType>
BinaryNode < ItemType > * BinarySearchTree<ItemType>::removeLeftmostNode(BinaryNode < ItemType > *subTreePtr,
	ItemType & inorderSuccessor)
{
	if (subTreePtr->getLeftChildPtr() == nullptr)
	{
		inorderSuccessor = subTreePtr->getItem();
		return removeNode(subTreePtr);
	}
	else
	{
		return removeLeftmostNode(subTreePtr->getLeftChildPtr(), inorderSuccessor);
	}
}

template <class ItemType>
BinaryNode < ItemType > * BinarySearchTree<ItemType>::findNode(BinaryNode < ItemType > *treePtr,
	const ItemType & target) const
{
	if (treePtr == nullptr)
	{
		return nullptr;
	}
	else if (treePtr->getItem() == target)
	{
		return treePtr;
	}
	else if (treePtr->getItem() > target)
	{
		return findNode(treePtr->getLeftChildPtr(), target);
	}
	else
	{
		return findNode(treePtr->getRightChildPtr(), target);
	}
}

//------------------------------------------------------------
// Constructor and Destructor Section.
//------------------------------------------------------------
template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree()
	: rootPtr(nullptr)
{
}

template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType & rootItem)
{
	rootPtr = new BinaryNode<ItemType>(rootItem, nullptr, nullptr);
}

template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree < ItemType > &tree)
{
	rootPtr = copyTree(tree.rootPtr);
}

template <class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree()
{
	this->clear();
}

//------------------------------------------------------------
// Public Methods Section.
//------------------------------------------------------------
template <class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const
{
	if (rootPtr == nullptr)
	{
		return true;
	}
	return false;
}

template <class ItemType>
int BinarySearchTree<ItemType>::getHeight() const
{
	return BinaryNodeTree<ItemType>::getHeightHelper(rootPtr);
}

template <class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const
{
	return BinaryNodeTree<ItemType>::getNumberOfNodesHelper(rootPtr);
}

template <class ItemType>
ItemType BinarySearchTree<ItemType>::getRootData() const throw (PrecondViolatedExcep)
{
	if (this->isEmpty())
	{
		throw PrecondViolatedExcep("Attempted get root's data with empty root");
	}
	return rootPtr->getItem();
}

template <class ItemType>
void BinarySearchTree<ItemType>::setRootData(const ItemType & newData) const throw (PrecondViolatedExcep)
{
	if (isEmpty())
	{
		throw PrecondViolatedExcep("Attempted set root's data with empty tree");
	}
	rootPtr->setItem(newData);
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
	bool success = false;
	rootPtr = removeValue(rootPtr, anEntry, success);
	return success;
}

template <class ItemType>
void BinarySearchTree<ItemType>::clear()
{
	BinaryNodeTree<ItemType>::destroyTree(rootPtr);
}

template <class ItemType>
ItemType BinarySearchTree<ItemType>::getEntry(const ItemType & anEntry) const throw (NotFoundException)
{
	BinaryNode<ItemType>* result = findNode(rootPtr, anEntry);
	if (result == nullptr)
	{
		throw NotFoundException("Entry not found");
	}
	return result->getItem();
}

template <class ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType & anEntry) const
{
	BinaryNode<ItemType>* result = findNode(rootPtr, anEntry);
	if (result == nullptr)
	{
		return false;
	}
	return true;
}

//------------------------------------------------------------
// Public Traversals Section.
//------------------------------------------------------------
template <class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse(void visit(ItemType &)) const
{
	BinaryNodeTree<ItemType>::preorder(visit, rootPtr);
}

template <class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse(void visit(ItemType &)) const
{
	BinaryNodeTree<ItemType>::inorder(visit, rootPtr);
}

template <class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse(void visit(ItemType &)) const
{
	BinaryNodeTree<ItemType>::postorder(visit, rootPtr);
}

//------------------------------------------------------------
// Overloaded Operator Section.
//------------------------------------------------------------
template <class ItemType>
BinarySearchTree < ItemType > & BinarySearchTree<ItemType>::operator= (const BinarySearchTree < ItemType > &rightHandSide)
{
	if (this != &rightHandSide)
	{
		if (!(this->isEmpty()))
		{
			destroyTree(rootPtr);
		}
		rootPtr = copyTree(rightHandSide.rootPtr);
	}
	return *this;
}