#include <stdio.h>
#include "util.h"
#include <math.h>

/* Example decision tree - see the HW2 description 
int dt0(int t, double p, double h, int s, int w) {
    int r = 0;
    if (t>35 && w!=3) r = 1;
    else if (t<=35 && s==0) r = 1;
    return r;
}*/
char dt1a(double PL,double PW,double SW,double SL)
{
	if(PL < 2.45)
	{
		return 's';/*setosa*/
	}
	else
	{
		if(PW < 1.75)
		{
			if(PL < 4.95)
			{
				if(PW < 1.65)
				{
					return 'c';/*versicolor*/
				}
				else
				{
					return 'v';/*virginia*/
				}
			}
			else
			{
				return 'v';
			}
		}
		else
		{
			return 'v';
		}
	}
}
char dt1b(double PL,double PW,double SW,double SL)
{
	if(PL < 2.55)
	{
		return 's';
	}
	else 
	{
		if(PW < 1.69)
		{
			if(PL < 4.85)
			{
				return 'c';
			}
			else
			{
				return 'v';
			}
		}
		else
		{
			return 'v';
		}
	}
}
double dt2a(double x1,double x2,double x3,int x4,int x5)
{
	if(x1 < 31.5)
	{
		if(x2 > -2.5)
		 {
		 	return 5;
		 }
		 else
		 {
		 	if((x2-0.1 <= x1) && (x1<=x2+0.1))
		 	{
		 		return 2.1;
		 	}
		 	else
		 	{
		 		return -1.1;
		 	}
		 }
	}
	else
	{
		if((-1 <= x3) && (x3<= 3))
		{
			return 1.4;
		}
		else
		{
			if((x4 && x5)==1)
			{
				return -2.23;
			}
			else
			{
				return 11.0;
			} 
		}
	}
}
double dt2b(double x1,double x2,double x3,int x4,int x5)
{
	if((12 < x1) && (x1< 22))
	{
		if(x2 > 5/3)
		 {
		 	return -2.0;
		 }
		 else
		 {
		 	if((x1-0.1 <= x3) && (x3<=x1+0.1))
		 	{
		 		return 1.01;
		 	}
		 	else
		 	{
		 		return -8;
		 	}
		 }
	}
	else
	{
		if((x4 && x5)==1)
		{
			return -1;
		}
		else
		{
			if((-1 <= x2) && (x2<= 2))
			{
				return -1.0/7.0;
			}
			else
			{
				return sqrt(2)/3;
			} 
		}
	}
	
}


/* Provide your implementations for all the requested functions here */
/*The logic of the problem is to get the important data for the coin investment from the user and correct it for the user.*/
void dt3a(int coin_investing,int fear_greed_index,int risk_range,double btc_dominans,double total_value)
{
	if(coin_investing==1)/*The user is asked if he/she wants to invest in coins.*/
	{
		if(btc_dominans < 61.24)/*Enters the condition according to the btc dominans.*/
		{
			if(fear_greed_index <3)/*Enters the condition according to the fear greed index.*/
			{
				if(risk_range >= 2)/*The risk criteria, which are the user's own characteristics, are entered and compared.*/
				{
					printf("You need to choose ecosystem altcoins(like ETH,AVAX,SOLANA...)\n");
				}
				else
				{
					printf("You need to choose NFT altcoins(like MANA,SAND,APE...)\n");
				}
			}
			else
			{
				if(risk_range < 2)
				{
					printf("You need to choose shitcoins(like DOGE,SHİBU...)\n");
				}
				else
				{
					printf("You should not invest now.\n");
				}
			}
		}
		else
		{
			if(total_value < 2)/*Enters the condition according to the btc dominans.*/
			{
				printf("You need to buy BTC.\n");
			}
			else
			{
				printf("You should not invest now.\n");
			}
		}
	}
	else
	{
		printf("You should invest other things(like gold,silver) or not.\n");
	}
}
void dt3b(int coin_investing,int fear_greed_index,int risk_range,double btc_dominans,double total_value)
{
	if(coin_investing==1)
	{
		if(btc_dominans < 43.56)/*Enters the condition according to the btc dominans.*/
		{
			if(fear_greed_index < 2)/*Enters the condition according to the fear greed index.*/
			{
				if(risk_range > 2)
				{
					printf("You shouldn not invest now.\n");
				}
				else
				{
					printf("You need to choose ecosystem altcoins(like ETH,AVAX,SOLANA...)\n");
				}
			}
			else
			{
				if(risk_range < 2)/*The risk criteria, which are the user's own characteristics, are entered and compared.*/
				{
					printf("You need to choose NFT altcoins(like MANA,SAND,APE...)\n");
				}
				else
				{
					printf("You should not invest now.\n");
				}
			}
		}
		else
		{
			if(total_value < 1.2)/*Enters the condition according to the btc dominans.*/
			{
				printf("You need to buy BTC.\n");
			}
			else
			{
				printf("You should not invest now.\n");
			}
		}
	}
	else
	{
		printf("You should invest other things(like gold,silver) or not.\n");
	}	
}
