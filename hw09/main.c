#include <stdio.h>
#include <stdlib.h>
#define max 50

union Person
{
    char name[max];
    char adress[50];
    int phone;
};
union Loan
{
    float arr[3];
};
struct BankAccount
{
    union Person Customer;
    union Loan Loans[3];
};
void addCustomer(struct BankAccount *a)
{
    FILE *f;
    f=fopen("customer.txt","a");
    printf("Please Enter Customer Phone = ");
    scanf(" %d",&a->Customer.phone);// get customer phone
    fprintf(f,"\nCustomer Phone = %d",a->Customer.phone);//print file phone
    printf("Please Enter Customer Adress = ");
    scanf(" %[^\n]%*c",a->Customer.adress);// get customer adress
    fprintf(f,"\nCustomer Adress = %s",a->Customer.adress);//print file adress
    printf("Please Enter Customer Name = ");
    scanf(" %[^\n]%*c",a->Customer.name);// get customer name
    fprintf(f,"\nCustomer Name =  %s",a->Customer.name);//print file name
    fclose(f);
}
void listCustomer(struct BankAccount *a)
{
    printf("Customer Name = %s\n", a->Customer.name);
    if ((a->Loans[0].arr[0] != 0.0) && (a->Loans[1].arr[0] == 0.0) && (a->Loans[2].arr[0] == 0.0))//if the loan 0 is full and the others are empty, I printed it like this
    {
        printf("Loans = [%f] => %f\n", a->Loans[0].arr[0], a->Loans[0].arr[0]);
    }
    else if ((a->Loans[0].arr[0] != 0.0) && (a->Loans[1].arr[0] != 0.0) && (a->Loans[2].arr[0] == 0.0))//if the loan 0 and loan 1 are full and the others are empty, I printed it like this
    {
        printf("Loans = [%f + %f] => %f\n", a->Loans[0].arr[0], a->Loans[1].arr[0], a->Loans[0].arr[0] + a->Loans[1].arr[0]);
    }
    else if ((a->Loans[0].arr[0] != 0.0) && (a->Loans[1].arr[0]!=0.0) && (a->Loans[2].arr[0]!=0.0))//if all filled i printed it like this
        {
            printf("Loans = [%f + %f +%f] => %f\n", a->Loans[0].arr[0], a->Loans[1].arr[0], a->Loans[2].arr[0], a->Loans[0].arr[0] + a->Loans[1].arr[0] + a->Loans[2].arr[0]);
        }
    else if((a->Loans[0].arr[0] == 0.0) && (a->Loans[1].arr[0]==0.0) && (a->Loans[2].arr[0]==0.0))//I sent an error message if no loan was entered
    {
        printf("No loan entry.\n");
    }
    else
    {
        printf("her şey hatalı\n");
    }
}

float calculateLoan(float amount, int period, float interestRate)//recursion calculate loan
{
    float result;

    if (period == 0)
    {
        return 1;
    }
    else
    {
        result = (1 + interestRate) * calculateLoan(amount, period - 1, interestRate);
        return result;
    }
}
void newLoan(struct BankAccount *a, int rank)
{
    if ((a->Loans[0].arr[0] == 0.0) && (a->Loans[1].arr[0] == 0.0) && (a->Loans[2].arr[0] == 0.0))//Since 0.0 is entered if it is empty, if all of them are empty, I entered the 0th array and made an operation.
    {
        printf("Please enter the credit the customer will receive.\n");
        scanf("%f", &a->Loans[0].arr[0]);//Amount of 1 customer's first loan
        printf("Please enter the interest rate of the loan.\n");
        scanf("%f", &a->Loans[0].arr[1]);//a customer's initial loan rate
        printf("Please write in how many months the loan will be paid.\n");
        scanf("%f", &a->Loans[0].arr[2]);//a customer's first payment month
        float result = calculateLoan(a->Loans[0].arr[0], a->Loans[0].arr[2], a->Loans[0].arr[1]);
        a->Loans[0].arr[0] = result * a->Loans[0].arr[0];//I sent it to the function and multiplied it with itself and equalized again
        printf("%f\n", a->Loans[0].arr[0]);
        FILE *c;
        c = fopen("loan.txt", "a");
        fprintf(c, "\n%d\t0\t%f\t%f", rank, a->Loans[0].arr[0], a->Loans[0].arr[2]);//print txt
        fclose(c);
    }
    else if ((a->Loans[0].arr[0] != 0.0) && (a->Loans[1].arr[0] == 0.0) && (a->Loans[2].arr[0] == 0.0))//same things for other loans
    {
        printf("Please enter the credit the customer will receive.\n");
        scanf("%f", &a->Loans[1].arr[0]);
        printf("Please enter the interest rate of the loan.\n");
        scanf("%f", &a->Loans[1].arr[1]);
        printf("Please write in how many months the loan will be paid.\n");
        scanf("%f", &a->Loans[1].arr[2]);
        float result = calculateLoan(a->Loans[1].arr[0], a->Loans[1].arr[2], a->Loans[1].arr[1]);
        a->Loans[1].arr[0] = result * a->Loans[1].arr[0];
        printf("%f\n", a->Loans[1].arr[0]);
        FILE *c;
        c = fopen("loan.txt", "a");
        fprintf(c, "\n%d\t1\t%f\t%f", rank, a->Loans[1].arr[0], a->Loans[1].arr[2]);
        fclose(c);
    }
    else if ((a->Loans[0].arr[0] != 0.0) && (a->Loans[1].arr[0] != 0.0) && (a->Loans[2].arr[0] == 0.0))//same things for other loans
    {
        printf("Please enter the credit the customer will receive.\n");
        scanf("%f", &a->Loans[2].arr[0]);
        printf("Please enter the interest rate of the loan.\n");
        scanf("%f", &a->Loans[2].arr[1]);
        printf("Please write in how many months the loan will be paid.\n");
        scanf("%f", &a->Loans[2].arr[2]);
        float result = calculateLoan(a->Loans[2].arr[0], a->Loans[2].arr[2], a->Loans[2].arr[1]);
        a->Loans[2].arr[0] = result * a->Loans[2].arr[0];
        printf("%f\n", a->Loans[2].arr[0]);
        FILE *c;
        c = fopen("loan.txt", "a");
        fprintf(c, "\n%d\t2\t%f\t%f", rank, a->Loans[2].arr[0], a->Loans[2].arr[2]);
        fclose(c);
    }
    else//sends error code if user enters more than one loan
    {
        printf("You can give a maximum of 3 credits to 1 user.\n");
    }
}
void getReport(char a[][max], int k[], int l[], float m[], int c2, int x, int y,int *temp)
{
    float total;
    if (c2 == 1)
    {
        FILE *f;
        int i;
        if ((f = fopen("customer.txt", "r")) != NULL)
        {
            while (!feof(f))
            {
                for(i=0;i<(*temp)*3;i++)//temp keeps track of how many users there are
                {
                    fscanf(f, "\n%[^\n]%*c", a[i]); //get datas from txt
                }
                 for(i=0;i<(*temp)*3;i++)
                {
                    printf("%s\n",a[i]); //print that datas
                }
                
            }
            fclose(f);
        }
        else
        {
            printf("There is no data entire.");//if file is empty send errror
        }
    }
    else
    {
        FILE *p;
        int j = 0;
        float per[150];//period
        if ((p = fopen("loan.txt", "r")) != NULL)
        {
            while (!feof(p))
            {
                fscanf(p, "%d %d %f %f", &k[j], &l[j], &m[j], &per[j]);//get datas
                if (k[j] == x && l[j] == y)// If it is equal to the values received from the user, it will be processed.
                {
                    total = m[j];
                    printf("Total Credit Value = %f\n", m[j]);//print total value
                    int i;
                    for (i = 1; i <= per[j]; i++)
                    {
                        printf("%d. Month Installment = %f\n", i, total / per[j]);//print month installment
                    }
                } 
                j++;
            }
            fclose(p);
        }
        else
        {
            printf("There is no data entire.");//if file is empty send error
        }
    }
}
int main()
{
    struct BankAccount *account = NULL;
    account = (struct BankAccount*)malloc(max*sizeof(struct BankAccount));
    int choosen;
    int i;
    char a[500][max];
    int k[max];
    int l[max];
    float m[max];
    int rank;
    int *id;//this pointer importent for code
    int c2, x, y;
    int *temp = NULL;
    int z = 0;
    temp = &z;
    id = (int *)(malloc)(max * sizeof(int));// I reserved space in memory for id

    
    do
    {
        printf("-------------------------------\n");//menu
        printf("Welcome to the Bank System Menu\n");
        printf("-------------------------------\n");
        printf("\t1.List All Customer\n");
        printf("\t2.Add New coustomer\n");
        printf("\t3.New Loan Application\n");
        printf("\t4.Report Menu\n");
        printf("\t5.Exit System\n");
        printf("Choose = ");
        scanf("%d", &choosen);
        while (choosen != 1 && choosen != 2 && choosen != 3 && choosen != 4 && choosen != 5)
        {
            printf("it must be 1,2,3,4,5\n");
            scanf("%d", &choosen);
        }
        switch (choosen)
        {
        case 1:
            printf("temp %d\n", *temp);
            for (i = 0; i < *temp; i++)
            {

                printf("Customer ID: %d\n", id[i]);
                listCustomer(&account[i]);
            }
            break;
        case 2:

            if (*temp < 50)//In order not to enter more than 50 users
            {
                id[*temp] = *temp + 1;
                addCustomer(&account[*temp]);
                ++(*temp);
            }
            else
            {
                printf("you cannot enter more users\n ");//In order not to enter more than 50 users sending error
            }

            break;
        case 3:
            printf("please enter to which customer would you like to give credit?\n");
            scanf("%d", &rank);
            if (id[rank] == '\0')//I used ıd there.The purpose is to prevent lending to customers who are not here.
            {
                printf("There is no customer at that time. enter the correct order of customers.");//sending error
                break;
            }
            else
            {
                newLoan(&account[rank], rank);
            }

            break;
        case 4:
            printf("1. Customer Detail\n");
            printf("2. Loan Detail of Customer\n");
            printf("Choose = ");
            scanf("%d", &c2);//for report menu
            while (c2 != 1 && c2 != 2)
            {
                printf("it must be 1,2\n");
                scanf("%d", &c2);
            }
            switch (c2)
            {
            case 1:
                getReport(a, k, l, m, c2, x, y,temp);
                break;
            case 2:
                printf("Please enter customer details\n");
                printf("Customer queue = ");
                scanf("%d", &x);
                printf("loan order = ");
                scanf("%d", &y);
                getReport(a, k, l, m, c2, x, y,temp);
                break;
            default:
                break;
            }
            break;
        case 5:
            break;
        default:
            printf("wrong choice");
            break;
        }

    } while (choosen != 5);//for exit.

    return 0;
}
