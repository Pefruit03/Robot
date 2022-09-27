#include<string>
#include<iostream>
#include<cmath>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"graphics.h"
#pragma comment (lib, "graphics.lib")
#include<WinGDI.h>
using namespace std;
#define Round(a) (int)(a + 0.5)//DDA

struct Point{
	int x, y, x1, y1, x2, y2, color, R, WID, HEI, luachon, Check;
};
Point list_Save[100];
Point list_begin[100];
/*
//Thuat toan to mau ScanLineFill
void ScanLineFill(Point Tomau[],int v){
	int xmin,ymin,xmax,ymax;
	xmin=xmax=p[0].x;
}
*/
//Thuat toan ve duong thang lineDDA
void lineDDA(int x1,int y1,int x2,int y2,int color ){
     int Dx=x2-x1,Dy=y2-y1;
     float x_inc,y_inc;
     float step=max(abs(Dx),abs(Dy));
     x_inc=Dx/step;
     y_inc=Dy/step;
     float x=x1,y=y1;
     putpixel(x,y,color);
     int k=1; 
     while(k<=step){
     	k++;
     	x=x+x_inc;
     	y=y+y_inc;
     	putpixel(Round(x),Round(y),color);
	 }
	
	
	
	
	return;
}

//Tap cac ham dung ve duong tron 
  //Hàm v? 8 di?m d?i x?ng nhau
void put8pixel(int xc, int yc, int x, int y,int luachon, int color)
{
   if(luachon==0){
   	//ve mot nua ben duoi
    putpixel(x + xc, y + yc, color);
    putpixel(-x + xc, y + yc, color);
    putpixel( y + xc, x + yc, color);
    putpixel(-y + xc, x + yc, color);
}
else{
	//ve mot nua ben tren
	if(luachon==1){
	  putpixel(x + xc, -y + yc, color);	
	  putpixel(-x + xc, -y + yc, color);
	  putpixel(y + xc, -x + yc, color);
	  putpixel(-y + xc, -x + yc, color);	
	}
    else{
       if(luachon==2){
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
 //Hàm v? du?ng tròn 
 void drawCircleMidpoint(int xc, int yc, int r,int luachon, int color)
{
    int x = 0, y = r;
    int f = 1 - r;

    put8pixel(xc, yc, x, y,luachon, color);

    while (x < y)
    {
        if (f < 0) f += (x << 1) + 3;
        else
        {
            y--;
            f += ((x - y) << 1) + 5;
        }
        x++;
        put8pixel(xc, yc, x, y, luachon,color);
    }
}
//Ham ve hinh vuong chu nhat
void drawHCN_HV(int x,int y,int wid,int hei,int color){
	// x,y,H lan luot la toa do diem thu 1 va khoang cach
	    lineDDA(x,y,x+wid,y,color);
	    lineDDA(x+wid,y,x+wid,y+hei,color);
	    lineDDA(x+wid,y+hei,x,y+hei,color);
	    lineDDA(x,y+hei,x,y,color);
	    
	
}
//


//Ham khoi tao gia tri ban dau
void Hinhtrondautien(int x,int y,int color){
    	//hinh tron dau tien 
    drawCircleMidpoint(x,y,10,2,color); 
	}
void Hinhchunhatdautien(int x,int y,int color){
	 //hcn dau tien 
    drawHCN_HV(x,y,5,40,color);
}
void Motnuaduongtron(int x,int y,int color){
	//mot nua duong tron
	drawCircleMidpoint(x,y,40,1,color);
}
void Mat(int x,int y,int color){
	//mat
	drawHCN_HV(x,y,200,100,color);
}
void Khopco1(int x,int y,int color){
	//khop co 1
    drawHCN_HV(x,y,120,10,color);
    
}
void Khopco2(int x,int y,int color){
	//khop co 2
    drawHCN_HV(x,y,100,20,color);
    
}
void Bung(int x,int y,int color){
	  //bung
   drawHCN_HV(x,y,260,180,color);
}
void Dui(int x,int y,int color){
	 //dui
    drawHCN_HV(x,y,220,80,color);
}
void Duitren(int x1,int x2,int color){
	//dui tren 
    drawHCN_HV(x1,490,40,60,color);
    drawHCN_HV(x2,490,40,60,color);
}
void Goi(int x1,int x2,int color){
	//goi
	drawHCN_HV(x1,550,60,20,15);
	drawHCN_HV(x2,550,60,20,15);
}
void Cangchan(int x1,int x2,int color){
		//cang chan
	drawHCN_HV(x1,570,40,120,color);
	drawHCN_HV(x2,570,40,120,color);
}
void Banchan(int x1,int x2,int color){
	 //ban chan 
     drawHCN_HV(x1,690,80,29,color);
     drawHCN_HV(x2,690,80,29,color);
}
void Cotay(int x1,int x2,int color){
	 //co tay 
      drawHCN_HV(x1,240,-10,30,color);
      drawHCN_HV(x2,240,10,30,color);
}
void Baptay(int x1,int x2,int color){
	//Bap tay
      drawHCN_HV(x1,200,59,100,color);
      drawHCN_HV(x2,200,59,100,color);
}
void Khuyutay(int x1,int x2,int color){
	  //Khuuy tay
      drawHCN_HV(x1,300,40,190,color);
      drawHCN_HV(x2,300,40,190,color);
}
void Tai(int x1,int x2,int color){
	//Tai 
	     drawHCN_HV(x1,120,-20,60,color);
	     drawHCN_HV(x2,120,20,60,color);
}
void Face(int x1,int x2,int color){
	//Mat 
	    drawCircleMidpoint(x1,150,30,2,color);
	    drawCircleMidpoint(x2,150,30,2,color);
	
}
void Mieng(int x,int y,int color){
	    //Mieng
	    drawHCN_HV(x,y,100,20,color);
}
/*
void Taybentrai(int int int color){
	//Ban tay ben trai 
        lineDDA(1,580,1,490,15);
        lineDDA(1,490,78,490,15);
        lineDDA(78,490,78,540,15);
        lineDDA(1,580,25,580,15);
        lineDDA(25,580,25,520,15);
        lineDDA(25,520,78,540,15);
	 
}
void Taybenphai(int int int color){
	//Ban tay ben phai
	    lineDDA(399,580,399,490,15);
	    lineDDA(399,490,322,490,15);
	    lineDDA(322,490,322,540,15);
	    lineDDA(399,580,375,580,15);
	    lineDDA(375,580,375,520,15);
	    lineDDA(375,520,322,540,15);
}
*/
//Ham hien thi man hinh ban dau chua robot.
void drawDisplay(int color){
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
     
     
     //tap ngon tay
       //Ban tay ben trai 
        lineDDA(1,580,1,490,15);
        lineDDA(1,490,78,490,15);
         lineDDA(78,490,78,540,15);
        lineDDA(1,580,25,580,15);
        lineDDA(25,580,25,520,15);
        lineDDA(25,520,78,540,15);
     list_begin[23].x1=1;
     list_begin[23].y1=580;
     list_begin[23].x2=1;
     list_begin[23].y2=490;
     list_begin[23].color=15;
     list_begin[24].x1=1;
     list_begin[24].y1=490;
     list_begin[24].x2=78;
     list_begin[24].y2=490;
     list_begin[24].color=15;
     list_begin[25].x1=78;
     list_begin[25].y1=490;
     list_begin[25].x2=78;
     list_begin[25].y2=540;
     list_begin[25].color=15;
     list_begin[26].x1=1;
     list_begin[26].y1=580;
     list_begin[26].x2=25;
     list_begin[26].y2=580;
     list_begin[26].color=15;
     list_begin[27].x1=25;
     list_begin[27].y1=580;
     list_begin[27].x2=25;
     list_begin[27].y2=520;
     list_begin[27].color=15;
     list_begin[28].x1=25;
     list_begin[28].y1=520;
     list_begin[28].x2=78;
     list_begin[28].y2=540;
     list_begin[28].color=15;
	   //Ban tay ben phai
	    lineDDA(399,580,399,490,15);
	    lineDDA(399,490,322,490,15);
	    lineDDA(322,490,322,540,15);
	    lineDDA(399,580,375,580,15);
	    lineDDA(375,580,375,520,15);
	    lineDDA(375,520,322,540,15);
	     list_begin[29].x1=399;
     list_begin[29].y1=580;
     list_begin[29].x2=399;
     list_begin[29].y2=490;
     list_begin[29].color=15;
     list_begin[30].x1=399;
     list_begin[30].y1=490;
     list_begin[30].x2=322;
     list_begin[30].y2=490;
     list_begin[30].color=15;
     list_begin[31].x1=322;
     list_begin[31].y1=490;
     list_begin[31].x2=322;
     list_begin[31].y2=540;
     list_begin[31].color=15;
     list_begin[32].x1=399;
     list_begin[32].y1=580;
     list_begin[32].x2=375;
     list_begin[32].y2=580;
     list_begin[32].color=15;
     list_begin[33].x1=375;
     list_begin[33].y1=580;
     list_begin[33].x2=375;
     list_begin[33].y2=520;
     list_begin[33].color=15;
     list_begin[34].x1=375;
     list_begin[34].y1=520;
     list_begin[34].x2=322;
     list_begin[34].y2=540;
     list_begin[34].color=15;
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
}
//Ham giup random cac so trong mot khoang
int random(int minN, int maxN){
    return minN + rand() % (maxN + 1 - minN);
}
//Ham random cac bo phan cua robot 

void Randombophan(int a,int b,int color){

 //Ti le 1280x720 px
 int r1,r2=0;
  
    //srand(time(NULL));
    for(int i =0; i < 1; i++){
        r1 = random(a,b);
        r2 =random(a,b);
        Hinhtrondautien(r1,r2,color);
        cout<<r1<<""<<r2;
         r1 = random(a,b);
         r2 =random(a,b);
        Hinhchunhatdautien(r1,r2,color);
          r1 = random(a,b);
          r2 =random(a,b);
        Motnuaduongtron(r1,r2,color);
            r1 = random(a,b);
            r2 =random(a,b);
        Mat(r1,r2,color);
            r1 = random(a,b);
            r2 =random(a,b);
        Khopco1(r1,r2,color);
            r1 = random(a,b);
            r2 =random(a,b);
        Khopco2(r1,r2,color);
            r1 = random(a,b);
            r2 =random(a,b);
       Bung(r1,r2,color);
            r1 = random(a,b);
            r2 =random(a,b);
       Dui(r1,r2, color);
            r1 = random(a,b);
             r2 =random(a,b);
         Duitren(r1,r2, color);
           r1 = random(a,b);
            r2 =random(a,b); 
       Goi(r1,r2, color);
            r1 = random(a,b);
            r2 =random(a,b);
     Cangchan(r1,r2,color);
            r1 = random(a,b);
            r2 =random(a,b);
      Banchan(r1,r2, color);
            r1 = random(a,b);
            r2 =random(a,b);
      Cotay(r1,r2,color);
            r1 = random(a,b);
            r2 =random(a,b);
     Baptay(r1,r2,color);
          r1 = random(a,b);
            r2 =random(a,b);
     Khuyutay(r1,r2,color);
            r1 = random(a,b);
            r2 =random(a,b);
         Tai(r1,r2,color);
           r1 = random(a,b);
            r2 =random(a,b);
       Face(r1,r2,color);
            r1 = random(a,b);
            r2 =random(a,b);
        Mieng(r1,r2,color);

}
}




int main()
{
	//int gd = DETECT, gm;
	//initgraph(&gd, &gm, "c:\\tc\\bgi");
	initwindow(1280,720,"Robot",0,0);
	//Code bat su kien chuot trong graphics.h 
	
	getch();
    while (true)
	{
		int x, y;
		if (ismouseclick(WM_LBUTTONDOWN))
		{
		
			getmouseclick(WM_MOUSEMOVE, x, y);
		//	cout<<x<<"     "<<y;
			Motnuaduongtron(x,y,6);
		  cleardevice();
		   	if(ismouseclick(WM_LBUTTONUP)){
		   		getmouseclick(WM_LBUTTONUP, x, y );
		   		Motnuaduongtron(x,y,6);
		   	   goto a;
			   }
			   /// Motnuaduongtron(x,y,6);
		}
	}
	a:;
	

 
   // lineDDA(100,20,40,50,10);  
    
   // drawCircleMidpoint(200, 200, 100, BLUE);
    //Sleep(3000); 
    //drawHCN_HV(500,500,100,100,10);
    
    //drawDisplay(10);
   //cleardevice();
    
   //  Randombophan(60,1000,10);
   // //-----------------------------------
    getch();
	closegraph();
	
	return 0;
}