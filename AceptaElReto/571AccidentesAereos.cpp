#include <iostream>
#include <stack>
#include <iomanip>

#define ll long long
using namespace std;

struct fecha {
	int dd, mm, aa, vict;
};

int main() {
	int n, dd, mm, aa, vict;
	char c;
	fecha aux;
	cin >> n;
	while (std::cin) {
		std::stack<fecha> pila;
		for (int i = 0; i < n; ++i) {
			cin >> dd >> c >> mm >> c >> aa >> vict;
			while (!pila.empty() && pila.top().vict <= vict) pila.pop();

			if (pila.empty()) cout << "NO HAY\n";
			else {
				aux = pila.top();
				cout << std::setfill('0') << std::setw(2) << aux.dd << '/' << std::setw(2) << aux.mm << '/' <<
					std::setw(4) << aux.aa << '\n';
			}

			pila.push({ dd,mm,aa,vict });
		}

	cout << "---\n";
	cin >> n;
	}


return 0;
}