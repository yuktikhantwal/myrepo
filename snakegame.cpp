#include<iostream>
#include<conio.h>            //for kbhit() function
#include<stdlib.h>           //for rand() function
#include<string.h>

//function kbhit() is included in the conio.h file... it is used to record which key on the keyboard is hit and it can be retrieved by getch()
///kbhit() returns a zero/false value if no key is hit, but it returns a non zero/true value if key is hit
//function rand() is included in the stdlib.h file... it generates a very large random integer

//game is divided into functions which makes the code much easier and non-complex
//four important functions in this game are -> setup(),draw(),input(),logic()


int height =20;             //dimensions of the game box
int width =50;
int snakex,snakey;         //coordinates for snake's head
int fruitx,fruity;
int tailx[100],taily[100];        //coordinates for fruit
int score,gameOver,flag,tailCount;        //to keep score of game and flag for gameover and 'flag' is for keyhit
using namespace std;
void setup(void)         //for initializing variables
{
	gameOver =0;
	score =0;
	tailCount=0;
	snakex=width/2;
	snakey=height/2;
	label1 :
	fruitx=rand()%width;
	if(fruitx==0)
	goto label1;
	label2 :
	fruity=rand()%height;
	if(fruity==0)
	goto label2;
}
void draw(void)            //for drawing the box
{
	system("cls");
	cout<<"WELCOME TO SNAKE GAME!";
	cout<<endl<<endl;
	cout<<"Use keys a,s,w,d for left,down,up,right and press x key if you want to exit the game";
	cout<<endl<<endl;             //to clear the screen before drawing a new arena, as the game progresses
	int r;
	for(int j=0;j<width;j++)
	{
		cout<<"*";
	}
	cout<<endl;
	for(int i=0;i<height;i++)
	{
		for(int k=0;k<width;k++)
		{
			int q=0;
			if(k==0)
			cout<<"*";
			else if(k==width-1)
			cout<<"*"<<endl;
			else if((i==snakey)&&(k==snakex))
			cout<<"O";
			else if((i==fruity)&&(k==fruitx))
			cout<<"$";
			else
			{
				for(r=0;r<tailCount;r++)
				{
					if((i==taily[r])&&(k==tailx[r]))
					{
					cout<<"o";
					q=1;
				}
			    }
			    if(q==0)
				cout<<" ";
		}
		
		}
	}
	for(int x=0;x<width;x++)
	{
		cout<<"*";
	}
	cout<<endl;
}
void input(void)              //to see which key is hit and to move the snake
{
	if(kbhit())
	{
		switch(getch())       //a for left,d for right,w for up,s for down
		{
			case('a'):
			{
				flag=1;         //by value of flag we'll be able to know which key is hit
				break;
			}
			case('d'):
			{
				flag=2;
				break;
			}
			case('w'):
			{
				flag=3;
				break;
			}	
			case('s'):
			{
				flag=4;
			    break;
			}
			case('x'):
			{
				gameOver=1;
				break;
			}
		}
	}
}
void logic(void)           //basically the logic behind the game and what makes it work...
{
	int i;
	int prevx=tailx[0];
	int prevy=taily[0]; 
	int prev2x,prev2y;
	tailx[0]=snakex;
	taily[0]=snakey;
	for(int i=1;i<tailCount;i++)
	{
		prev2x=tailx[i];
		prev2y=taily[i];
		tailx[i]=prevx;
		taily[i]=prevy;
		prevx=prev2x;
		prevy=prev2y;
		
	}
	switch(flag)
	{
		case 1:
		{
			snakex--;
			break;
		}
		case 2:
		{
			snakex++;
			break;
		}
		case 3:
		{
		    snakey--;
		    break;
		}
		case 4:
		{
			snakey++;
			break;
		}				
	}
	if((snakex<0)||(snakex>width)||(snakey<0)||(snakey>height))
	{
		gameOver =1;
	}
	if((snakex==fruitx)&&(snakey==fruity))
	{
	score++;
	cout<<score;
	tailCount++;
	label3 :
	fruitx=rand()%width;
	if(fruitx==0)
	goto label3;
	label4 :
	fruity=rand()%height;
	if(fruity==0)
	goto label4;
	}
	for(int e=0;e<tailCount;e++)
	{
		if((snakex==tailx[e])&&(snakey==taily[e]))
		gameOver=1;
	}
}
int main()
{
	setup();
	while(gameOver==0){
	draw();
	input();
	logic();
    }
    if(gameOver==1){
    	cout<<"GAMEOVER!"<<endl;
    	cout<<"Your score is "<<score;
	}
	return 0;
}
