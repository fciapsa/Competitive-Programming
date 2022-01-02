#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

std::unordered_set<char> noZero;
std::vector<bool> marked(10);
std::unordered_map<char, int> map;

bool suma(std::string const& op1, std::string const& op2, std::string const& res, int carry, int column, int row) {
	if (column == -1) return carry == 0;

	if (row == 0) {
		if (op1[column] == '0' || map[op1[column]] != -1) return suma(op1, op2, res, carry, column, 1);
		else {
			bool found = false;
			int min = 0;
			if (noZero.count(op1[column])) min = 1;
			for (int i = min; i < 10 && !found; ++i) {
				if (!marked[i]) {
					marked[i] = true;
					map[op1[column]] = i;
					found = suma(op1, op2, res, carry, column, 1);
					if (!found) {
						marked[i] = false;
						map[op1[column]] = -1;
					}
				}
			}
			return found;
		}
	}
	else if (row == 1) {
		if (op2[column] == '0' || map[op2[column]] != -1) return suma(op1, op2, res, carry, column, 2);
		else {
			bool found = false;
			int min = 0;
			if (noZero.count(op2[column])) min = 1;
			for (int i = min; i < 10 && !found; ++i) {
				if (!marked[i]) {
					marked[i] = true;
					map[op2[column]] = i;
					found = suma(op1, op2, res, carry, column, 2);
					if (!found) {
						marked[i] = false;
						map[op2[column]] = -1;
					}
				}
			}
			return found;
		}
	}
	else {
		int sum, next_c;
		sum = map[op1[column]] + map[op2[column]] + carry;
		next_c = sum / 10;
		sum %= 10;

		if (map[res[column]] != -1) {
			if (map[res[column]] == sum) return suma(op1, op2, res, next_c, column - 1, 0);
			else return false;
		}
		else {
			bool found = false;
			int min = 0;
			if (noZero.count(res[column])) min = 1;
			for (int i = min; i < 10 && !found; ++i) {
				if (i == sum && !marked[i]) {
					marked[i] = true;
					map[res[column]] = i;
					found = suma(op1, op2, res, next_c, column - 1, 0);
					if (!found) {
						marked[i] = false;
						map[res[column]] = -1;
					}
				}
			}
			return found;
		}
	}
}

bool prod(std::string const& op1, std::string const& op2, std::string const& res, int carry, int c1, int c2, int row) {
	if (c1 == -1) return carry == 0;

	if (row == 0) {
		if (op1[c1] == '0' || map[op1[c1]] != -1) return prod(op1, op2, res, carry, c1, c2, 1);
		else {
			bool found = false;
			int min = 0;
			if (noZero.count(op1[c1])) min = 1;
			for (int i = min; i < 10 && !found; ++i) {
				if (!marked[i]) {
					marked[i] = true;
					map[op1[c1]] = i;
					found = prod(op1, op2, res, carry, c1, c2, 1);
					if (!found) {
						marked[i] = false;
						map[op1[c1]] = -1;
					}
				}
			}
			return found;
		}
	}
	else if (row == 1) {
		if (op2[c1] == '0' || map[op2[c1]] != -1) return prod(op1, op2, res, carry, c1, c2, 2);
		else {
			bool found = false;
			int min = 0;
			if (noZero.count(op2[c1])) min = 1;
			for (int i = min; i < 10 && !found; ++i) {
				if (!marked[i]) {
					marked[i] = true;
					map[op2[c1]] = i;
					found = prod(op1, op2, res, carry, c1, c2, 2);
					if (!found) {
						marked[i] = false;
						map[op2[c1]] = -1;
					}
				}
			}
			return found;
		}
	}
	else {
		int sum = carry, next_c, ind1 = c1, ind2 = c2;
		while (ind1 <= c2) {
			sum += map[op1[ind1]] * map[op2[ind2]];
			++ind1;
			--ind2;
		}
		next_c = sum / 10;
		sum %= 10;

		if (map[res[c1]] != -1) {
			if (map[res[c1]] == sum) return prod(op1, op2, res, next_c, c1 - 1, c2, 0);
			else return false;
		}
		else {
			bool found = false;
			int min = 0;
			if (noZero.count(res[c1])) min = 1;
			for (int i = min; i < 10 && !found; ++i) {
				if (i == sum && !marked[i]) {
					marked[i] = true;
					map[res[c1]] = i;
					found = prod(op1, op2, res, next_c, c1 - 1, c2, 0);
					if (!found) {
						marked[i] = false;
						map[res[c1]] = -1;
					}
				}
			}
			return found;
		}
	}
}

int main() {
	int ind1, ind2;
	std::string op1, op2, res;
	char op, c;
	std::cin >> op1;
	while (std::cin) {
		std::cin >> op >> op2 >> c >> res;

		noZero.clear();
		if (op1.size() > 1) noZero.insert(op1[0]);
		if (op2.size() > 1) noZero.insert(op2[0]);
		if (res.size() > 1) noZero.insert(res[0]);

		map.clear();
		for (int i = 0; i < op1.size(); ++i) map[op1[i]] = -1;
		for (int i = 0; i < op2.size(); ++i) map[op2[i]] = -1;
		for (int i = 0; i < res.size(); ++i) map[res[i]] = -1;

		while (op1.size() < res.size()) op1 = '0' + op1;
		while (op2.size() < res.size()) op2 = '0' + op2;
		for (int i = 0; i < 10; ++i) marked[i] = false;

		if (op == '+') {
			suma(op1, op2, res, 0, res.size() - 1, 0);
			//traducir
			for (int i = 0; i < op1.size(); ++i) {
				if (op1[i] != '0') op1[i] = char(48 + map[op1[i]]);
			}
			for (int i = 0; i < op2.size(); ++i) {
				if (op2[i] != '0') op2[i] = char(48 + map[op2[i]]);
			}
			for (int i = 0; i < res.size(); ++i) res[i] = char(48 + map[res[i]]);
			//obviar ceros a la izquierda
			ind1 = 0;
			if (op1.size() > 1) {
				while (op1[ind1] == '0') ++ind1;
			}
			ind2 = 0;
			if (op2.size() > 1) {
				while (op2[ind2] == '0') ++ind2;
			}

			std::cout << op1.substr(ind1, op1.size() - ind1) << " + " << op2.substr(ind2, op2.size() - ind2) << " = " << res << '\n';
		}
		else {
			prod(op1, op2, res, 0, res.size() - 1, res.size() - 1, 0);

			//traducir
			for (int i = 0; i < op1.size(); ++i) {
				if (op1[i] != '0') op1[i] = char(48 + map[op1[i]]);
			}
			for (int i = 0; i < op2.size(); ++i) {
				if (op2[i] != '0') op2[i] = char(48 + map[op2[i]]);
			}
			for (int i = 0; i < res.size(); ++i) res[i] = char(48 + map[res[i]]);
			//obviar ceros a la izquierda
			ind1 = 0;
			if (op1.size() > 1) {
				while (op1[ind1] == '0') ++ind1;
			}
			ind2 = 0;
			if (op2.size() > 1) {
				while (op2[ind2] == '0') ++ind2;
			}

			std::cout << op1.substr(ind1, op1.size() - ind1) << " * " << op2.substr(ind2, op2.size() - ind2) << " = " << res << '\n';
		}

		std::cin >> op1;
	}
	return 0;
}