#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <map>

void a_minusculas(std::string &s) {
	for (char & c : s)
		if ('A' <= c && c <= 'Z') // tolower(c) en <cctype>
			c = 'a' + (c - 'A');
}

void concordancias(std::istream & texto, std::map<std::string, std::set<int>> &concor, int linea) {
	// recuperar palabras contándolas
	std::string palabra;
	while (texto >> palabra) {
		if (palabra.size() > 2) {
			a_minusculas(palabra);
			concor[palabra].insert(linea);
		}
	}
}
template <class T>
std::ostream& operator<<(std::ostream& out, std::set<T> const&v) {
	if (v.size() > 0) {
		auto it = v.begin();
		out << *it;
		++it;
		for (; it != v.end(); ++it) out << ' ' << *it;
	}
	return out;
}

bool resuelveCaso() {
	int N;
	std::cin >> N;

	if (N == 0) return false;

	std::cin.ignore();

	std::map<std::string, std::set<int>> concor;
	std::string linea;
	std::stringstream ss;

	for (int i = 1; i <= N; ++i) {
		getline(std::cin, linea);
		ss.clear();
		ss.str(linea);
		concordancias(ss, concor, i);
	}

	// mostrarlas
	for (auto const& cv : concor)
		std::cout << cv.first << ' ' << cv.second << '\n';

	std::cout << "----\n";

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}