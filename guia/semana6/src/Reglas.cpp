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
    Pila<bool> aux;
       while (!tokens->isEmpty()) {
        std::string token = tokens->head();
        tokens->pop_front(); 

        if (token == "AND" || token == "OR" || token == "NOT") {
            
            if (token == "NOT") {
                if (aux.empty()) throw std::runtime_error("Faltan operandos");
                bool a = aux.pop();
                aux.push(!a);
            } else if (token == "AND") {
                if (aux.size() < 2) throw std::runtime_error("Faltan operandos");
                bool b = aux.pop();
                bool a = aux.pop();
                aux.push(a && b);
            } else if (token == "OR") {
                if (aux.size() < 2) throw std::runtime_error("Faltan operandos");
                bool b = aux.pop();
                bool a = aux.pop();
                aux.push(a || b);
            }
        } else {
            const Sensor* s = h->obtenerConstRec(
                h->sensores.begin(),
                h->sensores.end(),
                token
            );
            if (!s) throw std::runtime_error("Sensor no encontrado: " + token);

            aux.push(s->getValor()); 
        }
    }

    if (aux.size() != 1) throw std::runtime_error("Expresión RPN inválida");

    return aux.pop(); 
}
