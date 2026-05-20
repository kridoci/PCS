#include <iostream>
#include "unidirected_edge.hpp"
#include "unidirected_graph.hpp"
#include "containers.hpp"
#include "algo.hpp"
 

int main() {
	unidirected_graph<int> G;
	
	
	G.add_edge(1, 2);
	G.add_edge(1, 3);
	G.add_edge(2, 4);
	G.add_edge(3, 4);
	G.add_edge(4, 5);

	std::cout << "--- Test Visita in Ampiezza (BFS) ---" << std::endl;
	fifo<int> q;
	auto bfsG = graph_visit(G, 1, q);
	std::cout << "Archi dell'albero BFS: ";
	for(const auto& edge : bfsG.all_edges()) std::cout << edge << " ";
	std::cout << "\n\n";

	std::cout << "--- Test Visita in Profondità (DFS con LIFO) ---" << std::endl;
	lifo<int> s;
	auto dfsG = graph_visit(G, 1, s);
	std::cout << "Archi dell'albero DFS: ";
	for(const auto& edge : dfsG.all_edges()) std::cout << edge << " ";
	std::cout << "\n\n";

	std::cout << "--- Test Visita in Profondità (DFS Ricorsiva) ---" << std::endl;
	auto dfsRecG = recursive_dfs(G, 1);
	std::cout << "Archi dell'albero DFS Ricorsiva: ";
	for(const auto& edge : dfsRecG.all_edges()) std::cout << edge << " ";
	std::cout << "\n\n";

	std::cout << "--- Test Dijkstra ---" << std::endl;
	std::map<unidirected_edge<int>, double> weights;
	weights[unidirected_edge<int>(1, 2)] = 1.0;
	weights[unidirected_edge<int>(1, 3)] = 4.0;
	weights[unidirected_edge<int>(2, 4)] = 2.0;
	weights[unidirected_edge<int>(3, 4)] = 1.0;
	weights[unidirected_edge<int>(4, 5)] = 3.0;

	auto dijkstraG = dijkstra(G, 1, weights);
	std::cout << "Archi dell'albero dei cammini minimi: ";
	for(const auto& edge : dijkstraG.all_edges()) std::cout << edge << " ";
	std::cout << "\n\n";

	return 0;
}