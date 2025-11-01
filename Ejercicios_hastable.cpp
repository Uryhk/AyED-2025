#include <iostream>
#include <string>
#include <vector>
using namespace std;
 struct Nodo {
    int clave;
    string valor;
    Nodo* siguiente;
};


// Tabla hash simple
class HashTable {
private:
    int CAP = 10; // tamaño de la tabla
    Nodo** tabla;

    // Función hash simple
    int hashFunction(int clave) {
        return clave % CAP;
    }

  
          
    int hashFunctionstring(string &str){
        int hash=0;
        for(char c : str){
            hash=(hash*7+c)%CAP;
        }
        return hash;
    }          
          
 
    
public:
    // Constructor
    HashTable(int capacidadInicial = 10) : CAP(capacidadInicial) {
        tabla = new Nodo*[CAP];  
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
        delete[] tabla;  
    }
      HashTable(const HashTable& otra) : CAP(otra.CAP) {
        tabla = new Nodo*[CAP];
        for (int i = 0; i < CAP; i++) {
            tabla[i] = nullptr;
            Nodo* actual = otra.tabla[i];
            while (actual != nullptr) {
                insertar(actual->clave, actual->valor);
                actual = actual->siguiente;
            }
        }
    }
    
    // Operador de asignación (IMPORTANTE con dinámico)
    HashTable& operator=(const HashTable& otra) {
        if (this != &otra) 
            // Liberar memoria actual
            

            // Copiar nueva
        
        return *this;
    }
    
    // ==========================
    // Métodos a implementar
    // ==========================
    void insertar(int clave, const string& valor) {
        // TODO: crear nodo y agregarlo al bucket correspondiente
        int indice =hashFunction(clave);
        Nodo*actual=tabla[indice];
    
        
        
    }
    bool eliminar(int clave) {
        // TODO: buscar clave y eliminar nodo
    
        return false;
    }

    bool buscar(int clave, string& valor) {
        // TODO: buscar clave y devolver valor
      
         
        return false;
    }

    void mostrar() {
        // TODO: mostrar todos los elementos de la tabla
      
        
    }
    
     // ==========================
    // Métodos avanzados / poco comunes
    // ==========================
    
    void rehash(int nuevaCapacidad) {
        // TODO: crear una nueva tabla con capacidad mayor y redistribuir nodos
        //creo una tabla dinamica de forma puntero a puntero  y luego genero el espacio como un nodo de arreglos  con la nueva capacidad;
        //le asigno null a los nodos de arreglos en cada indice;
        
            //recorro tabla y guardo el primer nodo con la direccion del siguiente;
           
         
          //calculo indice 
            
       //elimino el siguiente nodo igualando a null para acortarla lista
          //asigno el primer y unico nodo ahora al indice 
            //reasigno el nodo actual como el siguiente nodo volviendo a tener a lista sin el nodo 1 
            
        }
        
        delete [] tabla;//elimino el espacion dinamico del pntero a pntero de arreglos;
        tabla=nuevatabla;
       CAP=nuevaCapacidad;
     
    }

    bool contieneValor(const string& valor) const {
        // TODO: devolver true si el valor existe en la tabla
      
            return false;
        }
        
    

    vector<int> obtenerClaves() const {
        // TODO: devolver todas las claves almacenadas en la tabla
      
        return out;
        
    }

    vector<int> colisionesPorBucket() const {
        // TODO: devolver un vector con la cantidad de nodos por bucket
      
            
        return out;
    }

    double factorDeCarga() const {
        // TODO: calcular el factor de carga (total de elementos / CAP)
        
     
        
        return (double)telemento/CAP;
    }

    string valorMasFrecuente() const {
        // TODO: devolver el valor que más se repite en la tabla
    
        
        return masrep;
    }

  vector<int> clavesConColision() const {
   

    return aux;
}

    void merge(const HashTable& otra) {
        // TODO: fusionar otra tabla hash con esta, evitando duplicados
        
        //recorro  ambas tablas y verifico nodos duplicados 
     
        
        
    }

    bool operator==(const HashTable& otra) const {
        // TODO: devolver true si ambas tablas contienen exactamente los mismos pares clave-valor
     
        
        return true;
    }

    HashTable invertir() {
        // TODO: crear una nueva tabla donde los valores pasan a ser claves
     
            }
        }
        
        
        return invertido;
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
