#pragma once

#include <cstdint>

struct Node
{
	   int32_t mData;
	   
	   Node* mParent;
	   Node* mLeftChild;
	   Node* mRightChild;
	   
	   Node(int32_t data, Node* parent);
	   ~Node();
};