#include <iostream>
#include <vector>
#include <algorithm>

enum tPieza { BARRA, ELEI, ELED, CUADRADO, SD, T, SI };

void aumentar(std::vector<int> &v, int I, int R, int P) {
	int m;
	switch (I) {
	case BARRA:
		switch (R) {
	        case 0 :
			case 180: m = std::max(v[P], std::max(v[P + 1], std::max(v[P + 2], v[P + 3])));
				for (int i = 0; i < 4; ++i) {
					v[P + i] = m + 1;
				}
				break;
	        case 90:
	        case 270: v[P] += 4;break;
	    }break;
	case ELEI:
		switch (R) {
		case 0: m = std::max(v[P], std::max(v[P + 1], v[P + 2]));
			v[P] = m+2; v[P + 1] = m+1; v[P + 2] = m+1; break;
		case 90: m = std::max(v[P], v[P + 1]);
			v[P] = m+1; v[P+1] = m+3; break;
		case 180:
			m = std::max(v[P], std::max(v[P + 1], v[P + 2]));
			if (m == v[P + 2]) {
				v[P] = m+2; v[P + 1] = m+2; v[P + 2] = m+2;
			}
			else {
				v[P] = m+1; v[P + 1] = m+1; v[P + 2] = m+1;
			}
			break;
		case 270:
			if (v[P]+2 <= v[P + 1]) {
				v[P + 1] += 1;
				v[P] = v[P + 1];
			}
			else if (v[P]+1 <= v[P + 1]) {
				v[P + 1] += 2;
				v[P] = v[P + 1];
			}
			else {
				v[P] += 3;
				v[P + 1] = v[P];
			}
			break;
		}break;
	case ELED:
		switch (R) {
		case 0: m = std::max(v[P], std::max(v[P + 1], v[P + 2]));
			v[P] = m+1; v[P + 1] = m+1; v[P + 2] = m+2; break;
		case 90: 
			if (v[P+1] <= v[P] - 2) {
				v[P] += 1;
				v[P+1] = v[P];
			}
			else if (v[P+1] <= v[P] - 1) {
				v[P] += 2;
				v[P+1] = v[P];
			}
			else {
				v[P+1] += 3;
				v[P] = v[P+1];
			}
			break;
		case 180: m = std::max(v[P], std::max(v[P + 1], v[P + 2]));
			if (v[P] == m) {
				v[P] += 2; v[P + 1] = m+2; v[P + 2] = m+2;
			}
			else {
				v[P] = m+1; v[P + 1] = m+1; v[P + 2] = m+1;
			}
			break;
		case 270: m = std::max(v[P], v[P + 1]);
			v[P] = m+3; v[P+1] = m+1; break;
		}break;
	case CUADRADO: m = std::max(v[P], v[P + 1]);
		v[P] = m+2; v[P + 1] = m+2; break;
	case SD:
		switch (R) {
	case 0: m = std::max(v[P], std::max(v[P + 1], v[P + 2]));
		if (v[P + 2] > v[P+1] && v[P+2] > v[P]) {
			v[P + 2] += 1;
			v[P + 1] = v[P + 2];
			v[P] = v[P + 1] - 1;
		}
		else {
			v[P] = m + 1; v[P + 1] = m + 2; v[P + 2] = m + 2;
		}
        break;
	case 90:
		if (v[P + 1] < v[P]) {
			v[P] += 2;
			v[P + 1] = v[P] - 1;
		}
		else {
			v[P + 1] += 2;
			v[P] = v[P + 1] + 1;
		}
		break;
	case 180: m = std::max(v[P], std::max(v[P + 1], v[P + 2]));
		if (v[P + 2] > v[P + 1] && v[P + 2] > v[P]) {
			v[P + 2] += 1;
			v[P + 1] = v[P + 2];
			v[P] = v[P + 1] - 1;
		}
		else {
			v[P] = m + 1;
			v[P + 1] = m + 2;
			v[P + 2] = m + 2;
		}
		break;
	case 270:
		if (v[P] > v[P + 1]) {
			v[P] += 2;
			v[P + 1] = v[P] - 1;
		}
		else {
			v[P + 1] += 2;
			v[P] = v[P + 1] + 1;
		}
		break;
	}break;
	case T:
		switch (R) {
		case 0: 
			m = std::max(v[P], std::max(v[P + 1], v[P + 2]));
			v[P] = m+1; v[P + 1] = m+2; v[P + 2] = m+1; break;
		case 90: 
			if (v[P] > v[P + 1]) {
				v[P] += 1;
				v[P + 1] = v[P] + 1;
			}
			else {
				v[P + 1] += 3;
				v[P] = v[P + 1] - 1;
			}
			break;
		case 180:
			m = std::max(v[P], std::max(v[P + 1], v[P + 2]));
			if (v[P + 1] == m) {
				v[P + 1] += 2;
				v[P] = v[P + 1];
				v[P + 2] = v[P + 1];
			}
			else{
				v[P] = m + 1;
				v[P + 1] = v[P];
				v[P + 2] = v[P];
			}
			break;
		case 270:
			if (v[P+1] > v[P]) {
				v[P+1] += 1;
				v[P] = v[P+1] + 1;
			}
			else {
				v[P] += 3;
				v[P+1] = v[P] - 1;
			}
			break;
		}break;
	case SI:
		switch (R) {
		case 0: 
			m = std::max(v[P], std::max(v[P + 1], v[P + 2]));
			if (v[P] > v[P + 1] && v[P] > v[P + 2]) {
				v[P] += 1;
				v[P + 1] = v[P];
				v[P + 2] = v[P + 1] - 1;
			}
			else {
				v[P] = m + 2;
				v[P + 1] = m + 2;
				v[P + 2] = m + 1;
			}
			break;
		case 90: 
			if (v[P + 1] > v[P]) {
				v[P + 1] += 2;
				v[P] = v[P + 1] - 1;
			}
			else {
				v[P] += 2;
				v[P + 1] = v[P] + 1;
			}
			break;
		case 180:
			m = std::max(v[P], std::max(v[P + 1], v[P + 2]));
			if (v[P] > v[P + 1] && v[P] > v[P + 2]) {
				v[P] += 1;
				v[P + 1] = v[P];
				v[P + 2] = v[P + 1] - 1;
			}
			else {
				v[P] = m + 2;
				v[P + 1] = m + 2;
				v[P + 2] = m + 1;
			}
			break;
		case 270:
			if (v[P + 1] > v[P]) {
				v[P + 1] += 2;
				v[P] = v[P + 1] - 1;
			}
			else {
				v[P] += 2;
				v[P + 1] = v[P] + 1;
			}
			break;
		}break;
	}
}

bool resuelve() {
	int C, N;
	std::cin >> C >> N;

	if (C == 0 && N == 0) return false;

	std::vector<int> v(C, 0);
	int I, R, P;
	for (int i = 0; i < N; ++i) {
		std::cin >> I >> R >> P;
		--P;
		--I;
		aumentar(v, I, R, P);
	}

	std::cout << v[0];
	for (int i = 1; i < C; ++i) {
		std::cout << ' ' << v[i];
	}
	std::cout << '\n';
return true;
}

int main() {
	while (resuelve());
return 0;
}