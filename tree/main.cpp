#include <iostream>

#include "tree.h"

int main (int argc, char* argv[])
{
	
	Tree oFirstTree;
	
	oFirstTree.SetRoot(2);
	oFirstTree.AddNode(2, 4);
	oFirstTree.AddNode(2, 0);
	oFirstTree.AddNode(2, 3);
	oFirstTree.AddNode(4, 1);
	oFirstTree.AddNode(1, 5);
	oFirstTree.AddNode(1, 6);
	
	oFirstTree.DeleteNode(4);
	
	return 0;
}