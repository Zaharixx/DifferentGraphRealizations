#include "ListGraph.h"

ListGraph::ListGraph(int size) : adjacencyLists(size) {}

ListGraph::~ListGraph() {}

ListGraph::ListGraph(const IGraph& graph) : adjacencyLists(graph.VerticesCount()) {
	for (int i = 0; i < graph.VerticesCount(); ++i) {
		adjacencyLists[i] = graph.GetNextVertices(i);
	}
}

void ListGraph::AddEdge(int from, int to) {
	adjacencyLists[from].push_back(to);
}

int ListGraph::VerticesCount() const {
	return static_cast<int>(adjacencyLists.size());
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const {
	assert(vertex >= 0 && vertex < adjacencyLists.size());
	return adjacencyLists[vertex];
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const {
	assert(vertex >= 0 && vertex < adjacencyLists.size());
	std::vector<int> prevVertices;
	for (int from = 0; from < adjacencyLists.size(); ++from) {
		for (int to = 0; to < adjacencyLists[from].size(); ++to) {
			if (adjacencyLists[from][to] == vertex) {
				prevVertices.push_back(vertex);
			}
		}
	}
	return prevVertices;
}