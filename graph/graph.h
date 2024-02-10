#pragma once

#include <cstdint>
#include <vector>

class Graph
{
	private:
	   static constexpr const std::uint32_t Size = static_cast<std::uint32_t>(10);
	   static constexpr const std::uint32_t VeryBigInt = static_cast<std::uint32_t>(1000000000);
	   
	   std::uint32_t Matrix [Size][Size];
	   std::uint32_t Vertexes[Size];
	   bool VisitedVertex[Size];
	   std::uint32_t VertexCount;
	   std::uint32_t count;
	   
	   void Depth(std::uint32_t currentVertex, bool visitedVortex[]);
	   void Depth(std::uint32_t currentVertex, std::uint32_t to);
	   void Depth(std::uint32_t currentVertex, std::uint32_t to, std::uint32_t& sum, std::uint32_t& min);
	   bool AreVertexesAdjacent(std::uint32_t vertex1, std::uint32_t vertex2);
	   bool VertexExists(std::uint32_t vnumber);
	   
	   std::vector<int> path;
	   
	public:
	   Graph();
	   void Show();
	   void AddVertex(std::uint32_t vertexNumber);
	   void AddEdge(std::uint32_t vertexFirst, std::uint32_t vertexSecond, std::uint32_t weight = static_cast<std::uint32_t>(1));
	   void RemVertex(std::uint32_t vertexNumber);
	   void RemEdge(std::uint32_t vertexFirst, std::uint32_t vertexSecond);
	   void Depth(std::uint32_t start);
	   void Width(std::uint32_t start);
	   std::uint32_t FindPathCount(std::uint32_t from, std::uint32_t to);
	   void FindMinDistanceDecstr(std::uint32_t start);
	   void FindMinDistanceFloyd();
	   std::uint32_t FindMinDistanceRecursive(std::uint32_t from, std::uint32_t to);
};
