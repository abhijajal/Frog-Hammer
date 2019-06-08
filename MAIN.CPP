
#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#include<time.h>
#include<fstream.h>
#include<iostream.h>
#include<iomanip.h>
#include<string.h>

int i=1;
static int life=3,score=0;
void title()
{
    settextstyle(1,HORIZ_DIR,8);
    setcolor(BLUE);
    outtext("FROG HAMMER");
    setcolor(RED);
    line(0,100,900,100);
}
void title1()
{
    settextstyle(1,HORIZ_DIR,8);
    setcolor(YELLOW);
    outtext("FROG HAMMER");
    setcolor(BLUE);
    line(0,100,900,100);
}

void mainmenu()
{
    setbkcolor(WHITE);
    title();
    settextstyle(4,HORIZ_DIR,5);
    setcolor(CYAN);
    outtextxy(5,100,"         MAIN MENU");
    settextstyle(10,HORIZ_DIR,3);
    setcolor(LIGHTBLUE);
    outtextxy(5,150,"Press 1 to PLAY GAME");
    outtextxy(5,200,"Press 2 for CONTROLS");
    outtextxy(5,250,"Press 3 for CREDITS");
    outtextxy(5,300,"Press 4 for HIGHSCORES");
    outtextxy(5,350,"Press 5 to EXIT");
}
void zero()
{
     setcolor(LIGHTMAGENTA);
    settextstyle(7,HORIZ_DIR,1);
    outtextxy(275,140,"Press ' 0 ' to return to MAIN MENU !");
}
int getzero()
{
    char c=getch();
    if(c==48)
	return 1;
    else
	return 0;
}

void drawcanvas()
{
    setfillstyle(1,RED);
    bar(50,150,150,250);
    bar(250,250,350,350);
    setfillstyle(1,BLUE);
    bar(50,350,150,450);
    bar(150,150,250,250);
    setfillstyle(1,LIGHTRED);
    bar(50,250,150,350);
    bar(250,350,350,450);
    setfillstyle(1,LIGHTBLUE);
    bar(150,350,250,450);
    bar(250,150,350,250);
    setfillstyle(1,LIGHTGREEN);
    bar(150,250,250,350);
}
int random()
{
   time_t seconds;
   time(&seconds);
     seconds=i*seconds;
	 i=i+i*i;
   srand((unsigned int) seconds);
   int x=rand() % (9 - 1 + 1) +1;
   return x;
}
void heart(int life)
{
    if (life==3)
    {
	for(int i=0;i<8;i++)
	{
	    line(485+i,398-i,500+i,413-i);
	    line(515-i,398-i,500-i,413-i);
	    arc(493,398,0,180,8-2*i);
	    arc(508,398,0,180,8-2*i);
	}
	for(i=0;i<8;i++)
	{
	    line(535+i,398-i,550+i,413-i);
	    line(565-i,398-i,550-i,413-i);
	    arc(543,398,0,180,8-2*i);
	    arc(558,398,0,180,8-2*i);
	}
	for(i=0;i<8;i++)
	{
	    line(585+i,398-i,600+i,413-i);
	    line(615-i,398-i,600-i,413-i);
	    arc(593,398,0,180,8-2*i);
	    arc(608,398,0,180,8-2*i);
	}
    }
    else if(life==2)
    {
	 for(int i=0;i<8;i++)
	{
	    line(485+i,398-i,500+i,413-i);
	    line(515-i,398-i,500-i,413-i);
	    arc(493,398,0,180,8-2*i);
	    arc(508,398,0,180,8-2*i);
	}
	for(i=0;i<8;i++)
	{
	    line(535+i,398-i,550+i,413-i);
	    line(565-i,398-i,550-i,413-i);
	    arc(543,398,0,180,8-2*i);
	    arc(558,398,0,180,8-2*i);
	}
	setcolor(8);
	for(i=0;i<8;i++)
	{
	    line(585+i,398-i,600+i,413-i);
	    line(615-i,398-i,600-i,413-i);
	    arc(593,398,0,180,8-2*i);
	    arc(608,398,0,180,8-2*i);
	}
    }
    else if(life==1)
    {
	    for(int i=0;i<8;i++)
	{
	    line(485+i,398-i,500+i,413-i);
	    line(515-i,398-i,500-i,413-i);
	    arc(493,398,0,180,8-2*i);
	    arc(508,398,0,180,8-2*i);
	}
	setcolor(8);
	for(i=0;i<8;i++)
	{
	    line(535+i,398-i,550+i,413-i);
	    line(565-i,398-i,550-i,413-i);
	    arc(543,398,0,180,8-2*i);
	    arc(558,398,0,180,8-2*i);
	}
	for(i=0;i<8;i++)
	{
	    line(585+i,398-i,600+i,413-i);
	    line(615-i,398-i,600-i,413-i);
	    arc(593,398,0,180,8-2*i);
	    arc(608,398,0,180,8-2*i);
	}
    }


}
void lifenscore(int score,int life)
{
    char a[10];
    setfillstyle(1,YELLOW);
    bar(450,175,650,425);
    setcolor(CYAN);
    settextstyle(7,HORIZ_DIR,2);
    outtextxy(470,188,"SCORE:-");
    outtextxy(470,313,"LIFE :-");
    setcolor(BLACK);
    line(450,300,650,300);
    setcolor(RED);
    settextstyle(7,HORIZ_DIR,2);
    sprintf(a,"      %d",score);
    outtextxy(470,250,a);
    heart(life);

}

void img1(int x,int y)
{

	cleardevice();
	title1();
	lifenscore(score,life);
		drawcanvas();
     setfillstyle(1,GREEN);
    setcolor(BLACK);
    ellipse(x,y,0,360,30,20);           //face
    floodfill(x,y,BLACK);
    setcolor(RED);
    ellipse(x,y+25,50,130,30,20);//smile

    setcolor(WHITE);
    setfillstyle(1,BLACK);
    circle(x+20,y-15,10);		  //right eye
    floodfill(x+20+1,y-15-1,WHITE);
    setfillstyle(1,WHITE);
    circle(x+20,y-20,5);
    floodfill(x+20,y-20,WHITE);

    setfillstyle(1,BLACK);

    circle(x-20,y-15,10);               //left eye
    floodfill(x-20+1,y-15+1,WHITE);

    setfillstyle(1,WHITE);
    circle(x-20,y-20,5);
    floodfill(x-20,y-20,WHITE);

    setfillstyle(1,RED);
    circle(x+20,y+10,3);
    floodfill(x+20,y+10,WHITE);          //right dimple
    circle(x-20,y+10,3);
    floodfill(x-20,y+10,WHITE);      //left dimple

}

void img(int x,int y)
{
     setfillstyle(1,GREEN);
    setcolor(BLACK);
    ellipse(x,y,0,360,30,20);           //face
    floodfill(x,y,BLACK);
    setcolor(RED);
    ellipse(x,y-5,230,310,30,20);        //smile

    setcolor(WHITE);
    setfillstyle(1,BLACK);
    circle(x+20,y-15,10);		  //right eye
    floodfill(x+20+1,y-15-1,WHITE);
    floodfill(x+20-1,y-15+1,WHITE);
    setfillstyle(1,WHITE);
    circle(x+15,y-15,5);
    floodfill(x+15,y-15,WHITE);

    setfillstyle(1,BLACK);

    circle(x-20,y-15,10);               //left eye
    floodfill(x-20+1,y-15+1,WHITE);
    floodfill(x-20-1,y-15-1,WHITE);
    setfillstyle(1,WHITE);
    circle(x-15,y-15,5);
    floodfill(x-15,y-15,WHITE);

    setfillstyle(1,RED);
    circle(x+20,y+10,3);
    floodfill(x+20,y+10,WHITE);          //right dimple
    circle(x-20,y+10,3);
    floodfill(x-20,y+10,WHITE);      //left dimple

}

void pop(int x)
{
    if(x==1)
	img(100,400);
    else if(x==2)
	img(200,400);
    else if(x==3)
	img(300,400);
    else if(x==4)
	img(100,300);
    else if(x==5)
	img(200,300);
    else if(x==6)
	img(300,300);
    else if(x==7)
	img(100,200);
    else if(x==8)
	img(200,200);
    else if(x==9)
	img(300,200);
}
void pop1(int x)
{
    if(x==1)
	img1(100,400);
    else if(x==2)
	img1(200,400);
    else if(x==3)
	img1(300,400);
    else if(x==4)
	img1(100,300);
    else if(x==5)
	img1(200,300);
    else if(x==6)
	img1(300,300);
    else if(x==7)
	img1(100,200);
    else if(x==8)
	img1(200,200);
    else if(x==9)
	img1(300,200);
}

void exit()
{
    cleardevice();
    title1();
    setcolor(RED);
    settextstyle(4,HORIZ_DIR,4);
    outtextxy(5,150,"Thank You ! BYE...");
    delay(1000);
    exit(1);
}
void vham(int x,int y)
{
	setfillstyle(1,BROWN);
	setcolor(BROWN);
	int i;
	for(i=0;i<=40;i++)
	{
		bar(x+40-i,y+34-i,x+45-i,y+25-i);
	}
		setfillstyle(1,DARKGRAY);
	setcolor(DARKGRAY);
	 circle(x-14,y+8,7);
	floodfill(x-14,y+8,DARKGRAY);
	for(i=0;i<=15;i++)
	{
		bar(x-i,y-6+i,x+5-i,y-15+i);
	}
	arc(x+7,y-1,45,135,15);
	arc(x+7,y-1,45,135,14);
	arc(x+7,y-1,45,135,13);
	arc(x+7,y-1,45,135,12);
	delay(500);


}

void hham(int x,int y,int z)
{
	setfillstyle(1,BROWN);
	bar(x+15,y-20,x+25,y+35);
	setfillstyle(1,DARKGRAY);
	setcolor(DARKGRAY);
	circle(x,y-25,7);
	floodfill(x,y-25,DARKGRAY);
	bar(x,y-30,x+25,y-20);
	arc(x+25,y-20,0,90,10);
	arc(x+25,y-20,0,90,9);
	arc(x+25,y-20,0,90,8);
	arc(x+25,y-20,0,90,7);
	delay(500);
	cleardevice();
	title1();
	drawcanvas();
	pop1(z);
	lifenscore(score,life);
	vham(x,y);
}
void hammer(int x)
{
      if(x==1)
	hham(100,400,1);
    else if(x==2)
	hham(200,400,2);
    else if(x==3)
	hham(300,400,3);
    else if(x==4)
	hham(100,300,4);
    else if(x==5)
	hham(200,300,5);
    else if(x==6)
	hham(300,300,6);
    else if(x==7)
	hham(100,200,7);
    else if(x==8)
	hham(200,200,8);
    else if(x==9)
	hham(300,200,9);

}
void prompt()
{
	closegraph();
	    char name[15];
	    FILE *f;
	    f=fopen("highscore.txt","a");
	    repeat:
	    textbackground(RED);
	    textcolor(BLUE);
	    for(int i=0;i<79;i++)
		cprintf("                                                                                ");
		textbackground(BLUE);
		textcolor(YELLOW);
	   for(i=0;i<3;i++)
	   {
		gotoxy(9,9+i);
		cprintf("                                                               \n");
	   }
	    textbackground(GREEN);
	     textcolor(RED);

	   for(i=0;i<1;i++)
	   {
		gotoxy(10,10+i);
		cprintf("                                                             \n");
	   }
	    gotoxy(20,9);
	    printf("PLease enter your name ( upto 15 characters ) :\n         ");
	    scanf("%15s",name);
	    if(strlen(name)>15)
		goto repeat;
	    fprintf(f,"%s %d\n",name,score);
	    fclose(f);
	    exit(1);
}
void controller()
{
    int x;

    if(life>0)
    {
	lifenscore(score,life);
	x=random();
	pop(x);
	int c,t=0;
	repeat:
	delay(100);
	if(kbhit()==0)
	{

		if(t<21)
		{
			t++;
			goto repeat;
		}
		else
		{
		life--;
		cleardevice();
		title1();
		drawcanvas();
		}
	}

  /*	repeat:
	if(kbhit()==0)
	{
		t++;
		if(t==21)
		{
			life--;
			cleardevice();
			lifenscore(score,life);
			title1();
			drawcanvas();
			pop(x);

		}
		delay(100);
		if(t<21);
		goto repeat;
	}         */
	else
	{

	c=getch();
	if(c>48 && c<58 || c==88 || c==121 || c==97)
	{
	    c=c-48;
	    if(c==x)
	    {
		score++;
		pop1(x);
		hammer(x);

	    }
	    else if(c==40)   //X
		i=0;
	    else if(c==73)   //y
		i=1;
	    else if(c==49)   //a
		score=score+5;
	    else
	    life--;
	}
	else
	    life--;
	cleardevice();
	title1();
	drawcanvas();
    }
    }
    else
    {
	cleardevice();
	invalid:
	settextstyle(0,HORIZ_DIR,4);
	outtextxy(150,50,"Game Over");
	settextstyle(7,HORIZ_DIR,1);
	outtextxy(50,150,"Do you Wanna save your score ? if yes dn press y else n !");
	char c=getch();

	if(c=='y' ||c=='Y')
	{
		prompt();
	}
	else if(c=='n' || c=='N')
	{
	    exit();
	}
	else
	{
	   outtextxy(100,300,"Invalid input !");
	   delay(1000);
	   cleardevice();
	   goto invalid;
	}

    }
}
void playgame()
{
    setbkcolor(BLACK);
    cleardevice();
    title1();
    drawcanvas();
    cont:
    controller();
    goto cont;
}
void eximg()
{
	setcolor(BLACK);
	setfillstyle(1,RED);
	bar(50,255,90,295);
	outtextxy(65,260,"7");
	bar(130,295,170,335);
	outtextxy(145,300,"6");

	setfillstyle(1,BLUE);
	bar(90,255,130,295);
	outtextxy(105,260,"8");
	bar(50,335,90,375);
	outtextxy(65,340,"1");
	setfillstyle(1,LIGHTBLUE);
	bar(130,255,170,295);
	outtextxy(145,260,"9");
	bar(90,335,130,375);
	outtextxy(105,340,"2");
	setfillstyle(1,LIGHTRED);
	bar(50,295,90,335);
	outtextxy(65,300,"4");
	bar(130,335,170,375);
	outtextxy(145,340,"3");
	setfillstyle(1,LIGHTGREEN);
	bar(90,295,130,335);
	outtextxy(105,300,"5");
}
void controls()
{
    cleardevice();
    title();
    zero();
    setcolor(RED);
    settextstyle(4,HORIZ_DIR,4);
    outtextxy(5,150,"Controls :-");
    setcolor(CYAN);
    settextstyle(7,HORIZ_DIR,1);
    outtextxy(5,200,"In this game a frog will pop out and you need to spot that frog ");
    outtextxy(5,215,"by using num keys as follows: ");
    outtextxy(5,385,"With each succesfull spoting score would be increased by 1.");
    outtextxy(5,400,"You have given 3 lifes !");
    outtextxy(5,415,"That means failure in spoting 3 times will lead to GAME OVER!");
    outtextxy(5,430,"Score and life are shown on right side of the screen. ");
    outtextxy(5,445,"Enjoy the Game ! Happpy Playing ! ;)");
    eximg();
}
void credits()
{
    cleardevice();
    title();
    zero();
    setcolor(RED);
    settextstyle(4,HORIZ_DIR,4);
    outtextxy(5,159,"Credits :-");
    setcolor(CYAN);
    settextstyle(7,HORIZ_DIR,1);
    outtextxy(5,200,"This game is a part of 3rd Sem Software Group Project jointly");
    outtextxy(5,225,"developed by: 14CE038 ( Akash Goswami) &");
    outtextxy(5,250,"              14CE043 ( Abhishek Jajal) ");
    outtextxy(5,270,"Who are pursuing BTech in Computer Engineering ");
    outtextxy(5,300,"At CHANDUBHAI PATEL INSTITUE OF TECHOLOGY , CHANGA ");
    outtextxy(5,325,"Thank You   :) ");
}
void highscores()
{
    cleardevice();
   title();
    zero();
    setcolor(RED);
	settextstyle(4,HORIZ_DIR,4);

  outtextxy(200,165,"High Scores");
  outtextxy(400,165,"(Top 10)");
  char name[15][50];
  int score[50];
  FILE *f;
  f=fopen("highscore.txt","r");
	char h;
	int count=0;
	for(h=getc(f);h!=EOF;h=getc(f))
	{
		if(h=='\n')
			count++;
	}

	fseek(f,0,0);

	int j;
	int i;
	char n[15];
	int s;
	for(i=0;i<count;i++)
{
	fscanf(f,"%s %d",name[i],&score[i]);
}
	for(j=0;j<count;j++)
	{
	for(i=0;i<count-1;i++)
	{
		if(score[i]<score[i+1])
		{
			strcpy(n,name[i]);
			s=score[i];
			strcpy(name[i],name[i+1]);
			score[i]=score[i+1];
			strcpy(name[i+1],n);
			score[i+1]=s;
		}
	}
	}
	fclose(f);
	f=fopen("highscore.txt","w");
	for(i=0;i<count;i++)
{
	fprintf(f,"%s %d\n",name[i],score[i]);
}
	fclose(f);
	f=fopen("highscore.txt","r");

	if(count>10)
		count=10;
		settextstyle(1,HORIZ_DIR,2);
	char arr[5];
	char no[2];
	setcolor(CYAN);
	for(i=0;i<count;i++)
{
	fscanf(f,"%s %d",name[i],&score[i]);
	sprintf(no,"%d.",i+1);
	outtextxy(10,200+20*i,no);
	outtextxy(50,200+20*i,name[i]);
	sprintf(arr,"%d",score[i]);
	outtextxy(300,200+20*i,arr);
}
	fclose(f);
	free(f);
}
int main()
{
    int gd=DETECT;
    int gm;
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    loop:
    mainmenu();
    int g=getch();
    g=g-48;
    if(g==1)
    {
	playgame();
    }
    else if(g==2)
    {
	repeat2:
	controls();
	if(getzero())
	{
	    cleardevice();
	    goto loop;
	}
	else
	    goto repeat2;
    }
    else if(g==3)
    {
	repeat3:
	credits();
	if(getzero(
	))
	{
	    cleardevice();
	    goto loop;
	}
	else
	    goto repeat3;
    }
    else if(g==4)
    {
	repeat4:
	highscores();
	if(getzero())
	{
	    cleardevice();
	    goto loop;
	}
	else
	    goto repeat4;
    }
    else if(g==5)
    {
       exit();
    }
    else
    {
	settextstyle(10,HORIZ_DIR,2);
	setcolor(RED);
	outtextxy(5,400,"Enter a valid Input !");
	outtextxy(5,435,"Press any key to enter again");
	getch();
	cleardevice();
	goto loop;
    }
    getch();
    getch();
    closegraph();
    return 0;
}
