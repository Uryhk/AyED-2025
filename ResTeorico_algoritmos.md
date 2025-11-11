# Resumen Teórico: Estructuras de Datos y Algoritmos en C++

## 📊 Tabla de Contenidos
1. [Algoritmos de Ordenamiento](#ordenamiento)
2. [Algoritmos de Búsqueda](#busqueda)
3. [Árboles](#arboles)
4. [Hash Table](#hashtable)
5. [Bitset y Set](#bitset-set)
6. [Grafos](#grafos)

---

## 🔢 1. Algoritmos de Ordenamiento {#ordenamiento}

### **Bubble Sort (Ordenamiento Burbuja)**

**Algoritmo:**
```
Para i desde 0 hasta n-1:
    Para j desde 0 hasta n-i-2:
        Si arr[j] > arr[j+1]:
            Intercambiar arr[j] y arr[j+1]
```

**Complejidad:**
- Mejor caso: O(n) - si ya está ordenado con optimización
- Caso promedio: O(n²)
- Peor caso: O(n²)
- Espacio: O(1)

**Características:**
- Estable (mantiene orden relativo de elementos iguales)
- In-place (no requiere memoria adicional)
- Simple pero ineficiente para arrays grandes

---

### **Selection Sort (Ordenamiento por Selección)**

**Algoritmo:**
```
Para i desde 0 hasta n-1:
    Encontrar el mínimo en arr[i...n-1]
    Intercambiar arr[i] con el mínimo
```

**Complejidad:**
- Todos los casos: O(n²)
- Espacio: O(1)

**Características:**
- **No estable** en implementación básica
- Hace menos intercambios que Bubble Sort (máximo n-1)
- Útil cuando el costo de escritura es alto

---

### **Insertion Sort (Ordenamiento por Inserción)**

**Algoritmo:**
```
Para i desde 1 hasta n-1:
    key = arr[i]
    j = i - 1
    Mientras j >= 0 y arr[j] > key:
        arr[j+1] = arr[j]
        j = j - 1
    arr[j+1] = key
```

**Complejidad:**
- Mejor caso: O(n) - array casi ordenado
- Caso promedio: O(n²)
- Peor caso: O(n²)
- Espacio: O(1)

**Características:**
- Estable
- Eficiente para arrays pequeños o casi ordenados
- Usado en Timsort (Python) para subarrays pequeños

---

### **Merge Sort (Ordenamiento por Mezcla)**

**Algoritmo:**
```
MergeSort(arr, inicio, fin):
    Si inicio < fin:
        medio = (inicio + fin) / 2
        MergeSort(arr, inicio, medio)
        MergeSort(arr, medio+1, fin)
        Merge(arr, inicio, medio, fin)
```

**Complejidad:**
- Todos los casos: O(n log n)
- Espacio: O(n)

**Características:**
- Estable
- Divide y conquista
- Predecible (siempre O(n log n))
- Requiere espacio adicional

---

### **Quick Sort (Ordenamiento Rápido)**

**Algoritmo:**
```
QuickSort(arr, bajo, alto):
    Si bajo < alto:
        pivote = Partition(arr, bajo, alto)
        QuickSort(arr, bajo, pivote-1)
        QuickSort(arr, pivote+1, alto)

Partition(arr, bajo, alto):
    pivote = arr[alto]
    i = bajo - 1
    Para j desde bajo hasta alto-1:
        Si arr[j] <= pivote:
            i++
            Intercambiar arr[i] con arr[j]
    Intercambiar arr[i+1] con arr[alto]
    Retornar i+1
```

**Complejidad:**
- Mejor caso: O(n log n)
- Caso promedio: O(n log n)
- Peor caso: O(n²) - array ya ordenado
- Espacio: O(log n) - recursión

**Características:**
- **No estable** en implementación básica
- In-place
- Muy eficiente en promedio
- Pivote aleatorio mejora rendimiento

---

### **Heap Sort (Ordenamiento por Montículo)**

**Algoritmo:**
```
HeapSort(arr):
    Construir max-heap
    Para i desde n-1 hasta 1:
        Intercambiar arr[0] con arr[i]
        Heapify(arr, 0, i)
```

**Complejidad:**
- Todos los casos: O(n log n)
- Espacio: O(1)

**Características:**
- **No estable**
- In-place
- No requiere recursión (puede implementarse iterativamente)
- Bueno cuando memoria es limitada

---

### **Tree Sort (Ordenamiento con Árbol)**

**Algoritmo:**
```
TreeSort(arr):
    Crear BST vacío
    Para cada elemento en arr:
        Insertar elemento en BST
    
    Realizar recorrido In-Order del BST
    Guardar elementos en arr en orden
```

**Complejidad:**
- Mejor caso: O(n log n) - árbol balanceado
- Caso promedio: O(n log n)
- Peor caso: O(n²) - árbol degenerado
- Espacio: O(n) - para el árbol

**Características:**
- Usa Árbol Binario de Búsqueda
- El recorrido In-Order produce salida ordenada
- Estable si se implementa correctamente
- Eficiente si el árbol está balanceado

**Ventajas:**
- Puede ser más eficiente que Quick Sort si el árbol está balanceado
- Útil cuando se necesitan inserciones dinámicas

**Desventajas:**
- Requiere memoria adicional para el árbol
- Peor caso O(n²) con datos ordenados

---

### **Quick Sort con Pivote Aleatorio (Randomized Quick Sort)**

**Algoritmo:**
```
RandomizedQuickSort(arr, bajo, alto):
    Si bajo < alto:
        pivote = RandomizedPartition(arr, bajo, alto)
        RandomizedQuickSort(arr, bajo, pivote-1)
        RandomizedQuickSort(arr, pivote+1, alto)

RandomizedPartition(arr, bajo, alto):
    // Seleccionar índice aleatorio entre bajo y alto
    índiceAleatorio = bajo + rand() % (alto - bajo + 1)
    
    // Intercambiar elemento aleatorio con el último
    Intercambiar arr[índiceAleatorio] con arr[alto]
    
    // Aplicar partition normal
    pivote = arr[alto]
    i = bajo - 1
    Para j desde bajo hasta alto-1:
        Si arr[j] <= pivote:
            i++
            Intercambiar arr[i] con arr[j]
    Intercambiar arr[i+1] con arr[alto]
    Retornar i+1
```

**Complejidad:**
- Mejor caso: O(n log n)
- Caso promedio: O(n log n)
- Peor caso: O(n²) - muy raro con aleatorización
- Espacio: O(log n) - recursión

**Características:**
- **Aleatorización mejora el rendimiento esperado**
- Evita el peor caso O(n²) con datos ordenados
- No estable en implementación básica
- In-place

**Diferencia con Quick Sort básico:**
- Quick Sort básico: pivote = último elemento (o primero)
- Randomized Quick Sort: pivote = elemento aleatorio

**Por qué es mejor:**
- Probabilidad de peor caso es extremadamente baja
- Performance consistente independiente del orden de entrada
- O(n log n) esperado para cualquier entrada

---

## 🔍 2. Algoritmos de Búsqueda {#busqueda}

### **Búsqueda Lineal (Linear Search)**

**Algoritmo:**
```
LinearSearch(arr, n, x):
    Para i desde 0 hasta n-1:
        Si arr[i] == x:
            Retornar i
    Retornar -1
```

**Complejidad:**
- Mejor caso: O(1) - elemento en primera posición
- Caso promedio: O(n)
- Peor caso: O(n)
- Espacio: O(1)

**Características:**
- No requiere array ordenado
- Simple de implementar
- Ineficiente para arrays grandes

---

### **Búsqueda Binaria (Binary Search)**

**Algoritmo:**
```
BinarySearch(arr, n, x):
    bajo = 0, alto = n - 1
    Mientras bajo <= alto:
        medio = (bajo + alto) / 2
        Si arr[medio] == x:
            Retornar medio
        Si arr[medio] < x:
            bajo = medio + 1
        Sino:
            alto = medio - 1
    Retornar -1
```

**Complejidad:**
- Todos los casos: O(log n)
- Espacio: O(1) iterativo, O(log n) recursivo

**Características:**
- **Requiere array ordenado**
- Muy eficiente
- Divide el espacio de búsqueda a la mitad en cada paso

---

### **Búsqueda Ternaria (Ternary Search)**

**Algoritmo:**
```
TernarySearch(arr, bajo, alto, x):
    Si bajo <= alto:
        mid1 = bajo + (alto - bajo) / 3
        mid2 = alto - (alto - bajo) / 3
        
        Si arr[mid1] == x: Retornar mid1
        Si arr[mid2] == x: Retornar mid2
        
        Si x < arr[mid1]:
            TernarySearch(arr, bajo, mid1-1, x)
        Si x > arr[mid2]:
            TernarySearch(arr, mid2+1, alto, x)
        Sino:
            TernarySearch(arr, mid1+1, mid2-1, x)
```

**Complejidad:**
- Todos los casos: O(log₃ n) ≈ 1.58 × O(log₂ n)
- Más comparaciones que búsqueda binaria en práctica

---

### **Jump Search (Búsqueda por Saltos)**

**Algoritmo:**
```
JumpSearch(arr, n, x):
    salto = √n
    prev = 0
    Mientras arr[min(salto, n) - 1] < x:
        prev = salto
        salto += √n
        Si prev >= n:
            Retornar -1
    
    // Búsqueda lineal en el bloque
    Para i desde prev hasta min(salto, n):
        Si arr[i] == x:
            Retornar i
    Retornar -1
```

**Complejidad:**
- O(√n)
- Espacio: O(1)

**Características:**
- Requiere array ordenado
- Más lento que búsqueda binaria
- Mejor que búsqueda lineal

---

### **Interpolation Search (Búsqueda por Interpolación)**

**Algoritmo:**
```
InterpolationSearch(arr, bajo, alto, x):
    Si bajo <= alto y x >= arr[bajo] y x <= arr[alto]:
        // Estimar posición
        pos = bajo + ((x - arr[bajo]) * (alto - bajo)) / (arr[alto] - arr[bajo])
        
        Si arr[pos] == x: Retornar pos
        Si arr[pos] < x:
            InterpolationSearch(arr, pos+1, alto, x)
        Sino:
            InterpolationSearch(arr, bajo, pos-1, x)
    Retornar -1
```

**Complejidad:**
- Mejor caso: O(log log n) - datos uniformemente distribuidos
- Peor caso: O(n) - datos no uniformes
- Espacio: O(1)

---

## 🌲 3. Árboles {#arboles}

### **Árbol Binario (Binary Tree)**

**Estructura:**
```cpp
struct Nodo {
    int dato;
    Nodo* izq;
    Nodo* der;
};
```

**Operaciones:**
- Inserción: O(n) - peor caso árbol degenerado
- Búsqueda: O(n)
- Eliminación: O(n)

---

### **Árbol Binario de Búsqueda (BST)**

**Propiedad:** Para cada nodo:
- Subárbol izquierdo: todos los valores < nodo
- Subárbol derecho: todos los valores > nodo

**Recorridos:**

1. **In-Order (Izq → Raíz → Der):**
   ```
   InOrder(nodo):
       Si nodo != NULL:
           InOrder(nodo->izq)
           Visitar(nodo)
           InOrder(nodo->der)
   ```
   - Resultado: elementos en orden ascendente
   - Complejidad: O(n)

2. **Pre-Order (Raíz → Izq → Der):**
   ```
   PreOrder(nodo):
       Si nodo != NULL:
           Visitar(nodo)
           PreOrder(nodo->izq)
           PreOrder(nodo->der)
   ```
   - Útil para copiar árbol
   - Complejidad: O(n)

3. **Post-Order (Izq → Der → Raíz):**
   ```
   PostOrder(nodo):
       Si nodo != NULL:
           PostOrder(nodo->izq)
           PostOrder(nodo->der)
           Visitar(nodo)
   ```
   - Útil para eliminar árbol
   - Complejidad: O(n)

4. **Level-Order (Por Niveles):**
   ```
   LevelOrder(raíz):
       Cola Q
       Q.encolar(raíz)
       Mientras !Q.vacía():
           nodo = Q.desencolar()
           Visitar(nodo)
           Si nodo->izq: Q.encolar(nodo->izq)
           Si nodo->der: Q.encolar(nodo->der)
   ```
   - Usa BFS
   - Complejidad: O(n)

**Complejidad BST:**
- Inserción: O(h) donde h = altura
  - Mejor caso: O(log n) - balanceado
  - Peor caso: O(n) - degenerado (lista)
- Búsqueda: O(h)
- Eliminación: O(h)
- Espacio: O(n)

---

### **Árbol AVL (Auto-balanceado)**

**Propiedad:** 
- Factor de balance: |altura(izq) - altura(der)| ≤ 1 para cada nodo

**Rotaciones:**
1. **Simple Derecha (LL):** hijo izq del izq desbalanceado
2. **Simple Izquierda (RR):** hijo der del der desbalanceado
3. **Doble Izq-Der (LR):** hijo der del izq desbalanceado
4. **Doble Der-Izq (RL):** hijo izq del der desbalanceado

**Complejidad:**
- Inserción: O(log n)
- Búsqueda: O(log n)
- Eliminación: O(log n)
- Espacio: O(n)
- Rebalanceo: O(log n)

**Ventajas:**
- Búsquedas más rápidas que BST no balanceado
- Garantiza altura logarítmica

**Desventajas:**
- Inserciones/eliminaciones más lentas (por rotaciones)
- Mayor complejidad de implementación

---

### **Árbol Rojo-Negro (Red-Black Tree)**

**Propiedades:**
1. Cada nodo es rojo o negro
2. Raíz es negra
3. Hojas (NULL) son negras
4. Hijos de nodo rojo son negros
5. Todo camino de nodo a hojas tiene mismo número de nodos negros

**Complejidad:**
- Inserción: O(log n)
- Búsqueda: O(log n)
- Eliminación: O(log n)
- Espacio: O(n)

**Comparación AVL vs Red-Black:**
- AVL: más balanceado → búsquedas más rápidas
- Red-Black: menos rotaciones → inserciones/eliminaciones más rápidas

---

### **Heap (Montículo)**

**Max-Heap:** Padre ≥ hijos  
**Min-Heap:** Padre ≤ hijos

**Propiedades:**
- Árbol binario completo (se llena de izq a der)
- Se implementa típicamente con array

**Índices en array:**
- Padre de i: (i-1)/2
- Hijo izquierdo: 2i + 1
- Hijo derecho: 2i + 2

**Operaciones:**
- Inserción: O(log n)
- Extraer máx/mín: O(log n)
- Obtener máx/mín: O(1)
- Construir heap: O(n)
- Heapify: O(log n)

**Usos:**
- Priority Queue
- Heap Sort
- Algoritmo de Dijkstra
- Algoritmo de Prim

---

### **Trie (Árbol de Prefijos)**

**Estructura:**
```cpp
struct NodoTrie {
    NodoTrie* hijos[26];  // para alfabeto
    bool esFinal;
};
```

**Complejidad:**
- Inserción: O(m) donde m = longitud de palabra
- Búsqueda: O(m)
- Eliminación: O(m)
- Espacio: O(ALPHABET_SIZE × m × n) en peor caso

**Usos:**
- Autocompletado
- Corrector ortográfico
- Búsqueda de prefijos
- IP routing

---

## 🔐 4. Hash Table {#hashtable}

### **Concepto**

Estructura que mapea claves a valores usando una función hash:
```
índice = hash(clave) % tamaño_tabla
```

### **Función Hash**

**Características deseables:**
- Determinista
- Distribución uniforme
- Rápida de calcular
- Minimiza colisiones

**Ejemplos:**
```cpp
// División
hash(k) = k % m

// Multiplicación
hash(k) = floor(m × (k × A % 1))  // 0 < A < 1

// String hashing
hash(s) = Σ(s[i] × p^i) % m  // p = primo
```

### **Manejo de Colisiones**

#### **1. Chaining (Encadenamiento)**
```
Tabla[i] → [elem1] → [elem2] → [elem3] → NULL
```

**Complejidad:**
- Inserción: O(1)
- Búsqueda: O(1 + α) donde α = factor de carga (n/m)
- Eliminación: O(1 + α)
- Espacio: O(n + m)

**Factor de carga:** α = n/m
- n = número de elementos
- m = tamaño de tabla
- α pequeño → menos colisiones

#### **2. Open Addressing (Direccionamiento Abierto)**

**a) Linear Probing:**
```
h(k, i) = (h'(k) + i) % m
```
- Problema: clustering primario

**b) Quadratic Probing:**
```
h(k, i) = (h'(k) + c₁i + c₂i²) % m
```
- Reduce clustering

**c) Double Hashing:**
```
h(k, i) = (h₁(k) + i × h₂(k)) % m
```
- Mejor distribución

**Complejidad Open Addressing:**
- Inserción: O(1/(1-α))
- Búsqueda: O(1/(1-α))
- α debe ser < 1 (tabla nunca llena completamente)

### **Rehashing**

Cuando α supera umbral (típicamente 0.7):
```
1. Crear nueva tabla (tamaño × 2)
2. Reinsertar todos los elementos
3. Complejidad: O(n)
```

### **Comparación**

| Operación | Promedio | Peor Caso |
|-----------|----------|-----------|
| Búsqueda  | O(1)     | O(n)      |
| Inserción | O(1)     | O(n)      |
| Eliminación | O(1)   | O(n)      |

---

## 🔢 5. Bitset y Set {#bitset-set}

### **Bitset**

**Concepto:** Array de bits compacto

**Operaciones:**
```cpp
bitset<8> b("10101010");
b.set(i)      // Poner bit i en 1
b.reset(i)    // Poner bit i en 0
b.flip(i)     // Invertir bit i
b.test(i)     // Consultar bit i
b.count()     // Contar bits en 1
b.any()       // ¿Algún bit en 1?
b.all()       // ¿Todos los bits en 1?
b.none()      // ¿Ningún bit en 1?
```

**Operaciones de bits:**
```cpp
b1 & b2   // AND
b1 | b2   // OR
b1 ^ b2   // XOR
~b1       // NOT
b1 << n   // Shift izquierda
b1 >> n   // Shift derecha
```

**Complejidad:**
- Todas las operaciones: O(1) o O(n/w) donde w = tamaño de palabra
- Espacio: n bits (compacto)

**Usos:**
- Representar conjuntos pequeños
- Máscaras de bits
- Optimización de memoria
- Algoritmos con estados binarios

---

### **Set (Conjunto)**

**Implementación en C++:** Árbol Rojo-Negro (ordenado)

**Operaciones:**
```cpp
set<int> s;
s.insert(x)    // Insertar
s.erase(x)     // Eliminar
s.find(x)      // Buscar
s.count(x)     // ¿Existe? (0 o 1)
s.size()       // Tamaño
s.empty()      // ¿Vacío?
s.clear()      // Limpiar
```

**Complejidad:**
- Inserción: O(log n)
- Búsqueda: O(log n)
- Eliminación: O(log n)
- Espacio: O(n)

**Características:**
- Elementos únicos
- Ordenados automáticamente
- No permite duplicados
- Iteradores bidireccionales

---

### **Unordered Set**

**Implementación:** Hash Table

**Complejidad:**
- Inserción: O(1) promedio, O(n) peor caso
- Búsqueda: O(1) promedio, O(n) peor caso
- Eliminación: O(1) promedio, O(n) peor caso
- Espacio: O(n)

**Características:**
- No ordenado
- Más rápido que set en promedio
- Elementos únicos

**Comparación Set vs Unordered Set:**

| Aspecto | Set | Unordered Set |
|---------|-----|---------------|
| Implementación | Árbol RB | Hash Table |
| Orden | Sí | No |
| Búsqueda | O(log n) | O(1) promedio |
| Iteración | Ordenada | Sin orden |
| Uso de memoria | Menor | Mayor |

---

### **Multiset**

**Diferencia con Set:** Permite elementos duplicados

**Complejidad:** Igual que set
- Inserción: O(log n)
- Búsqueda: O(log n)
- Eliminación: O(log n)

**Usos:**
- Contar frecuencias manteniendo orden
- Priority queue con duplicados

---

## 📊 6. Grafos {#grafos}

### **Definiciones Básicas**

- **Grafo:** G = (V, E) donde V = vértices, E = aristas
- **Grado:** número de aristas conectadas a un vértice
- **Camino:** secuencia de vértices conectados
- **Ciclo:** camino que empieza y termina en el mismo vértice
- **Conexo:** existe camino entre cualquier par de vértices
- **Componente conexa:** subgrafo conexo maximal

**Tipos:**
- **Dirigido vs No dirigido**
- **Ponderado vs No ponderado**
- **Cíclico vs Acíclico (DAG)**
- **Conexo vs Desconexo**

---

### **Representaciones**

#### **1. Matriz de Adyacencia**

```cpp
int adj[V][V];
adj[i][j] = 1 si existe arista entre i y j
```

**Complejidad:**
- Espacio: O(V²)
- Verificar arista: O(1)
- Obtener vecinos: O(V)
- Agregar arista: O(1)

**Ventajas:**
- Consulta rápida de aristas
- Simple para grafos densos

**Desventajas:**
- Desperdicia memoria en grafos dispersos
- Iterar vecinos es lento

---

#### **2. Lista de Adyacencia**

```cpp
vector<int> adj[V];
// o
struct Nodo {
    int dato;
    Nodo* siguiente;
};
Nodo* adj[V];
```

**Complejidad:**
- Espacio: O(V + E)
- Verificar arista: O(grado)
- Obtener vecinos: O(grado)
- Agregar arista: O(1)

**Ventajas:**
- Eficiente en memoria para grafos dispersos
- Rápido para iterar vecinos

**Desventajas:**
- Consultar arista específica es más lenta

---

### **Algoritmos de Recorrido**

#### **BFS (Breadth-First Search)**

**Algoritmo:**
```
BFS(grafo, origen):
    Cola Q
    Marcar origen como visitado
    Q.encolar(origen)
    
    Mientras !Q.vacía():
        u = Q.desencolar()
        Para cada vecino v de u:
            Si v no visitado:
                Marcar v como visitado
                Q.encolar(v)
                padre[v] = u
```

**Complejidad:**
- Tiempo: O(V + E)
- Espacio: O(V)

**Propiedades:**
- Encuentra camino más corto en grafos no ponderados
- Explora por niveles
- Usa cola (FIFO)

**Usos:**
- Camino más corto sin pesos
- Verificar conexidad
- Árbol de expansión
- Nivel de nodos

---

#### **DFS (Depth-First Search)**

**Algoritmo (Recursivo):**
```
DFS(grafo, u, visitados):
    Marcar u como visitado
    Para cada vecino v de u:
        Si v no visitado:
            padre[v] = u
            DFS(grafo, v, visitados)
```

**Algoritmo (Iterativo):**
```
DFS_Iterativo(grafo, origen):
    Pila S
    S.apilar(origen)
    
    Mientras !S.vacía():
        u = S.desapilar()
        Si u no visitado:
            Marcar u como visitado
            Para cada vecino v de u:
                Si v no visitado:
                    S.apilar(v)
```

**Complejidad:**
- Tiempo: O(V + E)
- Espacio: O(V)

**Propiedades:**
- Explora en profundidad antes de retroceder
- Usa pila (recursión o explícita)
- No garantiza camino más corto

**Usos:**
- Detectar ciclos
- Ordenamiento topológico
- Componentes fuertemente conexas
- Resolver laberintos

---

### **Algoritmos de Camino Más Corto**

#### **Dijkstra**

**Algoritmo:**
```
Dijkstra(grafo, origen):
    distancia[todos] = ∞
    distancia[origen] = 0
    PriorityQueue PQ
    PQ.insertar(origen, 0)
    
    Mientras !PQ.vacía():
        u = PQ.extraerMínimo()
        
        Para cada vecino v de u con peso w:
            Si distancia[u] + w < distancia[v]:
                distancia[v] = distancia[u] + w
                padre[v] = u
                PQ.insertar(v, distancia[v])
```

**Complejidad:**
- Con heap binario: O((V + E) log V)
- Con heap Fibonacci: O(E + V log V)
- Espacio: O(V)

**Requisitos:**
- **No funciona con pesos negativos**
- Grafos dirigidos o no dirigidos

**Características:**
- Algoritmo greedy
- Usa priority queue (min-heap)
- Encuentra camino más corto desde un origen a todos los demás

---

#### **Bellman-Ford**

**Algoritmo:**
```
BellmanFord(grafo, origen):
    distancia[todos] = ∞
    distancia[origen] = 0
    
    // Relajar todas las aristas V-1 veces
    Para i desde 1 hasta V-1:
        Para cada arista (u, v) con peso w:
            Si distancia[u] + w < distancia[v]:
                distancia[v] = distancia[u] + w
                padre[v] = u
    
    // Detectar ciclos negativos
    Para cada arista (u, v) con peso w:
        Si distancia[u] + w < distancia[v]:
            Retornar "Ciclo negativo detectado"
```

**Complejidad:**
- Tiempo: O(V × E)
- Espacio: O(V)

**Características:**
- **Funciona con pesos negativos**
- Detecta ciclos negativos
- Más lento que Dijkstra
- Programación dinámica

---

#### **Floyd-Warshall**

**Algoritmo:**
```
FloydWarshall(grafo):
    dist[V][V]
    // Inicializar
    Para i, j:
        dist[i][j] = peso(i, j) si existe arista
        dist[i][j] = ∞ si no existe
        dist[i][i] = 0
    
    // Algoritmo principal
    Para k desde 0 hasta V-1:
        Para i desde 0 hasta V-1:
            Para j desde 0 hasta V-1:
                Si dist[i][k] + dist[k][j] < dist[i][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]
```

**Complejidad:**
- Tiempo: O(V³)
- Espacio: O(V²)

**Características:**
- Encuentra caminos más cortos **entre todos los pares**
- Funciona con pesos negativos
- Detecta ciclos negativos
- Programación dinámica

---

### **Árbol de Expansión Mínima (MST)**

#### **Prim**

**Algoritmo:**
```
Prim(grafo):
    MST = vacío
    visitados = {origen}
    PQ = todas las aristas de origen
    
    Mientras |MST| < V-1:
        (u, v, peso) = PQ.extraerMínimo()
        Si v no visitado:
            Agregar (u, v) a MST
            Marcar v como visitado
            Agregar aristas de v a PQ
```

**Complejidad:**
- Con heap binario: O(E log V)
- Con heap Fibonacci: O(E + V log V)
- Espacio: O(V + E)

**Características:**
- Similar a Dijkstra
- Greedy
- Mejor
