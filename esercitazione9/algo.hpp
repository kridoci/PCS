#pragma once
#include "unidirected_graph.hpp"
#include "unidirected_edge.hpp"
#include <set>
#include <map>
#include <limits>


// visita
template <typename Node, typename Container>
unidirected_graph<Node> graph_visit(const unidirected_graph<Node>& G, const Node& source, Container& c) {
	unidirected_graph<Node> tree;
	std::set<Node> visited;
	std::map<Node, Node> parent; // chi ha scoperto chi per costruire l'albero

	c.put(source);
	parent[source] = source;

	while (!c.empty()) {
		Node u = c.get();

		if (visited.find(u) == visited.end()) {
			visited.insert(u);
			
			// aggiunge arco all'albero
			if (u != source) {
				tree.add_edge(parent[u], u);
			}

			// aggiunge  vicini non visitati al contenitore
			for (const Node& v : G.neighours(u)) { 
				if (visited.find(v) == visited.end()) {
					parent[v] = u; 
					c.put(v);
				}
			}
		}
	}
	return tree;
}

// visita ricorsiva DFS funzione helper
template <typename Node>
void dfs_recursive_helper(const unidirected_graph<Node>& G, const Node& u, std::set<Node>& visited, unidirected_graph<Node>& tree) {
	visited.insert(u);
	for (const Node& v : G.neighours(u)) {
		if (visited.find(v) == visited.end()) {
			tree.add_edge(u, v);
			dfs_recursive_helper(G, v, visited, tree);
		}
	}
}


template <typename Node>
unidirected_graph<Node> recursive_dfs(const unidirected_graph<Node>& G, const Node& source) {
	unidirected_graph<Node> tree;
	std::set<Node> visited;
	dfs_recursive_helper(G, source, visited, tree);
	return tree;
}

// dijkstra
template <typename Node>
unidirected_graph<Node> dijkstra(const unidirected_graph<Node>& G, const Node& source, const std::map<unidirected_edge<Node>, double>& weights) {
	unidirected_graph<Node> tree;
	std::map<Node, double> dist;
	std::map<Node, Node> parent;
	
	// dist infinite
	for (const Node& n : G.all_nodes()) {
		dist[n] = std::numeric_limits<double>::infinity();
	}
	dist[source] = 0.0;
	parent[source] = source;

	// std::set usato come priority queue
	std::set<std::pair<double, Node>> pq;
	pq.insert({0.0, source});

	while (!pq.empty()) {
		Node u = pq.begin()->second;
		pq.erase(pq.begin()); // erase v con dist min

		if (u != source) {
			tree.add_edge(parent[u], u);
		}

		for (const Node& v : G.neighours(u)) {
			unidirected_edge<Node> edge(u, v);
			
			// w_a,b
			double weight = 1.0; 
			auto it = weights.find(edge);
			if (it != weights.end()) {
				weight = it->second;
			}

			
			if (dist[u] + weight < dist[v]) {
				pq.erase({dist[v], v}); 
				dist[v] = dist[u] + weight;
				parent[v] = u;
				pq.insert({dist[v], v}); 
			}
		}
	}
	return tree;
}

