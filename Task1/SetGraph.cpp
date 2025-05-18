#include "SetGraph.h"

SetGraph::SetGraph(int size) : adjacencyTrees(size) {}

SetGraph::~SetGraph() {}

SetGraph::SetGraph(const IGraph& graph) : adjacencyTrees(graph.VerticesCount()) {
	for (int v = 0; v < graph.VerticesCount(); ++v) {
		for (int to : graph.GetNextVertices(v)) {
			adjacencyTrees[v].insert(to);
		}
	}
}

void SetGraph::AddEdge(int from, int to) {
	adjacencyTrees[from].insert(to);
}

int SetGraph::VerticesCount() const {
	return static_cast<int>(adjacencyTrees.size());
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
	assert(vertex >= 0 && vertex < adjacencyTrees.size());
	return std::vector<int>(adjacencyTrees[vertex].begin(), adjacencyTrees[vertex].end());
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
	assert(vertex >= 0 && vertex < adjacencyTrees.size());
	std::vector<int> prevVertices;
	for (int from = 0; from < adjacencyTrees.size(); ++from) {
		if (adjacencyTrees[from].count(vertex) > 0) {
			prevVertices.push_back(from);
		}
	}
	return prevVertices;
}