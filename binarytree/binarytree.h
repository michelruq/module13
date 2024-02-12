#pragma once

#include <cstdint>

#include "node.h"

class BinaryTree
{
	private:
	   Node* root;
	   
	   bool IsLeaf(Node* check);
	   bool IsRoot(Node* check);
	   void DeleteLeaf(Node* leaf);
	   void DeleteNodeWithOneChild(Node* deletedNode);
	   void SetNewChild(Node* child, Node* newChild);
	   void SimmetricWalk(int32_t output_array[], uint32_t& counter, Node* current);
	   
	public:
	   BinaryTree();
	   ~BinaryTree();
	   
	   void AddNewNode (int32_t data);
	   Node* FindNodeByData(int32_t data);
	   void DelNode(int32_t data);
	   void SimmetricWalk(int32_t output_array[]);
	   
};