#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ===========================
// Clase Bitset desde CERO
// ===========================
class BitsetManager {
private:
    static const size_t SIZE = 16;  
    static const size_t BITS_PER_WORD = 32;
    static const size_t NUM_WORDS = (SIZE + BITS_PER_WORD - 1) / BITS_PER_WORD;
    
    unsigned int data[NUM_WORDS]; // Array para almacenar los bits

    // Métodos auxiliares privados
    size_t getWordIndex(size_t pos) const {
        return pos / BITS_PER_WORD;
    }

    size_t getBitIndex(size_t pos) const {
        return pos % BITS_PER_WORD;
    }

    bool isValidPosition(size_t pos) const {
        return pos < SIZE;
    }

public:
    BitsetManager() {
        // TODO: Inicializar todos los bits en 0
        // Pista: recorrer el array data y poner cada elemento en 0
    }

    // Métodos básicos
    void setBit(size_t pos) {
        // TODO: Poner el bit en posición pos a 1
        // Pasos:
        // 1. Verificar que pos sea válida con isValidPosition()
        // 2. Obtener el índice de la palabra con getWordIndex()
        // 3. Obtener el índice del bit dentro de la palabra con getBitIndex()
        // 4. Usar operador OR (|) con una máscara: (1u << bitIndex)
        // Ejemplo: data[wordIndex] |= (1u << bitIndex);
    }

    void resetBit(size_t pos) {
        // TODO: Poner el bit en posición pos a 0
        // Similar a setBit pero usar AND con complemento: &= ~(1u << bitIndex)
    }

    void toggleBit(size_t pos) {
        // TODO: Invertir el bit en posición pos (0->1, 1->0)
        // Usar operador XOR (^): data[wordIndex] ^= (1u << bitIndex)
    }

    bool testBit(size_t pos) const {
        // TODO: Devolver true si el bit en pos está a 1
        // Usar AND para verificar: (data[wordIndex] & (1u << bitIndex)) != 0
        return false;
    }

    void mostrar() const {
        // TODO: Imprimir el bitset de derecha a izquierda
        // Ejemplo de salida: "0101001100110011"
        cout << "Bitset: ";
        for (int i = SIZE - 1; i >= 0; i--) {
            // Imprimir '1' o '0' dependiendo de testBit(i)
        }
        cout << endl;
    }

    // Métodos avanzados
    size_t contar() const {
        // TODO: Contar cuántos bits están a 1
        // Método 1 (simple): recorrer todos los bits con testBit()
        // Método 2 (avanzado): usar el algoritmo de Kernighan
        // while (word) { word &= (word - 1); count++; }
        return 0;
    }

    size_t contarCeros() const {
        // TODO: Devolver SIZE - contar()
        return 0;
    }

    void desplazarIzq(size_t n) {
        // TODO: Desplazar bits n posiciones a la izquierda
        // Los bits que salen por la izquierda se pierden
        // Entran 0s por la derecha
        // Pista: recorrer data y usar el operador <<
        // Tener cuidado con los bits que pasan de una palabra a otra
    }

    void desplazarDer(size_t n) {
        // TODO: Desplazar bits n posiciones a la derecha
        // Similar a desplazarIzq pero usar >>
    }

    void invertir() {
        // TODO: Invertir todos los bits (NOT bitwise)
        // Recorrer data y aplicar complemento: data[i] = ~data[i]
        // IMPORTANTE: Limpiar bits extra en la última palabra
    }

    bool esTodoUno() const {
        // TODO: Verificar si todos los bits están a 1
        // Opción 1: contar() == SIZE
        // Opción 2: Verificar cada palabra
        return false;
    }

    bool esTodoCero() const {
        // TODO: Verificar si todos los bits están a 0
        // Verificar que todas las palabras sean 0
        return false;
    }

    // Métodos adicionales útiles
    void resetAll() {
        // TODO: Poner todos los bits a 0
    }

    void setAll() {
        // TODO: Poner todos los bits a 1
    }
};

// ===========================
// Clase Set desde CERO (usando vector ordenado)
// ===========================
class SetManager {
private:
    vector<int> datos; // Vector ordenado sin duplicados

    // Método auxiliar: búsqueda binaria
    int buscarPosicion(int valor) const {
        // TODO: Implementar búsqueda binaria
        // Devolver la posición donde está o debería estar el valor
        // Puedes usar lower_bound o implementarla manualmente
        int left = 0;
        int right = datos.size();
        
        // Búsqueda binaria manual:
        // while (left < right) {
        //     int mid = left + (right - left) / 2;
        //     if (datos[mid] < valor) left = mid + 1;
        //     else right = mid;
        // }
        // return left;
        
        return 0;
    }

public:
    SetManager() {
        // El vector empieza vacío, no hay que hacer nada
    }

    // Métodos básicos
    void agregar(int valor) {
        // TODO: Agregar valor al set manteniendo orden
        // 1. Buscar posición con buscarPosicion()
        // 2. Verificar si ya existe (comparar con datos[pos])
        // 3. Si no existe, insertar con datos.insert(datos.begin() + pos, valor)
    }

    void eliminar(int valor) {
        // TODO: Eliminar valor del set
        // 1. Buscar posición
        // 2. Verificar si existe
        // 3. Eliminar con datos.erase(datos.begin() + pos)
    }

    bool contiene(int valor) const {
        // TODO: Verificar si el valor está en el set
        // Usar buscarPosicion() y verificar si ese índice contiene el valor
        return false;
    }

    void mostrar() const {
        // TODO: Imprimir elementos del set
        cout << "Set: { ";
        // Recorrer datos e imprimir cada elemento
        cout << "}" << endl;
    }

    // Métodos avanzados
    size_t tamaño() const {
        // TODO: Devolver datos.size()
        return 0;
    }

    int minimo() const {
        // TODO: Devolver el primer elemento (datos[0])
        // Verificar que el set no esté vacío
        if (datos.empty()) {
            throw runtime_error("Set vacío");
        }
        return 0;
    }

    int maximo() const {
        // TODO: Devolver el último elemento (datos.back())
        // Verificar que el set no esté vacío
        return 0;
    }

    SetManager unionCon(const SetManager& otro) const {
        // TODO: Crear un nuevo SetManager con todos los elementos
        // de ambos sets (sin duplicados)
        // Algoritmo de merge de dos arrays ordenados
        SetManager resultado;
        // Usar dos índices i, j para recorrer ambos vectores
        // Comparar y agregar el menor, avanzar el índice correspondiente
        return resultado;
    }

    SetManager interseccionCon(const SetManager& otro) const {
        // TODO: Crear un SetManager solo con elementos que están en ambos
        // Similar a unionCon pero solo agregar cuando son iguales
        SetManager resultado;
        return resultado;
    }

    SetManager diferenciaCon(const SetManager& otro) const {
        // TODO: Elementos que están en este set pero NO en otro
        // Recorrer este set y agregar solo si !otro.contiene(elemento)
        SetManager resultado;
        return resultado;
    }

    bool esSubconjunto(const SetManager& otro) const {
        // TODO: Verificar si todos los elementos de este set
        // están en el otro set
        // Recorrer datos y verificar otro.contiene() para cada uno
        return false;
    }

    // Métodos adicionales útiles
    void limpiar() {
        // TODO: Vaciar el set completamente
    }

    bool estaVacio() const {
        // TODO: Verificar si el set está vacío
        return false;
    }
};

// ===========================
// MAIN DE PRUEBA
// ===========================
int main() {
    cout << "=== TEST BITSET ===" << endl;
    BitsetManager bm;

    cout << "Estado inicial:" << endl;
    bm.mostrar();

    cout << "\nActivando bits 3, 5, 7:" << endl;
    bm.setBit(3);
    bm.setBit(5);
    bm.setBit(7);
    bm.mostrar();

    cout << "\nInvirtiendo bit 5:" << endl;
    bm.toggleBit(5);
    bm.mostrar();

    cout << "\nEstadísticas:" << endl;
    cout << "  Bits a 1: " << bm.contar() << endl;
    cout << "  Bits a 0: " << bm.contarCeros() << endl;
    cout << "  Test bit 3: " << (bm.testBit(3) ? "ON" : "OFF") << endl;
    cout << "  Test bit 5: " << (bm.testBit(5) ? "ON" : "OFF") << endl;

    cout << "\nDesplazando 2 posiciones a la izquierda:" << endl;
    bm.desplazarIzq(2);
    bm.mostrar();

    cout << "\nInvirtiendo todos los bits:" << endl;
    bm.invertir();
    bm.mostrar();

    cout << "\nVerificaciones:" << endl;
    cout << "  ¿Todos a 1?: " << (bm.esTodoUno() ? "Sí" : "No") << endl;
    cout << "  ¿Todos a 0?: " << (bm.esTodoCero() ? "Sí" : "No") << endl;

    cout << "\n=== TEST SET ===" << endl;
    SetManager sm;

    cout << "Agregando elementos 10, 5, 7, 15, 3:" << endl;
    sm.agregar(10);
    sm.agregar(5);
    sm.agregar(7);
    sm.agregar(15);
    sm.agregar(3);
    sm.mostrar();

    cout << "\nConsultas:" << endl;
    cout << "  ¿Contiene 5?: " << (sm.contiene(5) ? "Sí" : "No") << endl;
    cout << "  ¿Contiene 20?: " << (sm.contiene(20) ? "Sí" : "No") << endl;
    cout << "  Tamaño: " << sm.tamaño() << endl;
    cout << "  Mínimo: " << sm.minimo() << endl;
    cout << "  Máximo: " << sm.maximo() << endl;

    cout << "\nEliminando el 5:" << endl;
    sm.eliminar(5);
    sm.mostrar();
    cout << "  ¿Contiene 5?: " << (sm.contiene(5) ? "Sí" : "No") << endl;

    cout << "\nOperaciones entre sets:" << endl;
    SetManager otro;
    otro.agregar(7);
    otro.agregar(8);
    otro.agregar(15);
    cout << "Set 1: ";
    sm.mostrar();
    cout << "Set 2: ";
    otro.mostrar();

    SetManager uni = sm.unionCon(otro);
    cout << "Unión: ";
    uni.mostrar();

    SetManager inter = sm.interseccionCon(otro);
    cout << "Intersección: ";
    inter.mostrar();

    SetManager diff = sm.diferenciaCon(otro);
    cout << "Diferencia (Set1 - Set2): ";
    diff.mostrar();

    cout << "\n¿Set1 es subconjunto de Set2?: " 
         << (sm.esSubconjunto(otro) ? "Sí" : "No") << endl;

    cout << "\n=== FIN DEL TEST ===" << endl;
    return 0;
}

/* ========================================
   GUÍA DE IMPLEMENTACIÓN
   ========================================

BITSET - Conceptos clave:
-------------------------
1. Los bits se almacenan en un array de unsigned int
2. Cada unsigned int tiene 32 bits (BITS_PER_WORD)
3. Para acceder al bit N:
   - Palabra: N / 32
   - Posición dentro de palabra: N % 32

4. Operaciones fundamentales:
   - Activar bit:   data[word] |= (1u << bit)
   - Desactivar:    data[word] &= ~(1u << bit)
   - Invertir:      data[word] ^= (1u << bit)
   - Verificar:     (data[word] & (1u << bit)) != 0

5. Desplazamientos:
   - Izquierda: bits van hacia posiciones mayores
   - Derecha: bits van hacia posiciones menores
   - Los bits que "salen" se pierden
   - Entran ceros por el otro lado

SET - Conceptos clave:
----------------------
1. Implementado como vector ordenado sin duplicados
2. Búsqueda binaria para eficiencia O(log n)
3. Inserción mantiene el orden
4. No permite elementos duplicados

5. Operaciones de conjuntos:
   - Unión: elementos en A o B (merge ordenado)
   - Intersección: elementos en A y B
   - Diferencia: elementos en A pero no en B
   - Subconjunto: todos los de A están en B

6. Algoritmo de merge (para unión e intersección):
   - Dos punteros, uno en cada vector
   - Comparar elementos actuales
   - Agregar según la operación
   - Avanzar el/los puntero(s) correspondiente(s)

EJERCICIOS SUGERIDOS:
---------------------
1. Implementar todos los métodos marcados con TODO
2. Agregar método para convertir bitset a número decimal
3. Agregar método para crear bitset desde número decimal
4. Implementar operadores bitwise entre dos bitsets (AND, OR, XOR)
5. Agregar método en Set para crear desde array
6. Implementar diferencia simétrica en Set (A Δ B)
7. Optimizar búsqueda binaria en Set
8. Agregar iterador personalizado para ambas clases

======================================== */
