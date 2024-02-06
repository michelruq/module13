#pragma once

#include <cstdint>

class Graph
{
	private:
	   static constexpr const std::uint32_t Size = static_cast<std::uint32_t>(10);
	   
	   std::uint32_t Matrix [Size][Size];
	   std::uint32_t Vertexes[Size];
	   std::uint32_t VertexCount;
	   
	   void Depth(std::uint32_t currentVertex, bool visitedVortex[]);
	   bool AreVertexesAdjacent(std::uint32_t vertex1, std::uint32_t vertex2);
	   bool VertexExists(std::uint32_t vnumber);
	   
	public:
	   Graph();
	   void Show();
	   void AddVertex(std::uint32_t vertexNumber);
	   void AddEdge(std::uint32_t vertexFirst, std::uint32_t vertexSecond, std::uint32_t weight = static_cast<std::uint32_t>(1));
	   void RemVertex(std::uint32_t vertexNumber);
	   void RemEdge(std::uint32_t vertexFirst, std::uint32_t vertexSecond);
	   void Depth(std::uint32_t start);
	   void Width(std::uint32_t start);
};
