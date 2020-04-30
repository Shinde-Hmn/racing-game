#include<iostream.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<graphics.h>
#include<dos.h>
#include<fstream.h>
#include<process.h>
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ENTER 13
#define EXIT 27

class main_part
{
public:
 char  player[10];
 int score;

public:
 void enemycar(int x, int y)
  {
   setcolor(15);
   rectangle(x+1,y,x+49,y+100);
   rectangle(x+1,y+25,x+49,y+75);
   setfillstyle( SOLID_FILL,YELLOW);
   floodfill((x+x+50)/2,(y+y+100)/2,15);
   setfillstyle(1,YELLOW);
   floodfill((x+x+50)/2,(y+y+40)/2,15);
   floodfill((x+x+50)/2,(y+y+160)/2,15);
  }
 void mycar(int x, int y)
 {
   setcolor(15);
   rectangle(x+1,y,x+49,y+100);
   rectangle(x+1,y+25,x+49,y+75);
   setfillstyle(5,RED);
   floodfill((x+x+50)/2,(y+y+100)/2,15);
   setfillstyle(2,BLUE);
   floodfill((x+x+50)/2,(y+y+40)/2,15);
   floodfill((x+x+50)/2,(y+y+160)/2,15);
  }
 void myclear(int x,int y)
 {
 setcolor(8);
 rectangle(x+1,y,x+49,y+100);
 rectangle(x+1,y+25,x+49,y+75);
 setfillstyle(SOLID_FILL,8);
 floodfill((x+x+50)/2,(y+y+100)/2,8);
 floodfill((x+x+50)/2,(y+y+40)/2,8);
 floodfill((x+x+50)/2,(y+y+160)/2,8);
 }
 void enemyclear(int x,int y)
 {
 setcolor(8);
 rectangle(x+1,y,x+49,y+100);
 rectangle(x+1,y+25,x+49,y+75);
 line(x+1,y,x+1,y+100);
 }
// SCORE BOARD
void  score_store(int sco)
{
cleardevice();
setcolor(4);
settextstyle(2,0,6);
outtextxy(10,0,"Your score is");
gotoxy(20,2);
cout<<sco;
outtextxy(10,40,"Enter your name to store :");
gotoxy(35,4);
cin>>player;
ofstream sc;
sc.open("score.txt",ios::app);
sc<<"\n";
sc<<player<<"         "<<sco;
///sc.write(player,20);

sc.close();
}

 void menu()
  {
 int i=0;
int gdriver=DETECT,gmode,errorcode;
initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI ");
cleardevice();
 for (i=0;i<250;i++)
{
settextstyle(1,HORIZ_DIR,2);
outtextxy(100,400,"LOADING");
setfillstyle(SOLID_FILL,GREEN);
bar(190,400,190+i,420);
delay(25);
}
 int s=1,t=0,a,p=135;
   do
    {
     do
       {
	 cleardevice();
	 setcolor(YELLOW);
	 settextstyle(1,0,4);
	 outtextxy(230,30,"MENU");
	 setfillstyle(1,2);
	 bar(140,80,400,82);
	 settextstyle(1,0,1);
	 setcolor(10);
	 outtextxy(220,137,"PLAY GAME");
	 outtextxy(220,167,"SCORES");
	 outtextxy(220,197,"HELP");
	 outtextxy(220,227,"EXIT");
	 setcolor(RED);
	 rectangle(180,p,350,p+30);
	 a=getch();
	 switch(a)
	 {
	   case UP:
	    {
	      if(p>140)
	       {
		p=p-30;
		s--;
		}
		break;
	     }
	   case DOWN:
	   {
	    if(p<260)
	     {
		p=p+30;
		s++;
	      }
		break;
	    }
	  case ENTER:
	  {
	   a=1;
	   break;
	   }
	  default:
	     break;
      };
 }while(a!=1);
 switch(s)
 {
  case 1:
      {
	play();
       break;
       }
  case 2:
       {
       disp_score();
       break;
       }
  case 3:
      {
       help();
       break;
       }
  case 4:
      {
      exit(0);
      }
  default:
      {
      cout<<"\n INVALID CHOICE";
      break;
      }
  };
 }while(t==0);
 getch();
}


void  disp_score()
{
cleardevice();
setcolor(5);
settextstyle(2,0,9);
outtextxy(200,20,"SCORE BOARD");
ifstream sc("score.txt");
char ch;
int i=0;
gotoxy(1,5);
while(sc.get(ch))
{
sc.seekg(i,ios::beg);
sc.get(ch);
cout<<ch;
i++;
}
getch();
return;
}
// HELP FUNTION

void  help()
{
cleardevice();
settextstyle(4,0,6);
setcolor(13);
outtextxy(200,10,"HELP");
textcolor(YELLOW);
gotoxy(3,6);
cout<<"\n\n\n\n\n\n\n You have to use the following keys to control the car\n\n";
cout<<"->UP\t--\tForward movement\n";
cout<<"->LEFT\t--\tLeftside movement\n";
cout<<"->RIGHT\t--\tRightside movement\n";
cout<<"->Esc\t--\tExit from game at any time\n";
getch();
return;
}
void play()
{
 int gdriver = DETECT,gmode;
 initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");

  int x=300,y=350,ch,life=3,score=0;
  char choice;

  for(int m=1;m<25;m++)
    for(int n=1;n<80;n++) {
	gotoxy(n,m);
	cout<<" ";
	}
  setcolor(RED);
  rectangle(20,60,200,120);
  rectangle(20,300,200,420);
  rectangle(249,0,401,getmaxy());
  setfillstyle(SOLID_FILL,8);
  floodfill(325,getmaxy()/2,RED);
  setcolor(RED);
  rectangle(20,200,200,250);
  gotoxy(5,15);
  cout<<"Press <Esc> to Exit";
  for(int level=1;(level<=5)&&(life>0);level++){
    if(level==1){
      gotoxy(5,5);
      cout<<"Your War Starts Now";
      gotoxy(5,7);
      cout<<"All the best";
      delay(500);
      gotoxy(5,5);
      cout<<"                    ";
      gotoxy(5,7);
      cout<<"            ";
      }
     else {
	 gotoxy(5,5);
	 cout<<"Next level.";
	 delay(500);
	 gotoxy(5,5);
	 cout<<"           ";
	 }
  for(int i=0;(i<15)&&(life>0);i++) {
    if((level==5)&&(i==14)){
       gotoxy(5,5);
       cout<<"You have won";
       gotoxy(5,6);
       cout<<"Wanna continue <y/n>";
       choice = getch();
       if ((choice=='y')||(choice=='Y'))
	main();
       else
	exit(0);
       }
    setcolor(RED);
    rectangle(420,125,600,175);
    gotoxy(55,10);
    cout<<"Level = "<<level;
    rectangle(420,250,600,300);
    gotoxy(55,18);
    cout<<"Lives = "<<life;
    rectangle(420,350,600,400);
    gotoxy(55,24);
    cout<<"Score = "<<score;
    int accident=0;
    int y1=1,x1=250+((rand()%3)*50);
    int y2=1,x2=250+((rand()%3)*50);
    score += 10;
    while(y1<getmaxy()-1)
    {

	enemyclear(x1,y1);
	enemyclear(x2,y2);
	y1++;
	y2++;
	if(accident == 1)
	    break;
	enemycar(x1,y1);
	enemycar(x2,y2);
	mycar(x,y);
	delay(5-level);
	if(kbhit())
	{
	    mycar(x,y);
	    ch=getch();
	    switch(ch) {
	    case 27: exit(0);
	    break;
	    case 75:myclear(x,y);
		if(x>250)
		    x=x-50;
		    if((x==x1)||(x==x2))
			if( ( ((y-y1)<100)&&((y-y1)>0) ) || ( ((y-y2)<100)&&((y-y2)>0) ) )
			{
			    accident=1;
			    x=x+50;
			    mycar(x,y);
			    goto Next1;
			}
		 mycar(x,y);
	    break;
	    case 77:myclear(x,y);
		if(x<350)
		    x=x+50;
		    if((x==x1)||(x==x2))
			if( ( ((y-y1)<100)&&((y-y1)>0) ) || ( ((y-y2)<100)&&((y-y2)>0) ) )
			{
			    accident=1;
			    x=x-50;
			    mycar(x,y);
			    goto Next1;
			}
		mycar(x,y);
	    break;
	    case 72:myclear(x,y);
		if(y>0)
		      y=y-5;
		mycar(x,y);
	     break;
	     case 80:myclear(x,y);
		if(y<getmaxy()-105)
		    y=y+5;
		mycar(x,y);
	     break;
	    }
	}
	if((x==x1)||(x==x2))
	    if( ( ((y-y1)<100)&&((y-y1)>0) ) || ( ((y-y2)<100)&&((y-y2)>0) ) )
		accident=1;



      Next1:
      if(accident==1){
	life =life-1;
	score -= 10;
	if(life==0) {
	 gotoxy(5,5);
	 cout<<"GAME OVER ";
	  score_store(score) ;
	 gotoxy(5,6);
	 break;
	 }
	gotoxy(5,5);
	cout<<"You have lost 1 life";
	delay(500);
	gotoxy(5,5);
	cout<<"                    ";
	}
	}
  }
  }
}
};
void main()
{
main_part obj;
obj.menu();
getch();
}



