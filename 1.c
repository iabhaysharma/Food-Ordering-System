#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>

void insertfirst(int data, char foodname[25], float price);
void insertend(int data, char foodname[25], float price);
void updatefood(int udata, int uquantity);
int getdata();


int quantity;
double total=0;
int again;
FILE *fp,*ft,*dp,*dt;
     /// Display Function
void foodlist();
void order_view(int order, int quantity, int or_no);
void main_menu();
void mainmenu(void);
void aboutus(void);
void customer(void);
void Manjil(void);
void Manakamana(void);
void details(void);
struct Node{

	char foodname[50];
	float price;
	int data;
	struct Node *next;

};

typedef struct Node node ;

node *head, *list;

int main(){
    system("cls");
    mainmenu();
	int c=0; int any;
	int cardno[100];
	float cardmoney[100];
	float totalmoney = 0;
	int total_order[100];
	int order_quantity[100];
	int order=0;
	int uquantity;
	int citem;

	head = NULL;

}
//**********************************************************************************************************
void mainmenu(void)
{
    system("cls");
	printf("                                 __________________________________________________________________________\n");
	printf("                                                     WELCOME TO FOOD ORDER SYSTEM\n");
	printf("                                 __________________________________________________________________________\n\n\n");
	printf("          1. CUSTOMER SECTION--> \n\n          2. ABOUT US--> \n\n          3. Exit--> \n\n\n ");
    printf("          Enter Your Choice --->");            
	int choice;
	scanf("%d",&choice);
	if(choice==1)
	{
        system("cls");
		customer();
	}
	else if(choice==2)
	{
        system("cls");
		aboutus();
	}
	else if(choice==3)
	{
		system("cls");
		printf("\n\n\n");
		printf("_______________________________ THANK YOU _____________________________________\n");

		printf("*********Feeling HUNGRY ? Call or Walk-In FOODIE GOODIE KITCHEN***************\n\n");
		exit(0);
	}
}
//**********************************************************************************************************
void customer(void)
{

	system("cls");
	printf("                    ************************************************\n                                      WELCOME\n                    ************************************************\n\n");
	printf("Please select a Resturant\n");
    printf("              1.Manjil\n\n               2.Manakamana\n\n                      OR\n\n               3. Back To Main Menu\n\n   Enter Your Choice  -->");
	int k;
	scanf("%d",&k);
		int wait;
	//printf("In progress :");
	for(wait=0;wait<=500;wait++)
	{
		printf("\rIn progress : %d",wait/50);
	}
	if(k==1)
	{
		system("cls");
		Manjil();
	}
	else if(k==2)
	{
		system("cls");
		Manakamana();
	}
	else if(k==3)
	{
		system("cls");
		mainmenu();
	}
	else
	{
		printf("Wrong Input !Please Re-enter The Correct Option......\n\n");
		customer();
	}
}
//**********************************************************************************************************
void Manjil(){
    insertfirst(1,"Burger     ",175.00);
	insertend(2,"Pizza      ",250.00);
	insertend(3,"Hot Cake   ",475.00);
	insertend(4,"Coffee     ",325.00);
	insertend(5,"Ice cream  ",230.00);
	/*insertend(4,"Sandwich   ",320.00);
	insertend(7,"Grill      ",100);
	insertend(8,"Pancakes   ",350.00);
	insertend(9,"Cold Drinks",120.00);*/
    foodlist();
//******************************************************
 printf("\n\nEnter What You Want :");
	printf("\n\n");
    int choice;
    
	scanf("%d",&choice);
	if(choice==1)
	{
		printf("Quantity :  ");
		scanf("%d",&quantity);
		total=total + 175*(quantity);
	
		printf("\n");
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
        
		scanf("%d",&again);
		printf("\n");
		if(again==1)
		{
			system("cls");
			printf("\n\n");
			Manjil();
		}
		else if(again==2)
		{
			
			printf("Your Total Amount Is : Rs. %.2lf\n\n",total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
	
			details();
		}
	}
	else if(choice==2)
	{
		printf("Quantity :");
		scanf("%d",&quantity);
		total=total + 250*(quantity);
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf("%d",&again);
		if(again==1)
		{
			printf("\n\n");
			Manjil();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is : Rs. %.2lf\n\n",total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
	
			details();
		}
	}
	else if(choice==3)
	{
		printf("Quantity :  ");
		scanf("%d",&quantity);
		total=total + 475*(quantity);
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf("%d",&again);
		if(again==1)
		{
			printf("\n\n");
			Manjil();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is : Rs. %.2lf\n\n",total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
	
			details();
		}
	}
	else if(choice==4)
	{
		printf("Quantity :");
		scanf("%d",&quantity);
		total=total + 325*(quantity);
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf("%d",&again);
		if(again==1)
		{
			printf("\n\n");
			Manjil();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is : Rs. %.2lf\n\n",total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
	
			details();
		}
	}
	else if(choice==5)
	{
		printf("Quantity :");
		scanf("%d",&quantity);
		total=total + 250*(quantity);
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf("%d",&again);
		if(again==1)
		{
			printf("\n\n");
			Manjil();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is : Rs. %.2lf\n\n",total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
		
			details();
		}
			
	}
	else if(choice==6)
	{
		system("cls");
		customer();
	}
	else
	{
		printf("Wrong Input! Re-enter THe Correct Option\n\n");
		if(getch())
		Manjil();
	}
}

//***********************************************************************************************
void Manakamana(){
    insertfirst(5,"Burger     ",175.00);
	insertend(6,"Pizza      ",250.00);
	insertend(1,"Hot Cake   ",475.00);
	insertend(2,"Coffee     ",325.00);
	insertend(3,"Ice cream  ",230.00);
	insertend(4,"Sandwich   ",320.00);
	foodlist();
	printf("\n\nEnter What You Want :");
	printf("\n\n");
    int choice;
    
	scanf("%d",&choice);
	if(choice==1)
	{
		printf("Quantity :  ");
		scanf("%d",&quantity);
		total=total + 175*(quantity);
	
		printf("\n");
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
        
		scanf("%d",&again);
		printf("\n");
		if(again==1)
		{
			printf("\n\n");
			Manakamana();
		}
		else if(again==2)
		{
			
			printf("Your Total Amount Is : Rs. %.2lf\n\n",total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
	
			details();
		}
	}
	else if(choice==2)
	{
		printf("Quantity :");
		scanf("%d",&quantity);
		total=total + 250*(quantity);
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf("%d",&again);
		if(again==1)
		{
			printf("\n\n");
			Manakamana();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is : Rs. %.2lf\n\n",total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
	
			details();
		}
	}
	else if(choice==3)
	{
		printf("Quantity :  ");
		scanf("%d",&quantity);
		total=total + 475*(quantity);
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf("%d",&again);
		if(again==1)
		{
			printf("\n\n");
			Manakamana();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is : Rs. %.2lf\n\n",total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
	
			details();
		}
	}
	else if(choice==4)
	{
		printf("Quantity :");
		scanf("%d",&quantity);
		total=total + 325*(quantity);
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf("%d",&again);
		if(again==1)
		{
			printf("\n\n");
			Manakamana();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is : Rs. %.2lf\n\n",total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
	
			details();
		}
	}
	else if(choice==5)
	{
		printf("Quantity :");
		scanf("%d",&quantity);
		total=total + 250*(quantity);
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf("%d",&again);
		if(again==1)
		{
			printf("\n\n");
			Manakamana();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is : Rs. %.2lf\n\n",total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
		
			details();
		}
			
	}
	else if(choice==6)
	{
		system("cls");
		customer();
	}
	else
	{
		printf("Wrong Input! Re-enter THe Correct Option\n\n");
		if(getch())
		Manakamana();
	}
}
//*********************************************************
void details(void)
{
	char name1[20];
	char name2[20];
	long long int phone;
	char address[40];
	char landmark[30];
	printf("Please Give Your Contact Details \n");
	printf(" First Name : \n");
	scanf("%s",name1);
	printf("Last Name : \n");
	scanf("%s",name2);
	printf("Phone : \n");
	scanf("%lld",&phone);
	printf("Address : \n");
	scanf("%s",address);
	printf("Landmark : \n");
	scanf("%s",landmark);
	printf("\n\n");
    system("cls");
	printf("Your Entered Details Are --->\n");
	FILE *cust;
	cust = fopen("order.txt","a");
	fprintf(cust,"Order Placed By : %s %s\nPhone number : %lld\n",name1,name2,phone);
	fclose(cust);
	printf("    -->First Name :  %s\n    -->Last Name   :  %s\n    -->Phone     :%lld \n    -->Address  :%s \n    -->Landmark  :%s \n",name1,name2,phone,address,landmark);
	printf("\n\n\n");
	printf("                       _____________________________________________________________________________________________\n");
	printf("                                             Your Order Will Be At Your Door In 30 minutes.\n");
	printf("                                                       .....HAPPY ORDERING.....\n");
	printf("                       _____________________________________________________________________________________________\n");
	
	printf("Press Any To The MainMenu.");
	if(getch())
	customer();
}
//********************************************************

//**********************************************************************************************************
void insertend(int data, char foodname[25], float price){

	node *temp;

	temp=(node *)malloc(sizeof(node));

	temp->data = data;

	temp->price = price;

	strcpy(temp->foodname,foodname);

	temp->next = NULL;


	if(head==NULL){
		head = temp;
		list = head;
	}
	else{

		while(head->next != NULL){
			head = head->next;
		}

		head->next = temp;
	}

}

void insertfirst(int data, char foodname[25], float price){

	node *temp;

	temp=(node *)malloc(sizeof(node));

	temp->data = data ;

	temp->price = price;

	strcpy(temp->foodname,foodname);

	temp->next = head;

	head = temp;

	list = head ;

}

void foodlist(){

	printf("                 ____________________________________________________ \n");
	printf("                 |  Food No.  |     FooD Name         |    Price    |\n");
	printf("                 ____________________________________________________\n");
    
	node *temp;

	temp = list;

	while(temp != NULL){

		
		printf("                 |     %d      |     %s       |    %0.2f   |\n",temp->data,temp->foodname, temp->price);
		printf("                 ____________________________________________________\n");
        
		temp = temp->next ;



	}
}

//***************************************************************************************
void aboutus(void)
{
	system("cls");
    printf("FOOD DELIVARY SYSTEM\n");

	printf("PROJECT BY GROUP C :\n\n   -->ABHAY SHARMA\n\n   -->PRATIK KHANAL\n\n              ______________________________THANK YOU____________________________");
	printf("\n\n");
	printf("    Press Any Key To Go Back.");
	if(getch())
	mainmenu();
}