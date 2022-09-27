#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<dos.h>
#include"graphics.h"
#pragma comment (lib, "graphics.lib")

using namespace std;
struct Point
{
	int x, y;
};
Point H[2];
Point B[2];
Point LH[2];
Point RH[2];
Point L[3];

void opening();
void drawHead(Point H[]);
void drawBody();
void drawLeftHand(Point LH[]);
void drawRightHand();
void drawLeftLeg();
void drawRightLeg();
void move(Point p);
void ending();

int main() 
{
	//int gd = DETECT, gm;
	//initgraph( &gd, &gm, "c:\\tc\\bgi");
	initwindow(900, 700, "Robot");
	//Gioi thieu
	opening();
	//Ve robot
	H[0].x = 400, H[0].y = 150;
	drawHead(H);
	B[0].x = 350, B[0].y = 240;
	drawBody();
	LH[0].x = 300; LH[0].y = 250;
	drawLeftHand(LH);
	RH[0].x = 550; RH[0].y = 250;
	drawRightHand();
	L[0].x = 400; L[0].y = 370;
	drawLeftLeg();
	L[1].x = 500; L[1].y = 370;
	drawRightLeg();
	delay(2000);
	cleardevice();

	//Part
	srand(time(NULL));
	//Lock Body
	B[0].x = 350, B[0].y = 240;
	drawBody();
	//Draw Random
	H[0].x = rand() % 700; H[0].y = rand() % 700;
	//drawHead(H);
	LH[0].x = rand() % 700; LH[0].y = rand() % 700;
	//drawLeftHand();
	RH[0].x = rand() % 700; RH[0].y = rand() % 700;
	//drawRightHand();
	L[0].x = rand() % 700; L[0].y = rand() % 700;
	//drawLeftLeg();
	L[1].x = rand() % 700; L[1].y = rand() % 700;
	//drawRightLeg();
	delay(1500);
	
	cleardevice();
	drawBody();
	drawHead(H);
	do{
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			while(H[0].x != 400 && H[0].y != 150)
			{
				getmouseclick(WM_MOUSEMOVE, H[0].x, H[0].y);
				cleardevice();
				drawBody();
				drawHead(H);
				delay(50);
				cleardevice();
				if(H[0].x >= 387 && H[0].x <= 403 && H[0].y >= 147 && H[0].y <= 153)
				{
					cleardevice();
					H[0].x = 400, H[0].y = 150;
					drawHead(H);
					drawBody();
					//clearmouseclick(WM_MOUSEMOVE);
					getch();
				}
				//delay(1000);
			}
			
			/*cleardevice();
			delay(50);
			drawBody();
			drawHead(H);*/
			drawLeftHand(LH);
			clearmouseclick(WM_MOUSEMOVE);
			while(LH[0].x != 300 && LH[0].y != 250)
			{
				//clearmouseclick(WM_MOUSEMOVE);
				getmouseclick(WM_MOUSEMOVE, LH[0].x, LH[0].y);
				cleardevice();
				drawBody();
				drawHead(H);
				drawLeftHand(LH);
				delay(50);
				cleardevice();
				if (H[0].x >= 287 && H[0].x <= 303 && H[0].y >= 247 && H[0].y <= 253)
				{
					cleardevice();
					LH[0].x = 300, LH[0].y = 250;
					drawHead(H);
					drawBody();
					drawLeftHand(LH);
					getch();
				}
			}
		}
		
	}while(H[0].x != 400 && H[0].y != 150 && LH[0].x != 300 && LH[0].y != 250 && RH[0].x != 550 && RH[0].y != 250 && L[0].x != 400 && L[0].y != 370 && L[1].x != 500 && L[1].y != 370);
	//ending();
	getch();
	closegraph();
}

void opening()
{
	int midx = 900 / 2;
	int midy = 700 / 2;
	setcolor(WHITE);
	settextstyle(3, 0, 5);
	settextjustify(1, 1);
	outtextxy(midx, midy - 30, "Assemble Robot");
	outtextxy(midx, midy + 30, "Press any key to start");
	getch();
	cleardevice();
}

void drawHead(Point H[])
{
	H[1].x = H[0].x + 100; H[1].y = H[0].y + 50;
	//Head
	setfillstyle(1, 4);
	circle(H[0].x + 50, H[0].y, 15);
	floodfill(H[0].x + 50, H[0].y, 15);
	setfillstyle(1, 8);
	bar(H[0].x, H[0].y, H[1].x, H[1].y);
	setfillstyle(1, 3);
	bar(H[0].x + 45, H[0].y - 15, H[0].x + 55, H[0].y - 40);
	setfillstyle(1, 4);
	circle(H[0].x + 50, H[0].y - 47, 9);
	floodfill(H[0].x + 50, H[0].y - 47, 15);
	//Neck
	int nx = (H[0].x + H[1].x) / 2, ny = H[1].y;
	setfillstyle(1, 3);
	bar(nx - 7, ny, nx + 7, ny + 40);
	//Eyes
	setfillstyle(1,YELLOW);
	circle(H[0].x + 20, H[0].y + 15, 10);
	floodfill(H[0].x + 20, H[0].y + 15, 15);
	setfillstyle(1,YELLOW);
	circle(H[1].x - 20, H[0].y + 15, 10);
	floodfill(H[1].x - 20, H[0].y + 15, 15);
	//Mounth
	setfillstyle(1, 10);
	bar(H[0].x + 20, H[1].y - 18, H[1].x - 20, H[1].y - 8);
}
void drawBody()
{
	B[1].x = B[0].x + 200, B[1].y = B[0].y + 130;
	//Hop ngoai
	setfillstyle(1, 7);
	bar(B[0].x, B[0].y, B[1].x, B[1].y);
	//Hop trong
	setfillstyle(1, 13);
	bar(B[0].x + 15, B[0].y + 15, B[0].x + 145, B[0].y + 115);
	//In hop trong
	setfillstyle(1, 2);
	bar(B[0].x + 30, B[0].y + 30, B[0].x + 80, B[0].y + 102);
	setfillstyle(1, 4);
	bar(B[0].x + 30, B[0].y + 54, B[0].x + 80, B[0].y + 102);
	setfillstyle(1, 3);
	bar(B[0].x + 30, B[0].y + 78, B[0].x + 80, B[0].y + 102);
	setfillstyle(1, 9);
	circle(B[0].x + 115, B[0].y + 50, 12);
	floodfill(B[0].x + 115, B[0].y + 50, 15);
	setfillstyle(1, 9);
	circle(B[0].x + 115, B[0].y + 80, 12);
	floodfill(B[0].x + 115, B[0].y + 80, 15);
	//2 circle
	setfillstyle(1, 13);
	circle(B[0].x + 173, B[0].y + 45, 17);
	floodfill(B[0].x + 173, B[0].y + 45, 15);
	setfillstyle(1, 13);
	circle(B[0].x + 173, B[0].y + 90, 17);
	floodfill(B[0].x + 173, B[0].y + 90, 15);
}
void drawLeftHand(Point LH[])
{
	LH[1].x = LH[0].x + 50, LH[1].y = LH[0].y + 16;
	setfillstyle(1, 3);
	bar(LH[0].x, LH[0].y, LH[1].x, LH[1].y);
	setfillstyle(1, 3);
	bar(LH[0].x, LH[0].y + 16, LH[0].x + 16, LH[0].y + 80);
	setfillstyle(1, 4);
	pieslice(LH[0].x + 8, LH[0].y + 90, 320, 220, 17);
}
void drawRightHand()
{
	RH[1].x = RH[0].x + 50; RH[1].y = RH[0].y + 16;
	setfillstyle(1, 3);
	bar(RH[0].x, RH[0].y, RH[1].x, RH[1].y);
	setfillstyle(1, 3);
	bar(RH[1].x, RH[0].y + 16, RH[1].x - 16, RH[0].y + 80);
	setfillstyle(1, 4);
	pieslice(RH[1].x - 8, RH[0].y + 90, 320, 220, 17);
}
void drawLeftLeg()
{
	
	//Left leg
	setfillstyle(1, 3);
	bar(L[0].x, L[0].y, L[0].x + 18, L[0].y + 90);
	setfillstyle(1, 4);
	bar(L[0].x - 15,L[0].y + 90, L[0].x + 28, L[0].y + 108);
}
void drawRightLeg()
{
	//Right Leg
	setfillstyle(1, 3);
	bar(L[1].x, L[1].y, L[1].x - 18, L[1].y + 90);
	setfillstyle(1, 4);
	bar(L[1].x + 15,L[1].y + 90, L[1].x - 28, L[1].y + 108);
}
void move(Point p)
{

}
void ending()
{
	int midx = 700 / 2;
	int midy = 700 / 2;
	cleardevice();
	setcolor(15);
	settextstyle(3, 0, 5);
	settextjustify(1, 1);
	outtextxy(midx + 70, midy + 15, "Press any key to exit");
	delay(1000);
}