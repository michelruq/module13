#pragma once

#include <cstdint>

#include "node.h"

class Tree
{
	private:
	   Node* root;
	
	public:
	   Tree();
	   ~Tree();
	   
	   void SetRoot(uint32_t number);
	   void AddNode(uint32_t parentNumber, uint32_t newNodeNumber);
	   void DeleteNode(uint32_t number);
	   Node* GetNodeByNumber(uint32_t number, Node* current);
	   
};
