#ifndef H_WORLD
#define H_WORLD
typedef struct world {
	int** Arr;
	int NumOfStr;
	int NumOfCol;
}World;
typedef struct point {
	int x;
	int y;
}Point;
void hidecursor();
World MakeFullWorld(int NumberOfString, int NumberOfColumn);
void PrintfWorld(World world, int Time);
#endif