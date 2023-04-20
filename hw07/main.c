#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
      FILE *fp;
char arrayOfWords[50][50];
char chosenWord[7][50];
int wordCount = 0, i,j;
fp = fopen("wordlist.txt", "r");
if(fp != NULL) {
    while(!feof(fp)) {
        fscanf(fp, "%s", arrayOfWords[wordCount]);//Stringing 50 words
        wordCount++;
    }
}
 char map[15][15];// map array
 for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
        {
            map[i][j]=' ';//I added space to each element
        }
    }
    srand(time(NULL));


    int n=rand()%50+1;
        int n0=rand()%50+1;//0
        while(n==n0)
        {
        	 n0=rand()%50+1;
        }
        strcpy(chosenWord[0],arrayOfWords[n0]);//Randomly pick one of 50
        int n1=rand()%50+1;//1
        while(n0==n1)//algorithm to avoid getting the same
        {
        	 n1=rand()%50+1;
        }
        strcpy(chosenWord[1],arrayOfWords[n1]);//Randomly pick one of 50
        int n2=rand()%50+1;//2
        while(n2==n && n2==n1)//algorithm to avoid getting the same
        {
        	 n2=rand()%50+1;
        }
        strcpy(chosenWord[2],arrayOfWords[n2]);//Randomly pick one of 50
        int n3=rand()%50+1;//3
        while(n3==n2 && n3==n1 && n3==n0)//algorithm to avoid getting the same
        {
        	n3=rand()%50+1;
        }
        strcpy(chosenWord[3],arrayOfWords[n3]);//Randomly pick one of 50
        int n4=rand()%50+1;//4
        while(n4==n3 && n4==n2 && n4==n1 && n4==n0)//algorithm to avoid getting the same
        {
        	 n4=rand()%50+1;
        }
        strcpy(chosenWord[4],arrayOfWords[n4]);//Randomly pick one of 50
        int n5=rand()%50+1;//5
        while(n5==n4 && n5==n3 && n5==n2 && n5==n1 && n5==n0)//algorithm to avoid getting the same
        {
        	 n5=rand()%50+1;
        }
        strcpy(chosenWord[5],arrayOfWords[n5]);//Randomly pick one of 50
        int n6=rand()%50+1;//6
        while(n6==n5 && n6==n4 && n6==n3 && n6==n2 && n6==n1 && n6==n0)//algorithm to avoid getting the same
        {
        	 n6=rand()%50+1;
        }
        strcpy(chosenWord[6],arrayOfWords[n6]);//Randomly pick one of 50

        
    int a;
    int sayac=0;
   	int col,row;
   	 int x=0;
   	 int len;
   	 int tempcol[7];
   	 int temprow[7];
	for(j=0;j<7;j++)
	{
    	
     len =strlen(chosenWord[x]);// length of chosen word
	a=rand()%8;//Choice of one of the 8 directions
	col=rand()%15;
    row=rand()%15;
    	tempcol[x]=col+1;
	temprow[x]=row+1;
	printf("%d %d %s\n",temprow[x],tempcol[x], chosenWord[x]);//coordinates and spelling of the word
	switch(a)
	{
		case 0:

    while(col-1+len > 14)//so that it doesn't spill out
    {
        col=rand()%15;

    }

    if(map[row][col]==' ' && map[row][col+1]==' ' && map[row][col+2]==' ' && map[row][col+3]==' ' && map[row][col+4]==' ')//to put it in non-empty places
    {
    for(i=0;i<len;i++)
    {
        map[row][col]=chosenWord[x][i];
        col++;
    }
    }
    else
    {
    	sayac++;
    }
		break;
	case 1:


    while(col+1-len <0)
    {
        col=rand()%15;

    }

    if(map[row][col]==' ' && map[row][col-1]==' ' && map[row][col-2]==' ' && map[row][col-3]==' ' && map[row][col-4]==' ')//to put it in non-empty places
    {
    for(i=0;i<len;i++)
    {
        map[row][col]=chosenWord[x][i];
        col--;
    }
		
    }
    else
    {
    	sayac++;
    }
	break;
	case 2:


    while(row-1+len >14)
    {
        row=rand()%15;

    }

    if(map[row][col]==' ' && map[row+1][col]==' ' && map[row+2][col]==' ' && map[row+3][col]==' ' && map[row+4][col]==' ')//to put it in non-empty places
    {
    for(i=0;i<len;i++)
    {
        map[row][col]=chosenWord[x][i];
        row++;
    }
		
    }
    else
    {
    	sayac++;
    }
	break;
    case 3:


    while(row+1-len <0)
    {
        row=rand()%15;

    }

    if(map[row][col]==' ' && map[row-1][col]==' ' && map[row-2][col]==' ' && map[row-3][col]==' ' && map[row-4][col]==' ')
    {
    for(i=0;i<len;i++)
    {
        map[row][col]=chosenWord[x][i];
        row--;
    }
		
    }
    else
    {
    	sayac++;
    }
	break;
	case 4:


    while(row-1+len >14 || col-1+len > 14)
    {
        row=rand()%15;
        col=rand()%15;

    }

    if(map[row][col]==' ' && map[row+1][col+1]==' ' && map[row+2][col+2]==' ' && map[row+3][col+3]==' ' && map[row+4][col+4]==' ')//to put it in non-empty places
    {
    for(i=0;i<len;i++)
    {
        map[row][col]=chosenWord[x][i];
        row++;
        col++;
    }
		
    }
    else
    {
    	sayac++;
    }
	break;

	case 5:


    while(row-1+len >14 || col+1-len < 0)
    {
        row=rand()%15;
        col=rand()%15;

    }

    if(map[row][col]==' ' && map[row+1][col-1]==' ' && map[row+2][col-2]==' ' && map[row+3][col-3]==' ' && map[row+4][col-4]==' ')//to put it in non-empty places
    {
    for(i=0;i<len;i++)
    {
        map[row][col]=chosenWord[x][i];
        row++;
        col--;
    }
		
    }
    else
    {
    	sayac++;
    }
	break;
	case 6:


    while(row+1-len <0 || col-1+len > 14)
    {
        row=rand()%15;
        col=rand()%15;

    }

    if(map[row][col]==' ' && map[row-1][col+1]==' ' && map[row-2][col+2]==' ' && map[row-3][col+3]==' ' && map[row-4][col+4]==' ')//to put it in non-empty places
    {
    for(i=0;i<len;i++)
    {
        map[row][col]=chosenWord[x][i];
        row--;
        col++;
    }
		
    }
    else
    {
    	sayac++;
    }
	break;	
	case 7:


    while(row+1-len <0 || col+1-len < 0)
    {
        row=rand()%15;
        col=rand()%15;

    }

    if(map[row][col]==' ' && map[row-1][col-1]==' ' && map[row-2][col-2]==' ' && map[row-3][col-3]==' ' && map[row-4][col-4]==' ')//to put it in non-empty places
    {
    for(i=0;i<len;i++)
    {
        map[row][col]=chosenWord[x][i];
        row--;
        col--;
    }
		
    }
    else
    {
    	sayac++;
    }
	break;
	default:
	break;	
    } // switch
	x++;} // for
    char random;
    for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
        {
        	if(map[i][j]==' ')
        	{
        	random=rand()%26+97;
        	map[i][j]=random;// random letter assignment
           	}
        }
    }
    char arr[10];
    int coorc;
    int coorr;
    int finish=0;
    int total=0;
    
    do
    {
     for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
        {

           	printf("%c ",map[i][j]);//print map
       
        }
        printf("\n");
    }
    printf("Enter coordinates and word:");
    scanf("%s",arr);
    if(strcmp(arr,":q")==0)// for the game to end when ':q' is entered 
    {
    	finish=1;
    	printf("Your game finished.\n");
    	break;
    }
    else
    {
    
    }

       
    }
    while(finish!=1);// the game cannot be played
    
	



    return 0;
}


