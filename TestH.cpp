#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include "graphics.h"
#pragma comment(lib, "graphics.lib")

using namespace std;

#define Ground 500

struct Point
{
	int x, y;
};
void boundaryFill(int x, int y, int f_color, int b_color) {
	if (getpixel(x, y) != f_color && getpixel(x, y) != b_color)
	{
		putpixel(x, y, f_color);
		boundaryFill(x + 1, y, f_color, b_color);
		boundaryFill(x, y + 1, f_color, b_color);
		boundaryFill(x - 1, y, f_color, b_color);
		boundaryFill(x, y - 1, f_color, b_color);
	}
}
void lineDDA(Point a, Point b, int color) {
	int dx = b.x - a.x, dy = b.y - a.y;
	float step = max(abs(dx), abs(dy));
	float x_inc = dx / step, y_inc = dy / step;
	float x = a.x, y = a.y;
	putpixel(x, y, color);
	int k = 1;
	while (k <= step) {
		x += x_inc;
		y += y_inc;
		putpixel(x, y, color);
		k++;
	}
}
void drawGround() {
	Point a, b;
	a.x = 50;
	a.y = Ground;
	b.x = 750;
	b.y=Ground;
	lineDDA(a, b, WHITE);
}
void drawSnowFlake(Point a) {
	Point list[8];
	list[0].x = a.x; 
	list[0].y = a.y - 7;
	list[1].x = a.x + 7;
	list[1].y = a.y;
	list[2].x = a.x;
	list[2].y = a.y + 7;
	list[3].x = a.x - 7;
	list[3].y = a.y;
	list[4].x = a.x + 4;
	list[4].y = a.y - 4;
	list[5].x = a.x + 4;
	list[5].y = a.y + 4;
	list[6].x = a.x - 4;
	list[6].y = a.y + 4;
	list[7].x = a.x - 4;
	list[7].y = a.y - 4;

	lineDDA(list[0], list[2], WHITE);
	lineDDA(list[1], list[3], WHITE);
	lineDDA(list[4], list[6], WHITE);
	lineDDA(list[5], list[7], WHITE);
}
Point randomSnow() {
	Point a;
	a.x = rand() % 740 + 60;
	a.y = rand() % 400 + 10;
	return a;
}
void drawSnowDune(Point a) {
	arc(a.x, Ground, 0, 180, 20);
	boundaryFill(a.x, Ground - 2, WHITE, WHITE);
}
void snowDrop(Point a) {
	while (a.y < Ground - 4) {
		drawGround();
		cleardevice();
		a.y += 10;
		delay(20);
		drawSnowFlake(a);
	}
	cleardevice();
	drawGround();
	drawSnowDune(a);
}

void main()
{
	initwindow(800, 600, "VeLaCo");
	drawGround();
	for (int i = 0; i < 5; i++) {
		Point a = randomSnow();
		drawSnowFlake(a);
		snowDrop(a);
	}
	
	
	delay(90000);
	closegraph();

}