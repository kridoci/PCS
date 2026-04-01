#include <iostream>
#include "rational.hpp"

int main() {
	rational<int> r(3, 6);
	std::cout << r << "\n"; 

	// ulteriori test 
	rational<int> a(1, 2);
	rational<int> b(1, 3);
	
	std::cout << "Somma: " << a + b << "\n";
	std::cout << "Sottrazione: " << a - b << "\n";
	std::cout << "Moltiplicazione: " << a * b << "\n";
	std::cout << "Divisione: " << a / b << "\n";

	rational<int> inf(1, 0);
	std::cout << "Infinito + a: " << inf + a << "\n";

	return 0;
}