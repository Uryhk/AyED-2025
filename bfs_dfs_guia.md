# Guía Completa: BFS y DFS
## Búsqueda en Grafos - Teoría y Aplicaciones Prácticas

---

## 📚 Índice
1. [Conceptos Fundamentales](#conceptos)
2. [BFS - Breadth First Search](#bfs)
3. [DFS - Depth First Search](#dfs)
4. [Comparación BFS vs DFS](#comparacion)
5. [Aplicaciones Prácticas](#aplicaciones)
6. [Problemas Resueltos](#problemas)

---

## 🎯 Conceptos Fundamentales {#conceptos}

### ¿Qué es recorrer un grafo?
Visitar todos los nodos de un grafo de forma sistemática, explorando sus conexiones (aristas).

### Dos estrategias principales:
- **BFS (Breadth-First Search)**: Explora por **niveles** (primero vecinos cercanos)
- **DFS (Depth-First Search)**: Explora en **profundidad** (hasta el fondo antes de retroceder)

### Representación de grafos:

#### Matriz de adyacencia:
```cpp
int adj[MAXN][MAXN];
adj[i][j] = 1;  // hay arista entre i y j
adj[i][j] = 0;  // no hay arista
```

#### Lista de adyacencia:
```cpp
vector<int> adj[MAXN];
adj[i].push_back(j);  // agregar vecino j al nodo i
```

---

## 🌊 BFS - Breadth First Search {#bfs}

### Concepto
Explora el grafo **por niveles**, como ondas en el agua:
- **Nivel 0**: Nodo inicial
- **Nivel 1**: Vecinos directos
- **Nivel 2**: Vecinos de vecinos
- ...

### Estructura de datos clave: **Cola (Queue)**
**FIFO** - First In, First Out

### Algoritmo básico:
```
1. Encolar nodo inicial y marcarlo como visitado
2. Mientras la cola no esté vacía:
   a. Desencolar un nodo
   b. Procesar ese nodo
   c. Para cada vecino NO visitado:
      - Marcarlo como visitado
      - Encolarlo
```

### Implementación completa:

```cpp
struct BFSResult {
    int orden[MAXN];      // orden de descubrimiento
    int orden_len;
    int distancia[MAXN];  // distancia mínima desde origen
    int parent[MAXN];     // árbol BFS
    int alcanzados;       // nodos alcanzados
    int max_saltos;       // máxima distancia
};

BFSResult bfs(Grafo& g, int s) {
    BFSResult result;
    bool visitado[MAXN];
    
    // Inicialización
    result.orden_len = 0;
    result.alcanzados = 0;
    result.max_saltos = 0;
    
    for(int i = 0; i < g.n; i++) {
        visitado[i] = false;
        result.distancia[i] = -1;
        result.parent[i] = -1;
    }
    
    // Procesar nodo inicial
    queue<int> cola;
    visitado[s] = true;
    result.distancia[s] = 0;
    result.parent[s] = -1;
    cola.push(s);
    result.orden[result.orden_len++] = s;
    result.alcanzados++;
    
    // BFS
    while(!cola.empty()) {
        int actual = cola.front();
        cola.pop();
        
        // Explorar vecinos
        for(int vecino = 0; vecino < g.n; vecino++) {
            if(g.adj[actual][vecino] == 1 && !visitado[vecino]) {
                visitado[vecino] = true;
                result.distancia[vecino] = result.distancia[actual] + 1;
                result.parent[vecino] = actual;
                cola.push(vecino);
                result.orden[result.orden_len++] = vecino;
                result.alcanzados++;
                
                if(result.distancia[vecino] > result.max_saltos) {
                    result.max_saltos = result.distancia[vecino];
                }
            }
        }
    }
    
    return result;
}
```

### Ejemplo visual:
```
Grafo:     0 --- 1 --- 4
           |     |
           2 --- 3

BFS desde 0:
Nivel 0: [0]
Nivel 1: [1, 2]      (vecinos de 0)
Nivel 2: [3, 4]      (vecinos de 1 y 2)

Orden de visita: 0 → 1 → 2 → 3 → 4
Distancias: [0, 1, 1, 2, 2]
```

### Propiedades clave de BFS:
✅ Encuentra el **camino más corto** (en grafos NO ponderados)  
✅ Explora nivel por nivel  
✅ Complejidad: **O(V + E)** donde V=nodos, E=aristas  
✅ Usa memoria proporcional al ancho del grafo  

---

## 🌲 DFS - Depth First Search {#dfs}

### Concepto
Explora el grafo **en profundidad**: va lo más lejos posible antes de retroceder.

Como explorar un laberinto: seguir un camino hasta el fondo, luego volver y probar otro.

### Estructura de datos clave: **Pila (Stack)**
**LIFO** - Last In, First Out (o recursión implícita)

### Algoritmo básico:
```
1. Marcar nodo actual como visitado
2. Para cada vecino NO visitado:
   a. Hacer DFS recursivamente en ese vecino
```

### Implementación recursiva:

```cpp
struct DFSResult {
    int orden[MAXN];       // orden de descubrimiento
    int orden_len;
    int tiempo_entrada[MAXN];  // timestamp de entrada
    int tiempo_salida[MAXN];   // timestamp de salida
    int parent[MAXN];
    int alcanzados;
    int profundidad_max;
};

int tiempo_global;

void dfs_recursivo(Grafo& g, int nodo, bool visitado[], DFSResult& result, int profundidad) {
    // Marcar como visitado
    visitado[nodo] = true;
    result.orden[result.orden_len++] = nodo;
    result.alcanzados++;
    result.tiempo_entrada[nodo] = tiempo_global++;
    
    if(profundidad > result.profundidad_max) {
        result.profundidad_max = profundidad;
    }
    
    // Explorar vecinos
    for(int vecino = 0; vecino < g.n; vecino++) {
        if(g.adj[nodo][vecino] == 1 && !visitado[vecino]) {
            result.parent[vecino] = nodo;
            dfs_recursivo(g, vecino, visitado, result, profundidad + 1);
        }
    }
    
    result.tiempo_salida[nodo] = tiempo_global++;
}

DFSResult dfs(Grafo& g, int s) {
    DFSResult result;
    bool visitado[MAXN] = {false};
    
    result.orden_len = 0;
    result.alcanzados = 0;
    result.profundidad_max = 0;
    tiempo_global = 0;
    
    for(int i = 0; i < g.n; i++) {
        result.parent[i] = -1;
        result.tiempo_entrada[i] = -1;
        result.tiempo_salida[i] = -1;
    }
    
    result.parent[s] = -1;
    dfs_recursivo(g, s, visitado, result, 0);
    
    return result;
}
```

### Implementación iterativa (con pila):

```cpp
DFSResult dfs_iterativo(Grafo& g, int s) {
    DFSResult result;
    bool visitado[MAXN] = {false};
    stack<int> pila;
    
    result.orden_len = 0;
    result.alcanzados = 0;
    
    for(int i = 0; i < g.n; i++) {
        result.parent[i] = -1;
    }
    
    pila.push(s);
    visitado[s] = true;
    result.parent[s] = -1;
    
    while(!pila.empty()) {
        int actual = pila.top();
        pila.pop();
        
        result.orden[result.orden_len++] = actual;
        result.alcanzados++;
        
        // Explorar vecinos (en orden inverso para simular recursión)
        for(int vecino = g.n - 1; vecino >= 0; vecino--) {
            if(g.adj[actual][vecino] == 1 && !visitado[vecino]) {
                visitado[vecino] = true;
                result.parent[vecino] = actual;
                pila.push(vecino);
            }
        }
    }
    
    return result;
}
```

### Ejemplo visual:
```
Grafo:     0 --- 1 --- 4
           |     |
           2 --- 3

DFS desde 0 (recursivo):
0 → 1 (primer vecino de 0)
  → 3 (primer vecino de 1)
    → 2 (primer vecino de 3)
      → vuelve a 3
    → vuelve a 1
  → 4 (siguiente vecino de 1)
    → vuelve a 1
  → vuelve a 0
→ termina

Orden de visita: 0 → 1 → 3 → 2 → 4
```

### Propiedades clave de DFS:
✅ Útil para detectar **ciclos**  
✅ Encuentra **componentes conexas**  
✅ Genera un **bosque de expansión**  
✅ Complejidad: **O(V + E)**  
✅ Usa memoria proporcional a la profundidad (recursión)  

---

## ⚖️ Comparación BFS vs DFS {#comparacion}

| Característica | BFS | DFS |
|---------------|-----|-----|
| **Estructura** | Cola (Queue) | Pila (Stack) o Recursión |
| **Estrategia** | Por niveles | En profundidad |
| **Orden FIFO/LIFO** | FIFO | LIFO |
| **Camino más corto** | ✅ SÍ (grafos NO ponderados) | ❌ NO |
| **Memoria** | Proporcional al ancho | Proporcional a la profundidad |
| **Detección de ciclos** | Posible | ✅ Más natural |
| **Complejidad** | O(V + E) | O(V + E) |
| **Uso típico** | Distancias mínimas | Topología, ciclos, backtracking |

### ¿Cuándo usar cada uno?

**Usa BFS cuando:**
- Necesites el camino más corto
- El grafo es ancho pero poco profundo
- Quieras explorar por "grados de separación"

**Usa DFS cuando:**
- Necesites detectar ciclos
- Hagas backtracking
- El grafo es profundo pero angosto
- Quieras ordenamiento topológico

---

## 🚀 Aplicaciones Prácticas {#aplicaciones}

### 1️⃣ **Camino más corto (BFS)**

**Problema:** Encontrar el camino más corto entre dos nodos.

```cpp
vector<int> encontrarCamino(Grafo& g, int origen, int destino) {
    BFSResult res = bfs(g, origen);
    vector<int> camino;
    
    if(res.distancia[destino] == -1) {
        cout << "No hay camino" << endl;
        return camino;
    }
    
    // Reconstruir camino usando parent[]
    int nodo = destino;
    while(nodo != -1) {
        camino.push_back(nodo);
        nodo = res.parent[nodo];
    }
    
    reverse(camino.begin(), camino.end());
    
    cout << "Distancia: " << res.distancia[destino] << " saltos" << endl;
    return camino;
}
```

**Aplicaciones reales:**
- 🌐 Redes sociales (grados de separación)
- 🗺️ GPS básico (calles sin pesos)
- 🎮 Videojuegos (movimientos mínimos)

---

### 2️⃣ **Componentes conexas (BFS o DFS)**

**Problema:** ¿Cuántos grupos separados hay en el grafo?

```cpp
int contarComponentes(Grafo& g) {
    bool visitado[MAXN] = {false};
    int componentes = 0;
    
    for(int i = 0; i < g.n; i++) {
        if(!visitado[i]) {
            componentes++;
            
            // BFS desde i
            queue<int> cola;
            cola.push(i);
            visitado[i] = true;
            
            while(!cola.empty()) {
                int actual = cola.front();
                cola.pop();
                
                for(int vecino = 0; vecino < g.n; vecino++) {
                    if(g.adj[actual][vecino] == 1 && !visitado[vecino]) {
                        visitado[vecino] = true;
                        cola.push(vecino);
                    }
                }
            }
        }
    }
    
    return componentes;
}
```

**Aplicaciones reales:**
- 👥 Grupos de amigos en redes sociales
- 🔌 Sectores eléctricos independientes
- 🌊 Islas en un mapa

---

### 3️⃣ **Detectar ciclos (DFS)**

**Problema:** ¿El grafo tiene ciclos?

```cpp
bool tieneCiclo_util(Grafo& g, int nodo, bool visitado[], bool enPila[]) {
    visitado[nodo] = true;
    enPila[nodo] = true;
    
    for(int vecino = 0; vecino < g.n; vecino++) {
        if(g.adj[nodo][vecino] == 1) {
            if(!visitado[vecino]) {
                if(tieneCiclo_util(g, vecino, visitado, enPila)) {
                    return true;
                }
            } else if(enPila[vecino]) {
                // Encontramos un nodo en la pila actual = CICLO
                return true;
            }
        }
    }
    
    enPila[nodo] = false;
    return false;
}

bool tieneCiclo(Grafo& g) {
    bool visitado[MAXN] = {false};
    bool enPila[MAXN] = {false};
    
    for(int i = 0; i < g.n; i++) {
        if(!visitado[i]) {
            if(tieneCiclo_util(g, i, visitado, enPila)) {
                return true;
            }
        }
    }
    return false;
}
```

**Aplicaciones reales:**
- 📦 Dependencias circulares en software
- 💰 Detección de arbitraje en trading
- 🔄 Deadlocks en sistemas operativos

---

### 4️⃣ **Laberinto / Grid (BFS)**

**Problema:** Salir de un laberinto en mínimos pasos.

```cpp
int resolverLaberinto(int maze[MAXN][MAXN], int filas, int cols, 
                      int startX, int startY, int endX, int endY) {
    int dx[] = {0, 0, 1, -1};  // derecha, izquierda, abajo, arriba
    int dy[] = {1, -1, 0, 0};
    
    int distancia[MAXN][MAXN];
    for(int i = 0; i < filas; i++)
        for(int j = 0; j < cols; j++)
            distancia[i][j] = -1;
    
    queue<pair<int,int>> cola;
    cola.push({startX, startY});
    distancia[startX][startY] = 0;
    
    while(!cola.empty()) {
        auto [x, y] = cola.front();
        cola.pop();
        
        if(x == endX && y == endY) {
            return distancia[x][y];
        }
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 0 && nx < filas && ny >= 0 && ny < cols && 
               maze[nx][ny] == 0 && distancia[nx][ny] == -1) {
                distancia[nx][ny] = distancia[x][y] + 1;
                cola.push({nx, ny});
            }
        }
    }
    
    return -1;  // No hay camino
}
```

**Aplicaciones reales:**
- 🎮 Pathfinding en videojuegos
- 🤖 Navegación de robots
- 🧩 Resolución de puzzles

---

### 5️⃣ **Grafo bipartito (BFS con coloreo)**

**Problema:** ¿Se puede dividir el grafo en dos grupos sin conexiones internas?

```cpp
bool esBipartito(Grafo& g) {
    int color[MAXN];
    for(int i = 0; i < g.n; i++) color[i] = -1;
    
    for(int inicio = 0; inicio < g.n; inicio++) {
        if(color[inicio] == -1) {
            queue<int> cola;
            cola.push(inicio);
            color[inicio] = 0;
            
            while(!cola.empty()) {
                int actual = cola.front();
                cola.pop();
                
                for(int vecino = 0; vecino < g.n; vecino++) {
                    if(g.adj[actual][vecino] == 1) {
                        if(color[vecino] == -1) {
                            color[vecino] = 1 - color[actual];
                            cola.push(vecino);
                        } else if(color[vecino] == color[actual]) {
                            return false;  // Mismo color = NO bipartito
                        }
                    }
                }
            }
        }
    }
    return true;
}
```

**Aplicaciones reales:**
- 💼 Asignación de tareas (trabajadores-tareas)
- 📚 Horarios sin conflictos
- 🎨 Coloreo de mapas con 2 colores

---

### 6️⃣ **Ordenamiento topológico (DFS)**

**Problema:** Ordenar tareas respetando dependencias.

```cpp
void dfs_topologico(Grafo& g, int nodo, bool visitado[], stack<int>& pila) {
    visitado[nodo] = true;
    
    for(int vecino = 0; vecino < g.n; vecino++) {
        if(g.adj[nodo][vecino] == 1 && !visitado[vecino]) {
            dfs_topologico(g, vecino, visitado, pila);
        }
    }
    
    pila.push(nodo);  // Agregar después de procesar vecinos
}

vector<int> ordenTopologico(Grafo& g) {
    bool visitado[MAXN] = {false};
    stack<int> pila;
    
    for(int i = 0; i < g.n; i++) {
        if(!visitado[i]) {
            dfs_topologico(g, i, visitado, pila);
        }
    }
    
    vector<int> orden;
    while(!pila.empty()) {
        orden.push_back(pila.top());
        pila.pop();
    }
    
    return orden;
}
```

**Aplicaciones reales:**
- 📦 Compilación de proyectos (dependencias)
- 📋 Planificación de tareas
- 🎓 Orden de materias universitarias

---

## 🎯 Problemas Resueltos Paso a Paso {#problemas}

### **Problema 1: Grados de Kevin Bacon**

**Enunciado:** En una red de actores, encontrar la distancia mínima entre dos actores (películas en común).

```cpp
// Grafo: nodos = actores, aristas = actuaron juntos
int gradosSeparacion(Grafo& redActores, int actor1, int actor2) {
    BFSResult res = bfs(redActores, actor1);
    
    if(res.distancia[actor2] == -1) {
        cout << "No están conectados" << endl;
        return -1;
    }
    
    cout << "Grados de separación: " << res.distancia[actor2] << endl;
    
    // Mostrar camino
    vector<int> camino;
    int nodo = actor2;
    while(nodo != -1) {
        camino.push_back(nodo);
        nodo = res.parent[nodo];
    }
    reverse(camino.begin(), camino.end());
    
    for(int i = 0; i < camino.size(); i++) {
        cout << "Actor " << camino[i];
        if(i < camino.size() - 1) cout << " -> ";
    }
    cout << endl;
    
    return res.distancia[actor2];
}
```

---

### **Problema 2: Contar islas**

**Enunciado:** Dada una matriz de 0s (agua) y 1s (tierra), contar cuántas islas hay.

```cpp
int contarIslas(int grid[MAXN][MAXN], int filas, int cols) {
    bool visitado[MAXN][MAXN] = {false};
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    int islas = 0;
    
    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < cols; j++) {
            if(grid[i][j] == 1 && !visitado[i][j]) {
                islas++;
                
                // BFS desde esta celda
                queue<pair<int,int>> cola;
                cola.push({i, j});
                visitado[i][j] = true;
                
                while(!cola.empty()) {
                    auto [x, y] = cola.front();
                    cola.pop();
                    
                    for(int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        
                        if(nx >= 0 && nx < filas && ny >= 0 && ny < cols &&
                           grid[nx][ny] == 1 && !visitado[nx][ny]) {
                            visitado[nx][ny] = true;
                            cola.push({nx, ny});
                        }
                    }
                }
            }
        }
    }
    
    return islas;
}
```

---

### **Problema 3: Escalera de palabras**

**Enunciado:** Transformar una palabra en otra cambiando una letra a la vez (cada paso debe ser una palabra válida).

```cpp
int escalerasPalabras(string inicio, string fin, set<string>& diccionario) {
    if(inicio.length() != fin.length()) return -1;
    
    queue<pair<string, int>> cola;
    set<string> visitado;
    
    cola.push({inicio, 0});
    visitado.insert(inicio);
    
    while(!cola.empty()) {
        auto [palabra, pasos] = cola.front();
        cola.pop();
        
        if(palabra == fin) return pasos;
        
        // Probar cambiar cada letra
        for(int i = 0; i < palabra.length(); i++) {
            string temp = palabra;
            for(char c = 'a'; c <= 'z'; c++) {
                temp[i] = c;
                
                if(diccionario.count(temp) && !visitado.count(temp)) {
                    visitado.insert(temp);
                    cola.push({temp, pasos + 1});
                }
            }
        }
    }
    
    return -1;  // No hay camino
}

// Ejemplo: "gato" -> "pato" -> "palo" -> "pelo"
```

---

## 📝 Resumen Final

### Cuándo usar BFS:
✅ Camino más corto (sin pesos)  
✅ Nivel/distancia de nodos  
✅ Grados de separación  
✅ Laberintos y grids  

### Cuándo usar DFS:
✅ Detectar ciclos  
✅ Ordenamiento topológico  
✅ Componentes fuertemente conexas  
✅ Backtracking  

### Complejidad:
Ambos: **O(V + E)** donde V = nodos, E = aristas

### Estructuras de datos:
- **BFS**: Cola (FIFO)
- **DFS**: Pila o Recursión (LIFO)

---

## 💡 Consejos Finales

1. **Siempre marca visitados** antes de agregar a la cola/pila
2. **Inicializa todo en -1** para detectar nodos no alcanzados
3. **BFS garantiza camino mínimo** solo en grafos NO ponderados
4. **DFS es más natural con recursión**, pero cuidado con el stack overflow
5. **Practica modelando problemas como grafos**: ¿Qué son los nodos? ¿Qué son las aristas?

---

¡Ahora tenés todas las herramientas para resolver problemas con BFS y DFS! 🚀
