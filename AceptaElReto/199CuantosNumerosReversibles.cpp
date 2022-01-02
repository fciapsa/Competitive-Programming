#include <iostream>
#include <cmath>
#include <algorithm>

/*Hay que analizar varios casos:
1 digito: imposible
2 digitos: pares de digitos que suman impar y sin usar el cero => 40, pero hay que descartar los que producen carry porque estropean
           la paridad del segundo digito => 20 posibilidades
3 digitos: el central se suma a si mismo, luego independientemente de cual sea, el primero y ultimo deben producir carry.
           Hay 20 pares de numeros que suman impar y producen carry. Ademas, el central no debe producir carry pues estropearia
		   la paridad del digito que tiene delante => digitos menores que 5 en el centro => 20*5 posibilidades
4 digitos: si el par central podruce carry, estropea la paridad del digito que tiene delante
           si el par exterior produce carry, estropea la paridad del penultimo digito
		   Para el par exterior tenemos de nuevo 20 pares cuya suma es impar y no produce carry, pero para el interior son 30
		   ya que aqui si que podemos usar el 0 => 20*30 posibilidades
5 digitos: el central se suma a si mismo, luego necesita que le llegue un carry, pero se prueba que en todos los casos esto
            hace imposible que el numero final tenga todas las cifras impares...

Se puede generalizar esto a:
    Los numero de 2k digitos tienen 20*30^(k-1) posibilides(como 2,4,...)
	Los numeros de 4k+1 digitos no tienen ningun numero reversible (como 1,5,...)
	Los numeros de 4k+3 digitos tiene 5*20*(20*25)^k (como 3,7,...) [el 20*25 surge de que a partir de 7 tenemos cojuntos
	de pares internos que nos dan 20 y 25 posibilidades]
*/

int main() {
	int n;
	std::cin >> n;
	while (n != 0) {
		if (n % 2 == 0) std::cout << (long long int)((long long int)20 * std::pow((long double)30,n / 2 - 1)) << '\n';
		else if (n % 4 == 1) std::cout << "0\n";
		else std::cout << (long long int)((long long int)100* std::pow((long double)500, n / 4)) << '\n';
	std::cin >> n;
	}
return 0;
}