#include <iostream>

#include "graph.h"

Graph::Graph()
{
	for(std::uint32_t i{static_cast<std::uint32_t>(0)}; i < Size; ++i)
	{
		for(std::uint32_t j{static_cast<std::uint32_t>(0)}; j < Size; ++j)
		{
		   Matrix [i][j] = static_cast<std::uint32_t>(0);	
		}
		Vertexes[i] = 0;
	}
	VertexCount = 0;		
}

void Graph::Show()
{
	for(std::uint32_t i{static_cast<std::uint32_t>(0)}; i < Size; ++i)
	{
		for(std::uint32_t j{static_cast<std::uint32_t>(0)}; j < Size; ++j)
		{
		   std::cout << Matrix [i][j] << " ";	
		}
		std::cout << std::endl;
	}
}

void Graph::AddVertex(std::uint32_t vertexNumber)
{
	++VertexCount;
	Vertexes[VertexCount] = vertexNumber;
}

void Graph::AddEdge(std::uint32_t vertexFirst, std::uint32_t vertexSecond, std::uint32_t weight)
{
	 Matrix [vertexFirst][vertexSecond] = Matrix[vertexSecond][vertexFirst] = weight;
}

void Graph::RemVertex(std::uint32_t vertexNumber)
{
   for(std::uint32_t i{static_cast<std::uint32_t>(0)}; i < Size; ++i)
   {
       Matrix[i][vertexNumber] = static_cast<std::uint32_t>(0);
	   Matrix[vertexNumber][i] = static_cast<std::uint32_t>(0);
   }
   std::uint32_t foundIndex = static_cast<std::uint32_t>(0);
   for(int i=0;i < VertexCount; i++)
   {
	 if(Vertexes[i] == vertexNumber)
		 foundIndex = i;
   }
   --VertexCount;
   for(int i=foundIndex; i< VertexCount; i++)
   {
        Vertexes[i] = Vertexes[i+1];
   }
}

void Graph::RemEdge(std::uint32_t vertexFirst, std::uint32_t vertexSecond)
{
	Matrix [vertexFirst][vertexSecond] = Matrix[vertexSecond][vertexFirst] = static_cast<std::uint32_t>(0);
}

void Graph::Depth(std::uint32_t start)
{
	//1. Initializing 
	bool visited[Size] = {false, false, false, false, false, false, false, false, false, false};
	//2. Call recursive
    Depth(start, visited);	
}

void  Graph::Depth(std::uint32_t currentVertex, bool visitedVortex[])
{
	std::cout << "V" << currentVertex << " , ";
	visitedVortex [currentVertex] = true;
	for(std::uint32_t i{0}; i < VertexCount; i++)
	{
		if(AreVertexesAdjacent(currentVertex, i) && (!visitedVortex[i]))
		{
			Depth(i, visitedVortex);
		}
	}
}

bool Graph::AreVertexesAdjacent(std::uint32_t vertex1, std::uint32_t vertex2)
{
	return static_cast<bool>(Matrix[vertex1][vertex2] != static_cast<std::uint32_t>(0));
}

void Graph::Width(std::uint32_t start)
{
	std::uint32_t queue[Size];
	std::uint32_t queueCount = static_cast<std::uint32_t>(0);
	
	bool visited[Size] = {false, false, false, false, false, false, false, false, false, false};
	
	queue[queueCount++] = start;
	
	while(queueCount > 0)
	{
		std::uint32_t currentNum = queue[0];
		queueCount --;
		for(std::uint32_t i{0}; i < queueCount; ++i )
		{
			queue[i] = queue[i + 1];
		}
		std::cout << "V" << currentNum << " , ";
		visited[currentNum] = true;
		for(std::uint32_t i{0}; i < Size; ++i)
		{
			bool alreadyAdded = false;
			for(std::uint32_t j{0}; j<queueCount; ++j)
			{
              if(queue[j] == i)
              {
                 alreadyAdded = true;
                 break;
              }
			}
           if(!alreadyAdded && AreVertexesAdjacent(currentNum,i) && !visited[i])
		   {
               queue[queueCount++] = i;
		   }
			
		}
	}
}

bool Graph::VertexExists(std::uint32_t vnumber)
{
    for(std::uint32_t i=0;i<VertexCount;i++)
	{
       if(Vertexes[i] == vnumber)
	   {
          return true;
	   }
	}
    return false;
}

