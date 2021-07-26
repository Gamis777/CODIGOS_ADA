#include <iostream>
#include <queue>
#include <vector>
#define max 100 
#define INFINITY 9999 
using namespace std;

struct Edge
{
	int nodo; 
	int costo; 
	Edge(int _nodo, int _costo) : nodo(_nodo), costo(_costo) {} // Cparametrizado
	Edge() : nodo(-1), costo(-1) {} // C.defecto
};

struct Graph
{
	vector<Edge> G[max]; 
	int V; 
	int A; 
};

struct State
{
	int nodo; // actual.
	int costo; 
	State(int _nodo, int _distancia) : nodo(_nodo), costo(_distancia) {} // C.parametrizado.
	bool operator <(const State &b) const 
	{
		return costo> b.costo;
	}
};

int algoritmo(const int begin, const int end, const Graph graph)
{
	priority_queue<State> pq; 
	vector<int> Dist(graph.V,INFINITY); //  distancia hacia  los vertices.
	vector<bool> visitados(graph.V, false); 

	Dist[begin] = 0; // inicio
	pq.push(State(begin, 0));
	while(!pq.empty()) 
	{
		State st = pq.top(); pq.pop(); // desencola  minimo.
		visitados[st.nodo] = true; 
		if (st.nodo == end)
			return st.costo; //  vertice destino.

		int A= (int)graph.G[st.nodo].size();
		for(int i = 0; i < A; ++i) //  adyacencias.
		{
		
			if (!visitados[graph.G[st.nodo][i].nodo] && ((Dist[st.nodo] + graph.G[st.nodo][i].costo) < Dist[graph.G[st.nodo][i].nodo]))
			{
				Dist[graph.G[st.nodo][i].nodo] = st.costo + graph.G[st.nodo][i].costo;
				pq.push(State(graph.G[st.nodo][i].nodo, st.costo + graph.G[st.nodo][i].costo));
			}
		}
	}
	return -1; // Si no llega  al destino
}

struct Imprimir
{
	int V, A;
	int comienzo, fin;
	void Detallar_Grafo(Graph& graph)
	{
		cout << "Inserte la cantidad de Vertices: " << endl;
		cin >> V;
		cout << "Inserte cantidad de Aristas: " << endl;
		cin >> A;

		graph.V = V;
		graph.A = A;
	}
	void Cargar_Grafo(Graph & graph)
	{
		for (int i = 0; i < A; ++i)
		{
			int Origen, Destino, Peso;
			cout << "Inserte Origen: " << endl;
			cin >> Origen;
			cout << "Inserte Destino: " << endl;
			cin >> Destino;
			cout << "Inserte el Costo de la Arista: " << endl;
			cin >> Peso;

			// Insertamos la arista 2veces, no dirigido.
			graph.G[Origen].push_back(Edge(Destino, Peso));
			graph.G[Destino].push_back(Edge(Origen, Peso));
		}
	}
	void Dijkstra(Graph graph)
	{
		cout << "Inserte Vertice Inicial: " << endl;
		cin >> comienzo;
		cout << "Inserte Vertice Final: " << endl;
		cin >> fin;
		int n = algoritmo(comienzo, fin, graph);
		cout << "Distancia  del  Camino: " << n << endl;
	}
};


int main()
{
	bool out=false;
	char salir;

	Imprimir programa; 
	Graph graph; 

	cout << "Algoritmo  Dijkstra" << endl;

	while (!out)
	{
	programa.Detallar_Grafo(graph); // cantidad  v ,A
	programa.Cargar_Grafo(graph); // cargar aristas
	programa.Dijkstra(graph); 
	cout << "Salir? (T/F)" << endl;
	cin >> salir;
		if (salir == 'T')
		{
			out = true;
		}
	}
}
