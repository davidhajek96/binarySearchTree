
#include "Conjunto.h"

template <class T>
Conjunto<T>::Conjunto() : _raiz(nullptr){
}

template <class T>
Conjunto<T>::~Conjunto() { 
    // Completar
}

template <class T>
bool Conjunto<T>::pertenece(const T& clave) const {
    if (buscarNodo(_raiz, clave) == nullptr){
        return false;
    }
    return (buscarNodo(_raiz, clave)->valor == clave);
    //return false;
}
template <class T>
void Conjunto<T>::insertar(const T& clave) {

    Nodo* ainsertar = new Nodo(clave);
    //Nodo ainsertar = Nodo(clave);
    if (!pertenece(clave)){
        Nodo* padre = buscarNodoPadre(_raiz,clave);
        if(padre == nullptr){
            _raiz = ainsertar;
        }
        else if(clave < padre->valor){
                padre->izq = ainsertar;
             }else{
                padre->der = ainsertar;
        }
    }
    ainsertar = nullptr;
    delete ainsertar;


}

template <class Nodo, class T>
void deleteNode(Nodo*& root, T key) {
    if (root == nullptr) {
        return;
    }
    if (key < root->valor) {
        deleteNode(root->izq, key);
    } else if (key > root->valor) {
        deleteNode(root->der, key);
    } else {
        if (root->izq == nullptr) {
            Nodo* temp = root->der;
            delete root;
            root = temp;
        } else if (root->der == nullptr) {
            Nodo* temp = root->izq;
            delete root;
            root = temp;
        } else {
            Nodo* temp = root->der;
            while (temp->izq != nullptr) {
                temp = temp->izq;
            }
            root->valor = temp->valor;
            deleteNode(root->der, temp->valor);
        }
    }
}

template <class T>
void Conjunto<T>::remover(const T& clave) {
    deleteNode(_raiz, clave);
}


template <class T>
const T& Conjunto<T>::siguiente(const T& clave) {
    Nodo* actual = _raiz;
    Nodo* aDevolver;

    while (actual != nullptr){
        if (actual->valor > clave){
            aDevolver = actual;
            actual = actual->izq;
        } else {
            actual = actual->der;
        }

    }

    return aDevolver->valor;
}

template <class T>
const T& Conjunto<T>::minimo() const {
    Nodo* actual = _raiz;

    while(actual->izq != nullptr){
        actual = actual->izq;
    }
    return actual->valor;
}

template <class T>
const T& Conjunto<T>::maximo() const {
    Nodo* actual = _raiz;

    while(actual->der != nullptr){
        actual = actual->der;
    }
    return actual->valor;
}

template <class T>
unsigned int Conjunto<T>::cardinal() const {
    return cardinalAux(_raiz);

}

template <class T>
unsigned int Conjunto<T>::cardinalAux(Nodo* r) const {
    if (r == nullptr){
        return 0;
    }else {
        return (1 + cardinalAux(r->der) + cardinalAux(r->izq));
    }

}

template <class T>
void Conjunto<T>::mostrar(std::ostream&) const {
    assert(false);
}




