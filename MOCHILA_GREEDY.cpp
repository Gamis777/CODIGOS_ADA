#include <bits/stdc++.h> 
using namespace std; 
struct myItem 
{
	int item; 
	int valor;
	int peso;
	float div;
}; 
// Función de comparación para clasificar por peso
bool cmp(struct myItem a, struct myItem b) 
{ 
	return a.div > b.div; 
} 

float Mochila(int Capacidad, struct myItem arr[], int n) 
{ 
	// calculando la relación de beneficio por peso 
	for(int i=0;i<n;i++)
	{
		arr[i].div = ((float)arr[i].valor / arr[i].peso);
	}
 // ordenando el item  por peso 
	sort(arr, arr + n, cmp); 

	cout<<"Detalles de los items : \n";
	cout<<"item\t"<<"peso\t"<<"valor\t"<<"div\t"<<endl;
	for (int i = 0; i < n; i++) 
	{ 
		cout <<arr[i].item<<"\t"<<arr[i].peso<<"\t"<<arr[i].valor<<"\t"<<((float)arr[i].div)<<endl; 
	}
	cout<<endl;
	
	float Max = 0.0; //valor maximo
	int i=0; 
	// tomar elementos hasta que la capacidad se vuelva cero 
	while(Capacidad > 0 && i<=n-1)
	{
		// si podemos tomar todos los pesos
		if(Capacidad >= arr[i].peso)
		{
			Max = Max + (float)arr[i].valor;
			Capacidad = Capacidad - arr[i].peso;
		}
		// podemos tomar solo una fracción
		else
		{
			Max += (Capacidad * arr[i].div);
			Capacidad = 0;
		}
		i++;
	}  

	return Max; 
} 

int main() 
{ 
	int C= 10;   
	myItem arr[] ={{1,20,6, 0}, {2, 15, 5, 0},{3, 10, 4, 0}};
	//myItem arr[] = { {1, 30, 10, 0}, {2, 20, 5, 0} , {3, 40, 15, 0}, {4, 36, 8, 0}}; 
	int n = sizeof(arr) / sizeof(arr[0]);

	cout<<"Detalles de todos los items antes de la  eleccion: \n";
	cout<<"item\t"<<"peso\t"<<"valor\t"<<"div\t"<<endl;
	for (int i = 0; i < n; i++) 
	{ 
		cout <<arr[i].item<<"\t"<<arr[i].peso<<"\t"<<arr[i].valor<<"\t"<<((float)arr[i].div)<<endl; 
	} 
	cout<<endl;
	cout << "Maximo valor es = "<< Mochila(C, arr, n);

	return 0; 
} 
