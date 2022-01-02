#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
struct prop {
	string name;
	double price;
	int met, id;
	bool operator<(prop const& other) const {
		return met > other.met || (met == other.met && price < other.price || (met == other.met &&
			price == other.price && id < other.id));
	}
};

int main() {
	int n, p, k = 1;
	string s;
	cin >> n >> p;
	while (n != 0 || p != 0) {
		cin.ignore();
		for (int i = 0; i < n; ++i) {
			getline(cin, s);
		}

		vector<prop> props(p);
		for (int i = 0; i < p; ++i) {
			getline(cin, props[i].name);
			cin >> props[i].price >> props[i].met;
			cin.ignore();
			for (int j = 0; j < props[i].met; ++j) getline(cin, s);
		}

		sort(props.begin(), props.end());

		if (k != 1) cout << '\n';
		cout << "RFP #" << k << '\n';
		++k;
		cout << props[0].name << '\n';
	cin >> n >> p;
	}
return 0;
}