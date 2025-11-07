/* ⚠️ GUÍA DE APLICACIONES BFS Y DFS
   Esta guía se enfoca en aplicaciones prácticas de BFS y DFS
   usando MATRIZ DE ADYACENCIA con ARRAYS ESTÁTICOS
*/

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

const int MAX_V = 100; // Máximo número de vértices

// ============================================
// GRAFO - MATRIZ DE ADYACENCIA (ARRAY ESTÁTICO)
// ============================================
class Grafo {
private:
    int V; // Número de vértices
    int adj[MAX_V][MAX_V]; // Matriz de adyacencia estática
    bool dirigido; // true = dirigido, false = no dirigido
    
public:
    Grafo(int v, bool esDirigido = false) : V(v), dirigido(esDirigido) {
        // Inicializar matriz en 0
        for (int i = 0; i < MAX_V; i++) {
            for (int j = 0; j < MAX_V; j++) {
                adj[i][j] = 0;
            }
        }
    }
    
    // Agregar arista
    void agregarArista(int u, int v) {
        // IMPLEMENTAR:
        // 1. Marcar arista de u a v:
        //    adj[u][v] = 1;
        // 2. Si NO es dirigido, marcar también de v a u:
        //    if (!dirigido) {
        //        adj[v][u] = 1;
        //    }
    }
    
    // ============================================
    // APLICACIÓN 1: BFS BÁSICO - Recorrido por niveles
    // ============================================
    void BFS(int inicio) {
        // IMPLEMENTAR:
        // 1. Crear arreglo: bool visitado[MAX_V] = {false};
        // 2. Crear cola: queue<int> cola;
        // 3. Marcar inicio como visitado y agregarlo a la cola
        //    visitado[inicio] = true;
        //    cola.push(inicio);
        // 4. Mientras la cola no esté vacía:
        //    - int actual = cola.front(); cola.pop();
        //    - Imprimir actual
        //    - Recorrer todos los vértices j de 0 a V-1:
        //      * Si adj[actual][j] == 1 && !visitado[j]:
        //        - visitado[j] = true
        //        - cola.push(j)
        
        cout << "\nBFS desde " << inicio << ": ";
        // Tu código aquí
        cout << endl;
    }
    
    // ============================================
    // APLICACIÓN 2: DFS RECURSIVO - Recorrido en profundidad
    // ============================================
    void DFSRecursivoUtil(int v, bool visitado[]) {
        // IMPLEMENTAR:
        // 1. Marcar v como visitado: visitado[v] = true;
        // 2. Imprimir v: cout << v << " ";
        // 3. Recorrer todos los vértices j de 0 a V-1:
        //    - Si adj[v][j] == 1 && !visitado[j]:
        //      * DFSRecursivoUtil(j, visitado);
    }
    
    void DFSRecursivo(int inicio) {
        // IMPLEMENTAR:
        // 1. Crear arreglo: bool visitado[MAX_V] = {false};
        // 2. cout << "\nDFS Recursivo desde " << inicio << ": ";
        // 3. Llamar a DFSRecursivoUtil(inicio, visitado);
        // 4. cout << endl;
    }
    
    // ============================================
    // APLICACIÓN 3: DFS ITERATIVO - Con pila explícita
    // ============================================
    void DFSIterativo(int inicio) {
        // IMPLEMENTAR:
        // 1. Crear arreglo: bool visitado[MAX_V] = {false};
        // 2. Crear pila: stack<int> pila;
        // 3. pila.push(inicio);
        // 4. Mientras la pila no esté vacía:
        //    - int actual = pila.top(); pila.pop();
        //    - Si no está visitado:
        //      * Marcarlo como visitado
        //      * Imprimirlo
        //      * Recorrer j de 0 a V-1:
        //        - Si adj[actual][j] == 1:
        //          * pila.push(j)
        
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
        //    bool visitado[MAX_V] = {false};
        //    int distancia[MAX_V];
        //    int padre[MAX_V];
        //    for (int i = 0; i < V; i++) {
        //        distancia[i] = -1;
        //        padre[i] = -1;
        //    }
        // 2. BFS desde origen:
        //    - distancia[origen] = 0, padre[origen] = -1
        //    - Para cada vecino j donde adj[actual][j] == 1:
        //      * distancia[j] = distancia[actual] + 1
        //      * padre[j] = actual
        // 3. Si distancia[destino] == -1:
        //    - cout << "No hay camino"
        //    - return
        // 4. Reconstruir camino:
        //    - stack<int> camino;
        //    - int nodo = destino;
        //    - while (nodo != -1) {
        //        camino.push(nodo);
        //        nodo = padre[nodo];
        //    }
        //    - Imprimir camino desde la pila
        // 5. Imprimir distancia[destino]
        
        cout << "\nCamino más corto de " << origen << " a " << destino << ":" << endl;
        // Tu código aquí
    }
    
    // ============================================
    // APLICACIÓN 5: COMPONENTES CONEXAS
    // ============================================
    int contarComponentes() {
        // IMPLEMENTAR:
        // 1. Crear arreglo: bool visitado[MAX_V] = {false};
        // 2. int componentes = 0;
        // 3. Para cada nodo i de 0 a V-1:
        //    - Si !visitado[i]:
        //      * componentes++;
        //      * Hacer BFS desde i:
        //        - queue<int> cola;
        //        - cola.push(i);
        //        - visitado[i] = true;
        //        - while (!cola.empty()) {
        //            int actual = cola.front(); cola.pop();
        //            for (int j = 0; j < V; j++) {
        //                if (adj[actual][j] == 1 && !visitado[j]) {
        //                    visitado[j] = true;
        //                    cola.push(j);
        //                }
        //            }
        //        }
        // 4. return componentes;
        
        // Tu código aquí
        return 0;
    }
    
    // ============================================
    // APLICACIÓN 6: NODOS A DISTANCIA K
    // ============================================
    void nodosADistanciaK(int origen, int k) {
        // IMPLEMENTAR:
        // 1. Crear arreglos:
        //    bool visitado[MAX_V] = {false};
        //    int distancia[MAX_V];
        //    for (int i = 0; i < V; i++) distancia[i] = -1;
        // 2. BFS desde origen calculando distancias
        //    - distancia[origen] = 0;
        //    - Para cada vecino j donde adj[actual][j] == 1:
        //      * distancia[j] = distancia[actual] + 1
        // 3. Recorrer distancia[] e imprimir nodos donde distancia[i] == k
        
        cout << "\nNodos a distancia " << k << " desde " << origen << ": ";
        // Tu código aquí
        cout << endl;
    }
    
    // ============================================
    // APLICACIÓN 7: VERIFICAR SI ES BIPARTITO
    // ============================================
    bool esBipartito() {
        // IMPLEMENTAR:
        // 1. Crear arreglo: int color[MAX_V];
        //    for (int i = 0; i < V; i++) color[i] = -1;
        // 2. Para cada componente (nodos no coloreados):
        //    for (int inicio = 0; inicio < V; inicio++) {
        //        if (color[inicio] == -1) {
        //            // BFS asignando colores 0 y 1
        //            queue<int> cola;
        //            cola.push(inicio);
        //            color[inicio] = 0;
        //            while (!cola.empty()) {
        //                int actual = cola.front(); cola.pop();
        //                for (int j = 0; j < V; j++) {
        //                    if (adj[actual][j] == 1) {
        //                        if (color[j] == -1) {
        //                            color[j] = 1 - color[actual];
        //                            cola.push(j);
        //                        } else if (color[j] == color[actual]) {
        //                            return false;
        //                        }
        //                    }
        //                }
        //            }
        //        }
        //    }
        // 3. return true
        
        // Tu código aquí
        return false;
    }
    
    // ============================================
    // APLICACIÓN 8: DETECTAR CICLOS (Grafo NO dirigido)
    // ============================================
    bool tieneCicloNoDirigidoUtil(int v, bool visitado[], int padre) {
        // IMPLEMENTAR:
        // 1. visitado[v] = true;
        // 2. Recorrer todos los vértices j de 0 a V-1:
        //    - Si adj[v][j] == 1:
        //      * Si !visitado[j]:
        //        - if (tieneCicloNoDirigidoUtil(j, visitado, v)) return true
        //      * Si visitado[j] && j != padre:
        //        - return true (hay ciclo)
        // 3. return false
        
        // Tu código aquí
        return false;
    }
    
    bool tieneCiclo() {
        // IMPLEMENTAR:
        // 1. bool visitado[MAX_V] = {false};
        // 2. Si es dirigido: usar método diferente (con recStack)
        // 3. Si NO es dirigido:
        //    - Para cada nodo i no visitado:
        //      * if (tieneCicloNoDirigidoUtil(i, visitado, -1)) return true
        // 4. return false
        
        // Tu código aquí
        return false;
    }
    
    // ============================================
    // APLICACIÓN 9: DETECTAR CICLOS (Grafo DIRIGIDO)
    // ============================================
    bool tieneCicloDirigidoUtil(int v, bool visitado[], bool recStack[]) {
        // IMPLEMENTAR:
        // 1. visitado[v] = true;
        //    recStack[v] = true;
        // 2. Recorrer todos los vértices j de 0 a V-1:
        //    - Si adj[v][j] == 1:
        //      * Si !visitado[j]:
        //        - if (tieneCicloDirigidoUtil(j, visitado, recStack)) return true
        //      * Si recStack[j]:
        //        - return true (hay ciclo)
        // 3. recStack[v] = false;
        // 4. return false
        
        // Tu código aquí
        return false;
    }
    
    // ============================================
    // APLICACIÓN 10: ORDENAMIENTO TOPOLÓGICO
    // ============================================
    void topoSortUtil(int v, bool visitado[], stack<int>& pila) {
        // IMPLEMENTAR:
        // 1. visitado[v] = true;
        // 2. Recorrer todos los vértices j de 0 a V-1:
        //    - Si adj[v][j] == 1 && !visitado[j]:
        //      * topoSortUtil(j, visitado, pila);
        // 3. pila.push(v); // Agregar DESPUÉS de procesar vecinos
    }
    
    void ordenamientoTopologico() {
        // IMPLEMENTAR:
        // 1. Verificar que sea dirigido y sin ciclos
        // 2. bool visitado[MAX_V] = {false};
        //    stack<int> pila;
        // 3. Para cada nodo i no visitado:
        //    - if (!visitado[i]) topoSortUtil(i, visitado, pila);
        // 4. Imprimir contenido de la pila (es el orden topológico)
        //    while (!pila.empty()) {
        //        cout << pila.top() << " ";
        //        pila.pop();
        //    }
        
        cout << "\nOrdenamiento Topológico: ";
        // Tu código aquí
        cout << endl;
    }
    
    // ============================================
    // APLICACIÓN 11: VERIFICAR CONECTIVIDAD
    // ============================================
    bool hayConexion(int origen, int destino) {
        // IMPLEMENTAR:
        // 1. bool visitado[MAX_V] = {false};
        // 2. BFS desde origen:
        //    queue<int> cola;
        //    cola.push(origen);
        //    visitado[origen] = true;
        //    while (!cola.empty()) {
        //        int actual = cola.front(); cola.pop();
        //        if (actual == destino) return true;
        //        for (int j = 0; j < V; j++) {
        //            if (adj[actual][j] == 1 && !visitado[j]) {
        //                visitado[j] = true;
        //                cola.push(j);
        //            }
        //        }
        //    }
        // 3. return false
        
        // Tu código aquí
        return false;
    }
    
    // ============================================
    // APLICACIÓN 12: ÁRBOL DE EXPANSIÓN DFS
    // ============================================
    void arbolExpansionDFSUtil(int v, bool visitado[], int padre[]) {
        // IMPLEMENTAR:
        // 1. visitado[v] = true;
        // 2. for (int j = 0; j < V; j++) {
        //        if (adj[v][j] == 1 && !visitado[j]) {
        //            padre[j] = v;
        //            arbolExpansionDFSUtil(j, visitado, padre);
        //        }
        //    }
    }
    
    void arbolExpansionDFS(int inicio) {
        // IMPLEMENTAR:
        // 1. bool visitado[MAX_V] = {false};
        //    int padre[MAX_V];
        //    for (int i = 0; i < V; i++) padre[i] = -1;
        // 2. arbolExpansionDFSUtil(inicio, visitado, padre);
        // 3. cout << "Aristas del árbol:" << endl;
        //    for (int i = 0; i < V; i++) {
        //        if (padre[i] != -1) {
        //            cout << padre[i] << " -> " << i << endl;
        //        }
        //    }
        
        cout << "\nÁrbol de expansión DFS desde " << inicio << ":" << endl;
        // Tu código aquí
    }
    
    // ============================================
    // APLICACIÓN 13: IMPRIMIR TODOS LOS CAMINOS
    // ============================================
    void todosLosCaminosUtil(int actual, int destino, bool visitado[], 
                             int camino[], int &indice) {
        // IMPLEMENTAR:
        // 1. visitado[actual] = true;
        //    camino[indice++] = actual;
        // 2. Si actual == destino:
        //    - cout << "Camino: ";
        //    - for (int i = 0; i < indice; i++) cout << camino[i] << " ";
        //    - cout << endl;
        // 3. Si no:
        //    - for (int j = 0; j < V; j++) {
        //        if (adj[actual][j] == 1 && !visitado[j]) {
        //            todosLosCaminosUtil(j, destino, visitado, camino, indice);
        //        }
        //    }
        // 4. Backtrack:
        //    indice--;
        //    visitado[actual] = false;
    }
    
    void todosLosCaminos(int origen, int destino) {
        // IMPLEMENTAR:
        // 1. bool visitado[MAX_V] = {false};
        //    int camino[MAX_V];
        //    int indice = 0;
        // 2. cout << "\nTodos los caminos de " << origen << " a " << destino << ":\n";
        // 3. todosLosCaminosUtil(origen, destino, visitado, camino, indice);
        
        // Tu código aquí
    }
    
    // Imprimir grafo
    void imprimir() {
        cout << "\nGrafo (" << (dirigido ? "Dirigido" : "No Dirigido") 
             << ") - Matriz de Adyacencia:" << endl;
        cout << "   ";
        for (int i = 0; i < V; i++) {
            cout << i << " ";
        }
        cout << endl;
        for (int i = 0; i < V; i++) {
            cout << i << ": ";
            for (int j = 0; j < V; j++) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
};

// ============================================
// APLICACIONES ESPECIALES CON GRIDS/MATRICES
// ============================================

const int MAX_GRID = 100; // Tamaño máximo del grid

// ============================================
// APLICACIÓN 14: BFS EN LABERINTO/GRID
// ============================================
void bfsLaberinto(int laberinto[MAX_GRID][MAX_GRID], int filas, int cols, 
                  int inicioX, int inicioY, int finX, int finY) {
    // IMPLEMENTAR:
    // 1. Crear matrices:
    //    bool visitado[MAX_GRID][MAX_GRID] = {false};
    //    int distancia[MAX_GRID][MAX_GRID];
    //    for (int i = 0; i < filas; i++)
    //        for (int j = 0; j < cols; j++)
    //            distancia[i][j] = -1;
    // 2. queue<pair<int,int>> cola;
    //    cola.push({inicioX, inicioY});
    //    visitado[inicioX][inicioY] = true;
    //    distancia[inicioX][inicioY] = 0;
    // 3. Movimientos: int dx[] = {0, 0, 1, -1};
    //                 int dy[] = {1, -1, 0, 0};
    // 4. BFS:
    //    while (!cola.empty()) {
    //        pair<int,int> actual = cola.front(); cola.pop();
    //        int x = actual.first, y = actual.second;
    //        if (x == finX && y == finY) {
    //            cout << "Distancia: " << distancia[x][y] << endl;
    //            return;
    //        }
    //        for (int i = 0; i < 4; i++) {
    //            int nx = x + dx[i];
    //            int ny = y + dy[i];
    //            if (nx >= 0 && nx < filas && ny >= 0 && ny < cols &&
    //                laberinto[nx][ny] == 0 && !visitado[nx][ny]) {
    //                visitado[nx][ny] = true;
    //                distancia[nx][ny] = distancia[x][y] + 1;
    //                cola.push({nx, ny});
    //            }
    //        }
    //    }
    // 5. cout << "No hay camino" << endl;
    
    cout << "\nCamino más corto en laberinto:" << endl;
    // Tu código aquí
}

// ============================================
// APLICACIÓN 15: CONTAR ISLAS (DFS/BFS en matriz)
// ============================================
void dfsIsla(int grid[MAX_GRID][MAX_GRID], bool visitado[MAX_GRID][MAX_GRID], 
             int filas, int cols, int x, int y) {
    // IMPLEMENTAR:
    // 1. visitado[x][y] = true;
    // 2. Movimientos: int dx[] = {0, 0, 1, -1};
    //                 int dy[] = {1, -1, 0, 0};
    // 3. for (int i = 0; i < 4; i++) {
    //        int nx = x + dx[i];
    //        int ny = y + dy[i];
    //        if (nx >= 0 && nx < filas && ny >= 0 && ny < cols &&
    //            grid[nx][ny] == 1 && !visitado[nx][ny]) {
    //            dfsIsla(grid, visitado, filas, cols, nx, ny);
    //        }
    //    }
}

int contarIslas(int grid[MAX_GRID][MAX_GRID], int filas, int cols) {
    // IMPLEMENTAR:
    // 1. bool visitado[MAX_GRID][MAX_GRID] = {false};
    // 2. int islas = 0;
    // 3. for (int i = 0; i < filas; i++) {
    //        for (int j = 0; j < cols; j++) {
    //            if (grid[i][j] == 1 && !visitado[i][j]) {
    //                islas++;
    //                dfsIsla(grid, visitado, filas, cols, i, j);
    //            }
    //        }
    //    }
    // 4. return islas;
    
    // Tu código aquí
    return 0;
}

// ============================================
// MAIN - EJEMPLOS DE USO
// ============================================
int main() {
    cout << "=== GUÍA DE APLICACIONES BFS Y DFS ===" << endl;
    cout << "\n*** IMPLEMENTACIÓN CON MATRIZ DE ADYACENCIA ***" << endl;
    cout << "*** USANDO ARRAYS ESTÁTICOS (SIN PUNTEROS) ***" << endl;
    
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
    
    cout << "\n--- VENTAJAS DE ARRAYS ESTÁTICOS ---" << endl;
    cout << "✓ No hay que gestionar memoria (new/delete)" << endl;
    cout << "✓ Código más simple y seguro" << endl;
    cout << "✓ Acceso rápido: O(1)" << endl;
    cout << "✓ No hay riesgo de memory leaks" << endl;
    cout << "✗ Tamaño fijo: limitado a MAX_V nodos" << endl;
    cout << "✗ Desperdicio de memoria si el grafo es pequeño" << endl;
    
    cout << "\n--- COMPLEJIDADES ---" << endl;
    cout << "BFS/DFS con Matriz: O(V²)" << endl;
    cout << "Espacio: O(V²) para la matriz + O(V) para auxiliares" << endl;
    
    cout << "\n--- CUÁNDO USAR ARRAYS ESTÁTICOS ---" << endl;
    cout << "✓ Tamaño del grafo conocido y pequeño (V < 1000)" << endl;
    cout << "✓ Programación competitiva (rapidez de implementación)" << endl;
    cout << "✓ Código educativo (más fácil de entender)" << endl;
    cout << "✓ Sistemas embebidos (memoria stack)" << endl;
    
    return 0;
}
