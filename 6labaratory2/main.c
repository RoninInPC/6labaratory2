#include<stdio.h>
#include<Windows.h>
#include<math.h>
#include"logic.h"
#include"randnumber.h"
#include"world.h"
int main() {
	hidecursor();
	HWND hwnd;
	char Title[1024];
	GetConsoleTitle(Title, 1024); // Узнаем имя окна
	hwnd = FindWindow(NULL, Title); // Узнаем hwnd окна
	HDC hdc = GetDC(hwnd);
	printf("Write Size of box: NumberOfString and NumberOfColumn\n");
	int NumberOfString;
	int NumberOfColumn;
	scanf_s("%d %d", &NumberOfString, &NumberOfColumn);
	int size = 2*(int)sqrt(NumberOfString * NumberOfColumn);
	printf("Write Time\n");
	int Time;
	scanf_s("%d", &Time);
	system("cls");
	while (1) {
		World W1 = MakeFullWorld(NumberOfString, NumberOfColumn);
		Point* points = MakePointsInWorld(15, W1);
		FreeAllPoints(&W1, points, 15);
		for (int i = 0; i < NumberOfString; i++) {
			for (int j = 0; j < NumberOfColumn; j++) {
				if (W1.Arr[i][j] == 35) {
					Ellipse(hdc, (i + 1) * 20, (j + 1) * 20, i * 20, j * 20);
				}
			}
		}
		Sleep(Time*10);
		system("cls");
	}
	return 0;
}