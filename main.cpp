///PAINT

#include<graphics.h>
#include<math.h>
#include<stdio.h>
#include<windows.h>


void menu();
void menu2();
void dikdortgen();
void ucgen();
void daire();
void duz_cizgi();
void kalem(int);
int renk_sec(int,int);
void cikis();

int main()
{
    FILE *dosya=fopen("paint.txt","r");

    DWORD screenWidth=GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight=GetSystemMetrics(SM_CYSCREEN);


    initwindow(screenWidth,screenHeight);

    menu();

int x,y;
int renk=0;
setcolor(BLACK);


    int i,j,sonuc;

        for(i=0;i<=getmaxx();i++)
        {
            for(j=131;j<=getmaxy();j++)
            {
                fscanf(dosya,"%d",&sonuc);
                putpixel(i,j,sonuc);
            }
        }


    while(1)
    {
       while(!ismouseclick(WM_LBUTTONDOWN))
       {
           delay(500);
       }
       getmouseclick(WM_LBUTTONDOWN,x,y);

       if((x>=12 && x<=68) && (y>=47 && y<=93))
        dikdortgen();
       else if((x>=73 && x<=129) && (y>=47 && y<=93))
       ucgen();
       else if((x>=134 && x<=190) && (y>=47 && y<=93))
        daire();
       else if((x>=195 && x<=251) && (y>=47 && y<=93))
        duz_cizgi();
        else if((x>=256 && x<=312) && (y>=47 && y<=93))
            kalem(renk);
       else if((x>=1250 && x<=1312) && (y>=47 && y<=93))
        cikis();
       else if((x>=317 && x<=470) && (y>=47 && y<=93))
        renk=renk_sec(x,y);

       else continue;

   setcolor(renk);

    }

fclose(dosya);
    return 0;
}
void cikis()
{

    settextstyle(10,0,1);
    setfillstyle(SOLID_FILL,DARKGRAY);
    bar(1100,36,1240,65);
    setfillstyle(SOLID_FILL,WHITE);
    bar(1101,37,1239,64);
    outtextxy(1104,38,"Kaydet");

    settextstyle(10,0,1);
    setfillstyle(SOLID_FILL,DARKGRAY);
    bar(1100,68,1240,97);
    setfillstyle(SOLID_FILL,WHITE);
    bar(1101,69,1239,96);
    outtextxy(1104,70,"Kaydetme");

    settextstyle(10,0,1);
    setfillstyle(SOLID_FILL,DARKGRAY);
    bar(1100,100,1240,129);
    setfillstyle(SOLID_FILL,WHITE);
    bar(1101,101,1239,128);
    outtextxy(1104,102,"Sil");


    delay(750);

    int x,y;
    while(1){

    while(!ismouseclick(WM_LBUTTONDOWN))
    {
        delay(500);
    }
    getmouseclick(WM_LBUTTONDOWN,x,y);

    if((x>=1100 && x<=1240) &&  (y>=36 && y<=65))
    {
        setfillstyle(SOLID_FILL,LIGHTBLUE);
        bar(1098,35,1242,130);

        int i,j;

        FILE *dosya=fopen("paint.txt","w+");

        for(i=0;i<=getmaxx();i++)
        {
            for(j=131;j<=getmaxy();j++)
            {
                fprintf(dosya,"%d ",getpixel(i,j));
            }
        }

        fclose(dosya);
           exit(0);
    }
    else if((x>=1100 && x<=1240) && (y>=68 && y<=97))
    {
        exit(0);
    }
    else if((x>=1100 && x<=1240) && (y>=100 && y<=129))
    {
  setbkcolor(WHITE);
    cleardevice();

    menu2();

    int i,j;

        FILE *dosya=fopen("paint.txt","w+");

        for(i=0;i<=getmaxx();i++)
        {
            for(j=131;j<=getmaxy();j++)
            {
                fprintf(dosya,"%d ",getpixel(i,j));
            }
        }

        fclose(dosya);
           exit(0);

    }
    }
}

int renk_sec(int x,int y)
{

    if((x>=323 && x<=338) && (y>=53 && y<=68))
    {
        return 0;
    }
    else if((x>=323 && x<=338) && (y>=72 && y<=87))
    {
        return 1;
    }
    else if((x>=341 && x<=356) && (y>=53 && y<=68))
    {
        return 2;
    }
    else if((x>=341 && x<=356) && (y>=72 && y<=87))
    {
        return 3;
    }
    else if((x>=359 && x<=374) && (y>=53 && y<=68))
    {
        return 4;
    }
    else if((x>=359 && x<=374) && (y>=72 && y<=87))
    {
        return 5;
    }
    else if((x>=377 && x<=392) && (y>=53 && y<=68))
    {
        return 6;
    }
    else if((x>=377 && x<=392) && (y>=72 && y<=87))
    {
        return 7;
    }
    else if((x>=395 && x<=410) && (y>=53 && y<=68))
    {
        return 8;
    }
    else if((x>=395 && x<=410) && (y>=72 && y<=87))
    {
        return 9;
    }

    else if((x>=413 && x<=428) && (y>=53 && y<=68))
    {
        return 10;
    }
    else if((x>=413 && x<=428) && (y>=72 && y<=87))
    {
        return 11;
    }
    else if((x>=431 && x<=446) && (y>=53 && y<=68))
    {
        return 12;
    }
    else if((x>=431 && x<=446) && (y>=72 && y<=87))
    {
        return 13;
    }
    else if((x>=449 && x<=464) && (y>=53 && y<=68))
    {
        return 14;
    }
    else if((x>=449 && x<=464) && (y>=72 && y<=87))
    {
        return 15;
    }
}



void kalem(int renk)
{
    settextstyle(10,0,1);
            outtextxy(12,100,"Cizimi Birakmak Icin Saga, Kalemi Birakmak Icin Menu Bolgesine Tiklayin!!!");

    setfillstyle(SOLID_FILL,renk);
    int x,y;

    while(1){

    while(!ismouseclick(WM_LBUTTONDOWN))
    {
        delay(500);
    }
    getmouseclick(WM_LBUTTONDOWN,x,y);

    if(y<=130)
        break;
    while(1)
    {
          getmouseclick(WM_MOUSEMOVE,x,y);
          if(y<=130&&y!=-1)
            break;
          bar(x,y,x+3,y+3);
          delay(1);
          if(ismouseclick(WM_RBUTTONDOWN))
          break;

    }
    clearmouseclick(WM_RBUTTONDOWN);

    }

    setfillstyle(SOLID_FILL,LIGHTBLUE);
            bar(10,95,1500,130);

    settextstyle(10,0,1);
            outtextxy(12,100,"Kalem Birakildi!!!");
            delay(750);

 setfillstyle(SOLID_FILL,LIGHTBLUE);
            bar(10,95,1500,130);

}

void duz_cizgi()
{

    int x,y,x2,y2;

    outtextxy(12,100,"Duz Cizginin Basi Ve Sonu Icin 2 Nokta Tiklayin!!!");
    delay(750);
    setfillstyle(SOLID_FILL,LIGHTBLUE);
    bar(10,95,1500,130);


    while(!ismouseclick(WM_LBUTTONDOWN))
    {
        delay(500);
    }
    getmouseclick(WM_LBUTTONDOWN,x,y);


    while(!ismouseclick(WM_LBUTTONDOWN))
    {
        delay(500);
    }
    getmouseclick(WM_LBUTTONDOWN,x2,y2);

    line(x,y,x2,y2);

    if(y<=130 || y2<=130)
    {
        menu2();
    }
}



void daire()
{
    int x,y,x2,y2;

    outtextxy(12,100,"Dairenin Merkezi Ve Yaricapi Icin 2 Nokta Tiklayin!!!");
    delay(750);
    setfillstyle(SOLID_FILL,LIGHTBLUE);
    bar(10,100,1500,130);

    while(!ismouseclick(WM_LBUTTONDOWN))
    {
        delay(500);
    }
    getmouseclick(WM_LBUTTONDOWN,x,y);

    while(!ismouseclick(WM_LBUTTONDOWN))
    {
        delay(500);
    }
    getmouseclick(WM_LBUTTONDOWN,x2,y2);

    float yaricap=sqrt(pow((double)(x-x2),2)+pow((double)(y-y2),2));
    circle(x,y,yaricap);

    if(y<=130 || (y-yaricap)<=130)
    {
        menu2();
    }

}

void ucgen()
{
    int x1,x2,x3,y1,y2,y3;

    settextstyle(10,0,1);
    outtextxy(12,100,"Ucgenin Koordinatlari Icin 3 Nokta Tiklayin!!!");
    delay(750);
    setfillstyle(SOLID_FILL,LIGHTBLUE);
    bar(10,95,1500,130);

    while(!ismouseclick(WM_LBUTTONDOWN))
    {
        delay(500);
    }
    getmouseclick(WM_LBUTTONDOWN,x1,y1);

    while(!ismouseclick(WM_LBUTTONDOWN))
    {
        delay(500);
    }
    getmouseclick(WM_LBUTTONDOWN,x2,y2);

    while(!ismouseclick(WM_LBUTTONDOWN))
    {
        delay(500);
    }
    getmouseclick(WM_LBUTTONDOWN,x3,y3);

    line(x1,y1,x2,y2);
    line(x2,y2,x3,y3);
    line(x1,y1,x3,y3);

    if(y1<=130 || y2<=130 || y3<=130)
    {

        menu2();
    }
}


void dikdortgen()
{
 int x,y;

            settextstyle(10,0,1);
            outtextxy(12,100,"Dikdortgenin Boyutlari Icin Kosegen Koordinatlarina Tiklayin!!!");
            delay(750);
            setfillstyle(SOLID_FILL,LIGHTBLUE);
            bar(10,95,1500,130);

int x2,y2;
    while(!ismouseclick(WM_LBUTTONDOWN))
    {

        delay(500);
    }
    getmouseclick(WM_LBUTTONDOWN,x,y);
    while(!ismouseclick(WM_LBUTTONDOWN))
    {

        delay(500);
    }
    getmouseclick(WM_LBUTTONDOWN,x2,y2);

    rectangle(x,y,x2,y2);


    if(y<=130 || y2<=130)
    {
      menu2();
    }

}


void menu()
{
    ///Arka plan rengi ayarlandý

    setbkcolor(WHITE);
    cleardevice();

    ///Paint yazan kýsým düzenlendi
    setfillstyle(SOLID_FILL,DARKGRAY);
    bar(0,0,1500,35);
    settextstyle(10,0,3);
    setcolor(GREEN);
    outtextxy(10,3,"P");

    settextstyle(10,0,3);
    setcolor(BLUE);
    outtextxy(30,3,"A");

    settextstyle(10,0,3);
    setcolor(DARKGRAY);
    outtextxy(50,3,"I");

    settextstyle(10,0,3);
    setcolor(RED);
    outtextxy(60,3,"N");

    settextstyle(10,0,3);
    setcolor(CYAN);
    outtextxy(80,3,"T");

    setcolor(BLACK);
    rectangle(9,3,99,31);



    ///Menulerin olduðu kýsýmda barlarýn çizilmesi
    setfillstyle(SOLID_FILL,LIGHTBLUE);
    bar(0,35,1500,130);
    settextstyle(10,0,1);

    setcolor(MAGENTA);

    ///Menünün üstünde dikdörtgen çiziliyo
    setfillstyle(SOLID_FILL,DARKGRAY);
    bar(12,47,68,93);
    setfillstyle(SOLID_FILL,WHITE);
    bar(15,50,65,90);
    rectangle(20,55,60,85);


    ///Menünün üstünde üçgen çiziliyo
    setfillstyle(SOLID_FILL,DARKGRAY);
    bar(73,47,129,93);
    setfillstyle(SOLID_FILL,WHITE);
    bar(76,50,126,90);

    line(81,85,101,55);
    line(101,55,121,85);
    line(81,85,121,85);

    ///Menünün üstünde daire çiziliyo
    setfillstyle(SOLID_FILL,DARKGRAY);
    bar(134,47,190,93);
    setfillstyle(SOLID_FILL,WHITE);
    bar(137,50,187,90);
    circle(162,70,16);

    ///Menünün üstünde düz çizgi çiziliyo
    setfillstyle(SOLID_FILL,DARKGRAY);
    bar(195,47,251,93);
    setfillstyle(SOLID_FILL,WHITE);
    bar(198,50,248,90);
    line(202,70,244,70);

    ///Menünün üstünde kalem çiziliyo
    setfillstyle(SOLID_FILL,DARKGRAY);
    bar(256,47,312,93);
    setfillstyle(SOLID_FILL,WHITE);
    bar(259,50,309,90);
    rectangle(281,53,289,75);
    line(281,75,285,85);
    line(289,75,285,85);


    ///Menünün üstünde renk butonlarý çiziliyo
    setfillstyle(SOLID_FILL,DARKGRAY);
    bar(317,47,470,93);
    setfillstyle(SOLID_FILL,WHITE);
    bar(320,50,467,90);

    setfillstyle(SOLID_FILL,BLACK);
    bar(323,53,338,68);

    setfillstyle(SOLID_FILL,BLUE);
    bar(323,72,338,87);

    setfillstyle(SOLID_FILL,GREEN);
    bar(341,53,356,68);

    setfillstyle(SOLID_FILL,CYAN);
    bar(341,72,356,87);

    setfillstyle(SOLID_FILL,RED);
    bar(359,53,374,68);

    setfillstyle(SOLID_FILL,MAGENTA);
    bar(359,72,374,87);

    setfillstyle(SOLID_FILL,BROWN);
    bar(377,53,392,68);

    setfillstyle(SOLID_FILL,LIGHTGRAY);
    bar(377,72,392,87);

    setfillstyle(SOLID_FILL,DARKGRAY);
    bar(395,53,410,68);

    setfillstyle(SOLID_FILL,LIGHTBLUE);
    bar(395,72,410,87);

    setfillstyle(SOLID_FILL,LIGHTGREEN);
    bar(413,53,428,68);

    setfillstyle(SOLID_FILL,LIGHTCYAN);
    bar(413,72,428,87);

    setfillstyle(SOLID_FILL,LIGHTRED);
    bar(431,53,446,68);

    setfillstyle(SOLID_FILL,LIGHTMAGENTA);
    bar(431,72,446,87);

    setfillstyle(SOLID_FILL,YELLOW);
    bar(449,53,464,68);

    setfillstyle(SOLID_FILL,WHITE);
    bar(449,72,464,87);
    setcolor(BLACK);
    rectangle(449,72,464,87);

    setfillstyle(SOLID_FILL,DARKGRAY);
    bar(1282,47,1312,77);
    setfillstyle(SOLID_FILL,LIGHTRED);
    bar(1285,50,1309,74);
    line(1288,53,1306,71);
    line(1288,71,1306,53);


}
void menu2()
{
    ///Paint yazan kýsým düzenlendi
    setfillstyle(SOLID_FILL,DARKGRAY);
    bar(0,0,1500,35);
    settextstyle(10,0,3);
    setcolor(GREEN);
    outtextxy(10,3,"P");

    settextstyle(10,0,3);
    setcolor(BLUE);
    outtextxy(30,3,"A");

    settextstyle(10,0,3);
    setcolor(DARKGRAY);
    outtextxy(50,3,"I");

    settextstyle(10,0,3);
    setcolor(RED);
    outtextxy(60,3,"N");

    settextstyle(10,0,3);
    setcolor(CYAN);
    outtextxy(80,3,"T");

    setcolor(BLACK);
    rectangle(9,3,99,31);



    ///Menulerin olduðu kýsýmda barlarýn çizilmesi
    setfillstyle(SOLID_FILL,LIGHTBLUE);
    bar(0,35,1500,130);
    settextstyle(10,0,1);

    setcolor(MAGENTA);

    ///Menünün üstünde dikdörtgen çiziliyo
    setfillstyle(SOLID_FILL,DARKGRAY);
    bar(12,47,68,93);
    setfillstyle(SOLID_FILL,WHITE);
    bar(15,50,65,90);
    rectangle(20,55,60,85);


    ///Menünün üstünde üçgen çiziliyo
    setfillstyle(SOLID_FILL,DARKGRAY);
    bar(73,47,129,93);
    setfillstyle(SOLID_FILL,WHITE);
    bar(76,50,126,90);

    line(81,85,101,55);
    line(101,55,121,85);
    line(81,85,121,85);

    ///Menünün üstünde daire çiziliyo
    setfillstyle(SOLID_FILL,DARKGRAY);
    bar(134,47,190,93);
    setfillstyle(SOLID_FILL,WHITE);
    bar(137,50,187,90);
    circle(162,70,16);

    ///Menünün üstünde düz çizgi çiziliyo
    setfillstyle(SOLID_FILL,DARKGRAY);
    bar(195,47,251,93);
    setfillstyle(SOLID_FILL,WHITE);
    bar(198,50,248,90);
    line(202,70,244,70);

    ///Menünün üstünde kalem çiziliyo
    setfillstyle(SOLID_FILL,DARKGRAY);
    bar(256,47,312,93);
    setfillstyle(SOLID_FILL,WHITE);
    bar(259,50,309,90);
    rectangle(281,53,289,75);
    line(281,75,285,85);
    line(289,75,285,85);


    ///Menünün üstünde renk butonlarý çiziliyo
    setfillstyle(SOLID_FILL,DARKGRAY);
    bar(317,47,470,93);
    setfillstyle(SOLID_FILL,WHITE);
    bar(320,50,467,90);

    setfillstyle(SOLID_FILL,BLACK);
    bar(323,53,338,68);

    setfillstyle(SOLID_FILL,BLUE);
    bar(323,72,338,87);

    setfillstyle(SOLID_FILL,GREEN);
    bar(341,53,356,68);

    setfillstyle(SOLID_FILL,CYAN);
    bar(341,72,356,87);

    setfillstyle(SOLID_FILL,RED);
    bar(359,53,374,68);

    setfillstyle(SOLID_FILL,MAGENTA);
    bar(359,72,374,87);

    setfillstyle(SOLID_FILL,BROWN);
    bar(377,53,392,68);

    setfillstyle(SOLID_FILL,LIGHTGRAY);
    bar(377,72,392,87);

    setfillstyle(SOLID_FILL,DARKGRAY);
    bar(395,53,410,68);

    setfillstyle(SOLID_FILL,LIGHTBLUE);
    bar(395,72,410,87);


    setfillstyle(SOLID_FILL,LIGHTGREEN);
    bar(413,53,428,68);

    setfillstyle(SOLID_FILL,LIGHTCYAN);
    bar(413,72,428,87);

    setfillstyle(SOLID_FILL,LIGHTRED);
    bar(431,53,446,68);

    setfillstyle(SOLID_FILL,LIGHTMAGENTA);
    bar(431,72,446,87);

    setfillstyle(SOLID_FILL,YELLOW);
    bar(449,53,464,68);

    setfillstyle(SOLID_FILL,WHITE);
    bar(449,72,464,87);
    setcolor(BLACK);
    rectangle(449,72,464,87);

    setfillstyle(SOLID_FILL,DARKGRAY);
    bar(1282,47,1312,77);
    setfillstyle(SOLID_FILL,LIGHTRED);
    bar(1285,50,1309,74);
    line(1288,53,1306,71);
    line(1288,71,1306,53);


}

