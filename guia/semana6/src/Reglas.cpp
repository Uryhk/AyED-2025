#include "Reglas.h"
#include <cstdlib>   // std::strtof
#include <iostream>

// utilitario: ¿es operador aritmético/relacional? 





static bool esOpNum(const std::string& t) {
    return (t == ">" || t == "<" || t == "==" );
}
static bool esOpBool(const std::string& t) {
    return (t == "&&" || t == "||");
}

bool Reglas::evaluarRPN(Habitacion* h, Lista<std::string>* tokens) {
    // TODO
    Pila<std::string> pila;  
Lista<std::string>* copia = new Lista<std::string>();
while(!tokens ->isEmpty()){

std::string token = copia->pop_front();

if(esOpNum(token)){
float b = std::strtof(pila.pop().c_str(),nullptr);
float a = std::strtof(pila.pop().c_str(),nullptr);

if(token==">")pila.push(a>b?"1":"0");
else if(token=="<")pila.push(a<b?"1":"0");
else if(token=="==")pila.push(a==b?"1":"0");

}else if(esOpBool(token)){

bool b = (pila.pop()!="0");
bool a = (pila.pop()!="0");
if(token=="&&")pila.push((a&&b)?"1":"0");
else if(token=="||")pila.push((a||b)?"1":"0");


}else if(token.rfind("ACT:",0)==0){

std::string nom= token.substr(4);
Sensor* sensor = h->obtenerSensor(nom);
if(sensor)pila.push(std::to_string(sensor->getValor()));

}else{
    Sensor* sensor = h->obtenerSensor(token);
    if(sensor)pila.push(std::to_string(sensor->getValor())); 
    else pila.push(token);
}
      
}


}
