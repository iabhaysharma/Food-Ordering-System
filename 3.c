#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>

void insertfirst(int data, char foodname[25], float price);
void insertend(int data, char foodname[25], float price);
void updatefood(int udata, int uquantity);

     /// Display Function
void foodlist();
void order_view(int order, int quantity, int or_no);
void main_menu();
void mainmenu(void);
void aboutus(void);
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
	/*insertfirst(5,"Burger     ",175.00);
	insertend(6,"Pizza      ",250.00);
	insertend(1,"Hot Cake   ",475.00);
	insertend(2,"Coffee     ",325.00);
	insertend(3,"Ice cream  ",230.00);
	insertend(4,"Sandwich   ",320.00);
	insertend(7,"Grill      ",100);
	insertend(8,"Pancakes   ",350.00);
	insertend(9,"Cold Drinks",120.00);*/
    //printf("=> 0. Main Menu \n");
	//foodlist();

}
//**********************************************************************************************************
void mainmenu(void)
{
    insertfirst(5,"Burger     ",175.00);
	insertend(6,"Pizza      ",250.00);
	insertend(1,"Hot Cake   ",475.00);
	insertend(2,"Coffee     ",325.00);
	insertend(3,"Ice cream  ",230.00);
	insertend(4,"Sandwich   ",320.00);
	insertend(7,"Grill      ",100);
	insertend(8,"Pancakes   ",350.00);
	insertend(9,"Cold Drinks",120.00);
	system("cls");
	printf("                                 **************************************************************************\n");
	printf("                                                     WELCOME TO FOOD ORDER SYSTEM\n");
	printf("                                 **************************************************************************\n\n\n");
	printf("          1. CUSTOMER SECTION--> \n\n          2. ABOUT US--> \n\n          3. Exit--> \n\n\n ");
    printf("          Enter Your Choice --->");            
	int choice;
	scanf("%d",&choice);
	if(choice==1)
	{
        system("cls");
		foodlist();
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
		printf("*******************************THANK YOU**************************************\n");

		printf("*********Feeling HUNGRY ? Call or Walk-In FOODIE GOODIE KITCHEN***************\n\n");
		exit(0);
	}
}

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
	printf("PEOPLE BEHIND THIS PROJECT :\n\n   -->Rohan Singh\n\n   -->Ashutosh Kumar\n\n   -->Naveen Prakash Satyarthi\n\n   -->Vishal Katiyar\n\n   -->Priyanshu Verma\n\n                       *****************************THANK YOU*****************************");
	printf("\n\n");
	printf("    Press Any Key To Go Back.");
	if(getch())
	mainmenu();
}
