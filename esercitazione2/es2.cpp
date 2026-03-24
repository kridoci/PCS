#include <iostream>
#include <algorithm>
#include <cmath>


int main()
{
	static const int N = 10;
	double arr[N] = {2.3, 234.0, -23.4, 0.234, 432.0, 43.2, 4.32, 243.0, 98.7900007, -9879797.0007};
	double minimo = arr[0];
	double massimo = arr[0];
	double somma = 0.0;
	for (int i=0; i< N; ++i)
	{
		minimo = std::min(minimo, arr[i]);
		massimo = std::max(massimo,arr[i]);
		somma += arr[i];
	}
	double media = somma / N;
	double somma_scarti_q = 0.0;
	for (int i=0; i<N; ++i)
	{
		double scarto_i = arr[i] - media;
		somma_scarti_q += scarto_i*scarto_i;
		}
	double deviazione_standard = std::sqrt(somma_scarti_q /N);
	
	std::cout << "il minimo è" << minimo << '\n';
	std::cout << "il massimo è" << massimo << '\n';
	std::cout << "la media è" << media << '\n';
	std::cout << "la deviazione standard è" << deviazione_standard << '\n';
		
	// Bubblesort test
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N-1; ++j)
		{
			if (arr[j]>arr[j+1])
			{
				double scambio = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = scambio;
				}
			}
		}
	std::cout<<"Bubbble sorte ha messo in ordine così:";
	for (int i =0;i <N; ++i)
	{
		std::cout << arr[i] <<"";
		if (i<N-1)
		{
			std::cout <<"|";
			}
		}
	std::cout << '\n';
	return 0;
}