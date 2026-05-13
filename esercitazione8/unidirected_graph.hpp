#pragma once
#include <set>
#include <list>
#include <map>
#include <unordered_map>
#include <stdexcept>
#include "unidirected_edge.hpp"

template <typename Node>
class unidirected_graph {
private:
	
	std::set<Node> m_nodes;

	std::map<unidirected_edge<Node>, int> m_edge_to_id; //   chiave id	
	
	std::unordered_map<int, unidirected_edge<Node>> m_id_to_edge; //  l'ID  all'arco. Accesso mmediato O(1)
	
	std::map<Node, std::list<Node>> m_adj_list;
	

	int next_edge_id; // numera

public:
	
	unidirected_graph() : next_edge_id(0) {}

	unidirected_graph(const unidirected_graph& other) 
		: m_nodes(other.m_nodes), 
		  m_edge_to_id(other.m_edge_to_id), 
		  m_id_to_edge(other.m_id_to_edge), 
		  m_adj_list(other.m_adj_list), 
		  next_edge_id(other.next_edge_id) {}

	void add_edge(const Node& u, const Node& v) {
		unidirected_edge<Node> e(u, v);
		
		
		if (m_edge_to_id.find(e) == m_edge_to_id.end()) {
			
			
			m_edge_to_id[e] = next_edge_id;
			m_id_to_edge[next_edge_id] = e;
			next_edge_id++;
			
			// insert nodes
			m_nodes.insert(u);
			m_nodes.insert(v);
			
			// M_G
			m_adj_list[u].push_back(v);
			m_adj_list[v].push_back(u);
		}
	}

	// N(a)
	
	std::list<Node> neighours(const Node& n) const { 
		auto it = m_adj_list.find(n);
		if (it != m_adj_list.end()) {
			return it->second;
		}
		return std::list<Node>(); 	}

	// E
	std::list<unidirected_edge<Node>> all_edges() const {
		std::list<unidirected_edge<Node>> edges;
		for (auto const& pair : m_edge_to_id) {
			edges.push_back(pair.first);
		}
		return edges;
	}

	// V
	std::set<Node> all_nodes() const {
		return m_nodes;
	}

	// e_i \in E
	int edge_number(const unidirected_edge<Node>& e) const {
		auto it = m_edge_to_id.find(e);
		if (it != m_edge_to_id.end()) {
			return it->second;
		}
		return -1; 
			}

	
	
	unidirected_edge<Node> edge_at(int n) const {
		auto it = m_id_to_edge.find(n);
		if (it != m_id_to_edge.end()) {
			return it->second;
		}
		throw std::out_of_range("Numero d'arco non presente nel grafo");
	}

	// Diff
	unidirected_graph operator-(const unidirected_graph& other) const {
		unidirected_graph result;
		
	
		for (auto const& pair : m_edge_to_id) {
			const unidirected_edge<Node>& e = pair.first;
			
			
			if (other.m_edge_to_id.find(e) == other.m_edge_to_id.end()) {
				result.add_edge(e.from(), e.to());
			}
		}
		return result;
	}
};
