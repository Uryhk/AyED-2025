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
        if (this != &otra) {
            // Liberar memoria actual
            for (int i = 0; i < CAP; i++) {
                Nodo* actual = tabla[i];
                while (actual) {
                    Nodo* temp = actual;
                    actual = actual->siguiente;
                    delete temp;
                }
            }
            delete[] tabla;

            // Copiar nueva
            CAP = otra.CAP;
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
        return *this;
    }
    
    // ==========================
    // Métodos a implementar
    // ==========================
    void insertar(int clave, const string& valor) {
        // TODO: crear nodo y agregarlo al bucket correspondiente
        int indice =hashFunction(clave);
        Nodo*actual=tabla[indice];
        while(actual!=nullptr){
            if(actual->clave == clave){
                actual->valor=valor;return;
            }
               actual= actual->siguiente;
        }
        
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
        Nodo** nuevatabla =new Nodo*[nuevaCapacidad];//creo una tabla dinamica de forma puntero a puntero  y luego genero el espacio como un nodo de arreglos  con la nueva capacidad;
        for(int i=0;i<nuevaCapacidad; ++i){nuevatabla[i]=nullptr;}//le asigno null a los nodos de arreglos en cada indice;
        for(int i=0; i<CAP; i++){
            Nodo* actual=tabla[i];//recorro tabla y guardo el primer nodo con la direccion del siguiente;
            while(actual!=nullptr){
            Nodo *siguiente=actual->siguiente;
            
            int indice= actual->clave%nuevaCapacidad;//calculo indice 
            
            actual->siguiente=nuevatabla[indice];//elimino el siguiente nodo igualando a null para acortarla lista
            nuevatabla[indice]=actual; //asigno el primer y unico nodo ahora al indice 
            actual=siguiente;//reasigno el nodo actual como el siguiente nodo volviendo a tener a lista sin el nodo 1 
            }
        }
        
        delete [] tabla;//elimino el espacion dinamico del pntero a pntero de arreglos;
        tabla=nuevatabla;
       CAP=nuevaCapacidad;
     
    }

    bool contieneValor(const string& valor) const {
        // TODO: devolver true si el valor existe en la tabla
        for(int i=0; i<CAP;i++){
            Nodo* actual=tabla[i];
            while(actual!=nullptr){
            if(actual->valor == valor)return true;
               actual=actual->siguiente;
            }
                
            }
            return false;
        }
        
    

    vector<int> obtenerClaves() const {
        // TODO: devolver todas las claves almacenadas en la tabla
        vector<int> out;
       for(int i=0; i<CAP; i++){
           Nodo* actual=tabla[i];
           while(actual!=nullptr){
               out.push_back(actual->clave);
               actual=actual->siguiente;
           }
       }
        return out;
        
    }

    vector<int> colisionesPorBucket() const {
        // TODO: devolver un vector con la cantidad de nodos por bucket
      
            vector<int> out;
            
            for(int i=0; i<CAP; i++){
           Nodo* actual=tabla[i];
             int cont=0;
           while(actual!=nullptr){
               cont++;
               actual=actual->siguiente;
           }
           out.push_back(cont);
       }
        return out;
    }

    double factorDeCarga() const {
        // TODO: calcular el factor de carga (total de elementos / CAP)
        
        int telemento=0;
        
        for(int i=0; i<CAP; i++){
            Nodo*actual=tabla[i];
            while(actual!=nullptr){
                telemento++;
                actual=actual->siguiente;
            }
        }
        
        return (double)telemento/CAP;
    }

    string valorMasFrecuente() const {
        // TODO: devolver el valor que más se repite en la tabla
        vector<string> aux;
           
        for(int i=0; i<CAP; i++){
            Nodo*actual=tabla[i];
            while(actual!=nullptr){
                aux.push_back(actual->valor);
                actual=actual->siguiente;
            }
        }
        
        string masrep="";
        int maxre=0;
        
        for(int i=0; i<aux.size(); i++){
            int contador=1;
            for(int j=i+1; j<aux.size(); j++){
             if(aux[i]==aux[j])contador++;
            }
            if(contador>maxre){
                maxre=contador;
                masrep=aux[i];
            }
        }
        
        
        return masrep;
    }

  vector<int> clavesConColision() const {
    vector<int> aux;

    for (int i = 0; i < CAP; i++) {
        int contador = 0;
        Nodo* actual = tabla[i];

        Nodo* temp = actual;
        while (temp != nullptr) {
            contador++;
            temp = temp->siguiente;
        }


        if (contador > 1) {
            actual = tabla[i];
            while (actual != nullptr) {
                aux.push_back(actual->clave);
                actual = actual->siguiente;
            }
        }
    }

    return aux;
}

    void merge(const HashTable& otra) {
        // TODO: fusionar otra tabla hash con esta, evitando duplicados
        
        //recorro  ambas tablas y verifico nodos duplicados 
        for(int i=0; i<CAP; i++ ){
          
            Nodo*actotra = otra.tabla[i];
            while(actotra!=nullptr){
             insertar(actotra->clave,actotra->valor);
             
                actotra=actotra->siguiente;
            }
            
        }
        
    }

    bool operator==(const HashTable& otra) const {
        // TODO: devolver true si ambas tablas contienen exactamente los mismos pares clave-valor
        if(CAP != otra.CAP)return false;
         for(int i=0; i<CAP; i++){
             Nodo *actual=tabla[i];
             Nodo* actotra= otra.tabla[i];
             while(actual!=nullptr && actotra!=nullptr){
                 
                 if((actual->valor != actotra->valor ) || (actual->clave !=actotra->clave))return false;
                 actual=actual->siguiente;
                 actotra= actotra->siguiente;
                 
             }
             if(actual!=nullptr || actotra !=nullptr)return false;
             
         }
        
        return true;
    }

    HashTable invertir() {
        // TODO: crear una nueva tabla donde los valores pasan a ser claves
        HashTable invertido;
        for(int i=0; i<CAP; i++){
            Nodo*actual=tabla[i];
            
            while(actual!=nullptr){
                int clave_vieja=actual->clave;
                string valor_viejo=actual->valor;
                
                int clave_new = hashFunctionstring(valor_viejo);
                
                string valor_new=to_string(clave_vieja);
                
                invertido.insertar(clave_new,valor_new);
                actual=actual->siguiente;
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
