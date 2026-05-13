#include <iostream>
#include <string>
#include <cassert>
#include <list>
#include <set>
#include "unidirected_edge.hpp"
#include "unidirected_graph.hpp"

void test_edge() {
	std::cout << "--- Inizio test unidirected_edge ---" << std::endl;
	
	// from < to
	unidirected_edge<int> e1(5, 2);
	assert(e1.from() == 2 && e1.to() == 5);
	
	unidirected_edge<std::string> e2("Zebra", "Alpaca");
	assert(e2.from() == "Alpaca" && e2.to() == "Zebra");

	// Test ==
	unidirected_edge<int> e3(2, 5);
	assert(e1 == e3);

	// Test <
	unidirected_edge<int> e4(1, 10);
	assert(e4 < e1); // (1, 10) è minore di (2, 5) perché 1 < 2

	// Test operator<< 
	std::cout << "Test stampa arco: " << e1 << std::endl;

	std::cout << "Test unidirected_edge superati!\n\n";
}

void test_graph() {
	std::cout << "--- Inizio test unidirected_graph ---" << std::endl;

	unidirected_graph<char> G;

	// Test add_edge e all_nodes
	G.add_edge('A', 'B');
	G.add_edge('B', 'C');
	G.add_edge('C', 'A');
	G.add_edge('C', 'D');

	std::set<char> nodes = G.all_nodes();
	assert(nodes.size() == 4);
	assert(nodes.find('A') != nodes.end());
	assert(nodes.find('D') != nodes.end());

	// Test all_edges e edge_number
	std::list<unidirected_edge<char>> edges = G.all_edges();
	assert(edges.size() == 4);

	unidirected_edge<char> edge_AB('A', 'B');
	unidirected_edge<char> edge_CD('D', 'C'); 	
	int id_AB = G.edge_number(edge_AB);
	int id_CD = G.edge_number(edge_CD);
	assert(id_AB != -1);
	assert(id_CD != -1);

	// Test edge_at
	assert(G.edge_at(id_AB) == edge_AB);
	assert(G.edge_at(id_CD) == edge_CD);

	// Test N_a
	std::list<char> vicini_C = G.neighours('C');
	assert(vicini_C.size() == 3); 

	// Test costruttore di copia
	unidirected_graph<char> G_copy(G);
	assert(G_copy.all_nodes().size() == 4);

	// Test operator- 
	unidirected_graph<char> G_prime;
	G_prime.add_edge('A', 'B');
	G_prime.add_edge('C', 'D');

	unidirected_graph<char> G_diff = G - G_prime;
	
	// G 4 archi, G_prime 2 in comune con G
	assert(G_diff.all_edges().size() == 2);
	
	//  archi rimanenti in G_diff  (B, C) e (A, C)
	assert(G_diff.edge_number(unidirected_edge<char>('B', 'C')) != -1);
	assert(G_diff.edge_number(unidirected_edge<char>('A', 'C')) != -1);
	// (A, B) non deve esserci perché era in G_prime
	assert(G_diff.edge_number(unidirected_edge<char>('A', 'B')) == -1);

	std::cout << "Test unidirected_graph superati!\n\n";
}

int main() {
	test_edge();
	test_graph();
	
	std::cout << "+++ TUTTI I TEST SONO STATI SUPERATI CON SUCCESSO! +++" << std::endl;
	return 0;
}
