#pragma once

#include <cstdint>

struct Node
{
    static constexpr const uint32_t Size = static_cast<uint32_t>(10);
	
	uint32_t mNumber;
	
	Node* mParent;
	Node* mChildren[Size];
	
	uint32_t childCount;
	
	Node(uint32_t number, Node* parent);
	~Node();
	
	void AddChild(Node* newChild);
	void DeleteChild(Node* child);
		
};
