#include "util.h"
#include <stdio.h>
#include <stdlib.h>


void generate_sequence(int xs, int currentlen, int seqlen, int *seq)
{
   int i;

   if(currentlen<=seqlen)//continues until currentlen equals seqlen
   {
      *(seq+currentlen)=xs;//inserting numbers into array incrementing by 1

      if(xs%2==1)
      {
         generate_sequence( xs*3+1,  currentlen+1,  seqlen,  seq);//odd number algorithm
      }
      else
      {
         generate_sequence( xs/2,  currentlen+1,  seqlen,  seq)  ;//even number algorithm
      }

   }
}
int has_loop(int *arr, int n, int looplen, int *ls, int *le)
{
      int i,c;
      *ls=0;
      if(looplen!=n/2)
      {
         *ls=(n/2-(looplen))*2;
      }
      *le=*ls+looplen-1;
      int control=0;
          if (n % 2 == 1)//to skip once in odd number long loops
        {
            c = 1;
        }
        else
        {
            c = 0;
        }
        for (i = 0 + c; i < looplen + c; i++)//to skip once in odd number long loops
        {

            if (arr[i + *ls+c] == arr[i + looplen + *ls+c])
            {
                control++;//if the numbers corresponding to the loop are the same, the control variable is increased by 1
            }
            else
            {
                control--;
            }
        }
        if (control == looplen)//if contol variable equal to loop length it will return 1
        {
            return 1;
        }
        else
        {

            return 0;//if not zero
        }
        
        control = 0;
      
}         
void check_loop_iterative(void (*f)(), int xs, int seqlen, int *loop, int *looplen)
{
   static int currentlen=0;
   int *arr;
   int i;
   arr=(int *)malloc(seqlen*sizeof(int));//for sequence array
   f(xs,  currentlen,  seqlen,  arr);
   if(*looplen==seqlen/2)//to write only once
   {
      printf("\nSequence: {");
      for(i=0;i<seqlen-1;i++)
      {
         printf("%d, ",arr[i]);
      }
      printf("%d }",arr[seqlen-1]);
               printf("\n");
   }
   
   int n=seqlen;
   int ls,le;
   int result=has_loop( arr,  n, *looplen,  &ls,  &le);// the result holds the number returned by the hasloop function
   if(result==1)
   {
      if(seqlen%2==0)//for even numbers
      {
         printf("Checking if there is a loop of length %d...\n",*looplen);
         printf("\n\n");
      printf("loop detected with  a length of %d.\n",*looplen);
      printf("The indexes of the loop's first occurance: %d (first digit), %d (last digit)\n",ls,le);
      for(i=0;i<*looplen;i++)//found and print loop  numbers
      {
         loop[i]=arr[i+ls];
      }
      printf("Loop: {");
      for(i=0;i<*looplen-1;i++)
      {
         printf("%d,",loop[i]);
      }
      printf("%d",loop[*looplen-1]);
      printf("}\n");
      }
      else//for odd numbers
      {
         printf("Checking if there is a loop of length %d...\n",*looplen);
         printf("\n\n");
         printf("loop detected with  a length of %d.\n",*looplen);
      printf("The indexes of the loop's first occurance: %d (first digit), %d (last digit)\n",ls+1,le+1);
      for(i=0;i<*looplen;i++)//found and print loop  numbers
      {
         loop[i]=arr[i+ls+1];
      }
      printf("{");
      for(i=0;i<*looplen-1;i++)
      {
         printf("%d,",loop[i]);
      }
      printf("%d",loop[*looplen-1]);
      printf("}\n");
      }  
   }
   else
   {//if the result is 0 it repeats the function until the loop length is at least 2
      if(*looplen>=2) 
      {
         printf("Checking if there is a loop of length %d...\n",*looplen);
         if(*looplen==2)
         {
            printf("No loop found.\n");
         }
         *looplen=*looplen-1;
         check_loop_iterative(f,  xs,  seqlen, loop, looplen);
      }    
      
   }
}
void hist_of_firstdigits(void (*f)(), int xs, int seqlen, int *h, int digit)
{
   static int currentlen=0;
   int *seq;
   int i;
   seq=(int *)malloc(seqlen*sizeof(int));
   f(xs,  currentlen,  seqlen,  seq);
   int a[seqlen];
   for(i=0;i<seqlen;i++)//find the first digits of the numbers in the array and placed them in an index
   {
      if(seq[i]>99)
      {
         a[i]=seq[i]/100;
      }
      else if(seq[i]>9 && seq[i]<100)
      {
         a[i]=seq[i]/10;
      }
      else if(seq[i]>999)
      {
         a[i=seq[i]]/1000;
      }
      else
      {
         a[i]=seq[i];
      }
   }
   
   if(digit<=9)//function repeats until digit is 9
   {
      for(i=0;i<seqlen;i++)
      {
         if(a[i]==digit)
         {
            h[digit]++;//histogram algorithm
         }
      }
      hist_of_firstdigits(f,  xs,  seqlen, h,  digit+1);
   }
}






