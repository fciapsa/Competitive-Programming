#include <iostream>
#include <cmath>//abs

const double MAX = 64;

int main() {
	double pili, marco, pedro;
	std::cin >> pili >> marco >> pedro;
	while (pili >= 0) {
		double media = (pili + marco + pedro) / 3;

		if ((pili == marco && marco == pedro) || (pili < pedro && pedro < marco) || (marco < pedro && pedro < pili))
			std::cout << "0\n";
		else if (marco == pili || pedro == marco || (pedro < pili && pedro < marco && pili > marco) ||
			(pedro > pili && pedro > marco && pili < marco)) {
			if (pili > pedro) {
				double peor = (MAX + MAX) / 3;
				if (std::abs(pili - peor) > std::abs(pedro - peor)) {
					double act = 1, sol = 0;
					double min = media;
					while (std::abs(pili - (MAX+MAX+act) / 3) > std::abs(pedro - (MAX+MAX+act) / 3)) {
						if (std::abs(act - media) < min) {
							min = std::abs(act - media);
							sol = act;
						}
						++act;
					}
					std::cout << sol << '\n';
				}
				else std::cout << "I\n";
			}
			else {
				if (std::abs(pili - MAX / 3) > std::abs(pedro - MAX / 3)) {
					double act = MAX - 1, sol = MAX;
					double min = std::abs(sol - media);
					while (std::abs(pili - act / 3) > std::abs(pedro - act / 3)) {
						if (std::abs(act - media) <= min) {// <= para que reduzca todo lo posible?
							min = std::abs(act - media);
							sol = act;
						}
						--act;
					}
					std::cout << sol << '\n';
				}
				else std::cout << "I\n";
			}
		}
		else if (pedro == pili || (pedro < pili && pedro < marco && marco > pili) ||
			(pedro > pili && pedro > marco && marco < pili)) {
			if (marco > pedro) {
				double peor = (MAX + MAX) / 3;
				if (std::abs(marco - peor) > std::abs(pedro - peor)) {
					double act = 1, sol = 0;
					double min = media;
					while (std::abs(marco - (MAX + MAX + act) / 3) > std::abs(pedro - (MAX + MAX + act) / 3)) {
						if (std::abs(act - media) < min) {
							min = std::abs(act - media);
							sol = act;
						}
						++act;
					}
					std::cout << sol << '\n';
				}
				else std::cout << "I\n";
			}
			else {
				if (std::abs(marco - MAX / 3) > std::abs(pedro - MAX / 3)) {
					double act = MAX - 1, sol = MAX;
					double min = std::abs(sol - media);
					while (std::abs(marco - act / 3) > std::abs(pedro - act / 3)) {
						if (std::abs(act - media) <= min) {// <= para que reduzca todo lo posible?
							min = std::abs(act - media);
							sol = act;
						}
						--act;
					}
					std::cout << sol << '\n';
				}
				else std::cout << "I\n";
			}
		}
	
	std::cin >> pili >> marco >> pedro;
	}
return 0;
}