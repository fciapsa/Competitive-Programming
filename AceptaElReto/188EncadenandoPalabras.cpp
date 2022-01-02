#include <iostream>
#include <string>
#include <vector>

bool resuelve() {
	std::string ln = "";
	std::getline(std::cin, ln);

	if (!std::cin) return false;

	bool b = true;
	std::vector<std::string> v;

	int ini = 0, i = 0;
	while (ln[i] != ' ' && i < ln.size()) ++i;
	v.push_back(ln.substr(ini, i - ini));
	ini = i + 1;
	++i;
	while(i < ln.size() && b) {
		while (ln[i] != ' ' && i < ln.size()) ++i;
		v.push_back(ln.substr(ini, i - ini));
		ini = i + 1;
		b = (v[v.size()-2][v[v.size() - 2].size() - 1] == v[v.size()-1][1]) && (v[v.size() - 2][v[v.size() - 2].size() - 2] == v[v.size() - 1][0]);
		++i;
	}

	if (b) std::cout << "SI\n";
	else std::cout << "NO\n";
return true;
}

int main() {
	while (resuelve());
return 0;
}