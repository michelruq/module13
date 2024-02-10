#include <iostream>
#include "graph.h"

int main(int argc, char* argv[])
{
	Graph oGraph;
	// oGraph.Show();
	
	// oGraph.AddVertex(0);
	// oGraph.AddVertex(1);
	// oGraph.AddVertex(2);
	// oGraph.AddVertex(3);
	
	// oGraph.AddEdge(0, 1, 5);
	// oGraph.AddEdge(0, 2, 4);
	// oGraph.AddEdge(0, 3, 3);
	// oGraph.AddEdge(1, 2, 11);
	// oGraph.AddEdge(2, 3, 9);
	
	// std::cout << std::endl;
	// oGraph.Show();	
	
	// oGraph.RemVertex(0);

	// std::cout << std::endl;
	// oGraph.Show();		
	
	// oGraph.RemVertex(1);
	
	// std::cout << std::endl;
	// oGraph.Show();	
	
	// oGraph.RemVertex(2);
	
	// std::cout << std::endl;
	// oGraph.Show();	
	
	// oGraph.RemVertex(3);
	
	// std::cout << std::endl;
	// oGraph.Show();
	
	oGraph.AddVertex(0);
	oGraph.AddVertex(1);
	oGraph.AddVertex(2);
	oGraph.AddVertex(3);
	oGraph.AddVertex(4);
	oGraph.AddVertex(5);
	oGraph.AddVertex(6);
	oGraph.AddVertex(7);
	oGraph.AddVertex(8);
	
	oGraph.AddEdge(0, 1);
	oGraph.AddEdge(0, 2);
	oGraph.AddEdge(0, 3);
	oGraph.AddEdge(1, 4);
	oGraph.AddEdge(2, 5);
	oGraph.AddEdge(4, 3);
	oGraph.AddEdge(5, 3);
	oGraph.AddEdge(4, 7);
	oGraph.AddEdge(3, 6);
	oGraph.AddEdge(3, 7);
	oGraph.AddEdge(3, 8);
	oGraph.AddEdge(5, 8);
	oGraph.AddEdge(8, 6);
	oGraph.AddEdge(7, 6);
	
	std::cout << std::endl;
	//oGraph.Show();	
	//for(int i {0}; i < 8; ++i)
	{
	   std::cout << oGraph.FindPathCount(0, 6) << std::endl;
	}
	
	// Graph oGraph1;
	
	// oGraph1.AddVertex(0);
	// oGraph1.AddVertex(1);
	// oGraph1.AddVertex(2);
	// oGraph1.AddVertex(3);
	// oGraph1.AddVertex(4);
	// oGraph1.AddVertex(5);
	
	// oGraph1.AddEdge(0, 2, 13);
	// oGraph1.AddEdge(0, 4, 21);
	// oGraph1.AddEdge(0, 5, 27);
	// oGraph1.AddEdge(2, 3, 82);
	// oGraph1.AddEdge(2, 4, 77);
	// oGraph1.AddEdge(1, 4, 43);
	// oGraph1.AddEdge(1, 5, 38);
	// oGraph1.AddEdge(4, 5, 11);
	
	// std::cout << std::endl;
	// oGraph1.Show();	

    // oGraph1.FindMinDistanceDecstr(0);
	
	// Graph oGraph2;
	
	// oGraph2.AddVertex(0);
	// oGraph2.AddVertex(1);
	// oGraph2.AddVertex(2);
	// oGraph2.AddVertex(3);
	// oGraph2.AddVertex(4);
	// oGraph2.AddVertex(5);
	
	// oGraph2.AddEdge(0, 2, 13);
	// oGraph2.AddEdge(0, 4, 21);
	// oGraph2.AddEdge(0, 5, 27);
	// oGraph2.AddEdge(2, 3, 82);
	// oGraph2.AddEdge(2, 4, 77);
	// oGraph2.AddEdge(1, 4, 43);
	// oGraph2.AddEdge(1, 5, 38);
	// oGraph2.AddEdge(4, 5, 11);
	
	std::cout << oGraph.FindMinDistanceRecursive(0, 6) << std::endl;
	
	return 0;
}