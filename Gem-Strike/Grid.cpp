#include "Grid.h"

void Grid::CreateGrid()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			NodoG<Gem>* gem01 = new NodoG<Gem>(Gem(i, i, j), i, j);
			//grafoGem.insertaNodo(gem01);
		}
	}
}