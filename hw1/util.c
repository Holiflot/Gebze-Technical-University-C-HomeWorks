#include <stdio.h>
#include "util.h"

int find_divisible(int x,int y,int z)
{
    int i,f=0;
    if(x<y && y==x)/*second integer must be bigger than first.if not error code is sent in main*/
    	{
    		return f;
    	}

    for(i=y-1;i>x;i--)
    {
        if(i%z==0)
        {
            f=i;/*algorithm to find the first divisor*/
        }
    }
        return f;
}
int find_nth_divisible(int n,int f_I,int z)
    {
    	int result=0;/*n. number finding algorithm*/
    	result=f_I+z*n;
    	return result;
    }
     //part2
    
     int validate_identity_number(char identity_number[])
    {
    	int i=0,length=0;
    	int odd=0,even=0;
    	int ascii_check=0;/*Value found to check letter or number*/
    	int control_check=0;/*Value found to check number of steps*/
    	
    	while(identity_number[i])/*Algorithm that checks input of 11 characters*/
        {
            i++;
        }
        length=i;
        if(length==11)
    	{
    		control_check ++;/*if it is true,step count increases by one*/
    	}
    	 for(i=0;i<11;i++)
        {
            if(identity_number[i]-48>=0 && identity_number[i]-48<=9)/*Algorithm that checks data consists of numbers*/
            {
                ascii_check ++;/*increases if true*/
            }
        }
        if(ascii_check==11)/*if it is true,step count increases by one*/
        {
            control_check++;
        }
            	if(identity_number[0]-48!=0)/*Algorithm that checks first number.It must be different from 1.*/
    	{
    		control_check ++;/*if it is true,step count increases by one*/
    	}
    	for(i=0;i<5;i++)
    	{
    		odd = odd + (identity_number[2*i]-48);/*addition of odd numbers*/
    	}
    	for(i=0;i<4;i++)
    	{
    		even = even + (identity_number[2*i+1]-48);/*addition of even numbers*/
    	}

    	if((odd*7-even)%10==(identity_number[9]-48) && (odd+even+identity_number[9]-48)%10==identity_number[10]-48)/*checking the 10th and 11th numbers according to the given formula*/
    	{
    		control_check++;/*if it is true,step count increases by one*/
    	}
    	if(control_check==4)/*if check step 4 all variables are true and sent to main*/
        {
            return 1;
        }
        else
        {
            return 0;
        }
        }
        int create_customer(char identity_number[], int password)
        {
        	/*function created for opening file and writing data*/
        	FILE *dosya;
        	dosya=fopen("customeraccount.txt","w");
        	fprintf(dosya,"%s,%d",identity_number,password);
        	fclose(dosya);
        }
        int check_login(char identity_number[],int password)
        {
        	/*reading data from file to log into account*/
        	FILE *dosya;
        	char txt_ID[11];
        	int txt_password;
        	dosya=fopen("customeraccount.txt","r");
        	fscanf(dosya,"%[^.,:!;],%d",txt_ID,&txt_password);
        	fclose(dosya);
        	
        	int i,check_login=0;
        	for(i=0;i<11;i++)/*Password and ID control to login to the account*/
        	{
        		if(txt_ID[i]==identity_number[i]) 
        		{
        			check_login++;/*control step increment for each correct character*/
        		}
        		
        	}
        		if(txt_password==password)
        		{
        			check_login++;/*control step increment for each correct character*/
        		}
        		if(check_login==12)
        		{
        			return 1;
        		}
        		else
        		{
				return 0;        		
        		}
        }
        int withdrawable_amount(float cash_amount)
        {
        	int i;
        	int a=0;
        	for(i=0;i<=cash_amount;i++)/*function that calculates the amount of money that can be withdrawn*/
        	{
        		if(i%10==0)
        		{
        				a=i;
        		}
        	}
        	return a;
   
        }
        
                          
