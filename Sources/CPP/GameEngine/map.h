#ifndef MAP_H
#define MAP_H

#include "GLFW/glfw3.h"

#include <vector>

#include "preprocessor.h"

enum HexagonState
{
	EMPTY,
	PLAYER
};

class Hexagon
{
public:
	Hexagon(int posX, int posY, int posZ);
	~Hexagon();

	int Update();
	void Draw();

private:
	int FPosX;
	int FPosY;
	int FPosZ;
	HexagonState FState;
};

class Grid
{
public:
	Grid(int sizeX, int sizeY, int sizeZ);
	~Grid();

	int Update();
	void Draw();

private:
	VECTOR3D(Hexagon*) FGrid;

	int FSizeX;
	int FSizeY;
	int FSizeZ;

};

#endif