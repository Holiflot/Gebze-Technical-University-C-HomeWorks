#include <stdio.h>
#include "util.h"

void fraction_print(int numerator, int denominator) {
    printf("%d//%d", numerator, denominator);
}  /* end fraction_print */

void fraction_add(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2 + n2*d1; /* mathematical formula for addition.*/
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_add */

void fraction_sub(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1 * d2 - n2 * d1;/* mathematical formula for subtraction.*/
    *d3 = d1 * d2;
    /* multiply negative numbers in the numerator and denominator by "-1" to appear correctly in output. */
    if(*n3<0 && *d3 < 0) 
    {
    *n3 = *n3 * (-1);
    *d3 = *d3 * (-1);
    }
    fraction_simplify(n3, d3);
} /* end fraction_sub */

void fraction_mul(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1 * n2;/* mathematical formula for multiplition.*/
    *d3 = d1 * d2;
    /* multiply negative numbers in the numerator and denominator by "-1" to appear correctly in output. */
    if(*n3<0 && *d3 < 0)
    {
    *n3 = *n3 * (-1);
    *d3 = *d3 * (-1);
    }
    fraction_simplify(n3, d3);
} /* end fraction_mul */

void fraction_div(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    /*A mathematical error was occurring because the second fraction was inverted and multiplied while dividing fractions. An error code was sent for this.*/
    if(n2==0)
    {
    	printf("Diversion is undefine.Result is not true!");
    }
    else
    {
    *n3 = n1 * d2;/* mathematical formula for diversion.*/
    *d3 = n2 * d1;
    }
    /* multiply negative numbers in the numerator and denominator by "-1" to appear correctly in output. */
    if(*n3<0 && *d3 < 0) 
    {
    *n3 = *n3 * (-1);
    *d3 = *d3 * (-1);
    }
    fraction_simplify(n3, d3);
} /* end fraction_div */

/* Simplify the given fraction such that they are divided by their GCD */
void fraction_simplify(int * n, int * d) {
     int i;
     int gcd=1;
    for(i=1; i<=*n || i<=*d;i++) /* find the greatest common divisor */
    {
       if(*n%i==0 && *d%i==0)
       {
            gcd=i;
       }
    } *n= *n/gcd;	/*division by greatest common divisor */
      *d=*d/gcd;
} /* end fraction_div */
