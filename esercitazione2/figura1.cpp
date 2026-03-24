#include <iostream>

int main()
{
	double ad[4] = {0.0, 1.1, 2.2, 3.3}; // fare il disegnino degli array
	float af[8] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
	int ai[3] = {0, 1, 2};
	
	int x = 1;
	float y = 1.1;
	
	(&y)[1] = 0; //far vedere cosa succede riga per riga, soprattutto questa, perché stampa 1, cosa fa "[.]" 
	
	std::cout << x << "\n";
	
	std::cout << "Indirizzo di x: " << &x << "\n";
    std::cout << "Indirizzo di y: " << &y << "\n";
	
	return 0;
}
	
	