#include "node.h"

Node::Node(int32_t data, Node* parent) : mData(data), mParent(parent), mLeftChild(nullptr), mRightChild(nullptr)
{
	
}

Node::~Node()
{
	if (mLeftChild != nullptr)
	{
		delete mLeftChild;
	}
	
	if (mRightChild != nullptr)
	{
		delete mRightChild;
	}
}