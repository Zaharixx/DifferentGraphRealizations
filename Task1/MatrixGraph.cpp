#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int size) : adjacencyMatrix(size, std::vector<bool>(size, false)) {}

MatrixGraph::~MatrixGraph() {}

MatrixGraph::MatrixGraph(const IGraph& graph) : adjacencyMatrix(graph.VerticesCount(), std::vector<bool>(graph.VerticesCount(), false)) {
	for (int v = 0; v < graph.VerticesCount(); ++v) {
		std::vector<int> nextVertices = graph.GetNextVertices(v);
		for (int to : nextVertices) {
			adjacencyMatrix[v][to] = true;
		}
	}
}

void MatrixGraph::AddEdge(int from, int to) {
	adjacencyMatrix[from][to] = true;
}

int MatrixGraph::VerticesCount() const {
	return static_cast<int>(adjacencyMatrix.size());
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
	assert(vertex >= 0 && vertex < adjacencyMatrix.size());
	std::vector<int> nextVertices;

	for (int to = 0; to < adjacencyMatrix.size(); ++to) {
		if (adjacencyMatrix[vertex][to]) {
			nextVertices.push_back(to);
		}
	}
	return nextVertices;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
	assert(vertex >= 0 && vertex < adjacencyMatrix.size());
	std::vector<int> prevVertices;

	for (int from = 0; from < adjacencyMatrix.size(); ++from) {
		if (adjacencyMatrix[from][vertex]) {
			prevVertices.push_back(from);
		}
	}
	return prevVertices;
}