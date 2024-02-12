#include <iostream>

#include "node.h"

Node::Node(uint32_t number, Node* parent) : mNumber(number), mParent(parent), childCount(0)
{
	for(uint32_t i = static_cast<uint32_t>(0); i < Size; ++i)
    {
	   mChildren[i] = nullptr; 
    }
}

void Node::AddChild(Node* newChild)
{
	mChildren[childCount++] = newChild;
}

void Node::DeleteChild(Node* child)
{
	uint32_t numberOfDeletedChild = static_cast<uint32_t>(0);
	for(uint32_t i = static_cast<uint32_t>(0); i < childCount; ++i)
	{
		if((child->mNumber) == (mChildren[i]->mNumber))
		{
			numberOfDeletedChild = i;
		}
	}
	
	--childCount;
	
	for(uint32_t i = numberOfDeletedChild; i < childCount; ++i)
	{
		mChildren[i] = mChildren[i + static_cast<uint32_t>(1)];
	}

	uint32_t childCountOfDeletedChild = child->childCount;
		
	for(uint32_t i = static_cast<uint32_t>(0); i < childCountOfDeletedChild; ++i)
	{
       child->mChildren[i]->mParent = child->mParent;
	   child->mParent->AddChild(child->mChildren[i]);
	}
	
	delete mChildren[numberOfDeletedChild];
}

Node::~Node()
{
    for(uint32_t i = static_cast<uint32_t>(0); i < Size; ++i)
    {
	   delete mChildren[i]; 
    }
}	
