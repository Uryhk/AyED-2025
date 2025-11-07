


/*Difusión de mensajes en una red de computadoras
Una empresa tiene una red de computadoras conectadas entre sí mediante enlaces directos.
Cada computadora puede comunicarse solo con aquellas a las que está conectada directamente (por cable o por una red local).

Cuando una computadora envía un mensaje de difusión (broadcast), el objetivo es que dicho mensaje llegue a todas las computadoras posibles.
Sin embargo, para optimizar la red, la empresa quiere saber cuál es la distancia mínima (en cantidad de saltos) desde una computadora origen hasta todas las demás, y cuál es el orden en que los equipos reciben el mensaje.

Objetivo
Implementar un algoritmo basado en BFS (Breadth-First Search) que simule la propagación de un mensaje a través de la red, determinando:

la distancia mínima en saltos desde la fuente a cada nodo,

y el orden en que cada nodo recibe el mensaje.

*/






#include<iostream>

struct BFSResult {
    int orden[MAXN];     // orden de recepción
    int orden_len;
    int distancia[MAXN]; // saltos mínimos
    int parent[MAXN];    // árbol BFS
    int alcanzados;      // cantidad de nodos alcanzados (distancia != -1)
    int max_saltos;      // máximo de saltos desde s
};

class Grafo {
public:
    int n;
    int adj[MAXN][MAXN]; // matriz 0/1

    Grafo(int n_) {
        n = n_;
        for (int i = 0; i < MAXN; i++) {
            for (int j = 0; j < MAXN; j++) {
                adj[i][j] = 0;
            }
        }
    }

    void agregarConexion(int a, int b) {
        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    BFSResult bfs(int s);
};

















//resolucion




BFSResult Grafo::bfs(int s) {
    //TODO
    BFSResult result; 
   std::queue<int>aux;

   result.orden_len=0;
   result.alcanzados=0;
   result.max_saltos=0;
    bool visitado[MAXN]; 
  
   for(int i=0; i<n; i++){
   result.parent[i]=-1;
    result.distancia[i]=-1;
    visitado[i]=false;
}

 visitado[s]=true;
 result.distancia[s]=0;
 result.parent[s]=-1;
 aux.push(s);

result.orden[result.orden_len]=s;
result.orden_len++;
result.alcanzados++;
 
while(!aux.empty()){
int actual = aux.front();
aux.pop();

for(int vecino=0; vecino<n; vecino++){
if( adj[actual][vecino]==1 && !visitado[vecino]){
visitado[vecino]=true;
result.parent[vecino]=actual;
result.distancia[vecino]=result.distancia[actual]+1;

aux.push(vecino);

result.orden[result.orden_len]=vecino;
result.orden_len++;
result.alcanzados++;
if(result.distancia[vecino]> result.max_saltos){
   result.max_saltos=result.distancia[vecino];
}

}
}

}
    return result;
}
