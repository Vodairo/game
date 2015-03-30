#include "map.h"

Hexagon::Hexagon(int posX, int posY, int posZ)
	: FPosX(posX)
	, FPosY(posY)
	, FPosZ(posZ)
{
	FState = HexagonState::EMPTY;
}

Grid::Grid(int sizeX, int sizeY, int sizeZ)
	: FSizeX(sizeX)
	, FSizeY(sizeY)
	, FSizeZ(sizeZ)
{
	FGrid[0][0][0] = new Hexagon(0, 0, 0);
	FOR2D(x, y, sizeX, sizeY)
		FGrid[x][y][0] = new Hexagon(x, y, 0);
	FOR2D(z, x, sizeX, sizeZ)
		FGrid[x][0][z] = new Hexagon(x, 0, z);
	FOR2D(y, z, sizeY, sizeZ)
		FGrid[0][y][z] = new Hexagon(0, y, z);
}