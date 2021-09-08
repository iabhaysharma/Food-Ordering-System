#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>


void mainmenu();
void customer(void);
void Admin(void);
void aboutus(void);

void Manjil(void);
void Manakamana(void);

void insertfirst(int data, char foodname[25], float price);
void insertend(int data, char foodname[25], float price);
void foodlist();
void orderplace();
void adminoption();
void foodadd();
void deletefood(int serial);
void backup(void);


int order_choice;
int c=0; int any;
int cardno[100];
float cardmoney[100];
float totalmoney = 0;
int total_order[100];
int order_quantity[100];
int quantity[100];
int order=0;
void details(void);



struct Node{

	char foodname[50];
	float price;
	int data;
	struct Node *next;

};

typedef struct Node node ;

node *head, *list;




void mainmenu(void)
{
  system("cls");
	printf("                                 __________________________________________________________________________\n\n");
	printf("                                                     WELCOME TO FOOD ORDER SYSTEM\n");
	printf("                                 __________________________________________________________________________\n\n\n");
	printf("          1. CUSTOMER SECTION--> \n\n"); Sleep(500);                          
    printf("          2. ADMIN PANAL-->  \n\n");Sleep(500);
    printf("          3. ABOUT US--> \n\n");Sleep(500);
    printf("          4. Exit--> \n\n\n ");Sleep(500);
    printf("          Enter Your Choice --->  ");            
	int choice;
	scanf("%d",&choice);
	if(choice==1)
	{
    system("cls");
	customer();
	}
  else if(choice==2){
    system("cls");
    Admin();

  }
	else if(choice==3)
	{
    system("cls");
	aboutus();
	}
	else if(choice==4)
	{
		system("cls");
		printf("\n\n\n");
		printf("_______________________________ THANK YOU _____________________________________\n");Sleep(500);

		printf("*********Feeling HUNGRY ? Call or Walk-In ***************\n\n");
		exit(0);
	}
}

void customer(void)
{

	system("cls");
	printf("                    ************************************************\n                                      WELCOME\n                    ************************************************\n\n");Sleep(500);
	
		printf("Please select a Resturent \n");Sleep(500); 
		printf("              1. Manjil-->\n\n");Sleep(250);                       
		printf("              2. Manakamana-->\n\n");Sleep(250);
		printf("              3. Back To Main Menu-->\n\n");Sleep(250);
		printf(" Enter Your Choice  -->");
	int k;
	scanf("%d",&k);
	
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
void Manjilmenu(){ 
	
	insertfirst(1,"Burger     ",175.00);
	insertend(2,"Pizza      ",250.00);
	insertend(3,"Hot Cake   ",475.00);
	insertend(4,"Coffee     ",325.00);
	insertend(5,"Ice cream  ",230.00);
	insertend(6,"Sandwich   ",320.00);
	insertend(7,"Grill      ",100);
	insertend(8,"Pancakes   ",350.00);
	insertend(9,"Cold Drinks",120.00);
    
  //foodlist();
   }

void Manjil(){
   Manjilmenu();
   foodlist();
   Sleep(500);

   printf("=> 0. Main Menu \n\n");Sleep(500);
   orderplace();
   
}
void Manakamanamenu(){
	insertend(1,"Hot Cake   ",475.00);
	insertfirst(5,"Burger     ",175.00);
	insertend(6,"Pizza      ",250.00);
	
	insertend(2,"Coffee     ",325.00);
	insertend(3,"Ice cream  ",230.00);
	insertend(4,"Sandwich   ",320.00);
	//foodlist();
}
void Manakamana(){
	system("cls");
    Manakamanamenu();Sleep(500);
	foodlist();
	printf("=> 0. Main Menu\n\n ");Sleep(500);
    orderplace();
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





int main(){
    
    system("cls");

    mainmenu();
    head = NULL;

}


void aboutus(){
    printf("okoko");
}

void orderplace(){

    printf("Place Your Order: "); 
    scanf("%d",&order_choice);

    if(order_choice==0){
		mainmenu();
	}
    node *temp;

	temp = list ;

	while(temp->data != order_choice){
		system("cls");

		temp = temp->next;
		system("cls");
		if(temp==NULL){
			system("cls");
			printf("Please Choose From List \n\n");
			foodlist();Sleep(500);
			orderplace();
		}
    }
    if(order_choice == temp->data){

		
		printf("Enter Food Quantity : ");

		int fcquantity;

		scanf("%d",&fcquantity); 
        

        if(fcquantity==0){
			printf("Quantity Can not be Zero \n\n");Sleep(500);
			system("cls");
			foodlist();Sleep(500);
			orderplace();
		}
        

        
        printf("Choice food %s  its price is %0.2f \n\n",temp->foodname,temp->price*fcquantity);
		printf("1. Confirm to buy this \n\n");
		printf("2. Food List \n\n  ");
		printf("Please Select:\n\n");
         int confirm;
         scanf("%d",&confirm);
		//confirm:
        if(confirm == 1 ){
			system("cls");
            printf("How would you like to pay?\n\n");Sleep(500);
			printf(" 1. Cash \n\n ");

			printf("2. Credit\n\n ");Sleep(500);
			printf("ENTER:");
			int payment;
			//payment:
			

			scanf("%d",&payment);

			if(payment==1){

                
				totalmoney += temp->price*fcquantity;
				order++;
				total_order[order]=order_choice;
    
	
    system("cls");
	details();
    printf("===>THANK YOU<===\n\n");Sleep(500);
    printf("Food Ordered Successfully ...\n\n");Sleep(500);
	printf("1. Do you want to buy any other item?\n\n");
	printf("2. Main Menu\n\n ");Sleep(500);
	printf("Press:   ");


    
    
    int ps_menu;
    scanf("%d",&ps_menu);
    if(ps_menu==1){
       foodlist();
	   orderplace();}
	else (ps_menu==2);{
        mainmenu();}
	//else{
  //  printf("Please Choice from list : ");
  //  psmenu();}
    
            }

    else (payment==2);{
                system("cls");
			   int card_number[100];
               int c=0;
			   c++;
                
				printf("Enter Your Card No : ");

				scanf("%d",&card_number[c]);
                cardno[c] = card_number[c];

                printf("Enter Your Card Pin   : ");

				int p=0; 
				char pin[4];
				 do{ 
					pin[p]=getch(); 
					if(pin[p]!='\r'){ 
					    printf("*"); 
				    	} 
					p++; 
				    }while(pin[p-1]!='\r'); 
				    pin[p-1]='\0'; 
				    //printf("\nYou have entered %s as pin",pin); 
				    getch(); 

                cardmoney[c] = temp->price*fcquantity;

				totalmoney += temp->price*fcquantity;
				order++;
				total_order[order]=order_choice;
				order_quantity[order]=fcquantity;
                details();
                printf("\n\nPayment Success...\n\n");Sleep(500);
				printf("1. Do you want to place another order ? \n\n");
				printf("2. Main Menu \n]n");Sleep(500);
				printf("Press:   ");
                
                int ps_menu2;
                scanf("%d",&ps_menu2);

				if(ps_menu2==1){
                foodlist();
				orderplace();}
				else{
                    mainmenu();}
				
    }
		}
    
     else(confirm == 2);{
    system("cls");Sleep(500);

	foodlist();
	orderplace();

		}


    
}
}

void Admin(){
	int admin_choice;
	printf("1. Main Menu\n\n"); Sleep(500);
	printf("Please Enter Password or ( 1 to Back in Main Menu ) : ");

    int p=0; 
	char password[20];
	do{ 
	password[p]=getch(); 
	if(password[p]!='\r'){ 
	 printf("*"); 
	} 
	p++; 
	}while(password[p-1]!='\r'); 
	password[p-1]='\0';

	if(strcmp(password,"12345")==0){
		system("cls");
		node *temp;

	    temp = list;
		adminoption();
	}
	else if(admin_choice==1){
				mainmenu();
			}
			else{
				printf("Please Enter Correct Choice\n\n");
				system("cls");
				Admin();
			}

}

void adminoption(){
	//node *temp;

	//temp = list;
	printf("\n\nYou are on Admin Pannel\n\n");
			
	printf(" 1. Total Cash Today \n\n");Sleep(250);
	printf(" 2. View Card Pay \n\n");Sleep(250);
	printf(" 3. Add Food \n\n");Sleep(250);
	printf(" 4. Delete Food \n\n");Sleep(250);
	printf(" 5. Backup System\n\n");Sleep(250);
	
	printf(" 0. Main Menu \n\n");Sleep(500);

	printf("PLEASE CHOOSE:  ");


	int adchoice;
	scanf("%d",&adchoice);

	if(adchoice==1){
    system("cls");
    printf("Todays Total Cash : %0.2f  \n",totalmoney);Sleep(500);
	printf("Press Any Key To Go Back.\n");
	if(getch())
    system("cls");
	adminoption();
	}

	else if(adchoice==2){

					if(c!=0){

						system("cls");

						printf(" ____________________________\n");
						printf("|   Card NO.   |   Money $   |\n");
						printf("------------------------------\n");

						for(int z=1; z<=c;z++){

							printf("|  %d  | %0.2f |\n",cardno[z],cardmoney[z]);
							printf("------------------------------\n");
							

						}	
					}
					if(c==0){

					system("cls");
					printf("No Card History\n\n");}Sleep(250);
	printf("Press Any Key To Go Back.\n");
	if(getch())
    system("cls");
	adminoption();
				//adminoption();
	}

	else if(adchoice==3){
		system("cls");
		printf("Please select a Resturent to add food to its menu \n");
		printf("              1. Manjil-->\n\n");Sleep(250);                       
		printf("              2. Manakamana-->\n\n");Sleep(250);
		printf("              3. Back To Main Menu-->\n\n");Sleep(250);
		printf(" Enter Your Choice  -->");
		int chooserest;
		scanf("%d",&chooserest);
		
		if (chooserest==1){
			system("cls");
		Manjilmenu();
		foodlist();Sleep(500);

		foodadd();
		
	//	foodadd();
		
		}
		else{
			system("cls");
		Manakamanamenu();
		foodlist();Sleep(500);
		foodadd();

		}
			
	}
	else if(adchoice==4){
		system("cls");
		printf("Please select a Resturent to add food to its menu \n");
		printf("              1. Manjil-->\n\n");Sleep(250);                       
		printf("              2. Manakamana-->\n\n");Sleep(250);
		printf("              3. Back To Main Menu-->\n\n");Sleep(250);
		printf(" Enter Your Choice  -->");
        int restchoose;
		scanf("%d",&restchoose);
			 		if (restchoose==1){
					system("cls");
					Manjilmenu();
					foodlist();Sleep(250);
					printf("Enter Serial No of the Food To Delete :  ");
					int f_delete;
					scanf("%d",&f_delete);
					node *temp;
					temp=list;
					
					
					
					
					while(temp->data != f_delete){
						temp = temp->next;
					}
					if(temp->data==f_delete){
						deletefood(f_delete);
					}
					else{
						printf("Please Enter Correct Number :  "); Sleep(500);
						Manjilmenu();
					}
					

					adminoption();
				}
				
				else{
					system("cls");
					Manakamanamenu();
					printf("Enter Serial No of the Food To Delete : ");
					int f_delete;
					scanf("%d",&f_delete);
					node *temp;
					temp=list;
					
			
					
					
					while(temp->data != f_delete){
						temp = temp->next;
					}
					if(temp->data==f_delete){
						deletefood(f_delete);
					}
					else{
						printf("Please Enter Correct Number :  "); Sleep(500);
					//	fdelete();
					}
					

					adminoption();
				}
				}
	else if(adchoice==5){


					char date[35]=__DATE__;

					strcat(date,".txt");
					FILE *fptr;
					fptr=fopen(date,"w");
					backup();
					if(fptr==NULL){
						printf("Error!"); Sleep(500);
						adminoption();
					}
					fprintf(fptr,"Total Cash Today : %0.2f\n\n\n",totalmoney);
					fprintf(fptr,"Card No ------- Money \n\n");
					for(int l=1; l<=c;l++){
						fprintf(fptr,"%d ------- %0.2f \n",cardno[l],cardmoney[l]);
					}
					printf("Backup Successfull..."); Sleep(1500);



					fclose(fptr);
					adminoption();
				}
			
	else if(adchoice==0){

					mainmenu();
				}

				else{
					printf("Please Select From List :  "); 
					adminoption();
				}



}

void foodadd(){
				//	system("cls");
                    //foodlist();
					char ffoodname[25];
					int fquantity;
					int fdata;
					float fprice;
					int fposi;

					printf(" Enter Food Name : \n ");

					scanf("%s",ffoodname);
					
					printf(" Enter Food Serial :  \n");
                    scanf("%d",&fdata);

					node *exist;
                    exist = list;
                while(exist->data!=fdata){
                            if(exist->next==NULL){
                                break;
                            }
                        exist=exist->next;
                      }
					   if(exist->data==fdata){
                       printf(" Food Serial Already Exist, Please Re-Enter  \n\n");Sleep(250);
                       foodadd();
                      }
					   printf(" Enter Food Price :  ");
					   scanf("%f",&fprice);

					    printf("Submiting your data");Sleep(250);
						for(int cs=0;cs<4;cs++){
							printf(" .");
							}
						insertend(fdata,ffoodname,fprice);
						printf("\n\nAdding Food  Successfull....\n");Sleep(250);
    printf("\n\n    Press Any Key To Go Back.\n");
	if(getch())
    system("cls");
	adminoption();

					}

	


	void deletefood(int serial){

	node *temp;
	temp=(node *)malloc(sizeof(node));

	temp = list;


	if(temp->data != serial){

		while(temp->next->data != serial){
			temp = temp->next;
		}

		if(temp->next->data == serial){

			temp->next = temp->next->next;
		//	cls();
			printf("\n\nDeleting Item %d ",serial);for(int cs=0;cs<4;cs++){printf(" .");Sleep(400);}

			printf("\n\n\n\n\t\t\tDeleted Successfylly \n");

		}
		else{
			printf("\n\n\n\n\t\t\tFood Item Not Found\n");
		}

		head = temp ;

	}
	else{

		temp = temp->next;
		//cls();
		printf("\n\n\n\n\t\t\tDeleting Item %d ",serial);for(int cs=0;cs<4;cs++){printf(" .");Sleep(400);}

		printf("\n\n\n\n\t\t\tDeleted Successfylly \n"); 

		head = temp ;

		list=head;
	}
}


void backup(void){

	for (int i=15;i<=100;i+=5){

		system("cls");
		

		printf("\n\n\n\n\n\n\n\t\t\t\t");
		printf("%d %% Backing UP DATA...\n\n\t\t",i);

		printf("");

		for (int j=0; j<i;j+=2){

			
			printf(" ");
			

		}
		Sleep(50);
		if(i==90 || i==50 || i==96 || i==83){
		Sleep(50);
		}
	}

}

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

	
}