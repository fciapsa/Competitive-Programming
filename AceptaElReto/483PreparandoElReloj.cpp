#include <iostream>
#include <string>


int main() {
	int nc;
	std::cin >> nc;

	for (int i = 0; i < nc; ++i) {
		int hh, hh2, mm, mm2, ss, ss2;
		std::string s1, s2;

		std::cin >> s1 >> s2;

		hh = (int(s1[0]) - int('0')) * 10 + int(s1[1]) - int('0');
		mm = (int(s1[3]) - int('0')) * 10 + int(s1[4]) - int('0');
		ss = (int(s1[6]) - int('0')) * 10 + int(s1[7]) - int('0');

	    hh2 = (int(s2[0]) - int('0')) * 10 + int(s2[1]) - int('0');
		mm2 = (int(s2[3]) - int('0')) * 10 + int(s2[4]) - int('0');
		ss2 = (int(s2[6]) - int('0')) * 10 + int(s2[7]) - int('0');

		int numCamps, camp;
		std::cin >> numCamps >> camp;

		int tot = 0;
		//Calcular seg
		if (ss <= ss2) tot += ss2 - ss;
		else {
			tot += ss2 + 60 - ss;
			if (mm2 > 0) --mm2;
			else {
				mm2 = 59;
				if (hh2 > 0) --hh2;
				else hh2 = 23;
			}
		}
		//Calcular seg de min
		if (mm <= mm2) tot += (mm2 - mm) * 60;
		else {
			tot += mm2 * 60 + (60 - mm) * 60;
			if (hh2 > 0) --hh2;
			else hh2 = 23;
			}
		//Calcular seg de horas
		if (hh <= hh2) tot += (hh2 - hh) * 3600;
		else tot += hh2 * 3600 + (24 - hh) * 3600;

		int frec = tot / (numCamps - 1);
		int k = 1;
		while (k < camp) {
			int aux = frec;
			while (aux >= 3600) {
				if (hh < 23) {
					++hh;
					aux -= 3600;
				}
				else {
					hh = 0;
					aux -= 3600;
				}
			}

			while (aux >= 60) {
				if (mm < 59) {
					++mm;
					aux -= 60;
				}
				else {
					mm = 0;
					if (hh < 23) ++hh;
					else hh = 0;
					aux -= 60;
				}
			}

			if (ss + aux < 60) ss += aux;
			else {
				if (mm < 59) ++mm;
				else {
					mm = 0;
					if (hh < 23) ++hh;
					else hh = 0;
				}
				ss = aux - (60 - ss);
			}

			++k;
		}

		if (hh < 10) std::cout << '0';
		std::cout << std::to_string(hh) << ':';

		if (mm < 10) std::cout << '0';
		std::cout << std::to_string(mm) << ':';

		if (ss < 10) std::cout << '0';
		std::cout << std::to_string(ss) << '\n';
	}

	return 0;
}