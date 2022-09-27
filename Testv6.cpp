#include<string>
#include<iostream>
#include<cmath>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"graphics.h"
#pragma comment (lib, "graphics.lib")
using namespace std;
#define Round(a) (int)(a + 0.5)//DDA

struct Point
{
	int x, y, x1, y1, x2, y2, color, R, WID, HEI, luachon, Check;
};
Point list_begin[100];
Point p[19];
int page = 0;

//Mo dau
void opening();
//Thuat toan ve duong thang lineDDA
void lineDDA(int x1, int y1, int x2, int y2, int color );
//Ham ve 8 diem doi xuwng
void put8pixel(int xc, int yc, int x, int y,int luachon, int color);
//Ham ve duong tron
void drawCircleMidpoint(int x0, int y0, int r,int luachon, int color);
//Ham ve hinh vuong chu nhat
void drawHCN_HV(int x, int y, int wid, int hei, int color);
//Ham khoi tao gia tri ban dau
void Hinhtrondautien(int x, int y, int color);
void Hinhchunhatdautien(int x, int y, int color);
void Motnuaduongtron(int x, int y, int color);
void Mat(int x, int y, int color);
void Khopco1(int x, int y, int color);
void Khopco2(int x, int y, int color);
void Bung(int x, int y, int color);
void Dui(int x, int y, int color);
void Duitren(int x, int y, int color);
void Goi(int x, int y, int color);
void Cangchan(int x, int y, int color);
void Banchan(int x, int y, int color);
void Cotay(int x,int y,int color);
void Baptay(int x, int y, int color);
void Khuyutay(int x, int y, int color);
void Tai(int x, int y, int color);
void Eyes(int x, int y, int color);
void Mieng(int x, int y, int color);
void Bantay(int x, int y, int color);
//Ham hien thi man hinh ban dau chua robot.
void drawDisplay(int color);
//Ham giup random cac so trong mot khoang
int randomx();
int randomy();
//Ham random cac bo phan cua robot 
void Randombophan(int color);
//Ve het cac bo phan
void drawAll(int color);
//Code bat su kien chuot
void mouse();
//Ket thuc
void ending();

int main()
{
	//int gd = DETECT, gm;
	//initgraph(&gd, &gm, "c:\\tc\\bgi");
	initwindow(1280, 720,"ROBOT", 0, 0);
	srand(time(NULL));
    
	//Mo dau
	opening();

	drawDisplay(10);//ve con robot cho nguoi dung nhin
	delay(1000);
	
	//random bo phan
	Randombophan(15);

	//Code bat su kien chuot trong graphics.h
	mouse();
	cleardevice();
	drawAll(15);
	getch();

	//Ket thuc
	ending();

    getch();
	closegraph();
	return 0;
}

void opening()
{
	int midx = getmaxx() / 2;
	int midy = getmaxy() / 2;
	setcolor(WHITE);
	settextstyle(3, 0, 5);
	settextjustify(1, 1);
	outtextxy(midx, midy - 30, "Assemble Robot");
	outtextxy(midx, midy + 30, "Press any key to start");
	getch();
	cleardevice();
}
void lineDDA(int x1, int y1, int x2, int y2, int color )
{
	int Dx = x2 - x1, Dy = y2 - y1;
	float x_inc, y_inc;
	float step = max (abs(Dx),abs(Dy));
	x_inc = Dx / step;
	y_inc = Dy / step;
	float x = x1, y = y1;
	putpixel(x,y,color);
	int k = 1; 
	while(k <= step)
	{
		k++;
		x = x + x_inc;
		y = y + y_inc;
		putpixel(Round(x),Round(y),color);
	}
	return;
}
void put8pixel(int xc, int yc, int x, int y,int luachon, int color)
{
	if (luachon == 0)
	{
		//ve mot nua ben duoi
		putpixel(x + xc, y + yc, color);
		putpixel(-x + xc, y + yc, color);
		putpixel( y + xc, x + yc, color);
		putpixel(-y + xc, x + yc, color);
	}
	else
	{
		//ve mot nua ben tren
		if(luachon==1)
		{
			putpixel(x + xc, -y + yc, color);	
			putpixel(-x + xc, -y + yc, color);
			putpixel(y + xc, -x + yc, color);
			putpixel(-y + xc, -x + yc, color);	
		}
		else
		{
			if(luachon==2)
			{
				//ve toan duong tron.
				putpixel(x + xc, y + yc, color);
				putpixel(-x + xc, y + yc, color);
				putpixel(x + xc, -y + yc, color);
				putpixel(-x + xc, -y + yc, color);
				putpixel( y + xc, x + yc, color);
				putpixel(-y + xc, x + yc, color);
				putpixel(y + xc, -x + yc, color);
				putpixel(-y + xc, -x + yc, color);
			}
		}
	}
}
void drawCircleMidpoint(int x0, int y0, int r,int luachon, int color)
{
	int x = 0;
	int y = r;
	int p = 5 / 4 - r;
	put8pixel(x0, y0, x, y, luachon, color);
	while (x < y)
	{
		if (p < 0)
			p += 2 * x + 3;
		else
		{
			p += 2 * (x - y) + 5;
			y -= 1;
		}
		x++;
		put8pixel(x0, y0, x, y, luachon, color);
	}
}
void drawHCN_HV(int x, int y, int wid, int hei, int color)
{
	// x, y, H lan luot la toa do diem thu 1 va khoang cach
	lineDDA(x, y, x + wid, y, color);
	lineDDA(x + wid, y, x + wid, y + hei, color);
	lineDDA(x + wid, y + hei, x, y + hei, color);
	lineDDA(x, y + hei, x, y, color);
}
void Hinhtrondautien(int x, int y, int color)
{
	x = p[0].x, y = p[0].y;
    //hinh tron dau tien 
	setfillstyle(1, 4);
	drawCircleMidpoint(x, y, 10, 2, color);
	//circle(x, y, 10);
	floodfill(x + 1, y + 1, 15);
}
void Hinhchunhatdautien(int x, int y, int color)
{
	x = p[1].x, y = p[1].y;
	//hcn dau tien
	setfillstyle(1, 3);
	drawHCN_HV(x, y, 5, 40, color);
	floodfill(x + 1, y + 1, 15);
}
void Motnuaduongtron(int x, int y, int color)
{
	x = p[2].x, y = p[2].y;
	//mot nua duong tron
	drawCircleMidpoint(x, y, 40, 1, color);
}
void Mat(int x, int y, int color)
{
	x = p[3].x, y = p[3].y;
	//drawHCN_HV(x, y, 200, 100, color);
	setfillstyle(1, 8);
	rectangle(x, y, x + 200, y + 100);
	floodfill(x + 1, y + 1, 15);
}
void Khopco1(int x, int y, int color)
{
	x = p[4].x, y = p[4].y;
	//khop co 1
	setfillstyle(1, 3);
	drawHCN_HV(x, y, 120, 10, color);
	floodfill(x + 1, y + 1, 15);
}
void Khopco2(int x, int y, int color)
{
	x = p[5].x, y = p[5].y;
	//khop co 2
	setfillstyle(1, 13);
	drawHCN_HV(x, y, 100, 20, color);
	floodfill(x + 1, y + 1, 15);
}
void Bung(int x, int y, int color)
{
	x = p[6].x, y = p[6].y;
	//bung
	setfillstyle(1, 8);
	drawHCN_HV(x, y, 260, 180, color);
	floodfill(x + 1, y + 1, 15);
}
void Dui(int x, int y, int color)
{
	x = p[7].x, y = p[7].y;
	//dui
	setfillstyle(1, 7);
	drawHCN_HV(x, y, 220, 80, color);
	floodfill(x + 1, y + 1, 15);
}
void Duitren(int x, int y, int color)
{
	x = p[8].x, y = p[8].y;
	//dui tren 
	setfillstyle(1, 4);
	drawHCN_HV(x, y, 40, 60, color);
	floodfill(x + 1, y + 1, 15);
	setfillstyle(1, 4);
	drawHCN_HV(x + 120, y, 40, 60, color);
	floodfill(x + 121, y + 1, 15);
}
void Goi(int x, int y, int color)
{
	x = p[9].x, y = p[9].y;
	//goi
	setfillstyle(1, 2);
	drawHCN_HV(x, y, 60, 20, 15);
	floodfill(x + 1, y + 1, 15);
	setfillstyle(1, 2);
	drawHCN_HV(x + 120, y, 60, 20, 15);
	floodfill(x + 121, y + 1, 15);
}
void Cangchan(int x, int y, int color)
{
	x = p[10].x, y = p[10].y;
	//cang chan
	setfillstyle(1, 6);
	drawHCN_HV(x, y, 40, 120, color);
	floodfill(x + 1, y + 1, 15);
	setfillstyle(1, 6);
	drawHCN_HV(x + 120, y, 40, 120, color);
	floodfill(x + 121, y + 1, 15);
}
void Banchan(int x, int y, int color)
{
	x = p[11].x, y = p[11].y;
	 //ban chan
	setfillstyle(1, 4);
	drawHCN_HV(x, y, 80, 29, color);
	floodfill(x + 1, y + 1, 15);
	setfillstyle(1, 4);
	drawHCN_HV(x + 160, y, 80, 29, color);
	floodfill(x + 161, y + 1, 15);
}
void Cotay(int x,int y,int color)
{
	x = p[12].x, y = p[12].y;
	//co tay
	drawHCN_HV(x, y, -10, 30, color);
	drawHCN_HV(x + 260, y, 10, 30, color);
}
void Baptay(int x, int y, int color)
{
	x = p[13].x, y = p[13].y;
	//Bap tay
	setfillstyle(1, 13);
	drawHCN_HV(x, y, 59, 100, color);
	floodfill(x + 1, y + 1, 15);
	setfillstyle(1, 13);
	drawHCN_HV(x + 339, y, 59, 100, color);
	floodfill(x + 340, y + 1, 15);
}
void Khuyutay(int x, int y, int color)
{
	x = p[14].x, y = p[14].y;
	//Khuuy tay
	setfillstyle(1, 1);
	drawHCN_HV(x, y, 40, 190, color);
	floodfill(x + 1, y + 1, 15);
	setfillstyle(1, 1);
	drawHCN_HV(x + 320, y, 40, 190, color);
	floodfill(x + 321, y + 1, 15);
}
void Tai(int x, int y, int color)
{
	x = p[15].x, y = p[15].y;
	//Tai 
	setfillstyle(1,3);
	drawHCN_HV(x, y, -20, 60, color);
	floodfill(x - 1, y + 1, 15);
	setfillstyle(1,3);
	drawHCN_HV(x + 200, y, 20, 60, color);
	floodfill(x + 201, y + 1, 15);
}
void Eyes(int x, int y, int color)
{
	x = p[16].x, y = p[16].y;
	//Mat
	setfillstyle(1, 10);
	drawCircleMidpoint(x, y, 30, 2, color);
	floodfill(x + 1, y + 1, 15);
	setfillstyle(1, 10);
	drawCircleMidpoint(x + 100, y, 30, 2, color);
	floodfill(x + 101, y + 1, 15);
}
void Mieng(int x, int y, int color)
{
	x = p[17].x, y = p[17].y;
	//Mieng
	setfillstyle(1, 4);
	drawHCN_HV(x, y, 100, 20, color);
	floodfill(x + 1, y + 1, 15);
}
void Bantay(int x, int y, int color)
{
	x = p[18].x, y = p[18].y;
	setfillstyle(1, 4);
	pieslice(x, y, 320, 220, 35);
	pieslice(x + 320, y, 320, 220, 35);
}
void drawDisplay(int color)
{
	//Ve man hinh chua noi lap rap robot.
	lineDDA(0,0,400,0,color);
	lineDDA(400,0,400,720,color);
	lineDDA(400,720,0,720,color);
	lineDDA(0,720,0,0,color);
	//-----
	
	//hinh tron dau tien 
	drawCircleMidpoint(200,10,10,2,15); 
	list_begin[0].x=200;
	list_begin[0].y=10;
	list_begin[0].luachon=2;
	list_begin[0].color=15;
	list_begin[0].R=10;
	
	//hcn dau tien 
	drawHCN_HV(198,20,5,40,15);
	list_begin[1].x=198;
	list_begin[1].y=20;
	list_begin[1].WID=5;
	list_begin[1].HEI=40;
	list_begin[1].color=15;

	//mot nua duong tron
	drawCircleMidpoint(200,100,40,1,15);
	lineDDA(160,100,240,100,15);
	list_begin[2].luachon=1;
	list_begin[2].color=15;
	list_begin[2].x=200;
	list_begin[2].y=100;
	list_begin[2].R=40;
	list_begin[3].x1=160;
	list_begin[3].y1=100;
	list_begin[3].x2=240;
	list_begin[3].y2=100;
	list_begin[3].color=15;

	//mat
	drawHCN_HV(100,100,200,100,15);
	list_begin[4].x=100;
	list_begin[4].y=100;
	list_begin[4].WID=200;
	list_begin[4].HEI=100;
	list_begin[4].color=15;

	//khop co 1
	drawHCN_HV(140,200,120,10,15);
	list_begin[5].x=140;
	list_begin[5].y=200;
	list_begin[5].WID=120;
	list_begin[5].HEI=10;
	list_begin[5].color=15;

	//khop co 2
	drawHCN_HV(150,210,100,20,15);
	list_begin[6].x=150;
	list_begin[6].y=210;
	list_begin[6].WID=100;
	list_begin[6].HEI=20;
	list_begin[6].color=15;

	//bung
	drawHCN_HV(70,230,260,180,15);
	list_begin[7].x=70;
	list_begin[7].y=230;
	list_begin[7].WID=260;
	list_begin[7].HEI=180;
	list_begin[7].color=15;
	
	//dui
	drawHCN_HV(90,410,220,80,15);
	list_begin[8].x=90;
	list_begin[8].y=410;
	list_begin[8].WID=220;
	list_begin[8].HEI=80;
	list_begin[8].color=15;

	//dui tren 
	drawHCN_HV(120,490,40,60,15);
	drawHCN_HV(240,490,40,60,15);
	list_begin[9].x=120;
	list_begin[9].y=490;
	list_begin[9].WID=40;
	list_begin[9].HEI=60;
	list_begin[9].color=15;
	list_begin[10].x=240;
	list_begin[10].y=490;
	list_begin[10].WID=40;
	list_begin[10].HEI=60;
	list_begin[10].color=15;

	//goi
	drawHCN_HV(110,550,60,20,15);
	drawHCN_HV(230,550,60,20,15);
	list_begin[11].x=110;
	list_begin[11].y=550;
	list_begin[11].WID=60;
	list_begin[11].HEI=20;
	list_begin[11].color=15;
	list_begin[12].x=230;
	list_begin[12].y=550;
	list_begin[12].WID=60;
	list_begin[12].HEI=20;
	list_begin[12].color=15;

	//cang chan
	drawHCN_HV(120,570,40,120,15);
	drawHCN_HV(240,570,40,120,15);
	list_begin[13].x=120;
	list_begin[13].y=570;
	list_begin[13].WID=40;
	list_begin[13].HEI=120;
	list_begin[13].color=15;
	list_begin[14].x=240;
	list_begin[14].y=570;
	list_begin[14].WID=40;
	list_begin[14].HEI=120;
	list_begin[14].color=15;

	//ban chan 
	drawHCN_HV(80,690,80,29,15);
	drawHCN_HV(240,690,80,29,15);
	list_begin[15].x=80;
	list_begin[15].y=690;
	list_begin[15].WID=80;
	list_begin[15].HEI=29;
	list_begin[15].color=15;
	list_begin[16].x=240;
	list_begin[16].y=690;
	list_begin[16].WID=80;
	list_begin[16].HEI=29;
	list_begin[16].color=15;

	//co tay 
	drawHCN_HV(70,240,-10,30,15);
	drawHCN_HV(330,240,10,30,15);
	list_begin[17].x =70;
	list_begin[17].y=240;
	list_begin[17].WID= -10;
	list_begin[17].HEI = 30;
	list_begin[17].color = 15;
	list_begin[18].x= 330;
	list_begin[18].y =240;
	list_begin[18].WID =10;
	list_begin[18].HEI =30;
	list_begin[18].color  =15;
       
	//Bap tay
	drawHCN_HV(1,200,59,100,15);
	drawHCN_HV(340,200,59,100,15);
	list_begin[19].x =1;
	list_begin[19].y =200;
	list_begin[19].WID=59;
	list_begin[19].HEI= 100;
	list_begin[19].color =15;
	list_begin[20].x =340;
	list_begin[20].y =200;
	list_begin[20].WID =59;
	list_begin[20].HEI =100;
	list_begin[20].color =15;

	//Khuuy tay
	drawHCN_HV(20,300,40,190,15);
	drawHCN_HV(340,300,40,190,15);
	list_begin[21].x =20;
	list_begin[21].y =300;
	list_begin[21].WID =40;
	list_begin[21].HEI =190;
	list_begin[21].color =15;
	list_begin[22].x=340;
	list_begin[22].y =300;
	list_begin[22].WID=40;
	list_begin[22].HEI =190;
	list_begin[22].color =15;

	//Tai 
	drawHCN_HV(100,120,-20,60,15);
	drawHCN_HV(300,120,20,60,15);
	list_begin[35].x=100;
	list_begin[35].y=120;
	list_begin[35].WID=-20;
	list_begin[35].HEI=60;
	list_begin[35].color=15;
	list_begin[36].x=300;
	list_begin[36].y=120;
	list_begin[36].WID=20;
	list_begin[36].HEI=60;
	list_begin[36].color=15;
	
	//Mat 
	drawCircleMidpoint(150,150,30,2,15);
	drawCircleMidpoint(250,150,30,2,15);
	list_begin[37].x =150;
	list_begin[37].y =150;
	list_begin[37].R =30;
	list_begin[37].luachon =2;
	list_begin[37].color =15;
	list_begin[38].x=250;
	list_begin[38].y =150;
	list_begin[38].R =30;
	list_begin[38].luachon= 2;
	list_begin[38].color= 15;
	
	//Mieng
	drawHCN_HV(150,180,100,20,15);
	list_begin[39].x =150;
	list_begin[39].y =180;
	list_begin[39].WID=100;
	list_begin[39].HEI =20;
	list_begin[39].color =15;

	//Ban tay ben trai
	setfillstyle(1, 0);
	pieslice(40, 490, 320, 220, 35);

	//Ban tay ben trai
	setfillstyle(1, 0);
	pieslice(360, 490, 320, 220, 35);
}
int randomx()
{
    return (rand() % (1100 + 1 - 500) + 500);
}
int randomy()
{
	return (rand() % (650 + 1 - 100) + 100);
}
void Randombophan(int color)
{
	for (int i = 0; i < 19; i++)
		p[i].x = randomx();
	for (int j = 0; j < 19; j++)
		p[j].y = randomy();
}
void drawAll(int color)
{
	Hinhtrondautien(p[0].x, p[0].y, color);
	Hinhchunhatdautien(p[1].x, p[1].y, color);
	Motnuaduongtron(p[2].x, p[2].y, color);
	Mat(p[3].x, p[3].y, color);
	Khopco1(p[4].x, p[4].y, color);
	Khopco2(p[5].x, p[5].y, color);
	Bung(p[6].x, p[6].y, color);
	Dui(p[7].x, p[7].y, color);
	Duitren(p[8].x, p[8].y, color);
	Goi(p[9].x, p[9].y, color);
	Cangchan(p[10].x, p[10].y, color);
	Banchan(p[11].x, p[11].y, color);
	Cotay(p[12].x, p[12].y, color);
	Baptay(p[13].x, p[13].y, color);
	Khuyutay(p[14].x, p[14].y, color);
	Tai(p[15].x, p[15].y, color);
	Eyes(p[16].x, p[16].y, color);
	Mieng(p[17].x, p[17].y, color);
	Bantay(p[18].x, p[18].y, color);
}
void mouse()
{
		//part 1 - Hinhtrondautien
next1:
	cleardevice();
	drawAll(15);
	drawDisplay(10);
	while (true)
	{
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_MOUSEMOVE, p[0].x, p[0].y);
			setactivepage(page);
			setvisualpage(1 - page);
			cleardevice();
			Hinhtrondautien(p[0].x, p[0].y, 15);
			//drawAll(15);
			drawDisplay(10);
			delay(1);
		   	if(ismouseclick(WM_LBUTTONUP))
			{
				getmouseclick(WM_LBUTTONUP, p[0].x, p[0].y);
				//Hinhtrondautien(p[0].x, p[0].y, 15);
				//setactivepage(0);
				goto a;
			}
			page = 1 - page;
		}
	}
a:
	if ((p[0].x >= 202 || p[0].x <= 198) && (p[0].y >= 12 || p[0].y <= 8))
		goto next1;
	else
	{
		setactivepage(0);
		cleardevice();
		p[0].x = 200, p[0].y = 10;
		drawDisplay(10);
		drawAll(15);
		getch();
		clearmouseclick(WM_MOUSEMOVE);
		clearmouseclick(WM_LBUTTONUP);
		clearmouseclick(WM_LBUTTONDOWN);
		goto next2;
	}
	//part 2 - Hinhchunhatdautien
next2:
	while (true)
	{
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_MOUSEMOVE, p[1].x, p[1].y);
			setactivepage(page);
			setvisualpage(1 - page);
			cleardevice();
			Hinhchunhatdautien(p[1].x, p[1].y, 15);
			//drawAll(15);
			drawDisplay(10);
			delay(1);
			//cleardevice();
		   	if(ismouseclick(WM_LBUTTONUP))
			{
				getmouseclick(WM_LBUTTONUP, p[1].x, p[1].y);
				//Hinhchunhatdautien(p[1].x, p[1].y, 15);
				//setactivepage(0);
				goto b;
			}
			page = 1 - page;
		}
	}
b:
	if ((p[1].x <= 196 || p[1].x >= 200) && (p[1].y <= 18 || p[1].y >= 22))
		goto next2;
	else
	{
		setactivepage(0);
		cleardevice();
		p[1].x = 198, p[1].y = 20;
		drawDisplay(10);
		drawAll(15);
		getch();
		clearmouseclick(WM_MOUSEMOVE);
		clearmouseclick(WM_LBUTTONUP);
		clearmouseclick(WM_LBUTTONDOWN);
		goto next3;
	}
	//part 3 - Motnuaduongtron
next3:
	while (true)
	{
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_MOUSEMOVE, p[2].x, p[2].y);
			setactivepage(page);
			setvisualpage(1 - page);
			cleardevice();
			Motnuaduongtron(p[2].x, p[2].y, 15);
			drawDisplay(10);
			delay(1);
		   	if(ismouseclick(WM_LBUTTONUP))
			{
				getmouseclick(WM_LBUTTONUP, p[2].x, p[2].y);
				//Motnuaduongtron(p[2].x, p[2].y, 15);
				goto c;
			}
			page = 1 - page;
		}
	}
c:
	if ((p[2].x >= 202 || p[2].x <= 198) && (p[2].y >= 102 || p[2].y <= 98))
		goto next3;
	else
	{
		setactivepage(0);
		cleardevice();
		p[2].x = 200, p[2].y = 100;
		drawDisplay(10);
		drawAll(15);
		getch();
		clearmouseclick(WM_MOUSEMOVE);
		clearmouseclick(WM_LBUTTONUP);
		clearmouseclick(WM_LBUTTONDOWN);
		goto next4;
	}
	//part 4 - Mat
next4:
	while (true)
	{
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_MOUSEMOVE, p[3].x, p[3].y);
			setactivepage(page);
			setvisualpage(1 - page);
			cleardevice();
			Mat(p[3].x, p[3].y, 15);
			drawDisplay(10);
			delay(1);
		   	if(ismouseclick(WM_LBUTTONUP))
			{
				getmouseclick(WM_LBUTTONUP, p[3].x, p[3].y);
				//Motnuaduongtron(p[3].x, p[3].y, 15);
				goto d;
			}
			page = 1 - page;
		}
	}
d:
	if ((p[3].x >= 102 || p[3].x <= 98) && (p[3].y >= 102 || p[3].y <= 98))
		goto next4;
	else
	{
		setactivepage(0);
		cleardevice();
		p[3].x = 100, p[3].y = 100;
		drawDisplay(10);
		drawAll(15);
		getch();
		clearmouseclick(WM_MOUSEMOVE);
		clearmouseclick(WM_LBUTTONUP);
		clearmouseclick(WM_LBUTTONDOWN);
		goto next5;
	}
	//part 5 - Khop co 1
next5:
	while (true)
	{
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_MOUSEMOVE, p[4].x, p[4].y);
			setactivepage(page);
			setvisualpage(1 - page);
			cleardevice();
			Khopco1(p[4].x, p[4].y, 15);
			drawDisplay(10);
			delay(1);
		   	if(ismouseclick(WM_LBUTTONUP))
			{
				getmouseclick(WM_LBUTTONUP, p[4].x, p[4].y);
				//Khopco1(p[4].x, p[4].y, 15);
				goto e;
			}
			page = 1 - page;
		}
	}
e:
	if ((p[4].x >= 142 || p[4].x <= 138) && (p[4].y >= 202 || p[4].y <= 198))
		goto next5;
	else
	{
		setactivepage(0);
		cleardevice();
		p[4].x = 140, p[4].y = 200;
		drawDisplay(10);
		drawAll(15);
		getch();
		clearmouseclick(WM_MOUSEMOVE);
		clearmouseclick(WM_LBUTTONUP);
		clearmouseclick(WM_LBUTTONDOWN);
		goto next6;
	}
	//part 6 - Khop co 2
next6:
	while (true)
	{
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_MOUSEMOVE, p[5].x, p[5].y);
			setactivepage(page);
			setvisualpage(1 - page);
			cleardevice();
			Khopco2(p[5].x, p[5].y, 15);
			drawDisplay(10);
			delay(1);
		   	if(ismouseclick(WM_LBUTTONUP))
			{
				getmouseclick(WM_LBUTTONUP, p[5].x, p[5].y);
				//Khopco2(p[5].x, p[5].y, 15);
				goto f;
			}
			page = 1 - page;
		}
	}
f:
	if ((p[5].x >= 152 || p[5].x <= 148) && (p[5].y >= 212 || p[5].y <= 208))
		goto next6;
	else
	{
		setactivepage(0);
		cleardevice();
		p[5].x = 150, p[5].y = 210;
		drawDisplay(10);
		drawAll(15);
		getch();
		clearmouseclick(WM_MOUSEMOVE);
		clearmouseclick(WM_LBUTTONUP);
		clearmouseclick(WM_LBUTTONDOWN);
		goto next7;
	}
	//part 7 - Bung
next7:
	while (true)
	{
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_MOUSEMOVE, p[6].x, p[6].y);
			setactivepage(page);
			setvisualpage(1 - page);
			cleardevice();
			Bung(p[6].x, p[6].y, 15);
			drawDisplay(10);
			delay(1);
		   	if(ismouseclick(WM_LBUTTONUP))
			{
				getmouseclick(WM_LBUTTONUP, p[6].x, p[6].y);
				//Bung(p[6].x, p[6].y, 15);
				goto g;
			}
			page = 1 - page;
		}
	}
g:
	if ((p[6].x >= 72 || p[6].x <= 68) && (p[6].y >= 232 || p[6].y <= 228))
		goto next7;
	else
	{
		setactivepage(0);
		cleardevice();
		p[6].x = 70, p[6].y = 230;
		drawDisplay(10);
		drawAll(15);
		getch();
		clearmouseclick(WM_MOUSEMOVE);
		clearmouseclick(WM_LBUTTONUP);
		clearmouseclick(WM_LBUTTONDOWN);
		goto next8;
	}
	//part 8 - Dui
next8:
	while (true)
	{
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_MOUSEMOVE, p[7].x, p[7].y);
			setactivepage(page);
			setvisualpage(1 - page);
			cleardevice();
			Dui(p[7].x, p[7].y, 15);
			drawDisplay(10);
			delay(1);
		   	if(ismouseclick(WM_LBUTTONUP))
			{
				getmouseclick(WM_LBUTTONUP, p[7].x, p[7].y);
				//Dui(p[7].x, p[7].y, 15);
				goto h;
			}
			page = 1 - page;
		}
	}
h:
	if ((p[7].x >= 92 || p[7].x <= 88) && (p[7].y >= 412 || p[7].y <= 408))
		goto next8;
	else
	{
		setactivepage(0);
		cleardevice();
		p[7].x = 90, p[7].y = 410;
		drawDisplay(10);
		drawAll(15);
		getch();
		clearmouseclick(WM_MOUSEMOVE);
		clearmouseclick(WM_LBUTTONUP);
		clearmouseclick(WM_LBUTTONDOWN);
		goto next9;
	}
	//part 9 - Dui tren
next9:
	while (true)
	{
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_MOUSEMOVE, p[8].x, p[8].y);
			setactivepage(page);
			setvisualpage(1 - page);
			cleardevice();
			Duitren(p[8].x, p[8].y, 15);
			drawDisplay(10);
			delay(1);
		   	if(ismouseclick(WM_LBUTTONUP))
			{
				getmouseclick(WM_LBUTTONUP, p[8].x, p[8].y);
				//Duitren(p[8].x, p[8].y, 15);
				goto i;
			}
			page = 1 - page;
		}
	}
i:
	if ((p[8].x >= 122 || p[8].x <= 118) && (p[8].y >= 492 || p[8].y <= 488))
		goto next9;
	else
	{
		setactivepage(0);
		cleardevice();
		p[8].x = 120, p[8].y = 490;
		drawDisplay(10);
		drawAll(15);
		getch();
		clearmouseclick(WM_MOUSEMOVE);
		clearmouseclick(WM_LBUTTONUP);
		clearmouseclick(WM_LBUTTONDOWN);
		goto next10;
	}
	//part 10 - Goi
next10:
	while (true)
	{
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_MOUSEMOVE, p[9].x, p[9].y);
			setactivepage(page);
			setvisualpage(1 - page);
			cleardevice();
			Goi(p[9].x, p[9].y, 15);
			drawDisplay(10);
			delay(1);
		   	if(ismouseclick(WM_LBUTTONUP))
			{
				getmouseclick(WM_LBUTTONUP, p[9].x, p[9].y);
				//Goi(p[9].x, p[9].y, 15);
				goto j;
			}
			page = 1 - page;
		}
	}
j:
	if ((p[9].x >= 112 || p[9].x <= 108) && (p[9].y >= 552 || p[9].y <= 548))
		goto next10;
	else
	{
		setactivepage(0);
		cleardevice();
		p[9].x = 110, p[9].y = 550;
		drawDisplay(10);
		drawAll(15);
		getch();
		clearmouseclick(WM_MOUSEMOVE);
		clearmouseclick(WM_LBUTTONUP);
		clearmouseclick(WM_LBUTTONDOWN);
		goto next11;
	}
	//part 11 - Cang chan
next11:
	while (true)
	{
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_MOUSEMOVE, p[10].x, p[10].y);
			setactivepage(page);
			setvisualpage(1 - page);
			cleardevice();
			Cangchan(p[10].x, p[10].y, 15);
			drawDisplay(10);
			delay(1);
		   	if(ismouseclick(WM_LBUTTONUP))
			{
				getmouseclick(WM_LBUTTONUP, p[10].x, p[10].y);
				Cangchan(p[10].x, p[10].y, 15);
				goto k;
			}
			page = 1 - page;
		}
	}
k:
	if ((p[10].x >= 122 || p[10].x <= 118) && (p[10].y >= 572 || p[10].y <= 568))
		goto next11;
	else
	{
		setactivepage(0);
		cleardevice();
		p[10].x = 120, p[10].y = 570;
		drawDisplay(10);
		drawAll(15);
		getch();
		clearmouseclick(WM_MOUSEMOVE);
		clearmouseclick(WM_LBUTTONUP);
		clearmouseclick(WM_LBUTTONDOWN);
		goto next12;
	}
	//part 12 - Ban chan
next12:
	while (true)
	{
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_MOUSEMOVE, p[11].x, p[11].y);
			setactivepage(page);
			setvisualpage(1 - page);
			cleardevice();
			Banchan(p[11].x, p[11].y, 15);
			drawDisplay(10);
			delay(1);
		   	if(ismouseclick(WM_LBUTTONUP))
			{
				getmouseclick(WM_LBUTTONUP, p[11].x, p[11].y);
				//Banchan(p[4].x, p[4].y, 15);
				goto l;
			}
			page = 1 - page;
		}
	}
l:
	if ((p[11].x >= 82 || p[11].x <= 78) && (p[11].y >= 688 || p[11].y <= 692))
		goto next12;
	else
	{
		setactivepage(0);
		cleardevice();
		p[11].x = 80, p[11].y = 690;
		drawDisplay(10);
		drawAll(15);
		getch();
		clearmouseclick(WM_MOUSEMOVE);
		clearmouseclick(WM_LBUTTONUP);
		clearmouseclick(WM_LBUTTONDOWN);
		goto next13;
	}
	//part 13 - Co tay
next13:
	while (true)
	{
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_MOUSEMOVE, p[12].x, p[12].y);
			setactivepage(page);
			setvisualpage(1 - page);
			cleardevice();
			Cotay(p[12].x, p[12].y, 15);
			drawDisplay(10);
			delay(1);
		   	if(ismouseclick(WM_LBUTTONUP))
			{
				getmouseclick(WM_LBUTTONUP, p[12].x, p[12].y);
				//Cotay(p[12].x, p[12].y, 15);
				goto m;
			}
			page = 1 - page;
		}
	}
m:
	if ((p[12].x >= 72 || p[12].x <= 68) && (p[12].y >= 242 || p[12].y <= 238))
		goto next13;
	else
	{
		setactivepage(0);
		cleardevice();
		p[12].x = 70, p[12].y = 240;
		drawDisplay(10);
		drawAll(15);
		getch();
		clearmouseclick(WM_MOUSEMOVE);
		clearmouseclick(WM_LBUTTONUP);
		clearmouseclick(WM_LBUTTONDOWN);
		goto next14;
	}
	//part 14 - Bap tay
next14:
	while (true)
	{
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_MOUSEMOVE, p[13].x, p[13].y);
			setactivepage(page);
			setvisualpage(1 - page);
			cleardevice();
			Baptay(p[13].x, p[13].y, 15);
			drawDisplay(10);
			delay(1);
		   	if(ismouseclick(WM_LBUTTONUP))
			{
				getmouseclick(WM_LBUTTONUP, p[13].x, p[13].y);
				//Baptay(p[13].x, p[13].y, 15);
				goto n;
			}
			page = 1 - page;
		}
	}
n:
	if (p[13].x >= 3 && (p[13].y >= 202 || p[13].y <= 198))
		goto next14;
	else
	{
		setactivepage(0);
		cleardevice();
		p[13].x = 1, p[13].y = 200;
		drawDisplay(10);
		drawAll(15);
		getch();
		clearmouseclick(WM_MOUSEMOVE);
		clearmouseclick(WM_LBUTTONUP);
		clearmouseclick(WM_LBUTTONDOWN);
		goto next15;
	}
	//part 15 - Khuyu tay
next15:
	while (true)
	{
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_MOUSEMOVE, p[14].x, p[14].y);
			setactivepage(page);
			setvisualpage(1 - page);
			cleardevice();
			Khuyutay(p[14].x, p[14].y, 15);
			drawDisplay(10);
			delay(1);
		   	if(ismouseclick(WM_LBUTTONUP))
			{
				getmouseclick(WM_LBUTTONUP, p[14].x, p[14].y);
				//Khuyutay(p[4].x, p[4].y, 15);
				goto o;
			}
			page = 1 - page;
		}
	}
o:
	if ((p[14].x >= 22 || p[14].x <= 18) && (p[14].y >= 302 || p[14].y <= 298))
		goto next15;
	else
	{
		setactivepage(0);
		cleardevice();
		p[14].x = 20, p[14].y = 300;
		drawDisplay(10);
		drawAll(15);
		getch();
		clearmouseclick(WM_MOUSEMOVE);
		clearmouseclick(WM_LBUTTONUP);
		clearmouseclick(WM_LBUTTONDOWN);
		goto next16;
	}
	//part 16 - Tai
next16:
	while (true)
	{
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_MOUSEMOVE, p[15].x, p[15].y);
			setactivepage(page);
			setvisualpage(1 - page);
			cleardevice();
			Tai(p[15].x, p[15].y, 15);
			drawDisplay(10);
			delay(1);
		   	if(ismouseclick(WM_LBUTTONUP))
			{
				getmouseclick(WM_LBUTTONUP, p[15].x, p[15].y);
				//Tai(p[15].x, p[15].y, 15);
				goto p;
			}
			page = 1 - page;
		}
	}
p:
	if ((p[15].x >= 102 || p[15].x <= 98) && (p[15].y >= 122 || p[15].y <= 118))
		goto next16;
	else
	{
		setactivepage(0);
		cleardevice();
		p[15].x = 100, p[15].y = 120;
		drawDisplay(10);
		drawAll(15);
		getch();
		clearmouseclick(WM_MOUSEMOVE);
		clearmouseclick(WM_LBUTTONUP);
		clearmouseclick(WM_LBUTTONDOWN);
		goto next17;
	}
	//part 17 - Eyes
next17:
	while (true)
	{
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_MOUSEMOVE, p[16].x, p[16].y);
			setactivepage(page);
			setvisualpage(1 - page);
			cleardevice();
			Eyes(p[16].x, p[16].y, 15);
			drawDisplay(10);
			delay(1);
		   	if(ismouseclick(WM_LBUTTONUP))
			{
				getmouseclick(WM_LBUTTONUP, p[16].x, p[16].y);
				//Face(p[16].x, p[16].y, 15);
				goto q;
			}
			page = 1 - page;
		}
	}
q:
	if ((p[16].x >= 152 || p[16].x <= 148) && (p[16].y >= 152 || p[16].y <= 148))
		goto next17;
	else
	{
		setactivepage(0);
		cleardevice();
		p[16].x = 150, p[16].y = 150;
		drawDisplay(10);
		drawAll(15);
		getch();
		clearmouseclick(WM_MOUSEMOVE);
		clearmouseclick(WM_LBUTTONUP);
		clearmouseclick(WM_LBUTTONDOWN);
		goto next18;
	}
	//part 18 - Mieng
next18:
	while (true)
	{
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_MOUSEMOVE, p[17].x, p[17].y);
			setactivepage(page);
			setvisualpage(1 - page);
			cleardevice();
			Mieng(p[17].x, p[17].y, 15);
			drawDisplay(10);
			delay(1);
		   	if(ismouseclick(WM_LBUTTONUP))
			{
				getmouseclick(WM_LBUTTONUP, p[17].x, p[17].y);
				//Mieng(p[17].x, p[17].y, 15);
				goto r;
			}
			page = 1 - page;
		}
	}
r:
	if ((p[17].x >= 152 || p[17].x <= 148) && (p[17].y >= 182 || p[17].y <= 178))
		goto next18;
	else
	{
		setactivepage(0);
		cleardevice();
		p[17].x = 150, p[17].y = 180;
		drawDisplay(10);
		drawAll(15);
		getch();
		clearmouseclick(WM_MOUSEMOVE);
		clearmouseclick(WM_LBUTTONUP);
		clearmouseclick(WM_LBUTTONDOWN);
		goto next19;
	}
	//part 19 - Ban tay
next19:
	while (true)
	{
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_MOUSEMOVE, p[18].x, p[18].y);
			setactivepage(page);
			setvisualpage(1 - page);
			cleardevice();
			Bantay(p[18].x, p[18].y, 15);
			drawDisplay(10);
			delay(1);
		   	if(ismouseclick(WM_LBUTTONUP))
			{
				getmouseclick(WM_LBUTTONUP, p[18].x, p[18].y);
				//Bantay(p[17].x, p[17].y, 15);
				goto s;
			}
			page = 1 - page;
		}
	}
s:
	if ((p[18].x >= 42 || p[18].x <= 38) && (p[18].y >= 492 || p[18].y <= 488))
		goto next19;
	else
	{
		setactivepage(0);
		cleardevice();
		p[18].x = 40, p[18].y = 490;
		drawDisplay(10);
		drawAll(15);
		getch();
		clearmouseclick(WM_MOUSEMOVE);
		clearmouseclick(WM_LBUTTONUP);
		clearmouseclick(WM_LBUTTONDOWN);
		goto next20;
	}
next20:;
}
void ending()
{
	int midx = getmaxx() / 2;
	int midy = getmaxy() / 2;
	cleardevice();
	setcolor(15);
	settextstyle(3, 0, 5);
	settextjustify(1, 1);
	outtextxy(midx, midy, "Press any key to exit");
}