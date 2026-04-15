#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "randfiller.h"
#include "es4.hpp"

int main() {
	randfiller rf;
	
	// Test su 100 vettori di dim  0 - 1000
	
	std::vector<int> sizes(100);
	rf.fill(sizes, 0, 1000); 

	for (int i = 0; i < 100; i++) {
		std::vector<int> v;
		v.resize(sizes[i]);
		rf.fill(v, -1000, 1000); 
		
		selection_sort(v); 
		
		if (!is_sorted(v)) {
			std::cerr << "Errore: vettore di int non ordinato correttamente con Selection Sort!\n";
			return EXIT_FAILURE;
		}
	}

	// Test su stringhe
	
	std::vector<std::string> vs = {
		"kolmogorov", "banach", "cauchy", "mirzakhani", "jacobi", 
		"galois", "gauss", "hermite", "cantor", "kovalevskaja"
	};
	
	selection_sort(vs); 
	
	if (!is_sorted(vs)) {
		std::cerr << "Errore: vettore di stringhe non ordinato correttamente con Selection Sort!\n";
		return EXIT_FAILURE;
	}

	std::cout << "Tutti i test per Selection Sort superati con successo!\n";
	return EXIT_SUCCESS;
}