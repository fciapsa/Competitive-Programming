#include <iostream>

using namespace std;

struct tMatriz {
	int A1, A2, A3, A4;
};


tMatriz ini() {
	return { 0, 1, 1, 1 };
}


tMatriz identidad() {
	return { 1, 0, 0, 1 };
}


tMatriz prodMat(tMatriz m1, tMatriz m2) {
	tMatriz m3;

	m3.A1 = ((m1.A1*m2.A1) % 46337 + (m1.A2*m2.A3) % 46337) % 46337;
	m3.A2 = ((m1.A1*m2.A2) % 46337 + (m1.A2*m2.A4) % 46337) % 46337;
	m3.A3 = ((m1.A3*m2.A1) % 46337 + (m1.A4*m2.A3) % 46337) % 46337;
	m3.A4 = ((m1.A3*m2.A2) % 46337 + (m1.A4*m2.A4) % 46337) % 46337;
return m3;
}


tMatriz fib(tMatriz matriz, int componente) {
	if (componente == 0) return identidad();
	if (componente % 2 == 0) {
		tMatriz mat1 = fib(matriz, componente / 2);
		tMatriz mat2 = prodMat(mat1, mat1);
		return mat2;
	}

	else {
		tMatriz mat1 = fib(matriz, componente / 2);
		tMatriz mat2 = prodMat(matriz, prodMat(mat1, mat1));
		return mat2;
	}
}



bool resuelve() {
	int componente;
	cin >> componente;
	if (componente == 0) return false;

	tMatriz matriz = fib(ini(), componente);
	cout << matriz.A2 << '\n';
}


int main() {
	while (resuelve());
return 0;
}