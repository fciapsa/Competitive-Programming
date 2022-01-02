#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> pron = { "yo ","tu ","el ","nosotros ","vosotros ","ellos " };
std::vector<std::string> aa = { "o","as","a","amos","ais","an" };
std::vector<std::string> ae = {"o","es","e","emos","eis","en"};
std::vector<std::string> ai = { "o","es","e","imos","is","en" };
std::vector<std::string> pa = { "e","aste","o","amos","asteis","aron" };
std::vector<std::string> pe = { "i","iste","io","imos","isteis","ieron" };
std::vector<std::string> pi = { "i","iste","io","imos","isteis","ieron" };
std::vector<std::string> fa = { "are","aras","ara","aremos","areis","aran" };
std::vector<std::string> fe = { "ere","eras","era","eremos","ereis","eran" };
std::vector<std::string> fi = { "ire","iras","ira","iremos","ireis","iran" };

int main() {
	std::string vb, w;
	char t;
	std::cin >> vb >> t;
	while (t != 'T') {
		w = vb.substr(0, vb.size() - 2);

		if (t == 'A') {
			if (vb[vb.size() - 2] == 'a') {
				for (int i = 0; i < 6; ++i) {
					std::cout << pron[i] << w << aa[i] << '\n';
				}
			}
			else if (vb[vb.size() - 2] == 'e') {
				for (int i = 0; i < 6; ++i) {
					std::cout << pron[i] << w << ae[i] << '\n';
				}
			}
			else {
				for (int i = 0; i < 6; ++i) {
					std::cout << pron[i] << w << ai[i] << '\n';
				}
			}
		}
		else if (t == 'P') {
			if (vb[vb.size() - 2] == 'a') {
				for (int i = 0; i < 6; ++i) {
					std::cout << pron[i] << w << pa[i] << '\n';
				}
			}
			else if (vb[vb.size() - 2] == 'e') {
				for (int i = 0; i < 6; ++i) {
					std::cout << pron[i] << w << pe[i] << '\n';
				}
			}
			else {
				for (int i = 0; i < 6; ++i) {
					std::cout << pron[i] << w << pi[i] << '\n';
				}
			}
		}
		else {
			if (vb[vb.size() - 2] == 'a') {
				for (int i = 0; i < 6; ++i) {
					std::cout << pron[i] << w << fa[i] << '\n';
				}
			}
			else if (vb[vb.size() - 2] == 'e') {
				for (int i = 0; i < 6; ++i) {
					std::cout << pron[i] << w << fe[i] << '\n';
				}
			}
			else {
				for (int i = 0; i < 6; ++i) {
					std::cout << pron[i] << w << fi[i] << '\n';
				}
			}
		}

	std::cin >> vb >> t;
	}
return 0;
}