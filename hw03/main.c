#include <stdio.h>
#include <math.h>
int sum(int n1, int n2, int flag);
int multi(int n1, int n2, int flag);
int isprime(int a);
void write_file(int number);
void print_file();


int main()
{
	int n1,n2,flag=0,result=0,c,choice,result2,a,i;
	printf("Select operation\n");
	printf("1. Calculate sum/multiplication between two numbers\n");
	printf("2. Calculate prime numbers\n");
	printf("3. Show number sequence in file\n");
	printf("4. Sort number sequence in file\n");/*I dont have 4th task*/
	scanf("%d",&choice);
	while(choice != 1 && choice != 2 && choice != 3 && choice != 4)
	 {
    	printf("You can select only 1,2,3 or 4,please enter again!\n");
    	scanf("%d", &choice);
    	}
	switch(choice)
	{
		case 1:
		printf("Select operaiton\n");
		printf("Please enter '0' for sum, '1' for multiplication\n");
		scanf("%d",&c);
		printf("Please enter '0' work on even numbers, '1' work on odd numbers\n");
		scanf("%d",&flag);
		printf("Please enter two different number:\n");
		printf("Number 1: ");
		scanf("%d",&n1);
		printf("Number 2: ");
		scanf("%d",&n2);
		while(n1 == n2)
		{
                            printf("Numbers must be different\n");
                            printf("Please enter second number again: ");
                            scanf("%d", &n2);
              }
              if(n1 > n2)
              {
                             int temp;
                             temp = n1;
                             n1 = n2;
                             n2 = temp;
    	       }
    	       switch(c)
    	       {
    	        case 0:
    	        	printf("Result\n");
			result=sum(n1,n2,flag);
			write_file(result);
			printf("\n");
    	              printf("The result is written to the results.txt file.");
    	              break;
    	        case 1:
    	         	printf("Result\n");
			result=multi(n1,n2,flag);
			write_file(result);
			printf("\n");
    	              printf("The result is written to the results.txt file.");
    	                break;
    	        default:printf("please enter 1 or 0.");  
    	        break;
    	        }
    	        break;
    	        case 2:
    	    
		printf("Please enter an integer:");
		scanf("%d",&i);
		while(i<=2)
	 	{
    			printf("Enter a number greater than 2.\n");
    			scanf("%d", &i);
    		}
		for(a=2;a<i;a++)
		{
			result2=isprime(a);
			if(result2==1)
			{
				printf("%d is a prime number\n",a);
				
			}
			
			else 
			{
				printf("%d is not a prime number, it is dividble by %d\n",a,result2);
			}
		}
		break;
		case 3:
		print_file();
		break;
		default: printf("wrong entry");
		break;
	}
	

	

return 0;
}


int sum(int n1, int n2, int flag)
{
	int total=0;
	int i;
	switch(flag)
	{
		case 0:
		 if(n2%2==1)
    		{
        		for(i=n1+1; i<n2-2; i++)
        	{
            		if(i%2==0)
            		{
               		 total=total+i;
               		 printf("%d+",i);
            		}
        	}
        		total=total+i+1;
        		printf("%d=",i+1);
        		printf("%d",total);
        		return total;
    		}
    		if(n2%2==0)
    		{
        		for(i=n1+1; i<n2-2; i++)
        		{		
            			if(i%2==0)
            			{
                			total=total +i;
               			printf("%d+",i);
            			}
        		}
        		total=total+i;
        		printf("%d=",i);
       		printf("%d",total);
       		return total;
    		}

		
		case 1:
		if(n2%2==1)
    		{
        		for(i=n1+1; i<n2-2; i++)
        	{
            		if(i%2==1)
            		{
               		 total=total+i;
               		 printf("%d+",i);
            		}
        	}
        		total=total+i;
        		printf("%d=",i);
        		printf("%d",total);
        		return total;
    		}
    		if(n2%2==0)
    		{
        		for(i=n1+1; i<n2-2; i++)
        		{
            			if(i%2==1)
            			{
                			total=total +i;
                			printf("%d+",i);
            			}
        		}
        		total=total+i+1;
        		printf("%d=",i+1);
        		printf("%d",total);
        		return total;
    		}
		
	}

}
int multi(int n1, int n2, int flag)
{
	int multi=1;
	int i;
	switch(flag)
	{
		case 0:
		 if(n2%2==1)
    		{
        		for(i=n1+1; i<n2-2; i++)
        	{
            		if(i%2==0)
            		{
               		 multi=multi*i;
               		 printf("%d*",i);
            		}
        	}
        		multi=multi*(i+1);
        		printf("%d=",i+1);
        		printf("%d",multi);
        		return multi;
    		}
    		if(n2%2==0)
    		{
        		for(i=n1+1; i<n2-2; i++)
        		{		
            			if(i%2==0)
            			{
                			multi=multi *i;
               			printf("%d*",i);
            			}
        		}
        		multi=multi*i;
        		printf("%d=",i);
       		printf("%d",multi);
       		return multi;
    		}

		
		case 1:
		if(n2%2==1)
    		{
        		for(i=n1+1; i<n2-2; i++)
        	{
            		if(i%2==1)
            		{
               		 multi=multi*i;
               		 printf("%d*",i);
            		}
        	}
        		multi=multi*i;
        		printf("%d=",i);
        		printf("%d",multi);
        		return multi;
    		}
    		if(n2%2==0)
    		{
        		for(i=n1+1; i<n2-2; i++)
        		{
            			if(i%2==1)
            			{
                			multi=multi *i;
                			printf("%d*",i);
            			}
        		}
        		multi=multi*(i+1);
        		printf("%d=",i+1);
        		printf("%d",multi);
        		return multi;
    		}
		
	}
	
		


}
int isprime (int a)
{	
	int j;
	for(j=2;j<=sqrt(a);j++)
	{
		if(a%j==0)
		{
			return j;
		}

	}
	return 1;
	

}	
void write_file(int number){
    FILE *txt;
    txt = fopen("results.txt","a");
    fprintf(txt,"%d ", number);
    fclose(txt);
}

void print_file(){
    int num = 0;
    FILE *txt;
    txt = fopen("results.txt","r");

    while (!feof(txt))
    {
       fscanf(txt,"%d ", &num);
       printf("%d ", num);
    }
    fclose(txt);
}

    
