#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>

template <typename Valor>
class Arista_impl;

template <typename Valor>
class Arista {
public:
	Arista();
	Arista(int v, int w, Valor valor);
	int uno() const;
	int otro(int vert) const;
	Valor valor() const;
	void print(std::ostream& o = std::cout) const;
private:
	std::shared_ptr<Arista_impl<Valor>> pimpl;
};

template <typename Valor>
inline std::ostream& operator<<(std::ostream& o, Arista<Valor> const& ar) {
	ar.print(o);
	return o;
}

template <typename Valor>
inline bool operator<(Arista<Valor> const& a, Arista<Valor> const& b) {
	return a.valor() < b.valor();
}

template <typename Valor>
inline bool operator>(Arista<Valor> const& a, Arista<Valor> const& b) {
	return a.valor() > b.valor();
}


template <typename Valor>
using AdysVal = std::vector<Arista<Valor>>;  // lista de adyacentes a un vértice

template <typename Valor>
class GrafoValorado {
public:

	/**
	 * Crea un grafo valorado con V vértices, sin aristas.
	 */
	GrafoValorado(int v) : _V(v), _E(0), _ady(_V) {}

	/**
	 * Devuelve el número de vértices del grafo.
	 */
	int V() const { return _V; }

	/**
	 * Devuelve el número de aristas del grafo.
	 */
	int E() const { return _E; }

	/**
	 * Añade la arista v-w al grafo.
	 * @throws invalid_argument si algún vértice no existe
	 */
	void ponArista(Arista<Valor> const& arista);

	/**
	 * Devuelve la lista de adyacentes de v.
	 * @throws invalid_argument si v no existe
	 */
	AdysVal<Valor> const& ady(int v) const;

	/**
	 * Muestra el grafo en el stream de salida o
	 */
	void print(std::ostream& o = std::cout) const;

private:
	const int _V;   // número de vértices
	int _E;   // número de aristas
	std::vector<AdysVal<Valor>> _ady;   // vector de listas de adyacentes

};

/**
 * Para mostrar grafos por la salida estándar.
 */
template <typename Valor>
std::ostream& operator<<(std::ostream& o, GrafoValorado<Valor> const& g);



// IMPLEMENTACIÓN

template <typename Valor>
Arista<Valor>::Arista()
	: pimpl(nullptr) {}

template <typename Valor>
Arista<Valor>::Arista(int v, int w, Valor valor)
	: pimpl(std::make_shared<Arista_impl<Valor>>(v, w, valor)) {}

template <typename Valor>
int Arista<Valor>::uno() const { return pimpl->uno(); }

template <typename Valor>
int Arista<Valor>::otro(int vert) const { return pimpl->otro(vert); }

template <typename Valor>
Valor Arista<Valor>::valor() const { return pimpl->valor(); }

template <typename Valor>
void Arista<Valor>::print(std::ostream& o) const { pimpl->print(o); }


template <typename Valor>
class Arista_impl {
public:
	Arista_impl(int v, int w, Valor valor) : v(v), w(w), _valor(valor) {}
	int uno() const { return v; }
	int otro(int vert) const { return (vert == v) ? w : v; }
	Valor valor() const { return _valor; }
	void print(std::ostream& o = std::cout) const {
		o << "(" << v << ", " << w << ", " << _valor << ")";
	}
private:
	int v, w;
	Valor _valor;
};


template <typename Valor>
void GrafoValorado<Valor>::ponArista(Arista<Valor> const& arista) {
	int v = arista.uno();
	int w = arista.otro(v);
	if (v >= _V || w >= _V) throw std::invalid_argument("Vertice inexistente");
	++_E;
	_ady[v].push_back(arista);
	_ady[w].push_back(arista);
}

template <typename Valor>
AdysVal<Valor> const& GrafoValorado<Valor>::ady(int v) const {
	if (v >= _V) throw std::invalid_argument("Vertice inexistente");
	return _ady[v];
}

template <typename Valor>
void GrafoValorado<Valor>::print(std::ostream& o) const {
	o << _V << " vértices, " << _E << " aristas\n";
	for (auto v = 0; v < _V; ++v) {
		o << v << ": ";
		for (auto const& w : _ady[v]) {
			o << w << " ";
		}
		o << "\n";
	}
}

template <typename Valor>
inline std::ostream& operator<<(std::ostream& o, GrafoValorado<Valor> const& g) {
	g.print(o);
	return o;
}

#include <iostream>
#include <stdexcept>
#include <vector>

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
#include <climits>

void relax2(int v, Arista<int> const& e, std::vector<int>& callesTo, IndexPQ<int>& pq) {
	int w = e.otro(v);
	if (callesTo[w] > callesTo[v] + 1) {
		callesTo[w] = callesTo[v] + 1;
		pq.update(w, callesTo[w]);
	}
}

void relax(int v, Arista<int> const& e, std::vector<int>& distTo, std::vector<int>& callesTo, IndexPQ<int>& pq) {
	int w = e.otro(v);
	if (distTo[w] > distTo[v] + e.valor()) {
		distTo[w] = distTo[v] + e.valor();
		callesTo[w] = callesTo[v] + 1;
		pq.update(w, distTo[w]);
	}
	else if (distTo[w] == distTo[v] + e.valor() && callesTo[w] > callesTo[v] + 1) {
		callesTo[w] = callesTo[v] + 1;
	}
}

bool resuelveCaso() {
	int N;
	std::cin >> N;

	if (!std::cin) return false;

	GrafoValorado<int> gv(N + 1);
	int C;
	std::cin >> C;
	int a, b, val;
	for (int i = 0; i < C; ++i) {
		std::cin >> a >> b >> val;
		gv.ponArista(Arista<int>(a, b, val));
	}

	int K;
	std::cin >> K;
	for (int i = 0; i < K; ++i) {
		std::cin >> a >> b;

		IndexPQ<int> pq(N + 1);
		std::vector<int> distTo(N + 1, INT_MAX);
		std::vector<int> callesTo(N + 1, INT_MAX);
		distTo[a] = 0;
		callesTo[a] = 0;

		pq.push(a, 0);
		while (!pq.empty()) {
			int v = pq.top().elem;
			pq.pop();
			for (Arista<int> e : gv.ady(v)) {
				relax(v, e, distTo, callesTo, pq);
			}
		}

		IndexPQ<int> pq2(N + 1);
		std::vector<int> callesTo2(N + 1, INT_MAX);
		callesTo2[a] = 0;

		pq2.push(a, 0);
		while (!pq2.empty()) {
			int v = pq2.top().elem;
			pq2.pop();
			for (Arista<int> e : gv.ady(v)) {
				relax2(v, e, callesTo2, pq2);
			}
		}

		if (distTo[b] == INT_MAX) std::cout << "SIN CAMINO\n";
		else {
			std::cout << distTo[b] << ' ';
			if (callesTo[b] == callesTo2[b]) std::cout << "SI\n";
			else std::cout << "NO\n";
		}
	}

	std::cout << "----\n";
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}