#include <iostream>
#include <stdexcept>
#include <vector>
#include <unordered_map>

// T es el tipo de las prioridades
// Comparator dice cuándo un valor de tipo T es más prioritario que otro
template <typename T = int, typename Comparator = std::less<T>>
class IndexPQ {
public:
	// registro para las parejas < elem, prioridad >
	struct Par {
		int elem;
		T prioridad;
	};

private:
	// vector que contiene los datos (pares < elem, prio >)
	std::vector<Par> array;     // primer elemento en la posición 1

	// vector que contiene las posiciones en array de los elementos
	std::vector<int> posiciones;   // un 0 indica que el elemento no está

	/* Objeto función que sabe comparar prioridades.
	 antes(a,b) es cierto si a es más prioritario que b */
	Comparator antes;

public:
	IndexPQ(int N, Comparator c = Comparator()) : array(1), posiciones(N, 0), antes(c) {}

	IndexPQ(IndexPQ<T, Comparator> const&) = default;

	IndexPQ<T, Comparator>& operator=(IndexPQ<T, Comparator> const&) = default;

	~IndexPQ() = default;

	// e debe ser uno de los posibles elementos
	void push(int e, T const& p) {
		if (posiciones.at(e) != 0)
			throw std::invalid_argument("No se pueden insertar elementos repetidos.");
		else {
			array.push_back({ e, p });
			posiciones[e] = size();
			flotar(size());
		}
	}

	void update(int e, T const& p) {
		int i = posiciones.at(e);
		if (i == 0) // el elemento e se inserta por primera vez
			push(e, p);
		else {
			array[i].prioridad = p;
			if (i != 1 && antes(array[i].prioridad, array[i / 2].prioridad))
				flotar(i);
			else // puede hacer falta hundir a e
				hundir(i);
		}
	}

	int size() const {
		return int(array.size()) - 1;
	}

	bool empty() const {
		return size() == 0;
	}

	Par const& top() const {
		if (size() == 0)
			throw std::domain_error("No se puede consultar el primero de una cola vacia");
		else return array[1];
	}

	void pop() {
		if (size() == 0) throw std::domain_error("No se puede eliminar el primero de una cola vacía.");
		else {
			posiciones[array[1].elem] = 0; // para indicar que no está
			if (size() > 1) {
				array[1] = std::move(array.back());
				posiciones[array[1].elem] = 1;
				array.pop_back();
				hundir(1);
			}
			else
				array.pop_back();
		}
	}

private:

	void flotar(int i) {
		Par parmov = std::move(array[i]);
		int hueco = i;
		while (hueco != 1 && antes(parmov.prioridad, array[hueco / 2].prioridad)) {
			array[hueco] = std::move(array[hueco / 2]); posiciones[array[hueco].elem] = hueco;
			hueco /= 2;
		}
		array[hueco] = std::move(parmov); posiciones[array[hueco].elem] = hueco;
	}

	void hundir(int i) {
		Par parmov = std::move(array[i]);
		int hueco = i;
		int hijo = 2 * hueco; // hijo izquierdo, si existe
		while (hijo <= size()) {
			// cambiar al hijo derecho de i si existe y va antes que el izquierdo
			if (hijo < size() && antes(array[hijo + 1].prioridad, array[hijo].prioridad))
				++hijo;
			// flotar el hijo si va antes que el elemento hundiéndose
			if (antes(array[hijo].prioridad, parmov.prioridad)) {
				array[hueco] = std::move(array[hijo]); posiciones[array[hueco].elem] = hueco;
				hueco = hijo; hijo = 2 * hueco;
			}
			else break;
		}
		array[hueco] = std::move(parmov); posiciones[array[hueco].elem] = hueco;
	}

};


#include <iostream>
#include <vector>
#include <algorithm>

/*Definimos maxBajada(t, p) = maxima bajada posible desde el punto p cuando aun quedan t segundos y teniendo en cuenta
                             que hay que llegar a tiempo al destino(precalculamos para cada punto su camino mas corto 
							 al destino)

CASOS BASE: maxBajada(t, p) = -inf para t < dist(p,dest) [cuando no da tiempo a llegar al destino]
            maxBajada(dist(p,dest), p) =  bajada(p,dest) [cuando tiempo justo] (este dato de bajada hay que precalcularlo
			                                                                    si es posible al mismo tiempo que dist)

CASOS RECURSIVOS: maxBajada(t,p) = max( bajada(p,dest), max_{p'}{posibleBajada + maxBajada(t - distTo(p'), p')} )
                                    yendo al destino     alcanzables por tomar remontes o bajar a bases de remontes en tiempo

Tamano de la tabla: M*(2*N + 2)
Coste de rellenado: O(M * (2*N + 2)^2 )

IDEA GENERAL: Precalcular el camino mas corto desde todo "punto intermedio"(origen, base de remonte o cima de remonte) hasta
              el destino, y si es posible tambien la bajada acumulada por esta via.
			  (Basta hacer Dijkstra con el destino como origen tras invertir las aristas) ==> O((2*N + 2)^2)

Las opciones de desplazamiento desde todo "punto intermedio" son:
    -Tomar remontes que tengan su base en ese punto(si los hay)
	-Bajar a la base de otro remonte
	-Ir al destino para acabar el recorrido(usando el camino minimo precalculado)

*/

struct tArista {
	int from, to, coste;
};

struct tParada {
	int h, top, bot, T, id;
	bool operator<(tParada const& other) const {
		return h < other.h; //|| (h == other.h && isBottom && !other.isBottom);
	}
};

int maxBajadaDP(std::vector<std::vector<int>>& memoria, std::vector<std::vector<tArista>> const& adyList,
	std::vector<int> const& distTo,std::vector<int> const& bajadaTo, int p, int t, std::vector<tParada> const& ini_data) {
	if (t < 0) return -1;
	if (memoria[t][p] != -2) return memoria[t][p];
	
	if (t < distTo[p]) {
		memoria[t][p] = -1;
		return -1;
	}
	if (t == distTo[p]) {
		memoria[t][p] = bajadaTo[p];
		return bajadaTo[p];
	}

	int aux = bajadaTo[p];
	for (int j = 0; j < adyList[p].size(); ++j) {
		if (ini_data[adyList[p][j].to].h > ini_data[p].h) {
			aux = std::max(aux, maxBajadaDP(memoria, 
				adyList, distTo, bajadaTo, adyList[p][j].to, t - adyList[p][j].coste, ini_data));
		}
		else {
			int baja = maxBajadaDP(memoria,
				adyList, distTo, bajadaTo, adyList[p][j].to, t - adyList[p][j].coste, ini_data);
			if(baja != -1) aux = std::max(aux, adyList[p][j].coste + baja); //solo si es un camino valido
		}
	}
	memoria[t][p] = aux;

return aux;
}

int main() {
	int N, orig, dest, M, I, F, T;
	std::cin >> N;
	while (N != 0) {
		std::vector<tParada> paradas;
		for (int i = 0; i < N; ++i) {
			std::cin >> I >> F >> T;
			paradas.push_back({ I,F,-1,T,2*i});
			paradas.push_back({ F,-1,I,-1,2*i+1});
		}
		std::cin >> orig >> dest >> M;
		paradas.push_back({ orig,-1,-1,-1,2*N});
		paradas.push_back({ dest,-1,-1,-1,2*N+1});
		std::vector<tParada> ini_data = paradas;
		sort(paradas.begin(), paradas.end());

		//Guardar el grafo invertido
		std::vector<std::vector<tArista>> adyList(2 * N + 2);
		for (int i = paradas.size() - 1; i >= 0; --i) {
			int j = i;
			while (j > 0 && paradas[j - 1].h == paradas[i].h) --j;
			while (j < paradas.size()) {
				if (j != i) {
					if (paradas[i].id%2 == 0 && paradas[j].id == paradas[i].id + 1 && paradas[i].id != 2*N)//si es su remonte
						adyList[paradas[j].id].push_back({ paradas[j].id,paradas[i].id,paradas[i].T });

				adyList[paradas[i].id].push_back({ paradas[i].id,paradas[j].id,paradas[j].h - paradas[i].h });//siempre, lo contrario a bajar
				}
			++j;
			}
		}

		//Calcular distancias minimas con el algoritmo de Dijkstra
		std::vector<int> distTo(2 * N + 2, M+1);//M+1 es el +inf, excede el tiempo maximo
		std::vector<int> bajadaTo(2 * N + 2, -1);//-1 es que no se ha podido llegar
		distTo[2 * N + 1] = 0;
		bajadaTo[2 * N + 1] = 0;
		IndexPQ<int> pq(2 * N + 2);
		pq.push(2 * N + 1, 0);
		while (!pq.empty()) {
			int v = pq.top().elem;
			pq.pop();

			for (int i = 0; i < adyList[v].size(); ++i) {
				int w = adyList[v][i].to;
				if (distTo[w] > distTo[v] + adyList[v][i].coste) {
					distTo[w] = distTo[v] + adyList[v][i].coste;
					if (w%2 == 0 && v == w + 1) bajadaTo[w] = bajadaTo[v];
					else bajadaTo[w] = bajadaTo[v] + (ini_data[w].h - ini_data[v].h);

					pq.update(w, distTo[w]);
				}
				else if (distTo[w] == distTo[v] + adyList[v][i].coste) {
					if (w % 2 == 0 && v == w + 1) {
						if (bajadaTo[v] > bajadaTo[w]) bajadaTo[w] = bajadaTo[v];
					}
					else {
						if(bajadaTo[v] + (ini_data[w].h - ini_data[v].h) > bajadaTo[w])
							bajadaTo[w] = bajadaTo[v] + (ini_data[w].h - ini_data[v].h);
					}
				}
			}
		}
		/*Para depurar los caminos minimos
		for (int i = 0; i < distTo.size(); ++i) {
			std::cout << distTo[i] << ' ' << bajadaTo[i] << '\n';
		}*/

		//Pasar a la parte de DP. OJO: Necesitamos ahora el grafo sin invertir y SIN ARISTAS DE COSTE 0
		if (distTo[2 * N] > M) std::cout << "IMPOSIBLE\n";
		else {
			std::unordered_map<int, int> representantes;//para cada altura elegir un representante
			for (int i = 0; i < paradas.size(); ++i) {
				if (representantes.count(paradas[i].h) == 0) {
					representantes[paradas[i].h] = paradas[i].id;
				}
			}
			//Obtener el grafo sin invertir y concentrar las aristas en el representante de cada altura, quitando las de coste 0
			std::vector<std::vector<tArista>> adyListBack(2 * N + 2);
			for (int i = 0; i < adyList.size(); ++i) {
				for (int j = 0; j < adyList[i].size(); ++j) {
					if (adyList[i][j].coste > 0) {
						int idRepr = representantes[ini_data[adyList[i][j].to].h];
						int idReprDest = representantes[ini_data[i].h];
						adyListBack[idRepr].push_back({ idRepr, idReprDest, adyList[i][j].coste });
					}
				}
			}

			std::vector<std::vector<int>> memoria(M + 1, std::vector<int>(2 * N + 2, -2));// -2 desconocido, -1 imposible
			int maxBajada = maxBajadaDP(memoria, adyListBack,distTo, bajadaTo,representantes[ini_data[2*N].h], M, ini_data);
			std::cout << maxBajada << '\n';
		}

	std::cin >> N;
	}
return 0;
}