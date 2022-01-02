#include <iostream>
#include <string>
#include <list>

bool resuelveCaso() {
	std::string msg;
	getline(std::cin, msg);

	if (!std::cin) return false;

	std::list<char> sol;
	std::list<char>::iterator it = sol.begin();
	for (int i = 0; i < msg.size(); ++i) {
		switch (msg[i]) {
		case '-': it = sol.begin();
			break;
		case '+': it = sol.end();
			break;
		case '*': if (it != sol.end()) ++it;
			break;
		case '3':
			if (it != sol.end()) it = sol.erase(it);
			break;
		default: sol.insert(it, msg[i]);
			break;
		}
	}


	for (auto it = sol.begin(); it != sol.end(); ++it) {
		std::cout << *it;
	}
	std::cout << '\n';


	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}