#include <iostream>
#include <string>
#include <bits/stdc++.h> 
using namespace std;

class NodoLista
{
public:
	NodoLista* Siguiente;
	string palabra;

	NodoLista( string dato1)
	{
		Siguiente = nullptr;
		palabra = dato1;
	}

	NodoLista()
	{
	}

};
class ListaEnlazada
{
public:
	NodoLista* Primero;
	NodoLista* Ultimo;

	
	ListaEnlazada()
	{
		Primero = nullptr;
		Ultimo = nullptr;
	}

	void Insertar(string nombre);
	void Buscar();
	void Eliminar();
	void MostrarLista();
	void Menu();	
};




void ListaEnlazada::Insertar( string palabra)
{
	NodoLista* nuevo;
	nuevo = new NodoLista( palabra);
	

	if(Primero == nullptr)
	{
		Primero = nuevo;
		Primero->Siguiente = nullptr;
		Ultimo = nuevo;
	}
	else
	{
		Ultimo->Siguiente = nuevo;
		nuevo->Siguiente = nullptr;
		Ultimo = nuevo;
	}

	cout << " Datos Ingresados";
}

void ListaEnlazada::Buscar()
{
	NodoLista* actual;
	actual = new NodoLista();
	actual = Primero;
	bool nodoEncontrado = false;
	string nodoBuscar;

	cout << " Ingrese la palabra  a buscar: ";
	cin >> nodoBuscar;

	if(Primero != nullptr)
	{
		while(actual != nullptr && nodoEncontrado != true)
		{
			if (actual->palabra == nodoBuscar)
			{
				cout << " Nodo con el dato " << nodoBuscar << " Encontrado "<<endl;
				nodoEncontrado = true;
				cout <<  " Nombre: " << actual->palabra<< endl;

			}

			actual = actual->Siguiente;
		}
		if (!nodoEncontrado)
		{
			cout << "  Nodo No Encontrado  ";
		}
	}
	else
	{
		cout << "  La Lista se encuentra Vacia  ";
	}
}
	
void ListaEnlazada::Eliminar()
{
	NodoLista* actual;
	actual = new NodoLista();
	actual = Primero;
	NodoLista* Anterior = new NodoLista();
	Anterior = nullptr;
	bool nodoEncontrado = false;
	string nodoBuscado = "";
	cout << " Ingrese  la palabra  para eliminar: ";
	cin >> nodoBuscado;

	if (Primero!= nullptr)
	{

		while (actual!= nullptr && nodoEncontrado!= true)
		{

			if (actual->palabra == nodoBuscado)
			{
				cout << "  Nodo con el dato " << nodoBuscado << " Encontrado ";

				if (actual == Primero)
				{
					Primero = Primero->Siguiente;
				} else if (actual == Ultimo)
				{
					Anterior->Siguiente = nullptr;
					Ultimo = Anterior;
				}
				else
				{
					Anterior->Siguiente = actual->Siguiente;
				}

				cout << "   Palabra ELiminada Con Exito  ";

				nodoEncontrado = true;
			}

			Anterior = actual;
			actual = actual->Siguiente;
		}
		if (!nodoEncontrado)
		{
			cout << "  Nodo No Encontrado  ";
		}
	}
	else
	{
		cout << "  La Lista se encuentra Vacia";
	}
}

void ListaEnlazada::MostrarLista()
{
	NodoLista* actual;
	actual = new NodoLista();
	actual = Primero;
	string palabra;
	if (Primero != nullptr) 
	{

		while (actual != nullptr) 
		{
			cout << " Nombre: "<< actual->palabra << endl;
			actual = actual->Siguiente;
		}

	}
	else {
		cout << "  La Lista se Encuentra Vacia  ";
	}
}
int main()
{
	int opcion;
	string palabra;


	do
	{
		
		cout << "------ LISTA SIMPLE -----        ";
		cout << "\n***************************************";
		cout << "\n** 1. Insertar                       **";
		cout << "\n** 2. Buscar                         **";
		cout << "\n** 3. Eliminar                       **";
		cout << "\n** 4. Mostrar Lista                  **";
		cout << "\n** 5. Salir                          **";
		cout << "\n***************************************";
		cout << "\n\n Escoja su Opcion: ";
		cin >> opcion;

		switch (opcion)
		{
		case 1:
			cout << " Ingrese la palabra: ";
			cin >> palabra;
		  //Insertar(palabra);
			break;
		case 2:
			cout << "\n\n Buscar Datos En La Lista \n\n";
			//Buscar();
			break;
		case 3:
			cout << "\n\n Eliminar Datos De La Lista \n\n";
			//Eliminar();
			break;
		case 4:
			cout << "\n\n Desplegar Lista \n\n";
			//MostrarLista();
			break;
		case 5:
			cout << "\n\n Programa finalizado...";
			break;
		default:
			cout << "\n\n Opcion No Valida \n\n";
		}
	} while (opcion!= 6);


	return 0;
}
