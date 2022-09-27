#include <stdio.h>
#include<conio.h>
#include "graphics.h"
#pragma comment(lib, "graphics.lib")

int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	int x = 100;
	int y = 100;
	while (true)
	{
		circle(x, y, 50);
		setfillstyle(5, 4);
		floodfill(x, y, 15);
		delay(500);
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			system("cls");
			getmouseclick(WM_MOUSEMOVE, x, y);
			printf("Current mouse position: (%d, %d)\n", x, y);
		}
		if(ismouseclick(WM_LBUTTONUP)) {
			break;
		}
		cleardevice();
		
	}

	closegraph();
	return 0;
}