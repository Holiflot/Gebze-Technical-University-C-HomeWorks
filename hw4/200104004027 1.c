#include <stdio.h>

void coefficient_file(int a, int b, int c);
int draw_cartezien();
int draw_cartezien_txt();

int main(){
   FILE *txt;
   int choice;
   int a,b,c;
   int x,y;
   do{
   printf("1 -> Enter the coefficients\n");
   printf("2 -> Draw the graph.\n");
   printf("3 -> Print the graph into a .txt file.\n");
   printf("4. Exit\n");
   scanf("%d",&choice);
   switch(choice)
   {
      case 1:
             printf("Please enter the coefficient for the following equation: x=a*(y*y) + b*y + c\n");
          printf("a: ");
          scanf("%d",&a);
          printf("b: ");
          scanf("%d",&b);
          printf("c: ");
          scanf("%d",&c);
          coefficient_file(a,b,c);
            
      break;
      case 2:
         draw_cartezien();
      break;
      case 3:
        draw_cartezien_txt();
      break;
      case 4:
      break;
      default:
        printf("You can enter only 1,2,3 or 4\n");
      break;
      }
     }while(choice != 4);
  return 0;
}

void coefficient_file(int a, int b, int c)
{
  FILE *txt;
  txt = fopen("coefficients.txt","w");
  fprintf(txt,"%d\n",a);
  fprintf(txt,"%d\n",b);
  fprintf(txt,"%d\n",c);
  fclose(txt);
  printf("coefficients.txt file has been created.\n");
}


int draw_cartezien()
{
  int a = 0,b = 0,c = 0;
  FILE *txt;
  txt = fopen("coefficients.txt","r");
  if(txt == NULL)
   {
      printf("Data could not be retrieved!");
      return 0;
   }
  fscanf(txt,"%d ",&a);
  fscanf(txt,"%d ",&b);
  fscanf(txt,"%d ",&c);
  fclose(txt);

  printf("Coefficients has been read from the coeffecient.txt file.\n");
  printf("Printing the graph of x=%d(y*y) + %d*y + %d\n",a,b,c);

  int i,j;
  int min = -50,max = 15;
  int x,y;
  for(i = 0;i < 31;i++)
  {
    y = 15 - i;
    x = a*(y*y) + b*y + c;
    if(i != 15)
    {
       for(j = 0;j < 107;j++)
       {
         if(i == 16 && j%10==0)
         {
            printf("\033[0;33m");
            printf("%3d",min);
            printf("\033[0m");
            j+=3;
            min+=10;
         }
         if(j == x + 54)
         {
            if(i != 16)
            {
              printf("\033[0;34m");
              printf("\b#");
              printf("\033[0m");
            }
            else if(i == 16)
            {
              if(j%10 == 1)
              {
               printf("\033[0;34m");
               printf("\b#\b\b  ");
               printf("\033[0m");
              }
              else if(j%10 == 2)
              {
               printf("\033[0;34m");
               printf("\b\b #\b ");
               printf("\033[0m");
              }
              else if(j%10 == 3)
              {
               printf("\033[0;34m");
               printf("\b\b\b  #");
               printf("\033[0m");
              }
              else
              {
               printf("\033[0;34m");
               printf("\b#");
               printf("\033[0m");
              }
            }
            
         }
         printf(" ");
       if(i%5 == 0 && j == 51)
       {
        if(max == 0) max = -5;
        printf("\033[0;33m");
        printf("\b\b\b%3d",max);
        printf("\033[0m");
        max-=5;
       }

       if(j == 52) printf("\b|");
       
    }
    }
    else
    {
       printf("<");
       for(j = 0;j < 105;j++)
       {
          if(j != 51)
          {
          printf("-");
          }
          else printf("|");
          if(j == c + 51)
          {
            printf("\033[0;34m");
            printf("\b#");
            printf("\033[0m");
          }
       }
       printf(">");
    }

    printf("\n");
  }
}

int draw_cartezien_txt()
{
  int a = 0,b = 0,c = 0;
  FILE *txt;
  txt = fopen("coefficients.txt","r");
  if(txt == NULL)
   {
      printf("Error!");
      return 0;
   }
  fscanf(txt,"%d ",&a);
  fscanf(txt,"%d ",&b);
  fscanf(txt,"%d ",&c);
  fclose(txt);

  printf("Coefficients has been read from the coeffecient file.\n");
  
  FILE *graph;
  graph = fopen("graph.txt","w");
  
  int i,j;
  int min = -50,max = 15;
  int x,y;
  for(i = 0;i < 31;i++)
  {
    y = 15 - i;
    x = a*(y*y) + b*y + c;
   
    if(i != 15)
    {
       for(j = 0;j < 107;j++)
       {
         if(i == 16 && j%10==0)
         {
            fprintf(txt,"%3d",min);
            j+=3;
            min+=10;
         }
         if(j == x + 52)
         {
            if(i != 15)
            {
              fprintf(txt,"\b#");
            }
            else if(i == 15)
            {
              if(j%10 == 1)
              {
               fprintf(txt,"\b#\b\b  ");
              }
              else if(j%10 == 2)
              {
               fprintf(txt,"\b\b #\b ");
              }else if(j%10 == 3)
              {
               fprintf(txt,"\b\b\b  #");
              }else
              {
               fprintf(txt,"\b#");
              }
            }
            
         }
         fprintf(txt," ");
       if(i%5 == 0 && j == 51)
       {
        if(max == 0) max = -5;
          fprintf(txt,"\b\b\b%3d",max);
        max-=5;
       }

       if(j == 52) fprintf(txt,"\b|");
       }
    }
    else
    {
       fprintf(txt,"<");
       for(j = 0;j < 105;j++)
       {
          if(j != 51)
          {
            fprintf(txt,"-");
          }else fprintf(txt,"|");
          if(j == c + 51)
          {
            fprintf(txt,"\b#");
          }
       }
       fprintf(txt,">");
    }

    
  }
  fclose(graph);
  printf("The graph of x=%d(y*y) + %d*y + %d has been written to graph.txt file.\n",a,b,c);
  printf("\n");
}


