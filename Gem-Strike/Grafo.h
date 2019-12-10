#pragma once
#include "NodoG.h"
#include "NodoT.h"
#include <exception>

template <class T>
class Grafo
{
public:
	int size;
	NodoG<T> *first;
	bool ALLVISITED = false;
	void insertaNodo(T data, NodoG<T>* padre); // 25% inserta un nodo agregando el apuntador a la lista de hijos del padre
	void insertaNodo(NodoG<T>* hijo, NodoG<T>* padre);
	NodoG<T>* buscaNodo(T data); // 25% busca un nodo por su data y regresa el apuntador al nodo si es que lo encuentra
	void eliminaNodo(T data); // 25% busca un nodo por su data, y lo elimina, asegurándose que sus hijos son agregados a otro nodo
	void imprimeGrafo(); // 25% imprime el grafo de la siguiente manera: Padre1{hijo1, hijo2, hijo3,..., hijoN}
	void printsons(NodoG<T>* padre, bool allvisited);
	void Deletefromlist(T val, NodoG<T>* head);
	NodoG<T>* searchSons(T data, NodoG<T>* padre);
	NodoG<T>* GetNodo(int x);
	NodoG<T>* GetNodoAt(int x, int y);
	void CreateGrid();
	Grafo();
	~Grafo();
};

template <class T>
Grafo<T>::Grafo()
{
	first = NULL;
}

template <class T>
Grafo<T>::~Grafo()
{

}


/**
* Agrega un nuevo nodo
*
* @param padre es el padre del nodo para insertar
*/
template <class T>
void Grafo<T>::insertaNodo(T data, NodoG<T>* padre)
{
	try
	{
		NodoG<T>* temp = new NodoG<T>(data);
		if (first == nullptr)
		{
			first = padre;
			padre->l.Add(temp);
			temp->l.Add(padre);
		}
		else if (padre != NULL)
		{
			padre->l.Add(temp);
			temp->l.Add(padre);
		}
	}
	catch (std::exception & e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}


}

/**
* crea una conxión entre 2 nodos
*
* @param hijo Es el hijo(Existente)
* @param padre Es el padre(Existente)
*/
template <class T>
void Grafo<T>::insertaNodo(NodoG<T>* hijo, NodoG<T>* padre)
{
	try
	{
		if (first == nullptr)
		{
			first = padre;
		}
		if (padre->l.Search(hijo) == false && hijo->l.Search(padre) == false)
		{
			if (padre != NULL)
			{
				padre->l.Add(hijo);
				hijo->l.Add(padre);
			}
		}
		else
		{
			int x = 0;
			throw x;
		}
	}
	catch (int x)
	{
		std::cout << "EXEPTION: A caray, ya tienes esa conxión pero solo de un lado osea que se rompio" << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}


/**
* Borra el hijo de la lista de un padre
*
* @param hijo Es el hijo(Existente)
* @param padre Es el padre(Existente)
*/
template <class T>
void Grafo<T>::Deletefromlist(T val, NodoG<T>* head)
{
	try
	{
		for (int i = 0; i <= head->l.size; i++)
		{
			if (head->l.advance(i)->nodoData == val)
			{
				head->l.Delete_at(i - 2);
			}
		}
	}
	catch (std::exception & e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

/**
* Busca el elemento con el valor especificado
*
* @param data Es el valor del elemento que se desea encontrar
* @return NodoG<T>*
*/
template <class T>
NodoG<T>* Grafo<T>::buscaNodo(T data)
{
	NodoG<T>* temp = searchSons(data, first);
	ALLVISITED = !ALLVISITED;
	return temp;
}

/**
* No usar esta función duera de la clase
*
*/
template <class T>
NodoG<T>* Grafo<T>::searchSons(T data, NodoG<T>* padre)
{
	try
	{
		if (ALLVISITED)
		{
			padre->visited = false;
			if (padre->nodoData == data)
			{
				return padre;
			}
			else
			{
				for (int i = 0; i < padre->l.size; i++)
				{
					if (padre->l.advance(i)->visited == true)
					{
						if (searchSons(data, padre->l.advance(i)) != nullptr)
						{
							return searchSons(data, padre->l.advance(i));
						}
					}
					else
					{
						return nullptr;
					}
				}
			}
			
		}
		else
		{
			padre->visited = true;
			if (padre->nodoData == data)
			{
				return padre;
			}
			else
			{
				for (int i = 0; i < padre->l.size; i++)
				{
					if (padre->l.advance(i)->visited == false)
					{
						if (searchSons(data, padre->l.advance(i)) != nullptr)
						{
							return searchSons(data, padre->l.advance(i));
						}
					}
					else
					{
						return nullptr;
					}
				}
			}
			
		}
	}
	catch (std::exception & e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

/**
* Elimina el elemento con el valor especificado
*
* @param data Es el valor del elemento que se desea eliminar
*/
template <class T>
void Grafo<T>::eliminaNodo(T data)
{	
	try
	{
		NodoG<T>* del = first;
		if (del->l.advance(0)->l.size > 1)
		{
			NodoG<T>* temp = del->l.advance(1);
			NodoG<T>* temp2 = del->l.advance(2);

			insertaNodo(temp, temp2);
			insertaNodo(temp, first);
			Deletefromlist(data, del->l.advance(0));
			Deletefromlist(data, del);
		}
		else
		{			
			Deletefromlist(data, del);
		}

	}
	catch (std::exception & e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

/**
* Imprime los valores del grafo
*
* @param Null
*/
template <class T>
void Grafo<T>::imprimeGrafo()
{
	printsons(first, ALLVISITED);
	ALLVISITED = !ALLVISITED;
}

/**
* No usar esta función fuera de la clase
*
*/
template <class T>
void Grafo<T>::printsons(NodoG<T>* padre, bool allvisited)
{
	try
	{
		if (ALLVISITED)
		{
			int _counter = 0;
			padre->visited = false;
			std::cout << padre->nodoData << "{";
			for (int i = 0; i < padre->l.size; i++)
			{
				if (padre->l.advance(i)->visited == true)
				{
					_counter--;
					printsons(padre->l.advance(i), ALLVISITED);
				}
				else
				{
					std::cout << "}";
				}
			}
		}
		else
		{
			int _counter = 0;
			padre->visited = true;
			std::cout << padre->nodoData << "{";
			for (int i = 0; i < padre->l.size; i++)
			{
				if (padre->l.advance(i)->visited == false)
				{
					_counter--;
					printsons(padre->l.advance(i), ALLVISITED);
				}
				else
				{
					std::cout << "}";
				}
			}
		}
	}
	catch (std::exception & e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

template <class T>
NodoG<T>* Grafo<T>::GetNodo(int x)
{
	NodoG<T>* it = first;
	for (int i = 0; i < x; i++)
	{
		it = it->l.first->value;
	}
	return it;
}

template<class T>
inline void Grafo<T>::CreateGrid()
{
	/*ListaT<ListaT<NodoG<T>*>*> nodos;*/
	/*for (int i = 0; i < 8; i++)
	{
		nodos.push_back(new ListaT<NodoG<T>*>);
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			nodos.GetAt(i)->PushAt(j, new NodoG(Vec2(i, j)));
			if (i > 0)		connectnodos(nodos.GetAt(i - 1)->GetAt(j), nodos.GetAt(i)->GetAt(j));
			if (i < x - 1)	connectnodos(nodos.GetAt(i + 1)->GetAt(j), nodos.GetAt(i)->GetAt(j));
			if (j > 0)		connectnodos(nodos.GetAt(i)->GetAt(j - 1), nodos.GetAt(i)->GetAt(j));
			if (j < y - 1)	connectnodos(nodos.GetAt(i)->GetAt(j + 1), nodos.GetAt(i)->GetAt(j));
		}
	}
	root = nodos.GetAt(0)->GetAt(0);*/
}

template<class T>
NodoG<T>* Grafo<T>::GetNodoAt(int x, int y)
{
	int y2 = 0;
	int x2 = 0;
	NodoG<T>* it = first;
	bool search2 = false;
	while (search2 == false)
	{
		if (it->x == x)
		{
			search2 = true;
		}
		else if (it->l.first->value->x == x2 + 1)
		{
			it = it->l.first->value;
		}
		else if (it->l.first->next->value->x == x2 + 1)
		{
			it = it->l.first->next->value;
		}
		else if (it->l.first->next->next->value->x == x2 + 1)
		{
			it = it->l.first->next->next->value;
		}
		else if (it->l.first->next->next->next->value->x == x2 + 1)
		{
			it = it->l.first->next->next->next->value;
		}
		x2++;
	}


	bool search = false;
	while (search == false)
	{
		if (it->y == y && it->x == x)
		{
			search = true;
		}
		else if (it->l.first->value->y == y2 + 1)
		{
			it = it->l.first->value;
		}
		else if (it->l.first->next->value->y == y2 + 1)
		{
			it = it->l.first->next->value;
		}
		else if (it->l.first->next->next->value->y == y2 + 1)
		{
			it = it->l.first->next->next->value;
		}
		else if (it->l.first->next->next->next->value->y == y2 + 1)
		{
			it = it->l.first->next->next->next->value;
		}
		y2++;
	}
	return it;
}