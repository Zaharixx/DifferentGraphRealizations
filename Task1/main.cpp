#include "IGraph.h"
#include "ListGraph.h"
#include "MatrixGraph.h"
#include "SetGraph.h"
#include "ArcGraph.h"
#include "GraphActions.h"

#include <iostream>

void runGraphTest(const IGraph& graph) {
	std::cout << "BFS: ";
	mainBFS(graph, [](int vert) {std::cout << vert << " "; });
	std::cout << std::endl;

	std::cout << "DFS: ";
	mainDFS(graph, [](int vert) {std::cout << vert << " "; });
	std::cout << std::endl;

	std::cout << "Topological sort: ";
	for (int vertex : topologicalSort(graph)) {
		std::cout << vertex << " ";
	}

	std::cout << std::endl;
}

//                 0 
//              /     \
//             1       2
//           /    \   /      Напраление везде сверху-вниз кроме ребра 5 -> 1 (Таким образом, 0 -> 2 -> 5 -> 1 -> 0 - цикл)
//          4       5 
//          |
//          3
//
//
//                  6
//
//     Ожидается, что ArcGraph не сохранит вершину 6

int main(int argc, const char * argv[]) {
	ListGraph listGraph(7);
	listGraph.AddEdge(0, 1);
	listGraph.AddEdge(0, 2);
	listGraph.AddEdge(2, 5);
	listGraph.AddEdge(1, 4);
	listGraph.AddEdge(5, 1);
	listGraph.AddEdge(4, 3);

	std::cout << "ListGraph" << std::endl;
	runGraphTest(listGraph);
	std::cout << std::endl;

	MatrixGraph matrixGraph = listGraph;

	std::cout << "MatrixGraph" << std::endl;
	runGraphTest(matrixGraph);
	std::cout << std::endl;

	SetGraph setGraph = matrixGraph;

	std::cout << "SetGraph" << std::endl;
	runGraphTest(setGraph);
	std::cout << std::endl;

	ArcGraph arcGraph = setGraph;

	std::cout << "ArcGraph" << std::endl;
	runGraphTest(arcGraph);
	std::cout << std::endl;
}