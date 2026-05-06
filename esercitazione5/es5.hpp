#pragma once
#include <vector>
#include "es4.hpp" 

//merge
template<typename T>
void merge(std::vector<T>& A, int p, int q, int r) {
	// dim array temporanei
	int n1 = q - p + 1;
	int n2 = r - q;
	
	// alloca array temporanei
	std::vector<T> L(n1);
	std::vector<T> R(n2);
	
	// copia i dati
	for (int i = 0; i < n1; i++) L[i] = A[p + i];
	for (int j = 0; j < n2; j++) R[j] = A[q + 1 + j];
	
	// indici
	int i = 0, j = 0, k = p;
	
	
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		} else {
			A[k] = R[j];
			j++;
		}
		k++;
	}
	
	
	while (i < n1) { A[k] = L[i]; i++; k++; }
	
	while (j < n2) { A[k] = R[j]; j++; k++; }
}

// f ric per Mergesort
template<typename T>
void mergesort_helper(std::vector<T>& A, int p, int r) {
	if (p < r) {
		// p medio
		int q = p + (r - p) / 2;
		// sort
		mergesort_helper(A, p, q);
		mergesort_helper(A, q + 1, r);
		merge(A, p, q, r);
	}
}

// interfaccia pubblica per Mergesort
template<typename T>
void merge_sort(std::vector<T>& A) {
	if (!A.empty()) mergesort_helper(A, 0, A.size() - 1);
}


template<typename T>
int partition(std::vector<T>& A, int p, int r) {
	// scelta del pivot
	T x = A[r];
	int i = p - 1;
	
	// sposta gli elt minori
	for (int j = p; j <= r - 1; j++) {
		if (A[j] <= x) {
			i++;
			// scambio 
			T tmp = A[i]; A[i] = A[j]; A[j] = tmp;
		}
	}
	
	// pivot
	T tmp = A[i + 1]; A[i + 1] = A[r]; A[r] = tmp;
	return i + 1;
}

// f ricorsiva per Quicksort
template<typename T>
void quicksort_helper(std::vector<T>& A, int p, int r) {
	if (p < r) {
		// trova indice di partizione
		int q = partition(A, p, r);
		// ordina
		quicksort_helper(A, p, q - 1);
		quicksort_helper(A, q + 1, r);
	}
}

// interfaccia pubblica per Quicksort
template<typename T>
void quick_sort(std::vector<T>& A) {
	if (!A.empty()) quicksort_helper(A, 0, A.size() - 1);
}

// insertion sort su frammenti
template<typename T>
void insertion_sort_segment(std::vector<T>& A, int p, int r) {
	for (int j = p + 1; j <= r; j++) {
		// salva elemento corrente
		T key = A[j];
		int i = j - 1;
		
		// sposta gli elementi maggiori
		while (i >= p && A[i] > key) {
			A[i + 1] = A[i];
			i--;
		}
		// posizione corretta
		A[i + 1] = key;
	}
}

// Funzione  Quicksort 2.0
template<typename T>
void quick_sort_2_helper(std::vector<T>& A, int p, int r) {
	if (p < r) {
		// Soglia per vettori piccoli
		if (r - p + 1 <= 15) {
			// Usa algoritmo quadratico
			insertion_sort_segment(A, p, r);
		} else {
			// Usa quicksort logaritmico
			int q = partition(A, p, r);
			quick_sort_2_helper(A, p, q - 1);
			quick_sort_2_helper(A, q + 1, r);
		}
	}
}

// interfaccia  quicksort 2.0
template<typename T>
void quick_sort_2(std::vector<T>& A) {
	if (!A.empty()) quick_sort_2_helper(A, 0, A.size() - 1);
}