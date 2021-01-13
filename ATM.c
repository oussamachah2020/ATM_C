/*
 A simple ATM program in C
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


unsigned long amount = 10000, deposit, withdraw;
int choice, pin,k = 1;
int transaction;

void User_Account()
{
	printf("\t************ATM service**************\n\n");
	printf("\tEnter you pin: ");
	scanf("%d",&pin);

	while(pin != 1234)	
	{
		k++;
		if(k > 3)//3 tries in the maximum
		{
			printf("\tYour account is blocked please wait for 10 seconds then try again!\n\n");
			sleep(10);//sleep for 10 seconds
			break;
		}
		
		printf("\tEnter a valid pin!\n");
		printf("\tTry again: ");
		scanf("%d",&pin);
	}


    printf("\tEnter your pin: ");
	scanf("%d",&pin);

 	if(pin == 1234)//the right pin
	
	system("clear");//to clear the output

	printf("\tWelcome to your account sir!\n");
	printf("\tHow can i help you?\n\n");

	do //do-while loop to repeat the program
	{ 
	printf("\t**************************************\n\n");
	printf("\t1.check your Balance\n");
	printf("\t2.withdraw an amount\n");
	printf("\t3.desposit an amount\n");
	printf("\t4.Quit\n\n");
	printf("\t**************************************\n\n");
	printf("\tselect a choice: ");
	scanf("%d",&choice);

	 switch(choice)
	{
		case 1: 
		printf("\tYou have %lu$ in your account\n\n",amount);
		break;

		case 2:
		printf("\tEnter an amount to pull: ");
		scanf("%lu",&withdraw);
		while(withdraw % 100 != 0)
		{
			printf("\tadd an amount in multiples of 100\n\n");
			printf("\tTry again: ");
			scanf("%lu",&withdraw);
		}
		if (withdraw >(amount - 500))
		{
				printf("\tINSUFFICENT BALANCE\n");
		}else
			{ 
			  amount = amount-withdraw;
			  printf("\tPLEASE COLLECT CASH\n");
			  printf("You have %lu$ left in your account\n\n",amount);
			}
			break;
		
		case 3: 
		 printf("\tEnter an amount to add: ");
		 scanf("%lu",&deposit);
		 amount = amount + deposit;
		 printf("\tNow you have %lu$ in you account\n\n",amount);
		 break;

		 case 4: 
		 printf("\tAre you sure?\n\n");
		 break;

		 default :
		  printf("\tInvalid choice!");
	}
	printf("Do you have an other transaction?(1 = yes/0 = NO): ");
	fflush(stdin);
	scanf("%d",&transaction);
	}while(transaction != 0);//this input (0) ends the program
	  printf("\tThanks for using our ATM service!\n\n");
}
	
int main()
{
    User_Account();//the program function
}
