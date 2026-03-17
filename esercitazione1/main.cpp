#include <iostream>
#include <fstream>

int main(int argc, const char *argv[]) {
		if (argc != 2) {
			std::cerr << "Errore: parametro non corrisponde al titolo\n";
			return 1 ;
		}	
		std::ifstream ifs(argv[1]);
		
		if (!ifs.is_open()) {
			std::cerr << "Errore: impossibile aprire il file\n";
			return 1;
		}	
		
		while (!ifs.eof()) {
			std::string città;
			double t1, t2, t3, t4;
				
			ifs >> città >> t1 >> t2 >> t3 >> t4;
			if (ifs.fail()) {
				break; 
			}
			double media = (t1 + t2+ t3 +t4)/(4.0);
			std::cout << città << media << "\n";
	}
	return 0;
}