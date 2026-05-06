#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "randfiller.h"
#include "es5.hpp" 

int main() {
	randfiller rf;
	
	// Test su 100 vettori
	std::vector<int> sizes(100);
	rf.fill(sizes, 0, 1000); 

	for (int i = 0; i < 100; i++) {
		std::vector<int> v;
		v.resize(sizes[i]);
		rf.fill(v, -1000, 1000); 
		
		quick_sort(v);
		
		if (!is_sorted(v)) {
			std::cerr << "Errore, vettore non ordinato!\n";
			return EXIT_FAILURE;
		}
	}

	std::vector<std::string> vs = {
		"kolmogorov", "banach", "cauchy", "mirzakhani", "jacobi", 
		"galois", "gauss", "hermite", "cantor", "kovalevskaja"
	};
	quick_sort(vs);
	if (!is_sorted(vs)) return EXIT_FAILURE;
	std::cout << "Tutti i test per Bubble Sort superati con successo!\n";
	return EXIT_SUCCESS;
}