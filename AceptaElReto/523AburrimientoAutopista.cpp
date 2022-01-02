#include <iostream>
#include <string>

bool esMenor(std::string const& mio, std::string const& otro) {
	std::string mio1 = mio.substr(4, 3);
	std::string otro1 = otro.substr(4, 3);

	std::string mio2 = mio.substr(0, 4);
	std::string otro2 = otro.substr(0, 4);

	return mio1 < otro1 || (mio1 == otro1 && mio2 < otro2);
}

int main() {
	int N;
	std::cin >> N;

	std::string mio, otro;

	for (int i = 0; i < N; ++i) {
		int antiguos = 0, modernos = 0;
		std::cin >> mio;
		
		std::cin >> otro;
		while (otro != "0") {
			
			if (esMenor(mio,otro)) ++modernos;
			else ++antiguos;

			std::cin >> otro;
		}

		std::cout << antiguos << ' ' << modernos << '\n';
	}

return 0;
}