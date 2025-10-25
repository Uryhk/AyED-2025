#pragma once
#include <vector>
#include <string>
#include <stdexcept>

/* =========================
   Modelo de datos: Evento
   ========================= */
struct Evento {
    int ymdhm;                // clave temporal: YYYYMMDDHHMM
    std::string titulo;
    std::string descripcion;

    bool operator<(Evento& o); 
    bool operator==(Evento& o);
};

/* =========================================
   Nodo genérico para ABB (punteros crudos)
   ========================================= */
template <class T>
class Nodo {
public:
    T dato;
    Nodo* izq;
    Nodo* der;

    Nodo(T x);
};

/* =========================================
   Árbol Binario de Búsqueda (ABB<T>)
   - Sin balanceo
   - Inserción sin duplicados exactos
   - Extendido con lower_bound / predecessor / rango
   ========================================= */
template <class T>
class ABB {
private:
    Nodo<T>* raiz;

    // ---- helpers básicos ----
    void clearRec(Nodo<T>* p);
    int  tamRec(Nodo<T>* p);
    void inordenRec(Nodo<T>* p, std::vector<T>& out);
    Nodo<T>* minNode(Nodo<T>* p);

    // ---- inserción / borrado ----
    Nodo<T>* insertarRec(Nodo<T>* p, T x);
    Nodo<T>* eraseRec(Nodo<T>* p, T x);

    // ---- extensiones de orden ----
    Nodo<T>* lowerBoundHelper(Nodo<T>* p, T x);    // iterativo
    Nodo<T>* predecessorHelper(Nodo<T>* p, T x);   // iterativo
    void rangoRec(Nodo<T>* p, T a, T b, std::vector<T>& out); // recursivo

public:
    ABB();
    ~ABB();

    bool isEmpty();
    void clear();

    void insert(T x);
    void erase(T x);
    int  size();
    std::vector<T> inorden();

    // API pública de orden
    T& lower_bound(T x);
    T& predecessor(T x);
    std::vector<T> rango(T a, T b);
    
    
    
    private:
    
    
      void clearRec(Nodo<T>* p);{
          if(p==nullptr)return;
          clearRec(p->izq);
           clearRec(p->der);
           delete p;
      }
      
    int  tamRec(Nodo<T>* p){
        if(!P)return 0;
        else
        return 1+tamRec(p->izq)+tamRec(p->der);
    }
    
    void inordenRec(Nodo<T>* p, std::vector<T>& out){
        
        if(p==nullptr)return;
        
        inordenRec(p->izq,out);
        out.push_back(p->dato);
         inordenRec(p->der,out);
        
    }
    
    Nodo<T>* minNode(Nodo<T>* p){
        if(!p)return nullptr;
        
        if(!p->izq)return p;
        else
        minNode(p->izq);
    }

    // ---- inserción / borrado ----
    Nodo<T>* insertarRec(Nodo<T>* p, T x){
        
    }
    
    Nodo<T>* eraseRec(Nodo<T>* p, T x){
        
        
        
        
        
    }

    // ---- extensiones de orden ----
    /*Implementá la operación lower_bound(x) sobre un ABB (árbol binario de búsqueda) que guarda elementos ordenados por operator<.
Tu tarea es completar el helper iterativo lowerBoundHelper(p, x) que debe encontrar el primer elemento del árbol que sea >= x (usando solo comparaciones con operator<, sin <=/>=).
Si el candidato no existe, lower_bound debe lanzar runtime_error("lower_bound: no encontrado").
Recordá que el recorrido debe ser O(h) (h = altura): usá una búsqueda binaria manteniendo un mejor candidato (best) mientras bajás por el árbol.*/
Nodo<T>* lowerBoundHelper(Nodo<T>* p, T x){
        Nodo * best = nullptr;
        while(p != nullptr){
            if(x < p->dato ) 
            best= p;
            p=p->izq;
             else 
             p=p->der;
            
        }
        return p;
    }
    /*Implementá la operación predecessor(x) sobre un ABB (árbol binario de búsqueda) que guarda elementos ordenados por operator<.
Tu tarea es completar el helper iterativo predecessorHelper(p, x) que debe encontrar el elemento estrictamente menor que x más grande (el “inmediato anterior” a x en el orden del árbol), usando solo comparaciones con operator< (no uses <=/>=).
Si no existe un candidato (todos son ≥ x o el árbol está vacío), predecessor debe lanzar runtime_error("predecessor: no encontrado").
La búsqueda debe ser O(h) (h = altura): mantené un mejor candidato (best) mientras descendés por el árbol, moviéndote a derecha cuando p->dato < x y a izquierda en caso contrario.*/
    Nodo<T>* predecessorHelper(Nodo<T>* p, T x){
        Nodo * best = nullptr;
        while(p != nullptr){
            if( p->dato < x ) 
            best= p;
            p=p->der;
             else 
             p=p->izq;
            
        }
        return p;
    }
    /*Implementá el recorrido de rango en un ABB.
Completá el helper recursivo rangoRec(p, a, b, out) que debe:

No hacer nada si p == nullptr.

Visitar izquierda solo si pueden existir valores en rango: a < p->dato.

Agregar p->dato a out si está en el intervalo: !(p->dato < a) && !(b < p->dato) (equivalente a a ≤ p->dato ≤ b).

Visitar derecha solo si pueden existir valores en rango: p->dato < b.

El wrapper rango(a,b) crea el vector, llama al helper y lo retorna.*/
    void rangoRec(Nodo<T>* p, T a, T b, std::vector<T>& out){
        
        if(!p)return;
        
        if(a< p->dato)
        rangoRec(p->izq,a,b,out);
        
        if(!(p->dato < a) && !(b < p->dato))
        out.push_back(p->dato);
        
        if(p->dato <b)
             rangoRec(p->der,a,b,out);
        
    }

    
};

/* =========================================
   Calendar: fachada sobre ABB<Evento>
   ========================================= */
class Calendar {
private:
    ABB<Evento> tree;

    // claves auxiliares para intervalos
    Evento keyFloor(int ymdhm);
    Evento keyCeil (int ymdhm);

public:
    Calendar();

    void agregarEvento(Evento e);                
    void removerEvento(int ymdhm, std::string titulo); 

    Evento proximo(int ymdhm);                   
    std::vector<Evento> entre(int a, int b);      
    std::vector<Evento> conflictosEn(int ymdhm);  

    int size();                                   
    std::vector<Evento> inorden();                
};
