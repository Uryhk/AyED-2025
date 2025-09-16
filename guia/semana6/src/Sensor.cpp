#include "Sensor.h"
#include <cmath>   // std::fabs

Sensor::Sensor(std::string n, std::string u)
: nombre(n), valor(0.0f), unidad(u), ventana(nullptr), K(0), sumaVentana(0.0f) {}

Sensor::~Sensor() {
    if (ventana) delete ventana;
}

void Sensor::configurarVentana(int k) {
    //TODO
 
}

void Sensor::agregarLectura(float x) {
    // TODO
}

void Sensor::setValor(float nuevo) {
    //TODO
}

float Sensor::promedioMovil() const {
    //TODO
}

bool Sensor::estable(float umbral) const {
    //TODO
}
