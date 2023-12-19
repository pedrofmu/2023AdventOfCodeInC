#include <stdio.h>
#include <stdlib.h>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// Definición de la estructura para el nodo de la lista
typedef struct Nodo {
    int entero1;
    int entero2;
    struct Nodo* siguiente;
} Nodo;

// Función para crear un nuevo nodo
Nodo* crearNodo(int entero1, int entero2) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevoNodo != NULL) {
        nuevoNodo->entero1 = entero1;
        nuevoNodo->entero2 = entero2;
        nuevoNodo->siguiente = NULL;
    }
    return nuevoNodo;
}

// Función para insertar un nodo al principio de la lista
void insertarNodo(Nodo** cabeza, int entero1, int entero2) {
    Nodo* nuevo = crearNodo(entero1, entero2);
    if (nuevo != NULL) {
        nuevo->siguiente = *cabeza;
        *cabeza = nuevo;
    }
}

// Función para verificar si un par de valores ya existen en la lista
int existeValor(Nodo* cabeza, int entero1, int entero2) {
    Nodo* actual = cabeza;
    while (actual != NULL) {
        if (actual->entero1 == entero1 && actual->entero2 == entero2) {
            return 1; // Los valores existen en la lista
        }
        actual = actual->siguiente;
    }
    return 0; // Los valores no existen en la lista
}

#endif // LINKED_LIST_H
