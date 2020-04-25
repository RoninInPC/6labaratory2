#include"world.h"
#include"randnumber.h"
#include<stdio.h>
#include<stdlib.h>
void FreePointToPoint(World* world, Point one, Point two) {
	Point Head = one;
	while (1) {
		int x = two.x - Head.x;
		int y = two.y - Head.y;
		int Cx = 1;
		int Cy = 1;
		if (x < 0)Cx = -1;
		if (y < 0)Cy = -1;
		if (x == 0)Cx = 0;
		if (y == 0)Cy = 0;
		world->Arr[Head.x][Head.y] = 32;
		Head.x = Head.x + Cx;
		world->Arr[Head.x][Head.y] = 32;
		Head.y = Head.y + Cy;
		if (x == 0 && y == 0) break;
	}
}
void FreeAllPoints(World* world, Point* points,int size) {
	for (int i = 0; i < size-1; i++) {
		for (int j = i + 1; j < size; j++) {
			FreePointToPoint(world, points[i], points[j]);
		}
	}
}