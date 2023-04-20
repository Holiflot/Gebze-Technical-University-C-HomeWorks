#include <stdio.h>
#include <stdlib.h>
#include "util.h"



int main()
{
    int i;
    int seqlen,xs;
    int *loop;
    int looplen;
    printf("Please enter the sequence length: ");
    scanf("%d",&seqlen);
    printf("Please enter the first element: ");
    scanf("%d",&xs);
    looplen=seqlen/2;
    loop=(int *)malloc(looplen*sizeof(int));//I freed up the loop length of memory
    check_loop_iterative(generate_sequence,  xs,  seqlen,  loop,  &looplen);
    int *h;
    int digit=0;
    h=(int *)malloc(10*sizeof(int));//I freed up the memory
    hist_of_firstdigits(generate_sequence,  xs,  seqlen,  h,  digit);
    printf("\nHistogram of sequence: {");
    for(i=1;i<9;i++)
    {
        printf("%d, ",h[i]);// print histogram ignored 0. index
    }
    printf("%d",h[9]);
    printf("}\n");

    return 0;
}

