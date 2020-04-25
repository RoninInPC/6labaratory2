#include<stdio.h>
#include<time.h>
#include"world.h"
Point MakePoint(World world,int i) {
	srand(i * time(NULL));
	Point Ans;
	Ans.x = rand() % world.NumOfStr;
	Ans.y = rand() % world.NumOfCol;
	return Ans;
}
Point* MakePointsInWorld(int Size, World world) {
	Point* Ans = (Point*)malloc(Size * sizeof(Point));
	for (int j = 0; j < Size; j++) {
		while (1) {
			Ans[j] = MakePoint(world, j);
			if (world.Arr[Ans[j].x][Ans[j].y] == 35) break;
		}
	}
	return Ans;
}