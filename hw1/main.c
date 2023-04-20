#include<stdio.h>
#include"util.h"


int main()
{
					/*part1 */
    int x,y,f_I,z,n,result;
    /* requesting data by the user */
    printf("Enter the first integer: ");
    scanf("%d",&x);
    printf("Enter the second integer: ");
    scanf("%d",&y);
    printf("enter the divisor: ");
    scanf("%d",&z);
    f_I = find_divisible(x,y,z);
    /*If the return value is zero, an error code is sent, if it is a value other than 0, the operation is allowed to continue.*/
    if(f_I==0)
    {
        printf("There is any integer between %d and %d can be divided by %d.\n",x,y,z);
    }
    else
    {	
        printf("first divisible number is %d\n",f_I);/*print the first divisible number*/
        printf("please enter the Nth number that you want :");/*asking the user what number they want*/
        scanf("%d",&n);
        result=find_nth_divisible(n,f_I,z);
        if(x<result && result<y)
        {
            printf("%d. divisible number after the first divisible number :%d\n",n,result);/*If the number received in the function is the numbers requested from the user, the result is printed.*/
        }
        else/*If the number received in the function is not among the numbers requested from the user, an error is given.*/
        {
            printf("No possible to find %dth divisible between X and Y divided by Z.\n",n);
        }

    }
     //part2
                  
    char identity_number[20];
    int temp;/*element that holds the number from the function.*/
    printf("please enter your identity number: ");/*Asking the user for the ID number*/
    scanf("%s",identity_number);
    temp=validate_identity_number(identity_number);
   
    while(temp==0)/*if wrong ID number is entered, wrong transaction was entered*/
    {
    printf("ID number entered inccorrectly.Please enter again correctly: \n");
    scanf("%s",identity_number);
    temp=validate_identity_number(identity_number);
    }
     printf("ID number entered succesfully.\n");
    int password;/*4-digit password is requested when a successful ID number is entered*/
    printf("Please enter 4 digit password: ");
    scanf("%d",&password);
   
    	
    	
    	while(password>9999 || password<1000)/*Sending error code when 4-digit password is not entered*/
    	{
    		printf("It must be 4 digit! PLease enter again: \n");
    		scanf("%d",&password);
    	}
    	create_customer(identity_number,password);/*file opening and client account opening function*/
    													/*PART3*/
	    													
    printf("please enter your ID number for login: ");/*requesting a password and ID number from the user to log in to the account*/
    scanf("%s",identity_number);
    printf("please enter your password for login: ");
    scanf("%d",&password);
    int check_numbers=0;/*id and password control variable for account login*/
    check_numbers=check_login(identity_number,password);
    if(check_numbers==1)
    {
    	printf("Login succesfull\n");
    	float cash_amount;
    	printf("enter your withdrawable amount: ");/*Entering the money the user wants to withdraw*/
    	scanf("%f",&cash_amount);
    	int money=withdrawable_amount(cash_amount);
    	printf("your withdrawable amount is %d",money);/*Entering withdrawal money*/
    }
    else
    {
    	printf("wrong ID or password\n");/*Sending an error code on incorrect ID and password entry*/
    }
    
    
	                                     
    return 0;
}
     
