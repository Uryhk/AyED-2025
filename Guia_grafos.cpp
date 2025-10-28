/* ⚠️ Puntos de atención:

Siempre liberar memoria con delete[] para arreglos
Los destructores ya manejan la limpieza de listas y matrices
En tus implementaciones, no olvides delete[] al final de cada método
*/

#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

// Estructura para representar una arista con peso
struct Arista {
    int destino;
    int peso;
    Arista* siguiente;
};

// ============================================
// GRAFO NO DIRIGIDO - LISTA DE ADYACENCIA
// ============================================
class GrafoNoDigidoLista {
private:
    int V; // Número de vértices
    Arista** adj; // Arreglo de punteros a listas enlazadas
    
public:
    GrafoNoDigidoLista(int v) : V(v) {
        adj = new Arista*[V];
        for (int i = 0; i < V; i++) {
            adj[i] = nullptr;
        }
    }
    
    ~GrafoNoDigidoLista() {
        for (int i = 0; i < V; i++) {
            Arista* actual = adj[i];
            while (actual != nullptr) {
                Arista* temp = actual;
                actual = actual->siguiente;
                delete temp;
            }
        }
        delete[] adj;
    }
    
    // Agregar arista con peso (bidireccional)
    void agregarArista(int u, int v, int peso) {
        // IMPLEMENTAR:
        // 1. Crear nueva arista de u a v:
        //    - Arista* nueva1 = new Arista
        //    - Asignar destino = v, peso = peso
        //    - nueva1->siguiente = adj[u]
        //    - adj[u] = nueva1
        // 2. Crear nueva arista de v a u (bidireccional):
        //    - Arista* nueva2 = new Arista
        //    - Asignar destino = u, peso = peso
        //    - nueva2->siguiente = adj[v]
        //    - adj[v] = nueva2
    }
    
    // BFS - Búsqueda por Amplitud
    void BFS(int inicio) {
        // IMPLEMENTAR:
        // 1. Crear arreglo de visitados: bool* visitado = new bool[V]
        //    Inicializar todos en false
        // 2. Crear una cola (queue<int>)
        // 3. Marcar el nodo inicial como visitado y agregarlo a la cola
        // 4. Mientras la cola no esté vacía:
        //    - Extraer el frente de la cola
        //    - Procesar el nodo (imprimirlo)
        //    - Recorrer la lista enlazada adj[nodo]:
        //      * Para cada arista en la lista:
        //        - Si el destino no está visitado:
        //          * Marcarlo como visitado
        //          * Agregarlo a la cola
        // 5. Liberar memoria: delete[] visitado
    }
    
    // DFS - Búsqueda por Profundidad (Iterativo)
    void DFS(int inicio) {
        // IMPLEMENTAR:
        // 1. Crear arreglo de visitados: bool* visitado = new bool[V]
        //    Inicializar todos en false
        // 2. Crear una pila (stack<int>)
        // 3. Agregar el nodo inicial a la pila
        // 4. Mientras la pila no esté vacía:
        //    - Extraer el tope de la pila
        //    - Si no está visitado:
        //      * Marcarlo como visitado
        //      * Procesarlo (imprimirlo)
        //      * Recorrer la lista enlazada adj[nodo]:
        //        - Para cada arista, agregar el destino a la pila si no está visitado
        // 5. Liberar memoria: delete[] visitado
    }
    
    // DFS Recursivo (auxiliar)
    void DFSRecursivoUtil(int v, bool* visitado) {
        // IMPLEMENTAR:
        // 1. Marcar el nodo actual como visitado
        // 2. Procesarlo (imprimirlo)
        // 3. Recorrer la lista enlazada adj[v]:
        //    - Para cada arista:
        //      * Si el destino no está visitado:
        //        - Llamar recursivamente a DFSRecursivoUtil con el destino
    }
    
    // DFS Recursivo (método público)
    void DFSRecursivo(int inicio) {
        // IMPLEMENTAR:
        // 1. Crear arreglo de visitados: bool* visitado = new bool[V]
        //    Inicializar todos en false
        // 2. Llamar a DFSRecursivoUtil con el nodo inicial
        // 3. Liberar memoria: delete[] visitado
    }
    
    // Algoritmo de Dijkstra - Camino más corto desde un origen
    void dijkstra(int origen) {
        // IMPLEMENTAR:
        // 1. Crear arreglo de distancias: int* dist = new int[V]
        //    Inicializar todos en INT_MAX
        // 2. Crear priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>>
        //    El pair es (distancia, nodo)
        // 3. Establecer dist[origen] = 0
        // 4. Insertar (0, origen) en la cola de prioridad
        // 5. Mientras la cola no esté vacía:
        //    - Extraer el nodo con menor distancia
        //    - Si la distancia actual es mayor a la almacenada, continuar
        //    - Recorrer la lista enlazada adj[nodo]:
        //      * Para cada arista:
        //        - Calcular nueva_dist = dist[nodo] + arista->peso
        //        - Si nueva_dist < dist[arista->destino]:
        //          * Actualizar dist[arista->destino]
        //          * Insertar (nueva_dist, arista->destino) en la cola
        // 6. Imprimir el arreglo de distancias
        // 7. Liberar memoria: delete[] dist
    }
    
    // Verificar si el grafo es conexo
    bool esConexo() {
        // IMPLEMENTAR:
        // 1. Hacer un BFS o DFS desde el nodo 0
        // 2. Contar cuántos nodos se visitaron
        // 3. Retornar true si se visitaron todos los nodos, false en caso contrario
        // Nota: Usar arreglo dinámico para visitados
    }
    
    // Imprimir grafo
    void imprimir() {
        cout << "\nGrafo No Dirigido (Lista de Adyacencia):" << endl;
        for (int i = 0; i < V; i++) {
            cout << i << ": ";
            Arista* actual = adj[i];
            while (actual != nullptr) {
                cout << "(" << actual->destino << ",w=" << actual->peso << ") ";
                actual = actual->siguiente;
            }
            cout << endl;
        }
    }
};

// ============================================
// GRAFO NO DIRIGIDO - MATRIZ DE ADYACENCIA
// ============================================
class GrafoNoDigidoMatriz {
private:
    int V;
    int** matriz; // Matriz dinámica
    
public:
    GrafoNoDigidoMatriz(int v) : V(v) {
        // Crear matriz dinámica
        matriz = new int*[V];
        for (int i = 0; i < V; i++) {
            matriz[i] = new int[V];
            for (int j = 0; j < V; j++) {
                matriz[i][j] = 0;
            }
        }
    }
    
    ~GrafoNoDigidoMatriz() {
        for (int i = 0; i < V; i++) {
            delete[] matriz[i];
        }
        delete[] matriz;
    }
    
    // Agregar arista con peso (bidireccional)
    void agregarArista(int u, int v, int peso) {
        // IMPLEMENTAR:
        // Asignar peso en matriz[u][v] y matriz[v][u]
    }
    
    // BFS - Búsqueda por Amplitud
    void BFS(int inicio) {
        // IMPLEMENTAR:
        // 1. Crear arreglo de visitados: bool* visitado = new bool[V]
        //    Inicializar todos en false
        // 2. Crear una cola (queue<int>)
        // 3. Marcar el nodo inicial como visitado y agregarlo a la cola
        // 4. Mientras la cola no esté vacía:
        //    - Extraer el frente de la cola
        //    - Procesar el nodo (imprimirlo)
        //    - Para i = 0 hasta V-1:
        //      * Si matriz[nodo][i] > 0 y i no está visitado:
        //        - Marcar i como visitado
        //        - Agregar i a la cola
        // 5. Liberar memoria: delete[] visitado
    }
    
    // DFS - Búsqueda por Profundidad (Iterativo)
    void DFS(int inicio) {
        // IMPLEMENTAR:
        // Similar al BFS pero usando pila (stack<int>) en lugar de cola
        // Recorrer la matriz para encontrar vecinos
    }
    
    // Algoritmo de Dijkstra
    void dijkstra(int origen) {
        // IMPLEMENTAR:
        // 1. Crear arreglo de distancias: int* dist = new int[V]
        //    Inicializar todos en INT_MAX
        // 2. Crear arreglo de visitados: bool* visitado = new bool[V]
        //    Inicializar todos en false
        // 3. Establecer dist[origen] = 0
        // 4. Repetir V veces:
        //    - Encontrar el nodo no visitado con menor distancia (buscar en dist[])
        //    - Marcarlo como visitado
        //    - Para cada vecino j (donde matriz[nodo][j] > 0):
        //      * Si !visitado[j] y dist[nodo] + matriz[nodo][j] < dist[j]:
        //        - Actualizar dist[j]
        // 5. Imprimir el arreglo de distancias
        // 6. Liberar memoria: delete[] dist, delete[] visitado
    }
    
    // Algoritmo de Floyd-Warshall - Caminos más cortos entre todos los pares
    void floydWarshall() {
        // IMPLEMENTAR:
        // 1. Crear matriz dist[V][V]: int** dist = new int*[V]
        //    Para cada fila: dist[i] = new int[V]
        // 2. Copiar la matriz de adyacencia a dist
        // 3. Inicializar la diagonal en 0 (dist[i][i] = 0)
        // 4. Para las posiciones donde matriz[i][j] == 0 y i != j:
        //    - Establecer dist[i][j] = INT_MAX
        // 5. Triple bucle anidado:
        //    for k = 0 to V-1:  // k es el nodo intermedio
        //       for i = 0 to V-1:
        //          for j = 0 to V-1:
        //             if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
        //                if (dist[i][k] + dist[k][j] < dist[i][j])
        //                   dist[i][j] = dist[i][k] + dist[k][j]
        // 6. Imprimir la matriz de distancias resultante
        // 7. Liberar memoria: for(i) delete[] dist[i]; delete[] dist
    }
    
    // Imprimir matriz
    void imprimir() {
        cout << "\nGrafo No Dirigido (Matriz de Adyacencia):" << endl;
        cout << "   ";
        for (int i = 0; i < V; i++) cout << i << "  ";
        cout << endl;
        
        for (int i = 0; i < V; i++) {
            cout << i << "  ";
            for (int j = 0; j < V; j++) {
                cout << matriz[i][j] << "  ";
            }
            cout << endl;
        }
    }
};

// ============================================
// GRAFO DIRIGIDO - LISTA DE ADYACENCIA
// ============================================
class GrafoDirigidoLista {
private:
    int V;
    Arista** adj; // Arreglo de punteros a listas enlazadas
    
public:
    GrafoDirigidoLista(int v) : V(v) {
        adj = new Arista*[V];
        for (int i = 0; i < V; i++) {
            adj[i] = nullptr;
        }
    }
    
    ~GrafoDirigidoLista() {
        for (int i = 0; i < V; i++) {
            Arista* actual = adj[i];
            while (actual != nullptr) {
                Arista* temp = actual;
                actual = actual->siguiente;
                delete temp;
            }
        }
        delete[] adj;
    }
    
    // Agregar arista con peso (unidireccional)
    void agregarArista(int u, int v, int peso) {
        // IMPLEMENTAR:
        // Crear nueva arista solo de u a v (no agregar de v a u)
        // Arista* nueva = new Arista
        // nueva->destino = v
        // nueva->peso = peso
        // nueva->siguiente = adj[u]
        // adj[u] = nueva
    }
    
    // BFS - Búsqueda por Amplitud
    void BFS(int inicio) {
        // IMPLEMENTAR:
        // Igual que en grafo no dirigido con lista
        // Usar arreglos dinámicos
    }
    
    // DFS - Búsqueda por Profundidad (Iterativo)
    void DFS(int inicio) {
        // IMPLEMENTAR:
        // Igual que en grafo no dirigido con lista
        // Usar arreglos dinámicos
    }
    
    // DFS Recursivo (auxiliar)
    void DFSRecursivoUtil(int v, bool* visitado) {
        // IMPLEMENTAR:
        // Igual que en grafo no dirigido con lista
    }
    
    // DFS Recursivo
    void DFSRecursivo(int inicio) {
        // IMPLEMENTAR:
        // Igual que en grafo no dirigido con lista
        // Crear arreglo dinámico de visitados
    }
    
    // Algoritmo de Dijkstra
    void dijkstra(int origen) {
        // IMPLEMENTAR:
        // Igual que en grafo no dirigido con lista
        // Usar arreglos dinámicos
    }
    
    // Detectar ciclos (usando DFS)
    bool tieneCicloUtil(int v, bool* visitado, bool* recStack) {
        // IMPLEMENTAR:
        // 1. Marcar el nodo como visitado y en la pila de recursión
        //    visitado[v] = true
        //    recStack[v] = true
        // 2. Recorrer la lista enlazada adj[v]:
        //    - Para cada arista:
        //      * Si el destino no está visitado:
        //        - Llamar recursivamente, si retorna true, hay ciclo
        //      * Si el destino está en recStack:
        //        - Hay un ciclo, retornar true
        // 3. Quitar el nodo de la pila de recursión: recStack[v] = false
        // 4. Retornar false
    }
    
    bool tieneCiclo() {
        // IMPLEMENTAR:
        // 1. Crear arreglos: bool* visitado = new bool[V]
        //                    bool* recStack = new bool[V]
        //    Inicializar todos en false
        // 2. Para cada nodo no visitado:
        //    - Llamar a tieneCicloUtil
        //    - Si retorna true, liberar memoria y retornar true
        // 3. Liberar memoria y retornar false
    }
    
    // Ordenamiento Topológico (auxiliar)
    void topoSortUtil(int v, bool* visitado, stack<int>& pila) {
        // IMPLEMENTAR:
        // 1. Marcar el nodo como visitado
        // 2. Recorrer la lista enlazada adj[v]:
        //    - Para cada arista:
        //      * Si el destino no está visitado:
        //        - Llamar recursivamente a topoSortUtil
        // 3. Agregar el nodo actual a la pila
    }
    
    // Ordenamiento Topológico
    void ordenamientoTopologico() {
        // IMPLEMENTAR:
        // 1. Crear pila (stack<int>) y arreglo: bool* visitado = new bool[V]
        // 2. Para cada nodo no visitado:
        //    - Llamar a topoSortUtil
        // 3. Imprimir el contenido de la pila
        // 4. Liberar memoria: delete[] visitado
    }
    
    // Imprimir grafo
    void imprimir() {
        cout << "\nGrafo Dirigido (Lista de Adyacencia):" << endl;
        for (int i = 0; i < V; i++) {
            cout << i << " -> ";
            Arista* actual = adj[i];
            while (actual != nullptr) {
                cout << "(" << actual->destino << ",w=" << actual->peso << ") ";
                actual = actual->siguiente;
            }
            cout << endl;
        }
    }
};

// ============================================
// GRAFO DIRIGIDO - MATRIZ DE ADYACENCIA
// ============================================
class GrafoDirigidoMatriz {
private:
    int V;
    int** matriz; // Matriz dinámica
    
public:
    GrafoDirigidoMatriz(int v) : V(v) {
        matriz = new int*[V];
        for (int i = 0; i < V; i++) {
            matriz[i] = new int[V];
            for (int j = 0; j < V; j++) {
                matriz[i][j] = 0;
            }
        }
    }
    
    ~GrafoDirigidoMatriz() {
        for (int i = 0; i < V; i++) {
            delete[] matriz[i];
        }
        delete[] matriz;
    }
    
    // Agregar arista con peso (unidireccional)
    void agregarArista(int u, int v, int peso) {
        // IMPLEMENTAR:
        // Asignar peso solo en matriz[u][v]
    }
    
    // BFS - Búsqueda por Amplitud
    void BFS(int inicio) {
        // IMPLEMENTAR:
        // Igual que en grafo no dirigido con matriz
        // Usar arreglos dinámicos
    }
    
    // DFS - Búsqueda por Profundidad (Iterativo)
    void DFS(int inicio) {
        // IMPLEMENTAR:
        // Igual que en grafo no dirigido con matriz
        // Usar arreglos dinámicos
    }
    
    // Algoritmo de Dijkstra
    void dijkstra(int origen) {
        // IMPLEMENTAR:
        // Igual que en grafo no dirigido con matriz
        // Usar arreglos dinámicos
    }
    
    // Algoritmo de Floyd-Warshall - Caminos más cortos entre todos los pares
    void floydWarshall() {
        // IMPLEMENTAR:
        // Igual que en grafo no dirigido con matriz
        // Usar arreglos dinámicos (int**)
    }
    
    // Detectar ciclos
    bool tieneCiclo() {
        // IMPLEMENTAR:
        // Similar al de lista, pero adaptado para matriz
        // Para encontrar vecinos: si matriz[u][v] > 0, entonces v es vecino de u
        // Usar arreglos dinámicos para visitado y recStack
    }
    
    // Imprimir matriz
    void imprimir() {
        cout << "\nGrafo Dirigido (Matriz de Adyacencia):" << endl;
        cout << "   ";
        for (int i = 0; i < V; i++) cout << i << "  ";
        cout << endl;
        
        for (int i = 0; i < V; i++) {
            cout << i << "  ";
            for (int j = 0; j < V; j++) {
                cout << matriz[i][j] << "  ";
            }
            cout << endl;
        }
    }
};

// ============================================
// MAIN - INSTRUCCIONES DE USO
// ============================================
int main() {
    cout << "=== GUÍA DE IMPLEMENTACIÓN DE GRAFOS EN C++ ===" << endl;
    cout << "\nEsta guía contiene las estructuras y métodos para implementar." << endl;
    cout << "Cada método tiene comentarios con instrucciones detalladas." << endl;
    cout << "\n*** IMPORTANTE: Implementación sin vectores STL ***" << endl;
    cout << "- Usa arreglos dinámicos (new/delete)" << endl;
    cout << "- Listas enlazadas para lista de adyacencia" << endl;
    cout << "- Matrices dinámicas para matriz de adyacencia" << endl;
    
    cout << "\n--- Tipos de Grafos Disponibles ---" << endl;
    cout << "1. Grafo No Dirigido con Lista de Adyacencia (listas enlazadas)" << endl;
    cout << "2. Grafo No Dirigido con Matriz de Adyacencia (arreglos 2D)" << endl;
    cout << "3. Grafo Dirigido con Lista de Adyacencia (listas enlazadas)" << endl;
    cout << "4. Grafo Dirigido con Matriz de Adyacencia (arreglos 2D)" << endl;
    
    cout << "\n--- Métodos a Implementar ---" << endl;
    cout << "✓ agregarArista(u, v, peso)" << endl;
    cout << "✓ BFS(inicio) - Búsqueda por Amplitud" << endl;
    cout << "✓ DFS(inicio) - Búsqueda por Profundidad (Iterativo)" << endl;
    cout << "✓ DFSRecursivo(inicio) - Búsqueda por Profundidad (Recursivo)" << endl;
    cout << "✓ dijkstra(origen) - Camino más corto desde un origen" << endl;
    cout << "✓ floydWarshall() - Caminos más cortos entre todos los pares (solo matriz)" << endl;
    cout << "✓ esConexo() - Solo para grafos no dirigidos" << endl;
    cout << "✓ tieneCiclo() - Solo para grafos dirigidos" << endl;
    cout << "✓ ordenamientoTopologico() - Solo para grafos dirigidos acíclicos" << endl;
    
    cout << "\n--- Ejemplo de Uso ---" << endl;
    cout << "GrafoNoDigidoLista g(5);" << endl;
    cout << "g.agregarArista(0, 1, 10);" << endl;
    cout << "g.agregarArista(1, 2, 5);" << endl;
    cout << "g.BFS(0);" << endl;
    cout << "g.dijkstra(0);" << endl;
    
    cout << "\n--- Gestión de Memoria ---" << endl;
    cout << "• Siempre liberar memoria con delete/delete[]" << endl;
    cout << "• Los destructores ya están implementados" << endl;
    cout << "• En tus métodos, recuerda:" << endl;
    cout << "  - Arreglos: bool* arr = new bool[n]; ... delete[] arr;" << endl;
    cout << "  - Matrices: int** mat = new int*[n]; ... delete[] mat[i]; delete[] mat;" << endl;
    cout << "  - Listas: Recorrer y delete cada nodo" << endl;
    
    cout << "\n--- Notas Importantes ---" << endl;
    cout << "• Lista de Adyacencia: Mejor para grafos dispersos (pocas aristas)" << endl;
    cout << "• Matriz de Adyacencia: Mejor para grafos densos (muchas aristas)" << endl;
    cout << "• Complejidades:" << endl;
    cout << "  - BFS/DFS con Lista: O(V + E)" << endl;
    cout << "  - BFS/DFS con Matriz: O(V²)" << endl;
    cout << "  - Dijkstra con Lista y heap: O((V + E) log V)" << endl;
    cout << "  - Dijkstra con Matriz: O(V²)" << endl;
    cout << "  - Floyd-Warshall: O(V³)" << endl;
    cout << "\n• Diferencias clave:" << endl;
    cout << "  - Dijkstra: Camino más corto desde UN origen a todos los demás" << endl;
    cout << "  - Floyd-Warshall: Caminos más cortos entre TODOS los pares de nodos" << endl;
    cout << "  - Floyd-Warshall solo se implementa con matriz (más eficiente)" << endl;
    
    return 0;
}
