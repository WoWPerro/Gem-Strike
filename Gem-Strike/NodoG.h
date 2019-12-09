#pragma once
#include "ListaS.h"

template <class T>
class NodoG
{
public:
	bool visited = false;
	T nodoData; // Esto guarda el objeto deseado
	ListaS<NodoG<T>*> l; // esto guarda los apuntadores a los hijos
	int x;
	int y;
	NodoG<T>(T dat, int _x, int _y) : nodoData(dat), x(_x), y(_y) {}
};