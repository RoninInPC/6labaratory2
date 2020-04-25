#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include"world.h"
void hidecursor() {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}
World MakeFullWorld(int NumberOfString, int NumberOfColumn) {
	int** Ans = (int**)malloc(NumberOfString * sizeof(int*));
	for (int i = 0; i < NumberOfString; i++) {
		Ans[i] = (int*)malloc(NumberOfColumn * sizeof(int));
		for (int j = 0; j < NumberOfColumn; j++) {
			Ans[i][j] = 35;
		}
	}
	World w;
	w.Arr = Ans;
	w.NumOfStr = NumberOfString;
	w.NumOfCol = NumberOfColumn;
	return w;
}
void PrintfWorld(World world, int Time) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position;
	position.X = 0;
	position.Y = 0;
	SetConsoleCursorPosition(hConsole, position);
	for (int i = 0; i < world.NumOfStr; i++) {
		for (int j = 0; j < world.NumOfCol; j++) {
			printf("%c", world.Arr[i][j]);
		}
		printf("\n");
	}
	Sleep(Time);
}