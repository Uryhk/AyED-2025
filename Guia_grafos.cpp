/* ⚠️ GUÍA DE APLICACIONES BFS Y DFS
   Esta guía se enfoca en aplicaciones prácticas de BFS y DFS
   usando LISTA DE ADYACENCIA (la más común y eficiente)
*/

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Estructura para representar una arista
struct Arista {
    int destino;
    Arista* siguiente;
};

// ============================================
// GRAFO - LISTA DE ADYACENCIA
// ============================================
class Grafo {
private:
    int V; // Número de vértices
    Arista** adj; // Arreglo de punteros a listas enlazadas
    bool dirigido; // true = dirigido, false = no dirigido
    
public:
    Grafo(int v, bool esDirigido = false) : V(v), dirigido(esDirigido) {
        adj = new Arista*[V];
        for (int i = 0; i < V; i++) {
            adj[i] = nullptr;
        }
    }
    
    ~Grafo() {
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
    
    // Agregar arista
    void agregarArista(int u, int v) {
        // IMPLEMENTAR:
        // 1. Crear nueva arista de u a v:
        //    Arista* nueva = new Arista;
        //    nueva->destino = v;
        //    nueva->siguiente = adj[u];
        //    adj[u] = nueva;
        // 2. Si NO es dirigido, agregar también de v a u:
        //    if (!dirigido) {
        //        Arista* nueva2 = new Arista;
        //        nueva2->destino = u;
        //        nueva2->siguiente = adj[v];
        //        adj[v] = nueva2;
        //    }
    }
    
    // ============================================
    // APLICACIÓN 1: BFS BÁSICO - Recorrido por niveles
    // ============================================
    void BFS(int inicio) {
        // IMPLEMENTAR:
        // 1. Crear arreglo: bool* visitado = new bool[V]
        //    Inicializar todos en false
        // 2. Crear cola: queue<int> cola;
        // 3. Marcar inicio como visitado y agregarlo a la cola
        // 4. Mientras la cola no esté vacía:
        //    - int actual = cola.front(); cola.pop();
        //    - Imprimir actual
        //    - Recorrer lista adj[actual]:
        //      * Para cada arista:
        //        - Si destino no está visitado:
        //          * Marcarlo como visitado
        //          * Agregarlo a la cola
        // 5. Liberar memoria: delete[] visitado;
        
        cout << "\nBFS desde " << inicio << ": ";
        // Tu código aquí
        cout << endl;
    }
    
    // ============================================
    // APLICACIÓN 2: DFS RECURSIVO - Recorrido en profundidad
    // ============================================
    void DFSRecursivoUtil(int v, bool* visitado) {
        // IMPLEMENTAR:
        // 1. Marcar v como visitado: visitado[v] = true;
        // 2. Imprimir v: cout << v << " ";
        // 3. Recorrer lista adj[v]:
        //    Arista* temp = adj[v];
        //    while (temp != nullptr) {
        //        if (!visitado[temp->destino]) {
        //            DFSRecursivoUtil(temp->destino, visitado);
        //        }
        //        temp = temp->siguiente;
        //    }
    }
    
    void DFSRecursivo(int inicio) {
        // IMPLEMENTAR:
        // 1. Crear arreglo: bool* visitado = new bool[V]
        //    Inicializar todos en false
        // 2. cout << "\nDFS Recursivo desde " << inicio << ": ";
        // 3. Llamar a DFSRecursivoUtil(inicio, visitado);
        // 4. cout << endl;
        // 5. Liberar memoria: delete[] visitado;
    }
    
    // ============================================
    // APLICACIÓN 3: DFS ITERATIVO - Con pila explícita
    // ============================================
    void DFSIterativo(int inicio) {
        // IMPLEMENTAR:
        // 1. Crear arreglo: bool* visitado = new bool[V]
        // 2. Crear pila: stack<int> pila;
        // 3. pila.push(inicio);
        // 4. Mientras la pila no esté vacía:
        //    - int actual = pila.top(); pila.pop();
        //    - Si no está visitado:
        //      * Marcarlo como visitado
        //      * Imprimirlo
        //      * Recorrer lista adj[actual] y agregar vecinos a la pila
        // 5. Liberar memoria
        
        cout << "\nDFS Iterativo desde " << inicio << ": ";
        // Tu código aquí
        cout << endl;
    }
    
    // ============================================
    // APLICACIÓN 4: CAMINO MÁS CORTO (sin pesos)
    // ============================================
    void caminoMasCorto(int origen, int destino) {
        // IMPLEMENTAR:
        // 1. Crear arreglos:
        //    bool* visitado = new bool[V];
        //    int* distancia = new int[V];
        //    int* padre = new int[V];
        //    Inicializar: visitado=false, distancia=-1, padre=-1
        // 2. BFS desde origen:
        //    - distancia[origen] = 0, padre[origen] = -1
        //    - Para cada vecino: distancia[vecino] = distancia[actual] + 1
        // 3. Si distancia[destino] == -1:
        //    - cout << "No hay camino"
        //    - Retornar
        // 4. Reconstruir camino:
        //    - Usar un stack<int> o arreglo temporal
        //    - int nodo = destino;
        //    - while (nodo != -1) { guardar nodo; nodo = padre[nodo]; }
        //    - Imprimir camino en orden correcto
        // 5. Imprimir distancia[destino]
        // 6. Liberar memoria
        
        cout << "\nCamino más corto de " << origen << " a " << destino << ":" << endl;
        // Tu código aquí
    }
    
    // ============================================
    // APLICACIÓN 5: COMPONENTES CONEXAS
    // ============================================
    int contarComponentes() {
        // IMPLEMENTAR:
        // 1. Crear arreglo: bool* visitado = new bool[V]
        // 2. int componentes = 0;
        // 3. Para cada nodo i de 0 a V-1:
        //    - Si !visitado[i]:
        //      * componentes++;
        //      * Hacer BFS/DFS desde i (marca todos los alcanzables)
        // 4. Liberar memoria
        // 5. return componentes;
        
        // Tu código aquí
        return 0;
    }
    
    // ============================================
    // APLICACIÓN 6: NODOS A DISTANCIA K
    // ============================================
    void nodosADistanciaK(int origen, int k) {
        // IMPLEMENTAR:
        // 1. Crear arreglos:
        //    bool* visitado = new bool[V];
        //    int* distancia = new int[V];
        //    Inicializar en false y -1
        // 2. BFS desde origen calculando distancias
        // 3. Recorrer distancia[] e imprimir nodos donde distancia[i] == k
        // 4. Liberar memoria
        
        cout << "\nNodos a distancia " << k << " desde " << origen << ": ";
        // Tu código aquí
        cout << endl;
    }
    
    // ============================================
    // APLICACIÓN 7: VERIFICAR SI ES BIPARTITO
    // ============================================
    bool esBipartito() {
        // IMPLEMENTAR:
        // 1. Crear arreglo: int* color = new int[V]
        //    Inicializar todos en -1
        // 2. Para cada componente (nodos no coloreados):
        //    - BFS asignando colores 0 y 1 alternadamente
        //    - color[inicio] = 0
        //    - Para cada vecino:
        //      * Si color[vecino] == -1: color[vecino] = 1 - color[actual]
        //      * Si color[vecino] == color[actual]: return false
        // 3. Liberar memoria
        // 4. return true
        
        // Tu código aquí
        return false;
    }
    
    // ============================================
    // APLICACIÓN 8: DETECTAR CICLOS (Grafo NO dirigido)
    // ============================================
    bool tieneCicloNoDirigidoUtil(int v, bool* visitado, int padre) {
        // IMPLEMENTAR:
        // 1. visitado[v] = true;
        // 2. Recorrer lista adj[v]:
        //    - Para cada vecino:
        //      * Si !visitado[vecino]:
        //        - Si tieneCicloNoDirigidoUtil(vecino, visitado, v) return true
        //      * Si visitado[vecino] && vecino != padre:
        //        - return true (hay ciclo)
        // 3. return false
        
        // Tu código aquí
        return false;
    }
    
    bool tieneCiclo() {
        // IMPLEMENTAR:
        // 1. bool* visitado = new bool[V];
        // 2. Si es dirigido: usar método diferente (con recStack)
        // 3. Si NO es dirigido:
        //    - Para cada nodo no visitado:
        //      * Si tieneCicloNoDirigidoUtil(i, visitado, -1) return true
        // 4. Liberar memoria
        // 5. return false
        
        // Tu código aquí
        return false;
    }
    
    // ============================================
    // APLICACIÓN 9: DETECTAR CICLOS (Grafo DIRIGIDO)
    // ============================================
    bool tieneCicloDirigidoUtil(int v, bool* visitado, bool* recStack) {
        // IMPLEMENTAR:
        // 1. visitado[v] = true;
        //    recStack[v] = true;
        // 2. Recorrer lista adj[v]:
        //    - Para cada vecino:
        //      * Si !visitado[vecino]:
        //        - Si tieneCicloDirigidoUtil(vecino, ...) return true
        //      * Si recStack[vecino]:
        //        - return true (hay ciclo)
        // 3. recStack[v] = false;
        // 4. return false
        
        // Tu código aquí
        return false;
    }
    
    // ============================================
    // APLICACIÓN 10: ORDENAMIENTO TOPOLÓGICO
    // ============================================
    void topoSortUtil(int v, bool* visitado, stack<int>& pila) {
        // IMPLEMENTAR:
        // 1. visitado[v] = true;
        // 2. Recorrer lista adj[v]:
        //    - Para cada vecino no visitado:
        //      * topoSortUtil(vecino, visitado, pila);
        // 3. pila.push(v); // Agregar DESPUÉS de procesar vecinos
    }
    
    void ordenamientoTopologico() {
        // IMPLEMENTAR:
        // 1. Verificar que sea dirigido y sin ciclos
        // 2. bool* visitado = new bool[V];
        //    stack<int> pila;
        // 3. Para cada nodo no visitado:
        //    - topoSortUtil(i, visitado, pila);
        // 4. Imprimir contenido de la pila (es el orden topológico)
        // 5. Liberar memoria
        
        cout << "\nOrdenamiento Topológico: ";
        // Tu código aquí
        cout << endl;
    }
    
    // ============================================
    // APLICACIÓN 11: VERIFICAR CONECTIVIDAD
    // ============================================
    bool hayConexion(int origen, int destino) {
        // IMPLEMENTAR:
        // 1. BFS o DFS desde origen
        // 2. Verificar si destino fue visitado
        // 3. return true/false
        
        // Tu código aquí
        return false;
    }
    
    // ============================================
    // APLICACIÓN 12: ÁRBOL DE EXPANSIÓN DFS
    // ============================================
    void arbolExpansionDFS(int inicio) {
        // IMPLEMENTAR:
        // 1. bool* visitado = new bool[V];
        //    int* padre = new int[V];
        //    Inicializar padre[i] = -1
        // 2. DFS recursivo guardando el padre de cada nodo
        // 3. Imprimir aristas del árbol:
        //    Para cada i: if (padre[i] != -1) cout << padre[i] << " -> " << i
        // 4. Liberar memoria
        
        cout << "\nÁrbol de expansión DFS desde " << inicio << ":" << endl;
        // Tu código aquí
    }
    
    // ============================================
    // APLICACIÓN 13: IMPRIMIR TODOS LOS CAMINOS
    // ============================================
    void todosLosCaminosUtil(int actual, int destino, bool* visitado, 
                             int* camino, int &indice) {
        // IMPLEMENTAR:
        // 1. Marcar actual como visitado
        // 2. Agregar actual al camino: camino[indice++] = actual
        // 3. Si actual == destino:
        //    - Imprimir el camino
        // 4. Si no:
        //    - Para cada vecino no visitado:
        //      * Recursión: todosLosCaminosUtil(vecino, ...)
        // 5. Backtrack: indice--; visitado[actual] = false;
    }
    
    void todosLosCaminos(int origen, int destino) {
        // IMPLEMENTAR:
        // 1. bool* visitado = new bool[V];
        //    int* camino = new int[V];
        //    int indice = 0;
        // 2. cout << "\nTodos los caminos de " << origen << " a " << destino
        // 3. todosLosCaminosUtil(origen, destino, visitado, camino, indice);
        // 4. Liberar memoria
        
        // Tu código aquí
    }
    
    // Imprimir grafo
    void imprimir() {
        cout << "\nGrafo (" << (dirigido ? "Dirigido" : "No Dirigido") 
             << ") - Lista de Adyacencia:" << endl;
        for (int i = 0; i < V; i++) {
            cout << i << (dirigido ? " -> " : " -- ");
            Arista* actual = adj[i];
            while (actual != nullptr) {
                cout << actual->destino << " ";
                actual = actual->siguiente;
            }
            cout << endl;
        }
    }
};

// ============================================
// APLICACIONES ESPECIALES CON GRIDS/MATRICES
// ============================================

// ============================================
// APLICACIÓN 14: BFS EN LABERINTO/GRID
// ============================================
void bfsLaberinto(int** laberinto, int filas, int cols, 
                  int inicioX, int inicioY, int finX, int finY) {
    // IMPLEMENTAR:
    // 1. Crear matriz de visitados: bool** visitado
    //    Inicializar en false
    // 2. Crear matriz de distancias: int** distancia
    //    Inicializar en -1
    // 3. Cola de pares: queue<pair<int,int>> cola;
    // 4. Movimientos: int dx[] = {0, 0, 1, -1};
    //                 int dy[] = {1, -1, 0, 0};
    // 5. BFS:
    //    - Desde (inicioX, inicioY)
    //    - Para cada posición, probar 4 direcciones
    //    - Verificar límites y si es válido (laberinto[x][y] == 0)
    // 6. Si alcanzamos (finX, finY), imprimir distancia
    // 7. Liberar memoria de matrices dinámicas
    
    cout << "\nCamino más corto en laberinto:" << endl;
    // Tu código aquí
}

// ============================================
// APLICACIÓN 15: CONTAR ISLAS (DFS/BFS en matriz)
// ============================================
void dfsIsla(int** grid, bool** visitado, int filas, int cols, int x, int y) {
    // IMPLEMENTAR:
    // 1. Marcar (x, y) como visitado
    // 2. Movimientos: dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0}
    // 3. Para cada dirección:
    //    - Calcular nueva posición (nx, ny)
    //    - Si está dentro de límites, es tierra (grid[nx][ny]==1) 
    //      y no visitado:
    //      * Llamar recursivamente dfsIsla(grid, visitado, filas, cols, nx, ny)
}

int contarIslas(int** grid, int filas, int cols) {
    // IMPLEMENTAR:
    // 1. Crear matriz: bool** visitado
    // 2. int islas = 0;
    // 3. Para cada celda (i,j):
    //    - Si grid[i][j] == 1 && !visitado[i][j]:
    //      * islas++
    //      * dfsIsla(grid, visitado, filas, cols, i, j)
    // 4. Liberar memoria
    // 5. return islas
    
    // Tu código aquí
    return 0;
}

// ============================================
// MAIN - EJEMPLOS DE USO
// ============================================
int main() {
    cout << "=== GUÍA DE APLICACIONES BFS Y DFS ===" << endl;
    cout << "\n*** IMPLEMENTACIÓN CON LISTA DE ADYACENCIA ***" << endl;
    cout << "(La más común y eficiente para la mayoría de casos)" << endl;
    
    cout << "\n--- APLICACIONES DISPONIBLES ---\n" << endl;
    
    cout << "📊 RECORRIDOS BÁSICOS:" << endl;
    cout << "1. BFS(inicio) - Recorrido por niveles" << endl;
    cout << "2. DFSRecursivo(inicio) - Recorrido en profundidad" << endl;
    cout << "3. DFSIterativo(inicio) - DFS con pila explícita" << endl;
    
    cout << "\n🎯 CAMINOS Y DISTANCIAS:" << endl;
    cout << "4. caminoMasCorto(origen, destino) - Menor cantidad de aristas" << endl;
    cout << "5. nodosADistanciaK(origen, k) - Nodos a K saltos" << endl;
    cout << "6. todosLosCaminos(origen, destino) - Enumerar todos los caminos" << endl;
    
    cout << "\n🔍 ANÁLISIS DE ESTRUCTURA:" << endl;
    cout << "7. contarComponentes() - Grupos separados" << endl;
    cout << "8. hayConexion(origen, destino) - Verificar si hay camino" << endl;
    cout << "9. esBipartito() - Verificar si se puede colorear con 2 colores" << endl;
    cout << "10. arbolExpansionDFS(inicio) - Generar árbol de expansión" << endl;
    
    cout << "\n🔄 CICLOS Y ORDENAMIENTO:" << endl;
    cout << "11. tieneCiclo() - Detectar ciclos" << endl;
    cout << "12. ordenamientoTopologico() - Orden de dependencias (grafos dirigidos)" << endl;
    
    cout << "\n🗺️ APLICACIONES EN GRIDS:" << endl;
    cout << "13. bfsLaberinto() - Camino más corto en matriz" << endl;
    cout << "14. contarIslas() - Contar componentes en matriz binaria" << endl;
    
    cout << "\n--- EJEMPLO DE USO ---" << endl;
    
    // Ejemplo: Grafo no dirigido
    cout << "\n/* Crear grafo no dirigido con 5 nodos */" << endl;
    cout << "Grafo g(5, false);" << endl;
    cout << "g.agregarArista(0, 1);" << endl;
    cout << "g.agregarArista(0, 2);" << endl;
    cout << "g.agregarArista(1, 3);" << endl;
    cout << "g.agregarArista(2, 4);" << endl;
    cout << "\ng.BFS(0);              // Recorrer desde 0" << endl;
    cout << "g.caminoMasCorto(0, 4); // Camino de 0 a 4" << endl;
    cout << "g.contarComponentes();  // Contar grupos" << endl;
    
    // Ejemplo: Grafo dirigido
    cout << "\n/* Crear grafo dirigido con 4 nodos */" << endl;
    cout << "Grafo gDirigido(4, true);" << endl;
    cout << "gDirigido.agregarArista(0, 1);" << endl;
    cout << "gDirigido.agregarArista(1, 2);" << endl;
    cout << "gDirigido.agregarArista(2, 3);" << endl;
    cout << "\ngDirigido.ordenamientoTopologico(); // Orden de tareas" << endl;
    cout << "gDirigido.tieneCiclo();             // Verificar ciclos" << endl;
    
    cout << "\n--- COMPLEJIDADES ---" << endl;
    cout << "BFS/DFS con Lista de Adyacencia: O(V + E)" << endl;
    cout << "  donde V = vértices, E = aristas" << endl;
    cout << "\nEspacio: O(V) para arreglos auxiliares" << endl;
    
    cout << "\n--- GESTIÓN DE MEMORIA ---" << endl;
    cout << "⚠️ IMPORTANTE: Siempre liberar memoria dinámica" << endl;
    cout << "• Arreglos: delete[] nombreArray;" << endl;
    cout << "• Matrices: for + delete[] + delete[]" << endl;
    cout << "• Listas: while + delete cada nodo" << endl;
    
    cout << "\n--- CUÁNDO USAR QUÉ ---" << endl;
    cout << "✓ BFS: Caminos más cortos, distancias, niveles" << endl;
    cout << "✓ DFS: Ciclos, topológico, backtracking, árboles" << endl;
    cout << "✓ BFS en grid: Laberintos, propagación" << endl;
    cout << "✓ DFS en grid: Islas, flood fill" << endl;
    
    cout << "\n--- VENTAJAS LISTA DE ADYACENCIA ---" << endl;
    cout << "✓ Eficiente en memoria para grafos dispersos" << endl;
    cout << "✓ Rápido para recorrer vecinos" << endl;
    cout << "✓ Fácil de agregar/quitar aristas" << endl;
    cout << "✓ Complejidad óptima O(V + E)" << endl;
    
    return 0;
}
