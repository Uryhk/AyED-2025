#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
//#include <math>
using namespace std;

// Estructura del nodo del árbol
struct Nodo {
    int dato;
    Nodo* izq;
    Nodo* der;
    
    Nodo(int valor) : dato(valor), izq(nullptr), der(nullptr) {}
};

class ArbolBinarioBusqueda {
private:
    Nodo* raiz;
    
    // ========================================
    // MÉTODOS AUXILIARES RECURSIVOS (PRIVADOS)
    // ========================================
    
    Nodo* insertarRecursivo(Nodo* nodo, int valor) {
        // TODO: insertar valor en el árbol de forma recursiva
        // Si nodo es nullptr, crear nuevo nodo
        // Si valor < nodo->dato, insertar en subárbol izquierdo
        // Si valor > nodo->dato, insertar en subárbol derecho
        // Si valor == nodo->dato, no hacer nada (evitar duplicados)
        if(!nodo)return new Nodo(valor);
        
     
        if(valor< nodo->dato)
       nodo->izq=insertarRecursivo(nodo->izq,valor);
         
         if(valor > nodo->dato)
        nodo->der =insertarRecursivo(nodo->der,valor);
        
         if(valor==nodo->dato)return nodo;
    }
    
    bool buscarRecursivo(Nodo* nodo, int valor) const {
        // TODO: buscar valor en el árbol
        // Retornar true si se encuentra, false si no
        
        if(!nodo)return false;
        if(nodo->dato == valor)return true;
        
        if(valor>nodo->dato)return buscarRecursivos(nodo->der,valor);
        if(valor<nodo->dato)return buscarRecursivos(nodo->izq,valor);
        
        
        
    }
    
    Nodo* encontrarMinimo(Nodo* nodo) const {
        // TODO: encontrar el nodo con el valor mínimo
        // (el nodo más a la izquierda)
      if(!nodo)return nullptr;
      if(!nodo->izq)return nodo;
      encontrarMinimo(nodo->izq);
    }
    
    Nodo* encontrarMaximo(Nodo* nodo) const {
        // TODO: encontrar el nodo con el valor máximo
        // (el nodo más a la derecha)
            if(!nodo)return nullptr;
            
            if(!nodo->der)return nodo;
            encontrarMaximo(nodo->der);
            
    }
    
    Nodo* eliminarRecursivo(Nodo* nodo, int valor) {
        // TODO: eliminar un nodo con el valor dado
        // Casos:
        // 1. Nodo hoja (sin hijos)
        // 2. Nodo con un hijo
        // 3. Nodo con dos hijos (reemplazar con sucesor inorden)
        if(!nodo)return nullptr;
        
          
        if(valor<nodo->dato){
        nodo->izq=eliminarRecursivo(nodo->izq,valor);
        return nodo;
         }else if(valor>nodo->dato){
        nodo->der=eliminarRecursivo(nodo->der,valor);
        return nodo;}
        
        if(!nodo->izq && !nodo->der) delete nodo; return nullptr;
         
         if(!nodo->izq)
         Nodo *temp=nodo->der;
         delete nodo;
         return temp;
         
         if(!nodo->der)
         Nodo *temp= Nodo->izq;
         delete nodo;
         return temp;
        
        Nodo *sucesor = encontrarMinimo(nodo->der);
        nodo->dato= sucesor->dato;
        nodo->der=eliminarRecursivo(nodo->der, sucesor->dato);
        return nodo;
        
    }
    
    int contarNodosRecursivo(Nodo* nodo) const {
        // TODO: contar total de nodos en el árbol
        
        if(!nodo)return 0;
        else return 1+contarNodosRecursivo(nodo->izq)+contarNodosRecursivo(nodo->der);
        
        return 0;
    }
    
    int alturaRecursivo(Nodo* nodo) const {
        // TODO: calcular altura del árbol
        // Altura = máxima distancia desde raíz hasta hoja
        // Árbol vacío tiene altura -1
        // Árbol con solo raíz tiene altura 0
     
        if(!nodo)return -1;
        if(!nodo->izq && !nodo->der)return 0;
        else
        int altizq=1+alturaRecursivo(nodo->izq);
        int altder=1+alturaRecursivo(nodo->der);
        
        return max(altizq,altder);
        
    }
    
    int contarHojasRecursivo(Nodo* nodo) const {
        // TODO: contar cantidad de nodos hoja
        // Nodo hoja = nodo sin hijos
        
        if(!nodo)return 0;
        if(!nodo->izq && !nodo->der)
       return 1;
        else
         return contarHojasRecursivo(nodo->der)+contarHojasRecursivo(nodo->izq);
    }
    
    void inordenRecursivo(Nodo* nodo) const {
        // TODO: recorrido inorden (izq - raíz - der)
        // Imprime los valores en orden ascendente
        if(!nodo)return;
        inordenRecursivo(nodo->izq);
        cout<<nodo->dato<<" "<<endl;
        inordenRecursivo(nodo->der);
        
        
    }
    
    void preordenRecursivo(Nodo* nodo) const {
        // TODO: recorrido preorden (raíz - izq - der)
        if(!nodo)return;
        cout<<nodo->dato<<" "<<endl;
        preordenRecursivo(nodo->izq);
          preordenRecursivo(nodo->der);
    }
    
    void postordenRecursivo(Nodo* nodo) const {
        // TODO: recorrido postorden (izq - der - raíz)
        if(!nodo)return;
        postordenRecursivo(nodo->izq);
        postordenRecursivo(nodo->der);
        cout<<nodo->dato<<" "<<endl;
    }
    
    void destruirArbol(Nodo* nodo) {
        // TODO: liberar memoria de todos los nodos (postorden)
        if(!nodo)
        return;
        
        destruirArbol(nodo->izq);
        destruirArbol(nodo->der);
        delete nodo;
    }
    
    // ========================================
    // MÉTODOS AVANZADOS
    // ========================================
    
    bool esHoja(Nodo* nodo) const {
        // TODO: verificar si un nodo es hoja
        if(!nodo)return false;
        if(!nodo->izq && !nodo->der)return true;
  
       return false;
    }
    
    int sumaTotal(Nodo* nodo) const {
        // TODO: calcular suma de todos los valores
        if(!nodo)
        return 0;
        else 
        return nodo->dato + sumaTotal(nodo->izq) + sumaTotal(nodo->der);
    }
    
    bool esBalanceado(Nodo* nodo) const {
        // TODO: verificar si el árbol está balanceado
        // Balanceado: diferencia de alturas entre subárboles <= 1
        int altizq =alturaRecursivo(nodo->izq);
        int altder=alturaRecursivo(nodo->der);
        int dif= std::abs(altizq-altder);
        if(!nodo)return true;
        
        if(dif>1)return false;
        else
        return esBalanceado(nodo->izq) &&
        esBalanceado(nodo->der);
        
        
    }
    
    bool esPerfecto(Nodo* nodo, int altura, int nivel = 0) const {
        // TODO: verificar si el árbol es perfecto
        // Perfecto: todos los niveles están completamente llenos
        if(!nodo)return (altura == nivel);

        
        if(!esHoja(nodo))return (altura==nivel+1);
        if(!nodo->izq || !nodo->der)return false;
        return esPerfecto(nodo->izq,altura,nivel+1) && esPerfecto(nodo->der,altura,nivel+1);
    }
    
    bool esCompleto(Nodo* nodo, int indice, int totalNodos) const {
        // TODO: verificar si el árbol es completo
        // Completo: todos los niveles llenos excepto posiblemente el último
        
        if(!nodo)return true;
        
        if(indice >= totalNodos)return false;
        
        return esCompleto(nodo->izq ,(2*inice)+1 ,totalNodos)&& esCompleto(nodo->der ,(2*inice)+2 ,totalNodos)
        
        
        
    }
    
    int nivelDeNodo(Nodo* nodo, int valor, int nivel = 0) const {
        // TODO: encontrar el nivel de un nodo con valor dado
        // Raíz está en nivel 0
        
        if(!nodo)return -1;
        
        if(nodo->dato==valor)return nivel;
        
        if(valor<nodo->dato)
        return nivelDeNodo(nodo->izq,valor,nivel+1);
        
        if(valor>nodo->dato)
        return nivelDeNodo(nodo->der,valor,nivel+1);
        
    }
    
    Nodo* encontrarPadre(Nodo* nodo, int valor) const {
        // TODO: encontrar el padre de un nodo con valor dado
        if(!nodo)
        return nullptr;
        if(nodo->dato==valor)return nullptr;
        
        if(nodo->izq && nodo->izq->dato==valor) return nodo;
        if(nodo->der&& nodo->der->dato==valor)return nodo;
        
        if(valor<nodo->dato)
         return encontrarPadre(nodo->izq,valor);
         if(valor>nodo->dato)
         return encontrarPadre(nodo->der,valor);
         
         return nullptr;
    }
    
    bool sonHermanos(Nodo* nodo, int valor1, int valor2) const {
        // TODO: verificar si dos valores están en nodos hermanos
        // Hermanos: tienen el mismo padre
        Nodo *padre1=encontrarPadre(nodo,valor1);
        Nodo *padre2=encontrarPadre(nodo,valor2);
        if(!padre1 || !padre2)return false;
        if(padre1 == padre2)
        if( valor1 !=valor2)return true;
        else 
        return false;
    }
    
    void obtenerRango(Nodo* nodo, int min, int max, vector<int>& resultado) const {
        // TODO: obtener todos los valores en un rango [min, max]
      if(!nodo)return;
      if(min<nodo->dato)return obtenerRango(nodo->izq,min,max,resultado);
      if(min>=nodo->dato && nodo->dato<=max )resultado.push_back(nodo->dato);
      if(max>nodo->dato)return obtenerRango(nodo->der,min,max,resultado);
      
    }
    
    Nodo* copiarArbol(Nodo* nodo) const {
        // TODO: crear una copia profunda del árbol
        
        if(!nodo)return nullptr;
        Nodo* copia=new Nodo(nodo->dato);
        copia->izq=copiarArbol(nodo->izq);
        copia->der=copiarArbol(nodo->der);
        
        return copia;
    }
    
    bool sonIguales(Nodo* a, Nodo* b) const {
        // TODO: verificar si dos árboles son iguales (estructura y valores)
        if(!a&&!b)return true;
        
        if(!a || !b || a->dato != b->dato) return false;
        
        return sonIguales(a->izq,b->izq) && sonIguales(a->der,b->der);
      
        
   
    }
    
    bool esSubarbol(Nodo* arbolGrande, Nodo* arbolPequeño) const {
        // TODO: verificar si arbolPequeño es subárbol de arbolGrande
        if(!arbolGrande)return false;
        if(!arbolPequeño)return true;
        if(sonIguales(arbolGrande,arbolPequeño))return true;
      
       return esSubarbol(arbolGrande->izq,arbolPequeño) || esSubarbol(arbolGrande->der,arbolPequeño);
      
    }
    
    void espejar(Nodo* nodo) {
        // TODO: crear imagen espejo del árbol (intercambiar izq y der)
       
        if(!nodo)return;
        Nodo *aux= nodo->izq;
        nodo->izq=  nodo->der;
        nodo->der = aux;
        
        espejar(nodo->izq);
        espejar(nodo->der);
         
    }
    
    int diametro(Nodo* nodo, int& altura) const {
        // TODO: calcular diámetro del árbol
        // Diámetro: camino más largo entre dos hojas
        if(!nodo){altura=0;
        return 0;}
        
        int altizq=0,altder=0,diamizq,diamder; 
        diamizq=diametro(nodo->izq,altizq);
        diamder=diametro(nodo->der, altder);
        
        altura =1+max(altizq,altder);
        int diamtotal = 1+diamizq+diamder;
        
        return max(diamder,diamizq,diamtotal);
        
        
    }
    
    Nodo* ancestroComun(Nodo* nodo, int val1, int val2) const {
        // TODO: encontrar ancestro común más cercano de dos valores
         if(!nodo)return nullptr;
          if(val1<nodo->dato && val2<nodo->dato)return ancestroComun(nodo->izq,val1,val2);
          if(val1>nodo->dato && val2>nodo->dato)return ancestroComun(nodo->der,val1,val2);
        return nodo;
    }
    
    void nodosPorNivel(Nodo* nodo, int nivel, vector<int>& resultado) const {
        // TODO: obtener todos los nodos de un nivel específico
  
        if(!nodo)return;
        
        if(nivel==0){
        resultado.push_back(nodo->dato);return;}
        else{
        nodosPorNivel(nodo->izq,nivel-1,resultado);
        nodosPorNivel(nodo->der,nivel-1,resultado);
        }
        
    }
    
    int anchuraMaxima(Nodo* nodo) const {
        // TODO: encontrar el ancho máximo del árbol
        // Ancho: máximo número de nodos en cualquier nivel
        
         if (!nodo) 
        return 0;
    
        int max_ancho = 0;
        std::queue<Nodo*> cola;
        cola.push(nodo); 

         while (!cola.empty()) {
        
        int ancho_nivel_actual = cola.size();
        max_ancho = std::max(max_ancho, ancho_nivel_actual);

        
        for (int i = 0; i < ancho_nivel_actual; ++i) {
            Nodo* actual = cola.front();
            cola.pop();

            
            if (actual->izq) 
                cola.push(actual->izq);
            

            
            if (actual->der) 
                cola.push(actual->der);
            }
         }
          return max_ancho;
 }
    
    bool existeCamino(Nodo* nodo, int suma) const {
        // TODO: verificar si existe un camino raíz-hoja con suma dada
        if (!nodo) 
        return false;
        
        int suma_restante = suma - nodo->dato;

        if (!nodo->izq && !nodo->der) 
        return (suma_restante == 0);
    
        bool camino_izq = existeCamino(nodo->izq, suma_restante);
        bool camino_der = existeCamino(nodo->der, suma_restante);

        return camino_izq || camino_der;
        return false;
        
    }
    
    void todosLosCaminos(Nodo* nodo, vector<int>& camino, vector<vector<int>>& resultado) const {
        // TODO: obtener todos los caminos raíz-hoja

    if (!nodo) 
        return;
    camino.push_back(nodo->dato);

    if (!nodo->izq && !nodo->der) 
        resultado.push_back(camino); 
     else 
        todosLosCaminos(nodo->izq, camino, resultado);
        todosLosCaminos(nodo->der, camino, resultado);
    
    camino.pop_back();

    }
    
    
    void eliminarHojas(Nodo*& nodo) {
        // TODO: eliminar todos los nodos hoja del árbol
        if(!nodo)return;
        if(esHoja(nodo)){delete nodo;
        nodo=nullptr;
        return;}
        eliminarHojas(nodo->izq);
        eliminarHojas(nodo->der);
    }
    
    int contarNodosNivel(Nodo* nodo, int nivelObjetivo, int nivelActual = 0) const {
        // TODO: contar nodos en un nivel específico
        if(!nodo)return 0;
         if(nivelActual==nivelObjetivo)return 1;
        return
        contarNodosNivel(nodo->izq,nivelObjetivo,nivelActual+1)+
        contarNodosNivel(nodo->der,nivelObjetivo,nivelActual+1);
       
    }
    
    bool esBST(Nodo* nodo, int min, int max) const {
        // TODO: verificar si el árbol es un BST válido
        return false;
    }
    
public:
    // ========================================
    // CONSTRUCTOR Y DESTRUCTOR
    // ========================================
    
    ArbolBinarioBusqueda() : raiz(nullptr) {}
    
    ~ArbolBinarioBusqueda() {
        destruirArbol(raiz);
    }
    
    // ========================================
    // MÉTODOS PÚBLICOS BÁSICOS
    // ========================================
    
    void insertar(int valor) {
        raiz = insertarRecursivo(raiz, valor);
    }
    
    bool buscar(int valor) const {
        return buscarRecursivo(raiz, valor);
    }
    
    void eliminar(int valor) {
        raiz = eliminarRecursivo(raiz, valor);
    }
    
    int encontrarMin() const {
        if (raiz == nullptr) {
            throw runtime_error("Árbol vacío");
        }
        return encontrarMinimo(raiz)->dato;
    }
    
    int encontrarMax() const {
        if (raiz == nullptr) {
            throw runtime_error("Árbol vacío");
        }
        return encontrarMaximo(raiz)->dato;
    }
    
    bool estaVacio() const {
        return raiz == nullptr;
    }
    
    // ========================================
    // MÉTODOS PÚBLICOS DE INFORMACIÓN
    // ========================================
    
    int contarNodos() const {
        return contarNodosRecursivo(raiz);
    }
    
    int altura() const {
        return alturaRecursivo(raiz);
    }
    
    int contarHojas() const {
        return contarHojasRecursivo(raiz);
    }
    
    int suma() const {
        return sumaTotal(raiz);
    }
    
    bool balanceado() const {
        return esBalanceado(raiz);
    }
    
    bool perfecto() const {
        int h = altura();
        return esPerfecto(raiz, h);
    }
    
    bool completo() const {
        return esCompleto(raiz, 0, contarNodos());
    }
    
    int nivel(int valor) const {
        return nivelDeNodo(raiz, valor);
    }
    
    bool hermanos(int valor1, int valor2) const {
        return sonHermanos(raiz, valor1, valor2);
    }
    
    int diametro() const {
        int altura = 0;
        return diametro(raiz, altura);
    }
    
    int ancho() const {
        return anchuraMaxima(raiz);
    }
    
    bool esBSTValido() const {
        return esBST(raiz, INT_MIN, INT_MAX);
    }
    
    // ========================================
    // MÉTODOS PÚBLICOS DE RECORRIDO
    // ========================================
    
    void inorden() const {
        cout << "Inorden: ";
        inordenRecursivo(raiz);
        cout << endl;
    }
    
    void preorden() const {
        cout << "Preorden: ";
        preordenRecursivo(raiz);
        cout << endl;
    }
    
    void postorden() const {
        cout << "Postorden: ";
        postordenRecursivo(raiz);
        cout << endl;
    }
    
    void porNiveles() const {
        // TODO: recorrido por niveles (BFS) usando cola
        // Implementar sin recursión
        cout << "Por niveles: ";
        if (raiz == nullptr) {
            cout << endl;
            return;
        }
        
        queue<Nodo*> cola;
        cola.push(raiz);
        
        while (!cola.empty()) {
            Nodo* actual = cola.front();
            cola.pop();
            
            cout << actual->dato << " ";
            
            if (actual->izq != nullptr)
                cola.push(actual->izq);
            if (actual->der != nullptr)
                cola.push(actual->der);
        }
        cout << endl;
    }
    
    // ========================================
    // MÉTODOS PÚBLICOS AVANZADOS
    // ========================================
    
    vector<int> rango(int min, int max) const {
        vector<int> resultado;
        obtenerRango(raiz, min, max, resultado);
        return resultado;
    }
    
    ArbolBinarioBusqueda copia() const {
        ArbolBinarioBusqueda nuevo;
        nuevo.raiz = copiarArbol(raiz);
        return nuevo;
    }
    
    void espejo() {
        espejar(raiz);
    }
    
    int lca(int val1, int val2) const {
        Nodo* resultado = ancestroComun(raiz, val1, val2);
        return (resultado != nullptr) ? resultado->dato : -1;
    }
    
    vector<int> nodosEnNivel(int nivel) const {
        vector<int> resultado;
        nodosPorNivel(raiz, nivel, resultado);
        return resultado;
    }
    
    bool existeSumaCamino(int suma) const {
        return existeCamino(raiz, suma);
    }
    
    vector<vector<int>> obtenerCaminos() const {
        vector<vector<int>> resultado;
        vector<int> camino;
        todosLosCaminos(raiz, camino, resultado);
        return resultado;
    }
    
    int distancia(int val1, int val2) const {
        return distanciaEntreNodos(raiz, val1, val2);
    }
    
    void podarHojas() {
        eliminarHojas(raiz);
    }
    
    int nodosEnNivel(int nivel) const {
        return contarNodosNivel(raiz, nivel);
    }
    
    // ========================================
    // VISUALIZACIÓN
    // ========================================
    
    void mostrarEstructura() const {
        cout << "\n=== ESTRUCTURA DEL ÁRBOL ===" << endl;
        mostrarEstructuraRecursivo(raiz, "", true);
    }
    
private:
    void mostrarEstructuraRecursivo(Nodo* nodo, string prefijo, bool esUltimo) const {
        if (nodo == nullptr) return;
        
        cout << prefijo;
        cout << (esUltimo ? "└── " : "├── ");
        cout << nodo->dato << endl;
        
        string nuevoPrefijo = prefijo + (esUltimo ? "    " : "│   ");
        
        if (nodo->izq != nullptr || nodo->der != nullptr) {
            if (nodo->izq != nullptr) {
                mostrarEstructuraRecursivo(nodo->izq, nuevoPrefijo, nodo->der == nullptr);
            }
            if (nodo->der != nullptr) {
                mostrarEstructuraRecursivo(nodo->der, nuevoPrefijo, true);
            }
        }
    }
};

// ========================================
// MAIN DE PRUEBA
// ========================================

int main() {
    cout << "╔═══════════════════════════════════════════════╗" << endl;
    cout << "║  ÁRBOL BINARIO DE BÚSQUEDA - GUÍA COMPLETA   ║" << endl;
    cout << "╚═══════════════════════════════════════════════╝" << endl;
    
    ArbolBinarioBusqueda arbol;
    
    // Test 1: Inserción
    cout << "\n【 TEST 1: INSERCIÓN 】" << endl;
    cout << "Insertando: 50, 30, 70, 20, 40, 60, 80" << endl;
    arbol.insertar(50);
    arbol.insertar(30);
    arbol.insertar(70);
    arbol.insertar(20);
    arbol.insertar(40);
    arbol.insertar(60);
    arbol.insertar(80);
    
    arbol.mostrarEstructura();
    
    // Test 2: Recorridos
    cout << "\n【 TEST 2: RECORRIDOS 】" << endl;
    arbol.inorden();
    arbol.preorden();
    arbol.postorden();
    arbol.porNiveles();
    
    // Test 3: Búsqueda
    cout << "\n【 TEST 3: BÚSQUEDA 】" << endl;
    cout << "¿Existe 40? " << (arbol.buscar(40) ? "Sí" : "No") << endl;
    cout << "¿Existe 90? " << (arbol.buscar(90) ? "Sí" : "No") << endl;
    
    // Test 4: Mínimo y Máximo
    cout << "\n【 TEST 4: MIN/MAX 】" << endl;
    try {
        cout << "Mínimo: " << arbol.encontrarMin() << endl;
        cout << "Máximo: " << arbol.encontrarMax() << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    // Test 5: Información del árbol
    cout << "\n【 TEST 5: INFORMACIÓN 】" << endl;
    cout << "Total de nodos: " << arbol.contarNodos() << endl;
    cout << "Altura: " << arbol.altura() << endl;
    cout << "Cantidad de hojas: " << arbol.contarHojas() << endl;
    cout << "Suma total: " << arbol.suma() << endl;
    cout << "¿Está balanceado? " << (arbol.balanceado() ? "Sí" : "No") << endl;
    cout << "¿Es perfecto? " << (arbol.perfecto() ? "Sí" : "No") << endl;
    cout << "¿Es completo? " << (arbol.completo() ? "Sí" : "No") << endl;
    cout << "¿Es BST válido? " << (arbol.esBSTValido() ? "Sí" : "No") << endl;
    
    // Test 6: Niveles
    cout << "\n【 TEST 6: NIVELES 】" << endl;
    cout << "Nivel de 40: " << arbol.nivel(40) << endl;
    cout << "Nivel de 80: " << arbol.nivel(80) << endl;
    cout << "Ancho máximo: " << arbol.ancho() << endl;
    
    // Test 7: Rango
    cout << "\n【 TEST 7: RANGO 】" << endl;
    vector<int> rango = arbol.rango(25, 65);
    cout << "Valores entre 25 y 65: ";
    for (int val : rango) cout << val << " ";
    cout << endl;
    
    // Test 8: Hermanos
    cout << "\n【 TEST 8: HERMANOS 】" << endl;
    cout << "¿Son hermanos 20 y 40? " << (arbol.hermanos(20, 40) ? "Sí" : "No") << endl;
    cout << "¿Son hermanos 30 y 70? " << (arbol.hermanos(30, 70) ? "Sí" : "No") << endl;
    
    // Test 9: LCA (Lowest Common Ancestor)
    cout << "\n【 TEST 9: ANCESTRO COMÚN 】" << endl;
    cout << "LCA de 20 y 40: " << arbol.lca(20, 40) << endl;
    cout << "LCA de 20 y 80: " << arbol.lca(20, 80) << endl;
    
    // Test 10: Diámetro
    cout << "\n【 TEST 10: DIÁMETRO 】" << endl;
    cout << "Diámetro del árbol: " << arbol.diametro() << endl;
    
    // Test 11: Caminos
    cout << "\n【 TEST 11: CAMINOS 】" << endl;
    cout << "¿Existe camino con suma 100? " << (arbol.existeSumaCamino(100) ? "Sí" : "No") << endl;
    cout << "¿Existe camino con suma 120? " << (arbol.existeSumaCamino(120) ? "Sí" : "No") << endl;
    
    // Test 12: Distancia
    cout << "\n【 TEST 12: DISTANCIA 】" << endl;
    cout << "Distancia entre 20 y 40: " << arbol.distancia(20, 40) << endl;
    cout << "Distancia entre 20 y 80: " << arbol.distancia(20, 80) << endl;
    
    // Test 13: Nodos por nivel
    cout << "\n【 TEST 13: NODOS POR NIVEL 】" << endl;
    for (int i = 0; i <= arbol.altura(); i++) {
        vector<int> nodos = arbol.nodosEnNivel(i);
        cout << "Nivel " << i << ": ";
        for (int val : nodos) cout << val << " ";
        cout << "(" << arbol.nodosEnNivel(i) << " nodos)" << endl;
    }
    
    // Test 14: Eliminación
    cout << "\n【 TEST 14: ELIMINACIÓN 】" << endl;
    cout << "Eliminando 20..." << endl;
    arbol.eliminar(20);
    arbol.mostrarEstructura();
    arbol.inorden();
    
    cout << "\nEliminando 30..." << endl;
    arbol.eliminar(30);
    arbol.mostrarEstructura();
    arbol.inorden();
    
    cout << "\nEliminando 50 (raíz)..." << endl;
    arbol.eliminar(50);
    arbol.mostrarEstructura();
    arbol.inorden();
    
    // Test 15: Espejo
    cout << "\n【 TEST 15: ESPEJO 】" << endl;
    cout << "Creando imagen espejo..." << endl;
    arbol.espejo();
    arbol.mostrarEstructura();
    arbol.inorden();
    
    cout << "\n╔═══════════════════════════════════════════════╗" << endl;
    cout << "║           FIN DE LOS TESTS                    ║" << endl;
    cout << "╚═══════════════════════════════════════════════╝" << endl;
    
    return 0;
}
