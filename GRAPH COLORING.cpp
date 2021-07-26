#include<iostream>
#include<fstream>
#include <list>
#include <vector>
#include <bits/stdc++.h> 

using namespace std;
const int MAX = 100;
int n;
int a[MAX][MAX]; // a [n] [n] M.adyacencia 
// array color [n] almacena los colores de los vértices
int color[MAX]; 
int grado[MAX];
// la matriz NN [] v.que no son adyacentes al V actual
int NN[MAX];
int NNCount;
int unprocessed;// # vértices sin procesar

void GetInput()
{
    ifstream file;
	file.open("grafo2.txt",ios::in);
    if(file==NULL)
    cout<<"no se puede  leer";
    file >> n; // lee primero el número de vértices
    for (int i=0; i < n; i++)// luego lea la matriz de adyacencia      
        for (int j=0; j < n; j++)
            file >> a[i][j]; // // lee los elementos uno por uno
    file.close();
}


void Init()
{
    for (int i=0; i < n; i++)
    {
        color[i] = 0; 
        grado[i] = 0;// cuenta el grado de cada vértice
        for (int j = 0; j < n; j++)
            if (a[i][j] == 1) // si i-ésimo vértice es adyacente a otro
                grado[i] ++; // aumenta el grado en 1
    }
    NNCount = 0; // número de elemento en el conjunto NN
    unprocessed = n;
}

//  encuentra el vértice sin procesar cuyo grado es el máximo
int MaxgradoVertex()
{
    int max = -1;
    int max_i;
    for (int i =0; i < n; i++)
        if (color[i] == 0)
            if (grado[i]>max)
            {
                max = grado[i];
                max_i = i;
            }
    return max_i;
}


// restablece el valor de la matriz escaneada
void scannedInit(int scanned[MAX])
{
    for (int i=0; i < n; i++)
        scanned[i] = 0;
}


void Actualizar(int NumeroColor)
{
    NNCount = 0;
    for (int i=0; i < n; i++)
        if (color[i] == 0)  // color [i] = 0 si aún no lo hemos coloreado
        {
            NN[NNCount] = i;
            NNCount ++; // cuando agregamos un vértice, aumentamos el NNCount
        }
    for (int i=0; i < n; i++)
        if (color[i] == NumeroColor) // encuentra un vértice coloreado 
            for (int j=0; j < NNCount; j++)
                while (a[i][NN[j]] == 1)
               // elimina el vértice adyacente al vértice encontrado
                {
                    NN[j] = NN[NNCount - 1];
                    NNCount --; // disminuir el NNCount
                }
}

//encontrar vertice con maximo grado
int MaxgradoInNN()
{
    int tmp_y; // el vértice tiene el grado máximo actual
    int temp, max = 0;
    for (int i=0; i < NNCount; i++)
    {
        temp = 0;
        for (int j=0; j < n; j++)
            if (color[j] == 0 && a[NN[i]][j] == 1)
                temp ++;
        if (temp>max) // si el grado del vértice NN [i] es mayor que el de tmp_y
        {
            max = temp; // asignación de NN [i] a tmp_y
            tmp_y = NN[i];
        }
    }
    if (max == 0) //si todos los vértices tienen grado 0
        return NN[0];
    else // existe un maximo
        return tmp_y;
}




int FindSuitableY(int NumeroColor, int& VerticesInCommon)
{
    int temp,tmp_y,y;
    // matriz escaneada almacena vértices sin color
     // excepto que el vértice se está procesando
    int scanned[MAX];
    VerticesInCommon = 0;
    for (int i=0; i < NNCount; i++) // comprobar el i-ésimo vértice en NN
    {
        // tmp_y es el vértice que estamos procesando
        tmp_y = NN[i];
        // temp son los vecinos en común de tmp_y
        // y los vértices coloreados NumeroColor
        temp = 0;
        scannedInit(scanned);
        // restablecer la matriz escaneada para verificar todo
        // los vértices si son adyacentes al i-ésimo vértice en NN
        for (int x=0; x < n; x++)
            if (color[x] == NumeroColor) // encuentra un vértice coloreado 
                for (int k=0; k < n; k++)
                    if (color[k] == 0 && scanned[k] == 0)
                        if (a[x][k] == 1 && a[tmp_y][k] == 1)
                      // si k es un vecino en común de xy tmp_y
                        {
                            temp ++;
                            scanned[k] = 1; // k se escanea
                        }
        if (temp > VerticesInCommon)
        {
            VerticesInCommon = temp;
            y = tmp_y;
        }
    }
    return y;
}

// función de procesamiento
void Coloring()
{
    int x,y;
    int NumeroColor = 0;
    int VerticesInCommon = 0;
    while (unprocessed>0) // mientras hay un vértice sin color
    {
        x = MaxgradoVertex(); // encontrar el que tenga el grado máximo
        NumeroColor ++;
        color[x] = NumeroColor; 
        unprocessed --;
        Actualizar(NumeroColor); // encontrar el conjunto de no vecinos de x
        while (NNCount>0)
        {
        // encuentra y, el vértice tiene los vecinos máximos en común con x
        // VerticesInCommon es este número máximo
            y = FindSuitableY(NumeroColor, VerticesInCommon);
            if (VerticesInCommon == 0)
                y = MaxgradoInNN();
            color[y] = NumeroColor;
            unprocessed --;
            Actualizar(NumeroColor);

        }
    }
}


void Imprimir()
{
    for (int i=0; i < n; i++)
        cout << "Vertice " << i+1 
             << " es de color " << color[i] << endl;
}

int main(){
    GetInput(); 
    Init(); 
    Coloring(); 
    Imprimir(); 
}
