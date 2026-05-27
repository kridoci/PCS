#pragma once
#include <Eigen/Dense>

template <typename MatrixType, typename VectorType>
VectorType conjugate_gradient(const MatrixType& A, const VectorType& b, const VectorType& x0, double tol, int it_max, int& it_out) {
	// Inizializzazione
	VectorType x = x0;
	VectorType r = b - A * x;
	VectorType p = r;
	
	double r0_norm = r.norm();
	if (r0_norm == 0.0) {
		it_out = 0;// Il guess iniziale è già la soluzione esatta
	}

	int k = 0;
	while (k < it_max && r.norm() > tol * r0_norm) {
		// Pre-calcoliamo A*p poiché serve sia per alpha che per beta
		VectorType Ap = A * p;
		
		double p_dot_Ap = p.dot(Ap); // p_k^T A p_k
		
		// Calcolo di alpha_k
		double alpha_k = p.dot(r) / p_dot_Ap;
		
		// Aggiornamento della soluzione
		x = x + alpha_k * p;
		
		// Aggiornamento del residuo
		r = b - A * x;
		
		// Calcolo di beta_k
		// Nota: p^T A r_{k+1} equivale a (A p)^T r_{k+1} essendo A simmetrica
		double beta_k = Ap.dot(r) / p_dot_Ap;
		
		// Aggiornamento della direzione
		p = r - beta_k * p;
		
		k++;
	}
	
	it_out = k; // Salviamo il numero di iterazioni effettive
	return x;
}