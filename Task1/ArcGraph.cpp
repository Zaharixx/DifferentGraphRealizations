#include "ArcGraph.h"

#include <unordered_set>

ArcGraph::ArcGraph(int size) : edges(size) {}

ArcGraph::~ArcGraph() {}

ArcGraph::ArcGraph(const IGraph& graph) {
	edges.clear();
	for (int from = 0; from < graph.VerticesCount(); ++from) { // �.� IGraph graph - ��������������� ����, � edges �� ����� ����� ���������� (v1, v2) � (v2, v1)
		for (int to : graph.GetNextVertices(from)) {
			edges.push_back(std::make_pair(from, to));
		}
	}
}

void ArcGraph::AddEdge(int from, int to) {
	edges.push_back(std::make_pair(from, to));
}

int ArcGraph::VerticesCount() const { // ������ ������ �������� ����� ���������� ������ �� �������, ������� ��������� ������. ������� ��� ��������, ��������, ListGraph -> ArcGraph -> ListGraph ���������� ������ ������������� ������, ���� ����� ����
	// ��� ����, ����� ������� ��������� ��������� ��������� ������ O(n) ����� ������������ ���-�������
	std::unordered_set<int> uniqueVertices;

	for (int i = 0; i < edges.size(); ++i) {
		uniqueVertices.insert(edges[i].first);
		uniqueVertices.insert(edges[i].second);
	}
	return static_cast<int>(uniqueVertices.size());
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
	std::vector<int> nextVertices;

	for (int i = 0; i < edges.size(); ++i) {
		if (edges[i].first == vertex) {
			nextVertices.push_back(edges[i].second);
		}
	}
	return nextVertices;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
	std::vector<int> prevVertices;

	for (int i = 0; i < edges.size(); ++i) {
		if (edges[i].second == vertex) {
			prevVertices.push_back(edges[i].first);
		}
	}
	return prevVertices;
}