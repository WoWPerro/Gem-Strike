#pragma once
#include "Grafo.h"
#include "Gem.h"

class Grid
{
public:
	ListaT<Gem*> ToDeletelist;
	Grafo <Gem> grafoGem;
	ListaT<ListaT<NodoG<Gem>*>*> listaGemas;
	NodoG<Gem>* gem00 = new NodoG<Gem>(Gem(0, 0, 0), 0, 0);
	void CreateGrid();
	Image GetImage(int x, int y);
	void UpdateGems(int x, int y);
	Gem* GetGemAt(int x, int y);
	void CheckExplotions();
	void Check(int i, int j);
	bool FinishExplotions;
private:
	void Conections();
};