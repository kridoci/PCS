#include <iostream>
#include <vector>
#include <algorithm>
#include "randfiller.h"
#include "timecounter.h"
#include "es5.hpp"

int main() {
	randfiller rf;
	timecounter tc;

	const int NUM_TESTS = 100; 

	std::vector<int> sizes = {4, 8, 16, 24, 32, 64, 90};

	for (int size : sizes) {
		std::cout << "\nMisurazione per N = " << size << "\n";

		// Prealloco i vettori
		std::vector<std::vector<int>> base_vectors(NUM_TESTS, std::vector<int>(size));
		for (int i = 0; i < NUM_TESTS; i++) {
			rf.fill(base_vectors[i], -1000, 1000);
		}

		std::vector<std::vector<int>> vectors_to_sort;

		//bubblesort
		vectors_to_sort = base_vectors;
		tc.tic();
		for (int i = 0; i < NUM_TESTS; i++) bubble_sort(vectors_to_sort[i]);
		double t_bubble = tc.toc(); 

		// insertionsort
		vectors_to_sort = base_vectors;
		tc.tic();
		for (int i = 0; i < NUM_TESTS; i++) insertion_sort(vectors_to_sort[i]);
		double t_insertion = tc.toc();

		// selectionsort
		vectors_to_sort = base_vectors;
		tc.tic();
		for (int i = 0; i < NUM_TESTS; i++) selection_sort(vectors_to_sort[i]);
		double t_selection = tc.toc();

		// mergesort
		vectors_to_sort = base_vectors;
		tc.tic();
		for (int i = 0; i < NUM_TESTS; i++) merge_sort(vectors_to_sort[i]);
		double t_merge = tc.toc();

		// quicksort
		vectors_to_sort = base_vectors;
		tc.tic();
		for (int i = 0; i < NUM_TESTS; i++) quick_sort(vectors_to_sort[i]);
		double t_quick = tc.toc();

		// quicksort2
		vectors_to_sort = base_vectors;
		tc.tic();
		for (int i = 0; i < NUM_TESTS; i++) quick_sort_2(vectors_to_sort[i]);
		double t_quick_2 = tc.toc();

		
		vectors_to_sort = base_vectors;
		tc.tic();
		for (int i = 0; i < NUM_TESTS; i++) std::sort(vectors_to_sort[i].begin(), vectors_to_sort[i].end());
		double t_std = tc.toc();

		// Stampa medie (tempo totale diviso numero di test)
		std::cout << "Bubble:    " << t_bubble / NUM_TESTS << " \n";
		std::cout << "Insertion: " << t_insertion / NUM_TESTS << " \n";
		std::cout << "Selection: " << t_selection / NUM_TESTS << " \n";
		std::cout << "Merge:     " << t_merge / NUM_TESTS << " \n";
		std::cout << "Quick:     " << t_quick / NUM_TESTS << " \n";
		std::cout << "Quick 2.0: " << t_quick_2 / NUM_TESTS << " \n";
		std::cout << "Std::sort: " << t_std / NUM_TESTS << " \n";
	}

	return 0;
}