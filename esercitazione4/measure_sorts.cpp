#include <iostream>
#include <vector>
#include <algorithm> 
#include "randfiller.h"
#include "timecounter.h"
#include "es4.hpp"

int main() {
	randfiller rf;
	timecounter tc;

	std::cout << "Dimensione\tBubble\t\tInsertion\tSelection\tstd::sort\n";

	// Ciclo mult 2
	for (int size = 4; size <= 8192; size *= 2) {
		
		std::vector<int> base_vec;
		base_vec.resize(size);
		rf.fill(base_vec, -10000, 10000);

		// Copie per diff algoritmi
		std::vector<int> v_bubble = base_vec;
		std::vector<int> v_insertion = base_vec;
		std::vector<int> v_selection = base_vec;
		std::vector<int> v_stdsort = base_vec;

		std::cout << size << "\t\t";

		// Bubble
		tc.tic();
		bubble_sort(v_bubble);
		std::cout << tc.toc() << "\t";

		// Insertion
		tc.tic();
		insertion_sort(v_insertion);
		std::cout << tc.toc() << "\t";

		// Selection
		tc.tic();
		selection_sort(v_selection);
		std::cout << tc.toc() << "\t";

		// Misura std::sort
		tc.tic();
		std::sort(v_stdsort.begin(), v_stdsort.end());
		std::cout << tc.toc() << "\n";
	}

	return 0;
}