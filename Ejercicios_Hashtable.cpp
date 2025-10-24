#include <iostream>
#include <string>
using namespace std;
 struct Nodo {
    int clave;
    string valor;
    Nodo* siguiente;
};

// Tabla hash simple
class HashTable {
private:
    static const int CAP = 10; // tamaño de la tabla
    Nodo* tabla[CAP];

    // Función hash simple
    int hashFunction(int clave) {
        return clave % CAP;
    }

public:
    // Constructor
    HashTable() {
        for (int i = 0; i < CAP; i++)
            tabla[i] = nullptr;
    }

    // Destructor
    ~HashTable() {
        for (int i = 0; i < CAP; i++) {
            Nodo* actual = tabla[i];
            while (actual) {
                Nodo* temp = actual;
                actual = actual->siguiente;
                delete temp;
            }
        }
    }

    // ==========================
    // Métodos a implementar
    // ==========================
    void insertar(int clave, const string& valor) {
        // TODO: crear nodo y agregarlo al bucket correspondiente
        int indice =hashFunction(clave);
        Nodo *nuevo= new Nodo{clave,valor,nullptr};
        
      nuevo->siguiente=tabla[indice];
      tabla[indice]=nuevo;
        
        
    }

    bool eliminar(int clave) {
        // TODO: buscar clave y eliminar nodo
       int indice= hashFunction(clave);
       Nodo *actual=tabla[indice];
       Nodo *anterior=nullptr;
       
       while(actual != nullptr){
           
           if(actual->clave == clave){
          if(anterior ==nullptr){
              tabla[indice] = actual->siguiente;
          } else{
              anterior->siguiente = actual->siguiente;
          }
           delete actual;
           return  true;}
       

        anterior = actual;
        actual = actual->siguiente;}
        return false;
    }

    bool buscar(int clave, string& valor) {
        // TODO: buscar clave y devolver valor
        int indice=hashFunction(clave);
        Nodo *actual =tabla[indice];
        while(actual!=nullptr){
            if(actual->clave == clave){
            valor=actual->valor;
              return true;
            }
            actual= actual->siguiente;
          
        }
         
        return false;
    }

    void mostrar() {
        // TODO: mostrar todos los elementos de la tabla
        for(int i=0; i<CAP; i++){
            Nodo* actual=tabla[i];
            while(actual!=nullptr){
                cout<<actual->clave<<"  "<<actual->valor;
                actual = actual->siguiente;
            }
        }
        
    }
    
     // ==========================
    // Métodos avanzados / poco comunes
    // ==========================
    
    void rehash(int nuevaCapacidad) {
        // TODO: crear una nueva tabla con capacidad mayor y redistribuir nodos
    }

    bool contieneValor(const string& valor) const {
        // TODO: devolver true si el valor existe en la tabla
        return false;
    }

    vector<int> obtenerClaves() const {
        // TODO: devolver todas las claves almacenadas en la tabla
        return vector<int>();
    }

    vector<int> colisionesPorBucket() const {
        // TODO: devolver un vector con la cantidad de nodos por bucket
        return vector<int>();
    }

    double factorDeCarga() const {
        // TODO: calcular el factor de carga (total de elementos / CAP)
        return 0.0;
    }

    string valorMasFrecuente() const {
        // TODO: devolver el valor que más se repite en la tabla
        return "";
    }

    vector<int> clavesConColision() const {
        // TODO: devolver todas las claves que están en buckets con colisiones
        return vector<int>();
    }

    void merge(const HashTable& otra) {
        // TODO: fusionar otra tabla hash con esta, evitando duplicados
    }

    bool operator==(const HashTable& otra) const {
        // TODO: devolver true si ambas tablas contienen exactamente los mismos pares clave-valor
        return false;
    }

    HashTable invertir() const {
        // TODO: crear una nueva tabla donde los valores pasan a ser claves
        return HashTable();
    }
};


int main() {
    cout << "=== TEST DE TABLA HASH ===" << endl;

    HashTable tabla;

    cout << "\n→ Insertando elementos..." << endl;
    tabla.insertar(1, "Uno");
    tabla.insertar(2, "Dos");
    tabla.insertar(3, "Tres");
    tabla.insertar(10, "Diez");  // posible colisión

    cout << "\n→ Mostrando tabla:" << endl;
    tabla.mostrar();

    cout << "\n→ Buscando clave 2..." << endl;
    string valor;
    if (tabla.buscar(2, valor))
        cout << "Encontrado: " << valor << endl;
    else
        cout << "No se encontró la clave." << endl;

    cout << "\n→ Eliminando clave 3..." << endl;
    if (tabla.eliminar(3))
        cout << "Clave 3 eliminada correctamente." << endl;
    else
        cout << "No se encontró la clave 3." << endl;

    cout << "\n→ Estado actual:" << endl;
    tabla.mostrar();

    // =============================
    // Pruebas de métodos avanzados
    // =============================

    cout << "\n→ Verificando si existe el valor 'Dos'..." << endl;
    if (tabla.contieneValor("Dos"))
        cout << "Valor 'Dos' encontrado." << endl;
    else
        cout << "Valor 'Dos' NO encontrado." << endl;

    cout << "\n→ Obteniendo todas las claves..." << endl;
    vector<int> claves = tabla.obtenerClaves();
    for (int c : claves)
        cout << c << " ";
    cout << endl;

    cout << "\n→ Colisiones por bucket..." << endl;
    vector<int> colisiones = tabla.colisionesPorBucket();
    for (int n : colisiones)
        cout << n << " ";
    cout << endl;

    cout << "\n→ Factor de carga: " << tabla.factorDeCarga() << endl;

    cout << "\n→ Valor más frecuente: " << tabla.valorMasFrecuente() << endl;

    cout << "\n→ Claves en buckets con colisión..." << endl;
    vector<int> clavesCol = tabla.clavesConColision();
    for (int c : clavesCol)
        cout << c << " ";
    cout << endl;

    cout << "\n→ Rehashing a nueva capacidad 20..." << endl;
    tabla.rehash(20);
    tabla.mostrar();

    cout << "\n→ Invirtiendo tabla..." << endl;
    HashTable tablaInvertida = tabla.invertir();
    tablaInvertida.mostrar();

    cout << "\n=== FIN DEL TEST ===" << endl;
    return 0;
}
