#include <iostream>
#include "graph.h"

int main(int argc, char* argv[])
{
	Graph oGraph;
	oGraph.Show();
	
	oGraph.AddVertex(0);
	oGraph.AddVertex(1);
	oGraph.AddVertex(2);
	oGraph.AddVertex(3);
	
	oGraph.AddEdge(0, 1, 5);
	oGraph.AddEdge(0, 2, 4);
	oGraph.AddEdge(0, 3, 3);
	oGraph.AddEdge(1, 2, 11);
	oGraph.AddEdge(2, 3, 9);
	
	std::cout << std::endl;
	oGraph.Show();	
	
	oGraph.RemVertex(0);

	std::cout << std::endl;
	oGraph.Show();		
	
	oGraph.RemVertex(1);
	
	std::cout << std::endl;
	oGraph.Show();	
	
	oGraph.RemVertex(2);
	
	std::cout << std::endl;
	oGraph.Show();	
	
	oGraph.RemVertex(3);
	
	std::cout << std::endl;
	oGraph.Show();
	
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
	oGraph.Show();	
	
	oGraph.Width(7);
	
	return 0;
}