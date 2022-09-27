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
Point LL[2];
Point RL[2];

void opening();
void drawHead(Point H[]);
void drawBody();
void drawLeftHand(Point LH[]);
void drawRightHand(Point RH[]);
void drawLeftLeg(Point LL[]);
void drawRightLeg(Point RL[]);
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
	drawRightHand(RH);
	LL[0].x = 400; LL[0].y = 370;
	drawLeftLeg(LL);
	RL[0].x = 500; RL[0].y = 370;
	drawRightLeg(RL);
	delay(2000);
	cleardevice();

	//Part
	srand(time(NULL));
	B[0].x = 350, B[0].y = 240;
	//Draw Random
	H[0].x = rand() % (850 - 100 + 1) + 100; H[0].y = rand() % (600 - 100 + 1) + 100;
	LH[0].x = rand() % (850 - 100 + 1) + 100; LH[0].y = rand() % (600 - 100 + 1) + 100;
	RH[0].x = rand() % (850 - 100 + 1) + 100; RH[0].y = rand() % (600 - 100 + 1) + 100;
	LL[0].x = rand() % (850 - 100 + 1) + 100; LL[0].y = rand() % (600 - 100 + 1) + 100;
	RL[0].x = rand() % (850 - 100 + 1) + 100; RL[0].y = rand() % (600 - 100 + 1) + 100;
	delay(1500);
	
	cleardevice();
	drawBody();
	drawHead(H);
	drawLeftHand(LH);
	drawRightHand(RH);
	drawLeftLeg(LL);
	drawRightLeg(RL);
	int page = 0;
	do{
		while(H[0].x != 400 && H[0].y != 150)
		{
			if(ismouseclick(WM_LBUTTONUP))
			{
				getmouseclick(WM_LBUTTONUP, H[0].x, H[0].y); //Head
				drawBody();
				drawHead(H);
				drawLeftHand(LH);
				drawRightHand(RH);
				drawLeftLeg(LL);
				drawRightLeg(RL);
				delay(50);
				cleardevice();
				while(H[0].x >= 387 && H[0].x <= 403 && H[0].y >= 147 && H[0].y <= 153)
				{
					//cleardevice();
					H[0].x = 400, H[0].y = 150;
					//clearmouseclick(WM_LBUTTONDOWN);
					drawHead(H);
					drawBody();
					//getch();
					//clearmouseclick(WM_LBUTTONDOWN);
					//drawBody();
					//drawHead(H);
					drawLeftHand(LH);
					drawRightHand(RH);
					drawLeftLeg(LL);
					drawRightLeg(RL);
					getch();
					break;
				}
			}
			//break;
		}
		/*while(H[0].x != 400 && H[0].y != 150)
		{
			if (ismouseclick(WM_LBUTTONUP))
				{
					getmouseclick(WM_MOUSEMOVE, H[0].x, H[0].y);
					drawBody();
					drawHead(H);
					drawLeftHand(LH);
					drawRightHand(RH);
					drawLeftLeg(LL);
					drawRightLeg(RL);
					delay(100);
					cleardevice();
				}
		}*/
		while(LH[0].x != 300 && LH[0].y != 250)
		{
			if (ismouseclick(WM_LBUTTONUP))
			{
				getmouseclick(WM_LBUTTONUP, LH[0].x, LH[0].y); // Left Hand
				drawBody();
				drawHead(H);
				drawLeftHand(LH);
				drawRightHand(RH);
				drawLeftLeg(LL);
				drawRightLeg(RL);
				delay(50);
				cleardevice();
				while (LH[0].x >= 287 && LH[0].x <= 303 && LH[0].y >= 247 && LH[0].y <= 253)
				{
					//cleardevice();
					LH[0].x = 300, LH[0].y = 250;
					//clearmouseclick(WM_LBUTTONDOWN);
					drawLeftHand(LH);
					drawHead(H);
					drawBody();
					//getch();
					//clearmouseclick(WM_LBUTTONDOWN);
					//drawBody();
					//drawHead(H);
					//drawLeftHand(LH);
					drawRightHand(RH);
					drawLeftLeg(LL);
					drawRightLeg(RL);
					break;
				}
			}
		}
		while(RH[0].x != 550 && RH[0].y != 250)
		{
			if (ismouseclick(WM_LBUTTONUP))
			{
				getmouseclick(WM_LBUTTONUP, RH[0].x, RH[0].y); // Right Hand
				drawBody();
				drawHead(H);
				drawLeftHand(LH);
				drawRightHand(RH);
				delay(50);
				cleardevice();
				while (RH[0].x >= 547 && RH[0].x <= 553 && RH[0].y >= 247 && RH[0].y <= 253)
				{
					//cleardevice();
					RH[0].x = 550, RH[0].y = 250;
					//clearmouseclick(WM_LBUTTONDOWN);
					drawRightHand(RH);
					drawLeftHand(LH);
					drawHead(H);
					drawBody();
					getch();
					//clearmouseclick(WM_LBUTTONDOWN);
					drawBody();
					drawHead(H);
					drawLeftHand(LH);
					drawRightHand(RH);
					drawLeftLeg(LL);
					break;
				}
			}
		}
		//while(LL[0].x != 400 && LL[0].y != 370)
		//{
		//	if (ismouseclick(WM_LBUTTONDOWN))
		//	{
		//		getmouseclick(WM_MOUSEMOVE, LL[0].x, LL[0].y); // Left Leg
		//		drawBody();
		//		drawHead(H);
		//		drawLeftHand(LH);
		//		drawRightHand(RH);
		//		drawLeftLeg(LL);
		//		delay(50);
		//		cleardevice();
		//		while (LL[0].x >= 397 && LL[0].x <= 403 && LL[0].y >= 369 && LL[0].y <= 373)
		//		{
		//			cleardevice();
		//			LL[0].x = 400, LL[0].y = 370;
		//			clearmouseclick(WM_LBUTTONDOWN);
		//			drawLeftLeg(LL);
		//			drawRightHand(RH);
		//			drawLeftHand(LH);
		//			drawHead(H);
		//			drawBody();
		//			getch();
		//			//clearmouseclick(WM_LBUTTONDOWN);
		//			drawBody();
		//			drawHead(H);
		//			drawLeftHand(LH);
		//			drawRightHand(RH);
		//			drawLeftLeg(LL);
		//			drawRightLeg(RL);
		//			break;
		//		}
		//	}
		//}
		//while(RL[0].x != 500 && RL[0].y != 370)
		//{
		//	if (ismouseclick(WM_LBUTTONDOWN))
		//	{
		//		getmouseclick(WM_MOUSEMOVE, RL[0].x, RL[0].y); // Left Leg
		//		drawBody();
		//		drawHead(H);
		//		drawLeftHand(LH);
		//		drawRightHand(RH);
		//		drawLeftLeg(LL);
		//		drawLeftLeg(RL);
		//		delay(50);
		//		cleardevice();
		//		while (RL[0].x >= 497 && RL[0].x <= 503 && RL[0].y >= 369 && RL[0].y <= 373)
		//		{
		//			cleardevice();
		//			RL[0].x = 500, RL[0].y = 370;
		//			clearmouseclick(WM_LBUTTONDOWN);
		//			drawRightLeg(RL);
		//			drawLeftLeg(LL);
		//			drawRightHand(RH);
		//			drawLeftHand(LH);
		//			drawHead(H);
		//			drawBody();
		//			getch();
		//			//clearmouseclick(WM_LBUTTONDOWN);
		//			/*drawBody();
		//			drawHead(H);
		//			drawLeftHand(LH);
		//			drawRightHand(RH);
		//			drawLeftLeg(LL);
		//			drawRightLeg(RL);*/
		//			break;
		//		}
		//	}
		//}
		//cleardevice();
		//drawBody();
		//drawHead(H);
		//drawLeftHand(LH);
		//drawRightHand(RH);
		//drawLeftLeg(LL);
		//drawRightLeg(RL);
		//if (H[0].x == 400 && H[0].y == 150 && LH[0].x == 300 && LH[0].y == 250 && RH[0].x == 550 && RH[0].y == 250 && LL[0].x == 400 && LL[0].y == 370 && RL[0].x == 500 && RL[0].y == 370)
		//	break;
	}while(H[0].x != 400 && H[0].y != 150 && LH[0].x != 300 && LH[0].y != 250 && RH[0].x != 550 && RH[0].y != 250 && LL[0].x != 400 && LL[0].y != 370 && RL[0].x != 500 && RL[0].y != 370);
	getch();
	ending();
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
void drawRightHand(Point RH[])
{
	RH[1].x = RH[0].x + 50; RH[1].y = RH[0].y + 16;
	setfillstyle(1, 3);
	bar(RH[0].x, RH[0].y, RH[1].x, RH[1].y);
	setfillstyle(1, 3);
	bar(RH[1].x, RH[0].y + 16, RH[1].x - 16, RH[0].y + 80);
	setfillstyle(1, 4);
	pieslice(RH[1].x - 8, RH[0].y + 90, 320, 220, 17);
}
void drawLeftLeg(Point LL[])
{
	
	//Left leg
	setfillstyle(1, 3);
	bar(LL[0].x, LL[0].y, LL[0].x + 18, LL[0].y + 90);
	setfillstyle(1, 4);
	bar(LL[0].x - 15,LL[0].y + 90, LL[0].x + 28, LL[0].y + 108);
}
void drawRightLeg(Point RL[])
{
	//Right Leg
	setfillstyle(1, 3);
	bar(RL[0].x, RL[0].y, RL[0].x - 18, RL[0].y + 90);
	setfillstyle(1, 4);
	bar(RL[0].x + 15,RL[0].y + 90, RL[0].x - 28, RL[0].y + 108);
}
void move(Point p)
{

}

void ending()
{
	int midx = 900 / 2;
	int midy = 700 / 2;
	cleardevice();
	setcolor(15);
	settextstyle(3, 0, 5);
	settextjustify(1, 1);
	outtextxy(midx, midy, "Press any key to exit");
}