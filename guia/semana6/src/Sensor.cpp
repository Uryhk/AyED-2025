#include "Sensor.h"
#include <cmath>   // std::fabs

Sensor::Sensor(std::string n, std::string u)
: nombre(n), valor(0.0f), unidad(u), ventana(nullptr), K(0), sumaVentana(0.0f) {}

Sensor::~Sensor() {
    if (ventana) delete ventana;
}

void Sensor::configurarVentana(int k) {
    //TODO
    if (ventana) delete ventana;  // eliminar ventana anterior si existe
    K = k;
    ventana = new Cola<float>();  // crear nueva cola vacía
    sumaVentana = 0.0f;          // reiniciar suma
    
}

void Sensor::agregarLectura(float x) {
    // TODO

    if (!ventana) return;  // si no hay ventana, no hacer nada
    ventana->enqueue(x);
    sumaVentana += x;
    if (ventana->size() > K) {
        float eliminado = ventana->dequeue();
        sumaVentana -= eliminado;
    }
    valor = x;  // actualizar el valor actual del sensor

}

void Sensor::setValor(float nuevo) {
    //TODO
    valor = nuevo;
    agregarLectura(nuevo);  // alimentar la ventana si está configurada

}

float Sensor::promedioMovil() const {
    //TODO
    if (!ventana || ventana->empty()) return 0.0f;  // si no hay ventana o está vacía
    return sumaVentana / ventana->size();

}

bool Sensor::estable(float umbral) const {
    //TODO
    if (!ventana || ventana->empty()) return true;  // si no hay ventana o está vacía
    float promedio = promedioMovil();
    return std::fabs(valor - promedio) < umbral;
        
}

