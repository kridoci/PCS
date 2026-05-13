#pragma once
#include <iostream>

template <typename Node>
class unidirected_edge {
private:
	Node n_from;
	Node n_to;


public:

	
	// Costruttore di default  contenitori STL (map/unordered_map)
	unidirected_edge() = default;

	// costruttore from < to
	unidirected_edge(const Node& a, const Node& b) {
		if (a < b) {
			n_from = a;
			n_to = b;
		} else {
			n_from = b;
			n_to = a;
		}
	}

	// metodi getter (non modificano obj)
	Node from() const { return n_from; }
	Node to() const { return n_to; }

	// uguaglianza
	bool operator==(const unidirected_edge& other) const {
		return (n_from == other.n_from && n_to == other.n_to);
	}

	//  minore per l'ordinamento
	bool operator<(const unidirected_edge& other) const {
		if (n_from == other.n_from) {
			return n_to < other.n_to;
		}
		return n_from < other.n_from;
	}
};

// stampa (fuori classe)
template <typename Node>
std::ostream& operator<<(std::ostream& os, const unidirected_edge<Node>& e) {
	os << "{" << e.from() << ", " << e.to() << "}";
	return os;
}
