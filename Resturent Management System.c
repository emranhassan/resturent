#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int id;
    char name[100];
    int quantity;
    float price;
    struct node *next;

};
typedef struct node food;

void print(food *pt)
{
    while(pt != NULL)
    {
        printf("%d.%s - %0.2f Taka\n",pt->id,pt->name,pt->price);
        pt = pt->next;

    }

}
insert(food *pt, int id, char name[], float data)
{
    food *temp;
    temp = (food *) malloc(sizeof(food));
    temp -> price = data;
    temp -> id = id;
    strcpy(temp->name,name);
    temp->next = NULL;
    while(pt->next != NULL)
        pt = pt->next;
    pt->next = temp;

}

void breakfast(food *Breakfast)
{

    insert(Breakfast,1,"Bread",12.58);
    insert(Breakfast,2,"Banana",4.42);
    insert(Breakfast,3,"Sandwich",50);
    insert(Breakfast,4,"Soup",102.00);
}
void lunch(food *Lunch)
{
    insert(Lunch,1,"Fried Rice",120.58);
    insert(Lunch,2,"Fried chicken",154.42);
    insert(Lunch,3,"Vegetable  Salad",120);
    insert(Lunch,4,"Soup",102.00);


}
void dinner(food *Dinner)
{
    insert(Dinner,1,"Chicken soup",100.58);
    insert(Dinner,2,"Chicken Masala",140.42);
    insert(Dinner,3,"American Chopsuey",125);
    insert(Dinner,4,"Soup",102.00);


}

void sell(food *pt,food *temp)
{

    int id;
    scanf("%d",&id);
    while(temp->id != id)
        temp = temp->next;
    while(pt->next != NULL)
        pt = pt->next;
    food *newFood = (food*) malloc(sizeof(food));
    strcpy(newFood->name, temp->name);
    newFood->id = temp->id;
    newFood->price = temp->price;
    printf("Enter the quantity of the %s: ",temp->name);
    scanf("%d",&newFood->quantity);
    pt->next = newFood;
}

void printSell(food *pt)
{
    float total=0,price,withvat;
    int n=1;
    while(pt != NULL)
    {
        price = pt->price*pt->quantity;
        printf("%d.%s - Quantity = %d Total price = %.02f Taka\n",n,pt->name,pt->quantity,price);
        n++;
        total+=price;
        pt = pt->next;
    }
    withvat = (total + (total * 0.1));
    printf("Total price: %.02f Taka\nAmount to be paid (with 10%% vat) : %.02f Taka\n",total,withvat);

}

int main()
{
    food *Breakfast=(food*)malloc(sizeof(food));
    food *Lunch=(food*)malloc(sizeof(food));
    food *Dinner=(food*)malloc(sizeof(food));

    Breakfast->next=NULL;
    Lunch->next=NULL;
    Dinner->next=NULL;

    breakfast(Breakfast);
    lunch(Lunch);
    dinner(Dinner);

    int choice;
    printf("                              Food Order Simulation\n");
    printf("                              Created By Web Demons\n\n\n");
    printf("                           Welcome to our Restaurant \n\n\n ");
    printf("Please select any option to buy \n\n");
    printf("[1] Breakfast\n");
    printf("[2] Lunch\n");
    printf("[3] Dinner\n");
    printf("Enter your choice here : ");
    scanf("%d", &choice);
    system("clear");

    if(choice==1)
    {
        food *foodlist=(food *) malloc(sizeof(food));
        foodlist->next = NULL;
        printf("                           Welcome to our Restaurant. \n\n\n ");
        printf("Breakfast Menu \n\n");
        printf("Please select the food that you want \n\n");
        print(Breakfast->next);
        while(1)
        {
            sell(foodlist,Breakfast);
            int again;
            printf("\nWould you like to order anything else?\n[1] Yes , [2] No : ");
            scanf("%d",&again);
            if(again == 2) break;
            system("clear");

            food *foodlist=(food *) malloc(sizeof(food));
            foodlist->next = NULL;
            printf("                           Welcome to our Restaurant. \n\n\n ");
            printf("Breakfast Menu \n\n");
            printf("Please select the food that you want \n\n");
            print(Breakfast->next);
        }

        printSell(foodlist->next);
    }
    else if(choice==2)
    {


        food *foodlist=(food *) malloc(sizeof(food));
        foodlist->next = NULL;
        printf("                           Welcome to our Restaurant. \n\n\n ");
        printf("Lunch Menu \n\n");
        printf("Please select the food that you want \n\n");
        print(Lunch->next);
        while(1)
        {
            sell(foodlist,Lunch);
            int again;
            printf("\nWould you like to order anything else?\n[1] Yes , [2] No : ");
            scanf("%d",&again);
            if(again == 2) break;
            system("clear");

            food *foodlist=(food *) malloc(sizeof(food));
            foodlist->next = NULL;
            printf("                           Welcome to our Restaurant. \n\n\n ");
            printf("Lunch Menu \n\n");
            printf("Please select the food that you want \n\n");
            print(Lunch->next);
        }
          printSell(foodlist->next);

    }
    else if(choice==3)
    {



        food *foodlist=(food *) malloc(sizeof(food));
        foodlist->next = NULL;
        printf("                           Welcome to our Restaurant. \n\n\n ");
        printf("Dinner Menu \n\n");
        printf("Please select the food that you want \n\n");
        print(Dinner->next);
        while(1)
        {
            sell(foodlist,Dinner);
            int again;
            printf("\nWould you like to order anything else?\n[1] Yes , [2] No : ");
            scanf("%d",&again);
            if(again == 2) break;
            system("clear");

            food *foodlist=(food *) malloc(sizeof(food));
            foodlist->next = NULL;
            printf("                           Welcome to our Restaurant. \n\n\n ");
            printf("Dinner Menu \n\n");
            printf("Please select the food that you want \n\n");
            print(Dinner->next);
        }
         printSell(foodlist->next);
    }
    else printf("Invalid Choice!\n");
    return 0;
}
