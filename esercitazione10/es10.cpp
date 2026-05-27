#include <iostream>
#include <Eigen/Dense>
#include <Eigen/SVD>
#include "gradientec.hpp"


double condA(const Eigen::MatrixXd& A)
{
	Eigen::JacobiSVD<Eigen::MatrixXd> svd(A);
	Eigen::VectorXd singularValuesA = svd.singularValues();
	return singularValuesA.maxCoeff() / singularValuesA.minCoeff();
}

int main(int argc, char **argv) 
{
	const double tol = 1.0e-15;
	unsigned int n = 50; // Aumentiamo n per testare meglio il gradiente coniugato

	// Costruzione di una matrice definita positiva
	Eigen::MatrixXd B = Eigen::MatrixXd::Random(n, n);
	if (abs(B.determinant()) < tol) {
		std::cerr << "Matrice B singolare!" << std::endl;
		return -1;
	}
	Eigen::MatrixXd A = B.transpose() * B;
	
	// Soluzione esatta [1, 1, ..., 1]^T
	Eigen::VectorXd x_ex = Eigen::VectorXd::Ones(n);
	// Costruzione del termine noto
	Eigen::VectorXd b = A * x_ex;
	// Guess iniziale [0, 0, ..., 0]^T
	Eigen::VectorXd x0 = Eigen::VectorXd::Zero(n);

	// Parametri per il risolutore
	const unsigned int it_max = 10000;
	const double res_tol = 1.0e-12;
	int iterazioni_effettive = 0;

	std::cout.precision(2);
	std::cout << std::scientific << "Matrix Cond: " << condA(A) << std::endl;

	// Esecuzione del gradiente coniugato
	Eigen::VectorXd x = conjugate_gradient(A, b, x0, res_tol, it_max, iterazioni_effettive);

	// Calcolo degli errori a posteriori
	Eigen::VectorXd res_finale = b - A * x;
	double res_norm_0 = (b - A * x0).norm();
	const auto err_rel = (x_ex.norm() == 0.0) ? (x - x_ex).norm() : (x - x_ex).norm() / x_ex.norm();

	std::cout.precision(4);
	std::cout << "\n--- Risultati Gradiente Coniugato ---" << std::endl;
	std::cout << "Iterazioni effettuate / Iterazioni massime:" << std::endl;
	std::cout << iterazioni_effettive << " / " << it_max << std::endl;
	
	std::cout << "\n(Norma residuo finale) / (Norma residuo iniziale) rispetto a res_tol:" << std::endl;
	std::cout << std::scientific << res_finale.norm() / res_norm_0 << " <= " << res_tol << std::endl;
	
	std::cout << "\nErrore relativo rispetto alla soluzione esatta:" << std::endl;
	std::cout << std::scientific << err_rel << std::endl;

	// std::cout << "\nSoluzione calcolata:" << std::endl;
	// std::cout << std::scientific << x << std::endl;

	return 0;
}