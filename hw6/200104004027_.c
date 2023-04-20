#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define rows 15
#define columns 30
void printMap (char A[rows][columns]);
int dice();
int startGame(int p1,int p2);
int main()
{
	
    char A[rows][columns];
     A[1][1]='1';
    A[3][3]='2';
     printMap (A);/*map function*/
     int p1,p2;
     int winner;
     printf("\033[1;37m");
     	printf("To start game, players should dice and decide who is going to start first according to...\n");
     	printf("\033[1;33m");
     	printf("PLAYER 1... press ENTER to dice\n");
	p1=dice();/*dice function*/
	printf("\033[1;33m");
	printf("DICE: %d\n",p1);/*dice number for player 1*/
	printf("\033[1;34m");
	printf("PLAYER 2... press ENTER to dice\n");
	p2=dice();
	printf("\033[1;34m");
    printf("DICE: %d\n",p2);/*dice number for player 2*/
     winner=startGame(p1,p2);//send to function who will start
     if(winner==1)//If player 1 wins
     {
     int a=1,b=1;
     int k=3,l=3;
     int finish1_line=0;//control variable 1
     int finish2_line=0;//control variable 2
     
     		do
     		{
     		int dice1,dice2;
     		printf("\033[1;33m");
     		printf("PLAYER 1... press ENTER to dice\n");
		dice1=dice();// get dice number from function
		printf("\033[1;33m");
		printf("DICE: %d\n",dice1);
		printf("\033[1;34m");
		printf("PLAYER 2... press ENTER to dice\n");
		printf("\033[1;34m");
		dice2=dice();// get dice number from function
		printf("DICE: %d\n",dice2);
		if((a==1 && b<=28) || (k==3 && l<=26)) // for first runway
		{
			A[a][b]=' ';
			b=b+dice1;
			A[a][b]='1';
			
			A[k][l]=' ';
			l=l+dice2;
			A[k][l]='2';	
			printMap (A);	
		}
		else if((a<=13 && b==28) || (k<=11 && l==26))// for second runway (it does not work)
		{
			A[a][b]=' ';
			a=a+dice1;
			A[a][b]='1';
			
			A[k][l]=' ';
			k=k+dice2;
			A[k][l]='2';	
			printMap (A);	
		}
		else if((a==13 && b>=1) || (k==11 && l>=3))// for third runway (it does not work)
		{
			A[a][b]=' ';
			b=b-dice1;
			A[a][b]='1';
			
			A[k][l]=' ';
			l=l-dice2;
			A[k][l]='2';	
			printMap (A);	
		}
		else if((a>=2 && b==1) || (k>=4 && l==3)) // for fourth runway (it does not work)
		{
			A[a][b]=' ';
			a=a-dice1;
			A[a][b]='1';
			if(a=2)
			{
				finish1_line=1;
			}
			A[k][l]=' ';
			k=k-dice2;
			A[k][l]='2';
			if(k=4)
			{
				finish2_line=1;
			}	
			printMap (A);	
		}
		}while(finish1_line != 1 || finish2_line != 1 );
     }
     else// if player 2 wins
     {
     int a=1,b=1;
     int k=3,l=3;
     int finish1_line=0;
     int finish2_line=0;
		do
     		{
     		int dice1,dice2;// same as the first
		printf("\033[1;34m");
		printf("PLAYER 2... press ENTER to dice\n");
		printf("\033[1;34m");
		dice2=dice();
		printf("DICE: %d\n",dice2);
		printf("\033[1;33m");
     		printf("PLAYER 1... press ENTER to dice\n");
		dice1=dice();
		printf("\033[1;33m");
		printf("DICE: %d\n",dice1);
		if((a==1 && b<=28) || (k==3 && l<=26))
		{
			
			A[k][l]=' ';
			l=l+dice2;
			A[k][l]='2';
			
			A[a][b]=' ';
			b=b+dice1;
			A[a][b]='1';	
			printMap (A);	
		}
		else if((a<=13 && b==28) || (k<=11 && l==26))
		{
			
			A[k][l]=' ';
			k=k+dice2;
			A[k][l]='2';
			A[a][b]=' ';
			a=a+dice1;
			A[a][b]='1';	
			printMap (A);	
		}
		else if((a==13 && b>=1) || (k==11 && l>=3))
		{
			
			A[k][l]=' ';
			l=l-dice2;
			A[k][l]='2';
			
			A[a][b]=' ';
			b=b-dice1;
			A[a][b]='1';	
			printMap (A);	
		}
		else if((a>=2 && b==1) || (k>=4 && l==3))
		{

			A[k][l]=' ';
			k=k-dice2;
			A[k][l]='2';
			if(k=4)
			{
				finish2_line=1;
			}
			A[a][b]=' ';
			a=a-dice1;
			A[a][b]='1';
			if(a=2)
			{
				finish1_line=1;
			}	
			printMap (A);	
		}
		}while(finish1_line != 1 || finish2_line != 1 );
     }
    return 0;
}
void printMap (char A[rows][columns])
{
	int row=15;
    int col=30;
    int i,j;
    for(i=0;i<col;i++) //data entry to the top row
    {
        A[0][i]='.';
    }
    for(i=0;i<col;i++) //data entry to the bottom line
    {
        A[14][i]='.';
    }
    for(i=1;i<row-1;i++)//data entry in the leftmost column
    {
        A[i][0]=':';
    }
    for(i=1;i<row-1;i++)//data entry in the rightmost column
    {
        A[i][29]=':';
    }
    for(i=2;i<28;i++)// same things for 2. area
    {
        A[2][i]='.';
    }
    for(i=2;i<28;i++)
    {
        A[12][i]='.';
    }
    for(i=2;i<11;i++)
    {
        A[i+1][2]=':';
    }
    for(i=2;i<11;i++)
    {
        A[i+1][27]=':';
    }
     for(i=4;i<26;i++)// same things for 3. area
    {
        A[4][i]='.';
    }
    for(i=4;i<26;i++)
    {
        A[10][i]='.';
    }
    for(i=5;i<10;i++)
    {
        A[i][4]=':';
    }
    for(i=5;i<10;i++)
    {
        A[i][25]=':';
    }
    A[1][14]='X';//penalty points
    A[7][28]='X';
    A[3][10]='X';
    A[3][18]='X';
    A[5][26]='X';
    A[13][14]='X';
    A[10][26]='X';
    A[11][10]='X';
    A[11][18]='X';
    A[2][1]='_';//finish lines
    A[4][3]='_';
   
    
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(A[i][j]!='.' && A[i][j]!=':' && A[i][j]!='X' && A[i][j]!='1' && A[i][j]!='2' &&  A[i][j]!='_')
            {
                A[i][j]=' ';//enter spaces in blanks
            }
        }
    }
     for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)// print all thiings
        {
        	if( A[i][j]==A[1][14] || A[i][j]==A[7][28] || A[i][j]==A[3][10] || A[i][j]==A[3][18] || A[i][j]==A[5][26] || A[i][j]==A[13][14] || A[i][j]==A[10][26] || A[i][j]==A[11][10] || A[i][j]==A[11][18])
        	{
        		printf("\033[1;31m");
        		printf("%c",A[i][j]);
        	}
        	else if(A[i][j]==A[2][1] || A[i][j]==A[4][3])
        	{
        		printf("\033[1;32m");
        		printf("%c",A[i][j]);
        	}
        	else if(A[i][j]==A[1][1])
        	{
        		printf("\033[1;33m");
        		printf("%c",A[i][j]);
        	}
        	else if(A[i][j]==A[3][3])
        	{
        		printf("\033[1;34m");
        		printf("%c",A[i][j]);
        	}
        	else
        	{	
        		printf("\033[1;37m");
        		printf("%c",A[i][j]);
        	}
        }
        printf("\n");
    }
}
int dice()
{
	char game;// dice algorithm
	int dice;
	srand(time(NULL));
	scanf("%c",&game);
	if(game==10)
    {
        dice=rand() % 6 + 1;
    }
  
	return dice;
}
int startGame(int p1,int p2)
{	

	
	while(p1==p2)//if they are equal program want again
    {
    printf("\033[1;37m");
    printf("Same dice value... Please try again\n");
    printf("\033[1;33m");
    printf("PLAYER 1... press ENTER to dice\n");
        p1=dice();
        printf("\033[1;33m");
	printf("DICE: %d\n",p1);
	printf("\033[1;34m");
	printf("PLAYER 2... press ENTER to dice\n");
	p2=dice();
	printf("\033[1;34m");
    printf("DICE: %d\n",p2);
    }
    if(p1>p2)
    {
    printf("\033[1;37m");
    	printf("***Player 1 start game***\n");
        return 1;
    }
    else
    {
    printf("\033[1;37m");
    	printf("***Player 2 start game***\n");
        return 2;
    }
	
}
