#include "tree.h"

#include <iostream>

Tree::Tree() : root(nullptr)
{
	
}

void Tree::SetRoot(uint32_t number)
{
	if(root != nullptr)
	{
		delete root;
		root = nullptr;
	}
	root = new Node(number, nullptr);
}

void Tree::AddNode(uint32_t parentNumber, uint32_t newNodeNumber)
{
	Node* parentNode = GetNodeByNumber(parentNumber, root);
	Node* newNode = new Node(newNodeNumber, parentNode);
	parentNode->AddChild(newNode);
}

Node* Tree::GetNodeByNumber(uint32_t number, Node* current)
{
	if(current->mNumber == number)
	{
		return current;
	}
	
	for(uint32_t i {static_cast<uint32_t>(0)}; i < current->childCount; ++i)
	{
		Node* found = GetNodeByNumber(number, current->mChildren[i]);
		if(found != nullptr)
		{
			return found;
		}
	}
	
	return nullptr;
}

void Tree::DeleteNode(uint32_t number)
{
	Node* deletedNode = GetNodeByNumber(number, root);
	Node* parentOfDeletedNode = deletedNode -> mParent;
	parentOfDeletedNode->DeleteChild(deletedNode);
}

Tree::~Tree()
{
	if(root != nullptr)
	{
		delete root;
		root = nullptr;
	}
}
