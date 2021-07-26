#include<stdio.h>
#include<conio.h>
#include <windows.h>
#define INFINITY 9999
#define max 10
using namespace std;

 typedef struct {
	int dato;
	int marca;
} 
Grafo;
Grafo G[max][max];
int i,j,k,a,b,u,v,n,ni=1;
int min,cost_min=0,cost[9][9],parent[9];
int find(int);
int uni(int,int);
int Expansion[max][max];
void IngresaMatriz(Grafo G[max][max],int n);
void dijkstra(Grafo G[max][max],int n,int inicio);
void mostrar(Grafo G[max][max],int n);
void Dijkstra();
void Kruskal ();
void Prim();
int prims();

 

void Dijkstra(){
   int n,u;
    printf("CAMINO MINIMO CON DIJKTRA \n");
    printf("Ingrese numero  de Nodos: ");
    scanf("%d",&n);
   printf("\nIngrese La Matriz De Adyacencia :\n");
 
       
     IngresaMatriz( G,n);
    mostrar( G,n);
    printf("\nIngrese el Nodo De Partida :");
    scanf("%d",&u);
    dijkstra(G,n,u);
   
}

 void IngresaMatriz(Grafo G[max][max],int n){
 	 int i,j;
 	 for(i=0;i<n;i++){
    	for(j=0;j<n;j++){
        	
        		G[i][j].dato=0;
				G[i][j].marca=0;       	       	
        	
        }
    }
   
    for(i=0;i<n;i++){
    	for(j=0;j<n;j++){
        	   if((i!=j)&&(G[i][j].marca==0)){
        		   printf("\nIngrese Peso De Arista %d,%d :\n",i+1,j+1);
                   scanf("%d",&G[i][j].dato);
                   G[j][i].dato=G[i][j].dato ;
                   G[j][i].marca= 1;
        		}
        		
        	
           
                 
        	}     
        	
        }
   
 }
 void mostrar(Grafo G[max][max] , int n){
 	int i ,j;
 	  printf("\n Matrix Peso De Arista  \n\n");
        for(i=0;i<n;i++){
        	for(j=0;j<n;j++){
        	printf("%d \t", G[i][j].dato);
        }
              printf("\n");
        }
 }
void dijkstra(Grafo G[max][max] ,int n,int inicio)
{

	
   inicio=inicio-1;
    int cost[max][max],distancia[max],pred[max];
    int visited[max],count,seleccionar_min,nextnode,i,j;
   
   
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(G[i][j].dato==0)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=G[i][j].dato;
   
 
    for(i=0;i<n;i++)
    {
        distancia[i]=cost[inicio][i];
        pred[i]=inicio;
        visited[i]=0;
    }
   
    distancia[inicio]=0;
    visited[inicio]=1;
    count=1;
   
    while(count<n-1)
    {
        seleccionar_min=INFINITY;
       
   
        for(i=0;i<n;i++)
            if(distancia[i]<seleccionar_min&&!visited[i])
            {
                seleccionar_min=distancia[i];
                nextnode=i;
            }
           
                   
            visited[nextnode]=1;
            for(i=0;i<n;i++)
                if(!visited[i])
                    if(seleccionar_min+cost[nextnode][i]<distancia[i])
                    {
                        distancia[i]=seleccionar_min+cost[nextnode][i];
                        pred[i]=nextnode;
                    }
        count++;
    }

 
    for(i=0;i<n;i++)
        if(i!=inicio)
        {
            printf("\nDistancia del Nodo %d = %d",i+1,distancia[i]);
            printf("\n Camino = %d",i+1);
           
            j=i;
            do
            {
                j=pred[j];
                printf("<-%d",j+1);
            }while(j!=inicio);
    }
    printf("\n");

}
void Kruskal (){
		
 	printf(" RECORRIDO CON KRUSKAL \n");
	printf("INGRESE NUMERO DE NODOS : ");
    scanf("%d",&n);
    int mat[n+1][n+1];
    printf("\nIngrese La Matriz De Adyacencia :\n");
    IngresaMatriz( G,n);
    mostrar( G,n);
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
     cost[i][j]=G[i-1][j-1].dato;
   if(cost[i][j]==0)
    cost[i][j]=999;
  }
 }
  for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
     mat[i][j]=0;
  }
 }
 printf("");
  printf("\n ARISTAS DEL ARBOL EXPANSION MINIMO : \n",cost_min);
 while(ni<n)
 {
  for(i=1,min=999;i<=n;i++)
  {
   for(j=1;j<=n;j++)
   {
    if(cost[i][j]<min)
    {
     min=cost[i][j];
   
     a=u=i;
     b=v=j;
    }
   }
  }
 
  u=find(u);
  v=find(v);
 
  if(uni(u,v))
  {
  printf("\n%d ARISTA   de nodo %d a %d  = %d\n",ni++,a,b,min);
  mat[a][b]=min;
   cost_min +=min;
  }
  cost[a][b]=cost[b][a]=999;
 }
  for(i=1;i<=n;i++)
 {printf("\n");
  for(j=1;j<=n;j++)
  {
     printf(" %d ",mat[i][j]);
  }
 }
 printf("\n Peso Minimo = %d \n",cost_min);
 getch();
}
int find(int i)
{
 while(parent[i])
  i=parent[i];
 return i;
}
int uni(int i,int j)
{
 if(i!=j)
 {
  parent[j]=i;
  return 1;
 }
 return 0;

}
void Prim(){
	int i,j,total_cost;
	printf("RECORRIDO MINIMO GRAFO  CON PRIM \n");
    printf("Ingrese numero de Nodos :");
    scanf("%d",&n);
   
    printf("\nIngrese La Matriz De Adyacencia :\n");
    IngresaMatriz( G,n);
    mostrar( G,n);
       
         
   
    total_cost=prims();
    printf("\n \n ARBOL DE EXPANSION MINIMO MATRIZ :\n");
   
    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<n;j++)
            printf("%d \t",Expansion[i][j]);
    }
   
    printf("\n\n Costo Total  De Arbol de Expansion  Minimo = %d",total_cost);
    printf("\n");
}
int prims()
{
    int cost[max][max];
    int u,v,min_distance,distance[max],from[max];
    int visited[max],no_of_edges,i,min_cost,j;
   
 
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            if(G[i][j].dato==0)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=G[i][j].dato;
                Expansion[i][j]=0;
        }
       
 
    distance[0]=0;
    visited[0]=1;
   
    for(i=1;i<n;i++)
    {
        distance[i]=cost[0][i];
        from[i]=0;
        visited[i]=0;
    }
   
    min_cost=0;     
    no_of_edges=n-1;   
   
    while(no_of_edges>0)
    {
        min_distance=INFINITY;
        for(i=1;i<n;i++)
            if(visited[i]==0&&distance[i]<min_distance)
            {
                v=i;
                min_distance=distance[i];
            }
           
        u=from[v];
       
       
        Expansion[u][v]=distance[v];
        Expansion[v][u]=distance[v];
        no_of_edges--;
        visited[v]=1;
       
     
        for(i=1;i<n;i++)
            if(visited[i]==0&&cost[i][v]<distance[i])
            {
                distance[i]=cost[i][v];
                from[i]=v;
            }
       
        min_cost=min_cost+cost[u][v];
    }
   
    return(min_cost);
   
}
int main()
{

	int op;

		
	do{
		
		printf("\n 1- Algoritmo de KRUSKAL \n 2-Algoritmo de PRIM \n 3-Algoritmo de DIJKTRA  \n 4-Salir \n\n Opcion :  " );
		scanf("%d",&op);
		switch(op){
			case 1 :
				Kruskal();
				system("pause");
				break;
		    case 2:
				Prim();
				system("pause");
				break;
		    case 3:
				Dijkstra();
				system("pause");
				break;
		   
		}
	system("cls");	
	}while(op!=4);

    return 0;
 }
