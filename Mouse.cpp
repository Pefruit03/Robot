/* mouse example */ 
#include<iostream>
#include<conio.h>
#include "graphics.h"
#pragma comment (lib, "graphics.lib")

using namespace std;

void main(void) 
{ 
	const int LIMIT = 10; // Number of clicks to stop program. 
	int maxx, maxy; // Maximum x and y pixel coordinates 
	int count = 0; // Number of mouse clicks 
	int divisor; // Divisor for the length of a triangle side 
	 // Put the machine into graphics mode and get the maximum coordinates: 
	initwindow(450, 300); 
	maxx = getmaxx( ); 
	maxy = getmaxy( ); 
	// Draw a white circle with red inside and a radius of 50 pixels: 
	setfillstyle(SOLID_FILL, RED); 
	setcolor(WHITE); 
	fillellipse(maxx/2, maxy/2, 50, 50); 
 
	// Print a message and wait for a red pixel to be double clicked: 
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 2); 
	outtextxy(20, 20, "Left click times to end."); 
	setcolor(BLUE); 
	divisor = 2; 
	while (count < LIMIT) 
	{ 
		circle(maxx/divisor, maxy/divisor, 50); 
		delay(500); 
		divisor++; 
		if (ismouseclick(WM_LBUTTONDOWN)) 
		{ 
			clearmouseclick(WM_LBUTTONDOWN); 
			count++; 
		} 
	} 
	// Switch back to text mode: 
	closegraph( ); 
}