#include "Habitacion.h"
#include <iostream>

// ===== Constructores / básicos =====
Habitacion::Habitacion() : nombre("sin_nombre") {}
Habitacion::Habitacion(const std::string& n) : nombre(n) {}

const std::string& Habitacion::getNombre() const { return nombre; }
void Habitacion::setNombre(const std::string& n) { nombre = n; }

int  Habitacion::cantidadSensores() const { return (int)sensores.size(); }
bool Habitacion::vacia() const { return sensores.empty(); }

void Habitacion::agregarSensor(const Sensor& s) { sensores.push_back(s); }
void Habitacion::agregarSensor(const std::string& n, const std::string& u) {
    sensores.push_back(Sensor(n, u));
}

// ===== Helpers recursivos (head / tail) =====

void Habitacion::mostrarRec(std::vector<Sensor>::const_iterator it,
                            std::vector<Sensor>::const_iterator fin,
                            int idxBase) const {
    //TODO: imprimir la cabeza y llamar a la recursión con el resto
    if(it==fin)return;{}
    std::cout<< it-> getValor();
        mostrarRec(next(it),fin,idxBase+1);
}

int Habitacion::indiceDeRec(std::vector<Sensor>::const_iterator it,
                            std::vector<Sensor>::const_iterator fin,
                            int idxBase,
                            const std::string& nombreSensor) const {
    //TODO: devolver índice si la cabeza coincide, o recursión con el resto
    
  if(it==fin) return -1;
    if (it->getNombre() == nombreSensor) 
        return idxBase;
 return indiceDeRec(std::next(it), fin, idxBase + 1, nombreSensor);
}

bool Habitacion::setValorRec(std::vector<Sensor>::iterator it,
                             std::vector<Sensor>::iterator fin,
                             const std::string& nombreSensor,
                             float nuevoValor) {
    //TODO: si la cabeza coincide cambiar valor, si no, recursión con el resto
       if(it==fin) return false;
    if(it->getNombre() == nombreSensor) setValor(nuevoValor);
    return setValorRec(std::next(it),fin,nombreSensor,nuevoValor);
}

bool Habitacion::setNombreRec(std::vector<Sensor>::iterator it,
                              std::vector<Sensor>::iterator fin,
                              const std::string& nombreActual,
                              const std::string& nombreNuevo) {
    //TODO: si la cabeza coincide cambiar nombre, si no, recursión con el resto
    return false;
}

const Sensor* Habitacion::obtenerConstRec(std::vector<Sensor>::const_iterator it,
                                          std::vector<Sensor>::const_iterator fin,
                                          const std::string& nombreSensor) const {
    //TODO: devolver puntero al sensor si coincide, si no, recursión con el resto
    return nullptr;
}

Sensor* Habitacion::obtenerRec(std::vector<Sensor>::iterator it,
                               std::vector<Sensor>::iterator fin,
                               const std::string& nombreSensor) {
    //TODO: devolver puntero al sensor si coincide, si no, recursión con el resto
    return nullptr;
}

bool Habitacion::eliminarPorNombreRec(std::vector<Sensor>::iterator it,
                                      std::vector<Sensor>::iterator fin,
                                      const std::string& nombreSensor) {
    //TODO: si la cabeza coincide, borrar con erase; si no, recursión con el resto
    return false;
}

// ===== API pública (envoltorios) =====

void Habitacion::mostrar() const {
    std::cout << "Habitacion: " << nombre << "\n";
    if (sensores.empty()) { std::cout << "  (sin sensores)\n"; return; }
    mostrarRec(sensores.begin(), sensores.end(), 0);
}

int Habitacion::indiceDe(const std::string& nombreSensor) const {
    return indiceDeRec(sensores.begin(), sensores.end(), 0, nombreSensor);
}

bool Habitacion::existeSensor(const std::string& nombreSensor) const {
    return indiceDe(nombreSensor) != -1;
}

bool Habitacion::setValor(const std::string& nombreSensor, float nuevoValor) {
    return setValorRec(sensores.begin(), sensores.end(), nombreSensor, nuevoValor);
}

bool Habitacion::setNombreSensor(const std::string& nombreActual, const std::string& nombreNuevo) {
    return setNombreRec(sensores.begin(), sensores.end(), nombreActual, nombreNuevo);
}

const Sensor* Habitacion::obtenerSensor(const std::string& nombreSensor) const {
    return obtenerConstRec(sensores.begin(), sensores.end(), nombreSensor);
}

Sensor* Habitacion::obtenerSensor(const std::string& nombreSensor) {
    return obtenerRec(sensores.begin(), sensores.end(), nombreSensor);
}

bool Habitacion::eliminarSensorPorNombre(const std::string& nombreSensor) {
    return eliminarPorNombreRec(sensores.begin(), sensores.end(), nombreSensor);
}

bool Habitacion::eliminarSensorPorIndice(int idx) {
    if (idx < 0 || idx >= (int)sensores.size()) return false;
    sensores.erase(sensores.begin() + idx);
    return true;
}
