#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#define CLOSE_ENOUGH 0.001


int main()
{
/* Ask for the problem selection (1,2,3) .....  */
    int choice;
    printf("Which problem would you like to solve 1, 2 or 3? ");
    scanf("%d",&choice);
    while((choice<1) || (choice>4))
    {
    	printf("Its must be between 1 to 3!\n");
    	printf("please enter again: "); 
    	scanf("%d",&choice);
    }
    
        if(choice==1)
        {
         /* Get the input from the user for the first problem, i.e., to test dt1a and dt1b */
            double PL,PW,SW,SL;
            char result1,result2;
            printf("please enter PL, PW, SW and SL values.\n");
            scanf("%lf %lf %lf %lf",&PL,&PW,&SW,&SL);
            result1=dt1a(PL,PW,SW,SL);
            result2=dt1b(PL,PW,SW,SL);
             /* Compare performances and print results */
            if(result1==result2)
            {
		     if(result1=='s')
		     {
		         printf("According to the result, this flower is a setosa.\n");
		     }
		     else if(result1=='v')
		     {
		         printf("According to the result, this flower is a virginica.\n");
		     }
		     else
		     {
		         printf("According to the result, this flower is a versicolor.\n");
		     }
            }
            else
            {
            	     if(result1=='s')
		     {
		         printf("According to the result, this flower is a setosa.\n");
		     }
		     else if(result1=='v')
		     {
		         printf("According to the result, this flower is a virginica.\n");
		     }
		     else
		     {
		         printf("According to the result, this flower is a versicolor.\n");
		     }
		     if(result2=='s')
		     {
		         printf("According to the result, this flower is a setosa.\n");
		     }
		     else if(result2=='v')
		     {
		         printf("According to the result, this flower is a virginica.\n");
		     }
		     else
		     {
		         printf("According to the result, this flower is a versicolor.\n");
		     }
            }
            

        }
        else if(choice==2)
        {
        /* Get the input from the user for the second problem, i.e., to test dt2a and dt2b */
            double x1,x2,x3;
            int x4,x5;
            printf("please enter three real numbers.\n");
            printf("first real number= ");
            scanf("%lf",&x1);
             printf("Second real number= ");
            scanf("%lf",&x2);
             printf("Third real number= ");
            scanf("%lf",&x3);
            printf("please enter two binary number.Its must be 0 or 1!\n");
            printf("first binary number= ");
            scanf("%d",&x4);
              printf("second binary number= ");
            scanf("%d",&x5);
            while(x4!=0 && x4!=1)/*error code*/
            {
                printf("You entered wrong numbers.Please enter two binary number.Its must be 0 or 1!\n");
                scanf("%d",&x4);
            }
             while(x5!=0 && x5!=1)/*error code*/
            {
                printf("You entered wrong numbers.Please enter two binary number.Its must be 0 or 1!\n");
                scanf("%d",&x5);
            }
            double  a,b;
            a=dt2a(x1,x2,x3,x4,x5);
            b=dt2b(x1,x2,x3,x4,x5);
             /* Compare performances and print results */
            if(((a-b>0) && (a-b<=CLOSE_ENOUGH)) || ((b-a>0) && (b-a<=CLOSE_ENOUGH)))
            {
                printf("Result is %lf",(a+b)/2);
            }
            else
            {
                printf("First result is %lf\n",a);
                printf("Second result is %lf\n",b);
            }

        }
        else
        /* Get the input from the user for the third problem, i.e., to test dt3a and dt3b */
        {
        	int coin_investing,fear_greed_index,risk_range;
        	double btc_dominans,total_value;
        	printf("Dou you want to invest any coin.Enter 1 if yes,enter 0 if not.\n");
        	scanf("%d",&coin_investing);
        	 while(coin_investing!=0 && coin_investing!=1)/*error code*/
            {
                printf("You entered wrong numbers.Please enter two binary number.Its must be 0 or 1!\n");
                scanf("%d",&coin_investing);
            }
        	printf("Enter btc dominans value.");/*This data must be taken from the coinmarketcap.com site and entered.*/
        	scanf("%lf",&btc_dominans);
        	printf("extreme fear= 1\n");/*fear greed index cateogory*/
        	printf("fear= 2\n");
        	printf("normal= 3\n");
        	printf("greed= 4\n");
        	printf("extreme greed= 5\n");
        	printf("Please enter fear greed index value = ");/*This data must be taken from the coinmarketcap.com site and entered.*/
        	scanf("%d",&fear_greed_index);
        	 while((fear_greed_index<0) || (fear_greed_index>6))/*error code*/
            {
                printf("You entered wrong numbers.Its must be between 1 to 5!\n");
                scanf("%d",&fear_greed_index);
            }
        	printf("Enter total market cap value.PLease enter in  trillion dolars! (Example 1.3)\n");
        	scanf("%lf",&total_value);/*This data must be taken from the coinmarketcap.com site and entered.*/
        	printf("risky= 1\n");/*category of person's perception of risk*/
        	printf("low risk= 2\n");
        	printf("little risk free= 3\n");
        	printf("risk free= 4\n");
        	printf("choose your risk range =");/*entering the person's perception of risk*/
        	scanf("%d",&risk_range);
        	 while((risk_range<0) || (risk_range>4))/*error code*/
            {
                printf("You entered wrong numbers.Its must be between 1 to 5!\n");
                scanf("%d",&risk_range);
            }
            /* Compare performances and print results */
        	dt3a(coin_investing,fear_greed_index,risk_range,btc_dominans,total_value);
        	dt3b(coin_investing,fear_greed_index,risk_range,btc_dominans,total_value);
        }

    

    return 0;
}

