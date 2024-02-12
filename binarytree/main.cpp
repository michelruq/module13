#include <iostream>

#include "binarytree.h"

void auxiluaryFunction (Node* node)
{
	if(node != nullptr)
	{
		std::cout << " myself " << node;
		std::cout << " mData " << node->mData;
		std::cout << " mParent " << node->mParent;
		std::cout << " mLeftChild " << node->mLeftChild;
		std::cout << " mRightChild " << node->mRightChild;
		std::cout << std::endl;
	}
	else
	{
		std::cout << "nullptr" << std::endl;
	}
}

int main (int argc, char* argv[])
{
	Node* node = nullptr;
	// Use case 1 delete node without children 
	if(0)
	{
		BinaryTree oBinaryTree;
		std::int32_t testArray[] = {5, 4, -17, 20, 13, 43, 11, 18, 15, 19};
		std::int32_t outputArray[sizeof(testArray)/sizeof(std::int32_t)] = {0};
		for(std::int32_t i{0}; i < sizeof(testArray)/sizeof(std::int32_t); ++i)
		{
			oBinaryTree.AddNewNode(testArray[i]);
		}	
		
		for(std::int32_t i{0}; i < sizeof(testArray)/sizeof(std::int32_t); ++i)
		{
			auxiluaryFunction(oBinaryTree.FindNodeByData(testArray[i]));
		}

		oBinaryTree.DelNode(-17);
		
		for(std::int32_t i{0}; i < sizeof(testArray)/sizeof(std::int32_t); ++i)
		{
			auxiluaryFunction(oBinaryTree.FindNodeByData(testArray[i]));
		}
		oBinaryTree.SimmetricWalk(outputArray);
		for(std::int32_t i{0}; i < sizeof(testArray)/sizeof(std::int32_t); ++i)
		{
			std::cout << outputArray[i] << "  ";
		}
		std::cout << std::endl;
	}
	
	// Use case 2 delete node with one left children 
	if(1)
	{
		BinaryTree oBinaryTree;
		std::int32_t testArray[] = {5, 4, -17, 20, 13, 43, 11, 18, 15, 19};
		std::int32_t outputArray[sizeof(testArray)/sizeof(std::int32_t)] = {0};
		for(std::int32_t i{0}; i < sizeof(testArray)/sizeof(std::int32_t); ++i)
		{
			oBinaryTree.AddNewNode(testArray[i]);
		}	
		
		for(std::int32_t i{0}; i < sizeof(testArray)/sizeof(std::int32_t); ++i)
		{
			auxiluaryFunction(oBinaryTree.FindNodeByData(testArray[i]));
		}

		oBinaryTree.DelNode(4);
		
		for(std::int32_t i{0}; i < sizeof(testArray)/sizeof(std::int32_t); ++i)
		{
			auxiluaryFunction(oBinaryTree.FindNodeByData(testArray[i]));
		}
		oBinaryTree.SimmetricWalk(outputArray);
		for(std::int32_t i{0}; i < sizeof(testArray)/sizeof(std::int32_t); ++i)
		{
			std::cout << outputArray[i] << "  ";
		}
		std::cout << std::endl;
		
	}
	
	// Use case 3 delete node with one right children 
	if(0)
	{
		BinaryTree oBinaryTree;
		std::int32_t testArray[] = {5, 4, 3, 20, 13, 43, 11, 18, 15, 19, 67};
		std::int32_t outputArray[sizeof(testArray)/sizeof(std::int32_t)] = {0};
		for(std::int32_t i{0}; i < sizeof(testArray)/sizeof(std::int32_t); ++i)
		{
			oBinaryTree.AddNewNode(testArray[i]);
		}	
		
		for(std::int32_t i{0}; i < sizeof(testArray)/sizeof(std::int32_t); ++i)
		{
			auxiluaryFunction(oBinaryTree.FindNodeByData(testArray[i]));
		}

		oBinaryTree.DelNode(43);
		
		for(std::int32_t i{0}; i < sizeof(testArray)/sizeof(std::int32_t); ++i)
		{
			auxiluaryFunction(oBinaryTree.FindNodeByData(testArray[i]));
		}
		oBinaryTree.SimmetricWalk(outputArray);
		for(std::int32_t i{0}; i < sizeof(testArray)/sizeof(std::int32_t); ++i)
		{
			std::cout << outputArray[i] << "  ";
		}
		std::cout << std::endl;
		
	}
	
	// Use case 4 delete node with one both children (leaves)
	if(0)
	{
		BinaryTree oBinaryTree;
		std::int32_t testArray[] = {5, 4, 3, 20, 13, 43, 11, 18, 15, 19, 67};
		std::int32_t outputArray[sizeof(testArray)/sizeof(std::int32_t)] = {0};
		for(std::int32_t i{0}; i < sizeof(testArray)/sizeof(std::int32_t); ++i)
		{
			oBinaryTree.AddNewNode(testArray[i]);
		}	
		
		for(std::int32_t i{0}; i < sizeof(testArray)/sizeof(std::int32_t); ++i)
		{
			auxiluaryFunction(oBinaryTree.FindNodeByData(testArray[i]));
		}

		oBinaryTree.DelNode(18);
		
		for(std::int32_t i{0}; i < sizeof(testArray)/sizeof(std::int32_t); ++i)
		{
			auxiluaryFunction(oBinaryTree.FindNodeByData(testArray[i]));
		}
		oBinaryTree.SimmetricWalk(outputArray);
		for(std::int32_t i{0}; i < sizeof(testArray)/sizeof(std::int32_t); ++i)
		{
			std::cout << outputArray[i] << "  ";
		}
		std::cout << std::endl;
	}
	
	// Use case 5 delete node with one both children (leaves)
	if(0)
	{
		BinaryTree oBinaryTree;
		std::int32_t testArray[] = {5, 4, 3, 20, 13, 43, 11, 18, 15, 19, 67};
		std::int32_t outputArray[sizeof(testArray)/sizeof(std::int32_t)] = {0};
		for(std::int32_t i{0}; i < sizeof(testArray)/sizeof(std::int32_t); ++i)
		{
			oBinaryTree.AddNewNode(testArray[i]);
		}	
		
		for(std::int32_t i{0}; i < sizeof(testArray)/sizeof(std::int32_t); ++i)
		{
			auxiluaryFunction(oBinaryTree.FindNodeByData(testArray[i]));
		}

		oBinaryTree.DelNode(20);
		
		for(std::int32_t i{0}; i < sizeof(testArray)/sizeof(std::int32_t); ++i)
		{
			auxiluaryFunction(oBinaryTree.FindNodeByData(testArray[i]));
		}
		oBinaryTree.SimmetricWalk(outputArray);
		for(std::int32_t i{0}; i < sizeof(testArray)/sizeof(std::int32_t); ++i)
		{
			std::cout << outputArray[i] << "  ";
		}
		std::cout << std::endl;
	}
	
	delete node;
	return 0;
}