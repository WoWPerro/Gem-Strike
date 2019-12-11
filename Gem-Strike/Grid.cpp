#include "Grid.h"

void Grid::CreateGrid()
{
	int counter = 0;
	for (int i = 0; i < 8; i++)
	{
		ListaT<NodoG<Gem>*>* lista2 = new ListaT<NodoG<Gem>*>;
		for (int j = 0; j < 8; j++)
		{
			//NodoG<Gem>* gem = new NodoG<Gem>(Gem(i, i, j), i, j);
			lista2->push_back(new NodoG<Gem>(Gem(counter, i, j), i, j));
			counter++;
			if (counter == 7)
			{
				counter = 0;
			}
		}
		listaGemas.push_back(lista2);
	}
	Conections();
}

void Grid::Conections()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			//if (i != 0)
			//{
			//	grafoGem.insertaNodo(listaGemas.get_at(i - 1)->value->get_at(j)->value, listaGemas.get_at(i)->value->get_at(j)->value);
			//}
			//if (j != 0)
			//{
			//	grafoGem.insertaNodo(listaGemas.get_at(i)->value->get_at(j - 1)->value, listaGemas.get_at(i)->value->get_at(j)->value);
			//}
			if (i != 7)
			{
				grafoGem.insertaNodo(listaGemas.get_at(i + 1)->value->get_at(j)->value, listaGemas.get_at(i)->value->get_at(j)->value);
			}
			if (j != 7)
			{
				grafoGem.insertaNodo(listaGemas.get_at(i)->value->get_at(j + 1)->value, listaGemas.get_at(i)->value->get_at(j)->value);
			}
		}
	}
}

Image Grid::GetImage(int x, int y)
{
	//NodoG<Gem>* it = grafoGem.GetNodo(x);
	//for (int i = 0; i < y; i++)
	//{
	//	it = it->l.Get_at(1)->value;
	//}
	////return *grafoGem.GetNodo(x)->l.Get_at(y)->value->nodoData._actualImage;
	//return *it->nodoData._actualImage;
	return *grafoGem.GetNodoAt(x, y)->nodoData._actualImage;
}

void Grid::UpdateGems(int x, int y)
{
	//NodoG<Gem>* it = grafoGem.GetNodo(x);
	//for (int i = 0; i < y; i++)
	//{
	//	it = it->l.Get_at(1)->value;
	//}
	////return *grafoGem.GetNodo(x)->l.Get_at(y)->value->nodoData._actualImage;
	//it->nodoData.Update();
	//it->nodoData.Draw();

	grafoGem.GetNodoAt(x, y)->nodoData.Update();
	grafoGem.GetNodoAt(x, y)->nodoData.Draw();
}

Gem* Grid::GetGemAt(int x, int y)
{
	return &grafoGem.GetNodoAt(x, y)->nodoData;
}

void Grid::CheckExplotions()
{
	Check(0, 0);
}

void Grid::Check(int i, int j)
{
	Gem *gem = GetGemAt(i, j);
	gem->visited = true;
	if (gem->_type == GetGemAt(i + 1, j)->_type && gem->visited == false)
	{
		ToDeletelist.push_back(GetGemAt(i + 1, j));
	}
	if (gem->_type == GetGemAt(i - 1, j)->_type && gem->visited == false)
	{
		ToDeletelist.push_back(GetGemAt(i - 1, j));
	}
	if (gem->_type == GetGemAt(i, j + 1)->_type && gem->visited == false)
	{
		ToDeletelist.push_back(GetGemAt(i, j + 1));
	}
	if (gem->_type == GetGemAt(i, j - 1)->_type && gem->visited == false)
	{
		ToDeletelist.push_back(GetGemAt(i, j - 1));
	}
}