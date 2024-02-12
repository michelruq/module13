#include "binarytree.h"
#include <iostream>

BinaryTree::BinaryTree() : root(nullptr)
{
	
}

bool BinaryTree::IsLeaf(Node* check)
{
	return ((check->mLeftChild == nullptr) && (check->mRightChild == nullptr));
}

bool BinaryTree::IsRoot(Node* check)
{
	return (check == root);
}

void BinaryTree::DeleteLeaf(Node* leaf)
{
	if(IsRoot(leaf))
	{
		root = nullptr;
	}
	else
	{
		SetNewChild(leaf, nullptr);
	}
	delete leaf;
}

void BinaryTree::DeleteNodeWithOneChild(Node* deletedNode)
{
	if(deletedNode->mLeftChild != nullptr)
	{
		if(IsRoot(deletedNode))
		{
			root = deletedNode->mLeftChild;
		}
		else
		{
			SetNewChild(deletedNode, deletedNode->mLeftChild);
		}
		deletedNode->mLeftChild->mParent = deletedNode->mParent;
		deletedNode->mLeftChild = nullptr; 
	}
	else
	{
		if(IsRoot(deletedNode))
		{
			root = deletedNode->mRightChild;
		}
		else
		{
			SetNewChild(deletedNode, deletedNode->mRightChild);
		}
		deletedNode->mRightChild->mParent = deletedNode->mParent;
		deletedNode->mRightChild = nullptr; 
	}
	delete deletedNode;
}

void BinaryTree::SetNewChild(Node* child, Node* newChild)
{
	Node* parent = child->mParent;
	if(parent != nullptr)
	{
		if(parent->mLeftChild == child)
		{
			parent->mLeftChild = newChild;
		}
		else
		{
			parent->mRightChild = newChild;
		}
	}
}

void BinaryTree::AddNewNode (int32_t data)
{
	if(root == nullptr)
	{
		root = new Node(data, nullptr);
	}
	else
	{
		Node* current = root;
		Node* newNode = nullptr;
		while(newNode == nullptr)
		{
			if(current->mData > data)
			{
				if(current->mLeftChild != nullptr)
				{
					current = current->mLeftChild;
					continue;
				}
				newNode = new Node(data, current);
				current->mLeftChild = newNode;
			}
			else
			{
				if(current->mRightChild != nullptr)
				{
					current = current->mRightChild;
					continue;
				}
				newNode = new Node(data, current);
				current->mRightChild = newNode;
			}
		}
	}
}

Node* BinaryTree::FindNodeByData(int32_t data)
{
	Node* current = root;
	while(current->mData != data)
	{
		if(current->mData > data)
		{
			if(current->mLeftChild != nullptr)
			{
				current = current->mLeftChild;
				continue;
			}
			else
			{
				return nullptr;
			}
		}
		else
		{
			if(current->mRightChild != nullptr)
			{
				current = current->mRightChild;
				continue;
			}
			else
			{
				return nullptr;
			}
		}
	}
	return current;
}

void BinaryTree::DelNode(int32_t data)
{
	Node* deletedNode = FindNodeByData(data);
	if(deletedNode != nullptr)
	{
		Node* parentOfDeletedNode = deletedNode->mParent;
		
		if(IsLeaf(deletedNode))
		{
			std::cout << "case3" << std::endl;
			DeleteLeaf(deletedNode);
		}
		else if((deletedNode->mLeftChild == nullptr) || (deletedNode->mRightChild == nullptr))
		{
			DeleteNodeWithOneChild(deletedNode);
		}
		else if(deletedNode->mRightChild != nullptr && deletedNode->mLeftChild != nullptr)
		{
			std::cout << "case4" << std::endl;
			Node* current = deletedNode->mLeftChild;
			Node* nodeInsteadOfDeleted = nullptr;
			while(current != nullptr)
			{
				nodeInsteadOfDeleted = current;
				current = current->mRightChild;
			}
			// Так как мы не трогали правую ветку то и правый ребенок без изменения переходит новому 
			nodeInsteadOfDeleted->mRightChild = deletedNode->mRightChild;
			// Забираем самый правый из левой ветки и родителю в mParent передаем его
			(nodeInsteadOfDeleted->mParent) -> mRightChild = nodeInsteadOfDeleted ->mRightChild;
			// Помещаем новый узел взамен удаленного и в поля родителя прописываем то значение которое было у удаленного
			nodeInsteadOfDeleted->mParent = deletedNode->mParent;
			// С левым ребенком могут быть проблемы, потому что он может оказаться единственным и тем на что мы заменяем
			if(nodeInsteadOfDeleted != deletedNode->mLeftChild)
			{
			   nodeInsteadOfDeleted->mLeftChild = deletedNode->mLeftChild;
			}
			else
			{
				nodeInsteadOfDeleted->mLeftChild = nullptr;
			}
			
			parentOfDeletedNode->mRightChild = nodeInsteadOfDeleted;
		}
	}
}

BinaryTree::~BinaryTree()
{
	if(root != nullptr)
	{
		delete root;
	}
}

void BinaryTree::SimmetricWalk(int32_t output_array[])
{
	if(root != nullptr)
	{
		uint32_t counter = 0;
		SimmetricWalk(output_array, counter, root);
	}
}

void BinaryTree::SimmetricWalk(int32_t output_array[], uint32_t& counter, Node* current)
{
	if(current->mLeftChild != nullptr)
	{
		SimmetricWalk(output_array, counter, current->mLeftChild);
	}
	output_array[counter++] = current->mData;
	if(current->mRightChild != nullptr)
	{
		SimmetricWalk(output_array, counter, current->mRightChild);
	}
}