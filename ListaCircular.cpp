/*----------------------------------*/
/*  Practica 7. José Luis Bellosta  */
/*----------------------------------*/
#include "ListaCircular.h"

Nodo* ListaCircular::getNodo(int posicion) {
	assertdomjudge(n > 0 && lista != NULL && posicion >= 0 && posicion <= (n - 1));
	Nodo *temp = NULL;
	if (posicion <= (n / 2)) {
		temp = lista;
		for (int i = 0; i < posicion; i++) {
			temp = temp->siguienteNodo;
		}
	}
	else {
		temp = lista->anteriorNodo;
		for (int i = 0; i > posicion; i--) {
			temp = temp->anteriorNodo;
		}
	}
	return temp;
}

ListaCircular::ListaCircular() {
	lista = NULL;
	n = 0;
}

string ListaCircular::getValor(int posicion) {
	assertdomjudge(n > 0 && posicion >= 0 && posicion <= (n - 1));
	Nodo* temp = getNodo(posicion);
	return temp->elemento;
}

void ListaCircular::setValor(int posicion, string nuevoValor) {
	assertdomjudge(n > 0 && posicion >= 0 && posicion <= (n - 1));
	getNodo(posicion)->elemento = nuevoValor;
}

int ListaCircular::getN() {
	return n;
}

void ListaCircular::insertar(int posicion, string nuevoValor) {
	assertdomjudge(posicion >= 0 && posicion <= n);
	Nodo* temp = new  Nodo;
	temp->elemento = nuevoValor;
	if (n == 0) {
		temp->siguienteNodo = temp;
		temp->anteriorNodo = temp;
	}
	else {
		Nodo *nodoSig;
		if (posicion == n) {
			nodoSig = lista;
		}
		else {
			nodoSig = getNodo(posicion);
		}
		Nodo *nodoAnt = nodoSig->anteriorNodo;
		temp->anteriorNodo = nodoAnt;
		temp->siguienteNodo = nodoSig;
		nodoSig->anteriorNodo = temp;
		nodoAnt->siguienteNodo = temp;
	}
	if (posicion == 0) {
		lista = temp;
	}
	n++;
}

void ListaCircular::eliminar(int posicion) {
	assertdomjudge(n > 0 && posicion >= 0 && posicion <= (n - 1));
	Nodo* temp = getNodo(posicion);
	if (n == 1) {
		lista = NULL;
	}
	else {
		Nodo *nodoAnt = temp->anteriorNodo;
		Nodo* nodoSig = temp->siguienteNodo;
		nodoAnt->siguienteNodo = nodoSig;
		nodoSig->anteriorNodo = nodoAnt;
		if (posicion == 0) {
			lista = nodoSig;
		}
	}
	n--;
	delete(temp);
}

void ListaCircular::girar(int p) {
	assertdomjudge(lista != NULL);

	if (p < 0) {
		while (p != 0) {
			Nodo* temp = lista;
			for (int i = 0; i < n - 1; i++) {
				lista = lista->siguienteNodo;
			}
			lista->siguienteNodo = temp;
			p++;
		}
	}
	else if (p > 0) {
		while (p != 0) {
			Nodo* temp = lista;
			for (int i = 0; i < n - 1; i++) {
				lista = lista->anteriorNodo;
			}
			lista->anteriorNodo = temp;
			p--;
		}
	}
}

ListaCircular::~ListaCircular() {
	while (n > 0) {
		eliminar(0);
	}
}
