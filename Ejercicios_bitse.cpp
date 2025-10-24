#include <iostream>
#include <bitset>
#include <set>
#include <vector>
using namespace std;

// ===========================
// Clase para manejar Bitset
// ===========================
class BitsetManager {
private:
    static const size_t SIZE = 16;  
    bitset<SIZE> bits;

public:
    BitsetManager();

    // Métodos básicos
    void setBit(size_t pos) {
        // TODO: poner 1 en la posición pos
    }

    void resetBit(size_t pos) {
        // TODO: poner 0 en la posición pos
    }

    void toggleBit(size_t pos) {
        // TODO: invertir bit en pos
    }

    bool testBit(size_t pos) const {
        // TODO: devolver true si el bit está a 1
        return false;
    }

    void mostrar() const {
        // TODO: imprimir el bitset completo
    }

    // Métodos avanzados
    size_t contar() const {
        // TODO: devolver la cantidad de bits a 1
        return 0;
    }

    size_t contarCeros() const {
        // TODO: devolver la cantidad de bits a 0
        return 0;
    }

    void desplazarIzq(size_t n) {
        // TODO: desplazar todos los bits n posiciones a la izquierda
    }

    void desplazarDer(size_t n) {
        // TODO: desplazar todos los bits n posiciones a la derecha
    }

    void invertir() {
        // TODO: invertir todos los bits
    }

    bool esTodoUno() const {
        // TODO: devolver true si todos los bits están a 1
        return false;
    }

    bool esTodoCero() const {
        // TODO: devolver true si todos los bits están a 0
        return false;
    }
};

// ===========================
// Clase para manejar Set
// ===========================
class SetManager {
private:
    set<int> datos;

public:
    SetManager();

    // Métodos básicos
    void agregar(int valor) {
        // TODO: agregar un elemento al set
    }

    void eliminar(int valor) {
        // TODO: eliminar un elemento del set
    }

    bool contiene(int valor) const {
        // TODO: devolver true si el set contiene el valor
        return false;
    }

    void mostrar() const {
        // TODO: imprimir todos los elementos del set
    }

    // Métodos avanzados
    size_t tamaño() const {
        // TODO: devolver la cantidad de elementos en el set
        return 0;
    }

    int minimo() const {
        // TODO: devolver el valor mínimo del set
        return 0;
    }

    int maximo() const {
        // TODO: devolver el valor máximo del set
        return 0;
    }

    SetManager unionCon(const SetManager& otro) const {
        // TODO: devolver la unión del set actual con otro
        return SetManager();
    }

    SetManager interseccionCon(const SetManager& otro) const {
        // TODO: devolver la intersección del set actual con otro
        return SetManager();
    }

    SetManager diferenciaCon(const SetManager& otro) const {
        // TODO: devolver la diferencia del set actual con otro
        return SetManager();
    }

    bool esSubconjunto(const SetManager& otro) const {
        // TODO: devolver true si el set actual es subconjunto de otro
        return false;
    }
};

// ===========================
// MAIN DE PRUEBA
// ===========================
int main() {
    cout << "=== TEST BITSET ===" << endl;
    BitsetManager bm;

    bm.setBit(3);
    bm.resetBit(2);
    bm.toggleBit(5);
    bm.mostrar();

    cout << "Cantidad de bits a 1: " << bm.contar() << endl;
    cout << "Cantidad de bits a 0: " << bm.contarCeros() << endl;
    bm.desplazarIzq(2);
    bm.desplazarDer(1);
    bm.invertir();
    cout << "Todos a 1?: " << (bm.esTodoUno() ? "Sí" : "No") << endl;
    cout << "Todos a 0?: " << (bm.esTodoCero() ? "Sí" : "No") << endl;

    cout << "\n=== TEST SET ===" << endl;
    SetManager sm;
    sm.agregar(10);
    sm.agregar(5);
    sm.agregar(7);
    sm.mostrar();

    cout << "Contiene 5? " << (sm.contiene(5) ? "Sí" : "No") << endl;
    sm.eliminar(5);
    cout << "Contiene 5? " << (sm.contiene(5) ? "Sí" : "No") << endl;
    cout << "Tamaño: " << sm.tamaño() << endl;

    SetManager otro;
    otro.agregar(7);
    otro.agregar(8);

    SetManager uni = sm.unionCon(otro);
    SetManager inter = sm.interseccionCon(otro);
    SetManager diff = sm.diferenciaCon(otro);

    cout << "\n=== FIN DEL TEST ===" << endl;
    return 0;
}
