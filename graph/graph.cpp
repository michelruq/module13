#include <iostream>

#include "graph.h"

Graph::Graph(): VertexCount(static_cast<std::uint32_t>(0)), count(static_cast<std::uint32_t>(0)), path{0}
{
	for(std::uint32_t i{static_cast<std::uint32_t>(0)}; i < Size; ++i)
	{
		for(std::uint32_t j{static_cast<std::uint32_t>(0)}; j < Size; ++j)
		{
		   Matrix [i][j] = static_cast<std::uint32_t>(0);	
		}
		Vertexes[i] = static_cast<std::uint32_t>(0);
		VisitedVertex[i] = false;
	}	
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
	Vertexes[VertexCount] = vertexNumber;
	++VertexCount;
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
	std::cout << "V" << currentVertex << " -> ";
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

std::uint32_t Graph::FindPathCount(std::uint32_t from, std::uint32_t to)
{
	count = static_cast<std::uint32_t>(0);
	
	for(std::uint32_t i{static_cast<std::uint32_t>(0)}; i < Size; ++i)
	{
	   VisitedVertex[i] = false;
	}
	
	Depth(from, to);
	
	return count;
}

void Graph::Depth(std::uint32_t currentVertex, std::uint32_t to)
{	
	VisitedVertex[currentVertex] = true;
	
	if (currentVertex == to)
	{
		++count;
	}
	else
	{
		for(std::uint32_t i{static_cast<std::uint32_t>(0)}; i < VertexCount; ++i)
		{
			if(AreVertexesAdjacent(currentVertex, i) && !VisitedVertex[i])
			{
				Depth(i, to);
			}
		}
				
	}
	VisitedVertex[currentVertex] = false;
}

void Graph::Depth(std::uint32_t currentVertex, std::uint32_t to, std::uint32_t& sum, std::uint32_t& min)
{	
	VisitedVertex[currentVertex] = true;
	path.push_back(currentVertex);
	if (currentVertex == to)
	{
       for (const auto v : path)
	   {
		  std::cout << v << " -> ";
	   }
	   std::cout << std::endl;
	   if(min > sum)
	   {
	      min = sum;
	   }
	}
	else
	{
		for(std::uint32_t i{static_cast<std::uint32_t>(0)}; i < VertexCount; ++i)
		{
			if(AreVertexesAdjacent(currentVertex, i) && !VisitedVertex[i])
			{
				sum += Matrix[currentVertex][i];
				Depth(i, to, sum, min);
				sum -= Matrix[currentVertex][i];
			}
		}
				
	}
	path.pop_back();
	VisitedVertex[currentVertex] = false;
}

void Graph::FindMinDistanceDecstr(std::uint32_t start)
{
	std::uint32_t distances[Size];
	
	for(std::uint32_t i = static_cast<std::uint32_t>(0); i < Size; ++i)
	{
		distances[i] = VeryBigInt;
	}
	
	distances[start] = static_cast<std::uint32_t>(0);
	
	bool passed[Size];
	for(std::uint32_t i = static_cast<std::uint32_t>(0); i < Size; ++i)
	{
		passed[i] = false;
	}
	
	std::uint32_t currentVertexNum = start;
    std::uint32_t min_dist = static_cast<std::uint32_t>(0);
	
	while(min_dist != VeryBigInt)
	{
		passed[currentVertexNum] = true;
		
		for(std::uint32_t i = static_cast<std::uint32_t>(0); i < Size; ++i)
		{
			if(AreVertexesAdjacent(currentVertexNum,i)
               && (distances[currentVertexNum] + Matrix[currentVertexNum][i] < distances[i]))
                    distances[i] = 
                      distances[currentVertexNum] + Matrix[currentVertexNum][i];
		}
		
		min_dist = VeryBigInt;
		
		for(std::uint32_t i = static_cast<std::uint32_t>(0); i < Size; ++i)
		{
			if(VertexExists(i) && !passed[i] && (distances[i] < min_dist))
			{
				min_dist = distances[i];
                currentVertexNum = i;
			}
		}
	}
	
	for(std::uint32_t i= static_cast<std::uint32_t>(0); i<VertexCount; ++i) // вывод результата
    {
        std::cout << "V" << i << ": " << distances[Vertexes[i]] << ", ";
    }
    std::cout << std::endl;
}

void Graph::FindMinDistanceFloyd()
{
	std::uint32_t weight[Size][Size];
	
	for(std::uint32_t i = static_cast<std::uint32_t>(0); i < Size; ++i)
	{
		for(std::uint32_t j = static_cast<std::uint32_t>(0); j < Size; ++j)
		{
			if(i == j)
			{
				weight[i][j] = static_cast<std::uint32_t>(0);
			}
			else
			{
				if(!AreVertexesAdjacent(i,j))
				{
					weight[i][j] = VeryBigInt;
				}
				else
				{
					weight[i][j] = Matrix [i][j];
				}
			}
		}
	}
	
	for(std::uint32_t k = static_cast<std::uint32_t>(0); k < VertexCount; ++k)
	{
		std::uint32_t ck = Vertexes[k];
		for(std::uint32_t i = static_cast<std::uint32_t>(0); i < VertexCount; ++i)
		{
           if(i == k)
		   {
			   continue;
		   }
		   std::uint32_t ci = Vertexes[i]; 
		   for(std::uint32_t j = static_cast<std::uint32_t>(0); j < VertexCount; ++j)
		   {
			   if(j == k)
			   {
				   continue;
			   }
			   std::uint32_t cj = Vertexes[j]; 
			   if(weight[ci][ck] + weight[ck][cj] < weight[ci][cj] )
			   {
				   weight[ci][cj] = weight[ci][ck] + weight[ck][cj];
			   }
		   }
		}			
	}
	
	for(std::uint32_t i= static_cast<std::uint32_t>(0); i<VertexCount; ++i) // вывод результата
    {
        std::cout << "V" << i << ": " << weight[0][Vertexes[i]] << ", ";
    }
    std::cout << std::endl;
}

std::uint32_t Graph::FindMinDistanceRecursive(std::uint32_t from, std::uint32_t to)
{
	std::uint32_t min = VeryBigInt;
	std::uint32_t sum = static_cast<std::uint32_t>(0);
	path.clear();
	
	for(std::uint32_t i{static_cast<std::uint32_t>(0)}; i < Size; ++i)
	{
	   VisitedVertex[i] = false;
	}
	
	Depth(from, to, sum, min);
	
	return min;
}
