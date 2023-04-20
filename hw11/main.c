#include <stdio.h>
#include "util.h"


int main()
{
    /* A fractional number: 13/7 */
    int num1 = 13, den1 = 7;
    /* A fractional number: 13/7 */
    int num2 = 30, den2 = 11;
    /* An unitilized fractional number */
    int num3, den3;
    

    printf("First number: ");
    fraction_print(num1, den1);
    printf("\n");

    printf("Second number: ");
    fraction_print(num2, den2);
    printf("\n");

    printf("Addition: ");
    fraction_add(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Subtraction: ");
    fraction_sub(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Multiplication: ");
    fraction_mul(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Division: ");
    fraction_div(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");
    /* A fractional number: 13/7 */
    printf("Please enter the numerator and denominator of your first number.\n");
    int mynum1,myden1;
    scanf("%d %d",&mynum1,&myden1);
    while(myden1==0)
    {
        printf("denominator can not be zero, please enter a different number");
        scanf("%d",&myden1);
    }
    /* A fractional number: 13/7 */
    printf("Please enter the numerator and denominator of your first number.\n");
    int mynum2,myden2;
    scanf("%d %d",&mynum2,&myden2);
    while(myden2==0)
    {
        printf("denominator can not be zero, please enter a different number");
        scanf("%d",&myden2);
    }
    /* An unitilized fractional number */
    printf("First number: ");
    fraction_print(mynum1, myden1);
    printf("\n");

    printf("Second number: ");
    fraction_print(mynum2, myden2);
    printf("\n");

    printf("Addition: ");
    fraction_add(mynum1, myden1, mynum2, myden2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Subtraction: ");
    fraction_sub(mynum1, myden1, mynum2, myden2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Multiplication: ");
    fraction_mul(mynum1, myden1, mynum2, myden2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Division: ");
    fraction_div(mynum1, myden1, mynum2, myden2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");


    return(0);
}
