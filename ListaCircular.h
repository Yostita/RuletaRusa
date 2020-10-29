/*----------------------------------*/
/*  Practica 7. José Luis Bellosta  */
/*----------------------------------*/
#include <cstdlib>
#include "Nodo.h"
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}


class ListaCircular {
	Nodo* lista;

	int n;
	//Obtiene un nodo de la lista
	//Precondiciones: la posicion esta entre 0  y (n - 1) y lista !=  NULL y n tiene que ser mayor que 0
	//Complejidad temporal: O(n)
	//Complejidad espacial: O(1)
	Nodo* getNodo(int posicion);

public:
	//Creamos constructor sin parametros
	//Precondiciones: ninguna
	//Complejidad temporal: O(1)
	//Complejidad espacial: O(1)
	ListaCircular();

	//Devuelve el valor del elemento de la lista en esa posicion
	//Precondiciones: la posicion esta entre 0  y (n - 1) y n tiene que ser mayor que 0
	//Complejidad temporal: O(n)
	//Complejidad espacial: O(1)
	string getValor(int posicion);

	//Modificamos el valor de la lista en la posicion indicada
	//Precondiciones: la posicion esta entre 0  y (n - 1) y n tiene que ser mayor que 0
	//Complejidad temporal: O(n)
	//Complejidad espacial: O(1)
	void setValor(int posicion, string nuevoValor);

	//Devuelve el tama�o del tambor
	//Precondiciones: ninguna
	//Complejidad temporal: O(1)
	//Complejidad espacial: O(1)
	int getN();

	//Insertamos un elemento con su valor correspondiente en la posicion indicada
	//Precondiciones: la posicion esta entre 0  y n
	//Complejidad temporal: O(n)
	//Complejidad espacial: O(1)
	void insertar(int posicion, string nuevoValor);

	//Eliminamos el elemento de la posicion indicada
	//Precondiciones: la posicion esta entre 0  y (n - 1) y n tiene que ser mayor que 0
	//Complejidad temporal: O(n)
	//Complejidad espacial: O(1)
	void eliminar(int posicion);

	//Giramos los elementos hacia la izquierda (si p < 0) o a la derecha (si p > 0)
	//Precondiciones: lista != NULL
	//Complejidad temporal: O(n^n)
	//Complejidad espacial: O(n)
	void girar(int p);

	//Liberamos la memoria
	//Precondiciones: ninguna
	//Complejidad temporal: O(n)
	//Complejidad espacial: O(1)
	~ListaCircular();
};