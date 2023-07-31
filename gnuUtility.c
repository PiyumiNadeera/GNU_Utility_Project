#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Function prototypes
void offers();
void ordering();
void vegType();
void nonVegType();
void beverages();
void exitOrder();
void buyMore();
void displayBills();
void goBack();

//Global variables
int  membershipNumber,total,noOfPizzas,noOfBeverages,itemNumber,order1,validity,orderType,preference,quantity,continivity,beverageQuantity,login;
double price,finalTotal;
char typeOfOrder[50];

//Billing structure
struct billing{
    int day ;
    int month ;
    int year;
    int hours;
    int minutes;
    int seconds;
    int membershipCardNum;
    int itemCount;
    int pizzaCount;
    int beverageCount;
    float totalBill;
    char typeOfOrder[50];

};


int main() {

    printf("%85s","*****************************WELCOME*****************************\n");
    printf("%87s","***********************SANDY'S PIZZA SHOP************************\n\n\n");

    printf("START\n\n1.Customer\n2.Administration\n");
    scanf("%d",&login);

    if(login==2){
     int password;
     printf("\nEnter the password to log into the administration \n");
     scanf("%d",&password);


        if(password==1234){
            displayBills();
            goBack();
        }else{
            printf("\nInvalid password\n");
        }

    }else{
        //Displaying the price list
        printf("%60s","PRICE LIST\n\n");
        printf("%20s%40s%40s","VEG PIZZA","NON VEG PIZZA","BEVERAGES\n");
        printf("%30s%35s%40s","Mushroom Pizza - Rs.1200","Chicken Pizza - Rs.1500","Sprite - Rs.120\n");
        printf("%30s%35s%40s","Cheese Pizza - Rs.1300","Beef Pizza - Rs.1600","Coca-Cola - Rs.130\n");
        printf("%30s%35s%40s","Garlic Pizza - Rs.1400","Pork Pizza - Rs.1700","Pepsi - Rs.150\n");
        printf("%105s","Fanta - Rs.160\n");

        printf("\nDo you have a membership card?\n1.Yes\n2.No\n");
        scanf("%d", &validity);

        if(validity==1){
            printf("\nPlease enter your membership card number.\n");
            scanf("%d",&membershipNumber);
            printf("\nCongratulations. You can have 10%% discount for your bill.\n\n");
        } else {
            printf("\nYou can have a 5%% discount for a bill of more than Rs.5000/-.\n\n");
        }

        printf("Please enter the order type:\n");
        printf("1. Delivery\n");
        printf("2. Pick-up\n");
        scanf("%d", &orderType);

        if(orderType ==1){
            strcpy(typeOfOrder,"Delivery");
            printf("\nDelivery charges will be added. Place your order now.\n");
        }else if(orderType==2){
            strcpy(typeOfOrder,"Pick Up");
            printf("\nPlace your order now.\n");
        }else{
            strcpy(typeOfOrder,"Not Given");
        }


        buyMore();
    }
   return 0;
}

//Choosing veg type pizza
void vegType() {
    printf("\n=========Veg pizza types=========\n(Enter the number of your choice)\n");
    printf("1. Mushroom-Rs.1200/-\n2. Cheese-Rs.1300/-\n3. Garlic-Rs.1400/-\n");
    scanf("%d", &order1);

    if(order1==1||order1==2||order1==3){
        printf("\nEnter the quantity : ");
        scanf("%d",&quantity);

        if (order1 == 1) {
            printf("%d Mushroom pizzas ordered.\n",quantity);
            price = 1200;
        } else if (order1 == 2) {
            printf("%d Cheese pizzas ordered.\n",quantity);
            price = 1300;
        } else if (order1 == 3) {
            printf("%d Garlic pizzas ordered.\n",quantity);
            price = 1400;
        } else {
            printf("Invalid choice.\n");
        }

        total = total + price*quantity;
        itemNumber = itemNumber + 1;
        noOfPizzas = noOfPizzas + quantity;

        printf("\n**********Item Number: %d. Your current total is Rs. %d\n", itemNumber, total);
        printf("\nDo you want to buy anything else?\n1.Yes\n2.No\n");
        scanf("%d",&continivity);

        if(continivity==1){
            buyMore();
        }else{
            exitOrder();
        }
    }else{
        printf("\nInvalid choice\n");
        buyMore();
    }

}

//Choosing non veg pizzas
void nonVegType() {
    printf("\n=========Non veg pizza types=========\n(Enter the number of your choice)\n");
    printf("1. Chicken-Rs.1500/-\n2. Beef-Rs.1600/-\n3. Pork-Rs.1700/-\n");
    scanf("%d", &order1);

    if(order1==1||order1==2||order1==3){
        printf("\nEnter the quantity : ");
        scanf("%d",&quantity);

        if (order1 == 1) {
            printf("%d Chicken pizza ordered.\n",quantity);
            price = 1500;
        } else if (order1 == 2) {
            printf("%d Beef pizza ordered.\n",quantity);
            price = 1600;
        } else if (order1 == 3) {
            printf("%d Pork pizza ordered.\n",quantity);
            price = 1700;
        } else {
            printf("Invalid choice.\n");
        }

        total = total + price*quantity;
        itemNumber = itemNumber + 1;
        noOfPizzas = noOfPizzas + quantity;

        printf("\n**********Item Number: %d. Your current total is Rs. %d\n", itemNumber, total);
        printf("\nDo you want to buy anything else?\n1.Yes\n2.No\n");
        scanf("%d",&continivity);

        if(continivity==1){
            buyMore();
        }else{
            exitOrder();
        }
    }else{
        printf("\nInvalid choice\n");
        buyMore();
    }

}

//Choosing beverages
void beverages() {
    printf("\n=========Beverage types=========\n(Enter the number of your choice)\n");
    printf("1. Sprite-Rs.120/-\n2. Coca Cola-Rs.130/-\n3. Pepsi-Rs.150/-\n4. Fanta-Rs.160/-\n");
    scanf("%d", &order1);

    if(order1==1 ||order1==2||order1==3||order1==4 ){
        printf("\nEnter the quantity : ");
        scanf("%d",&beverageQuantity);

        if (order1 == 1) {
            printf("%d Sprite ordered.\n",beverageQuantity);
            price = 120;
        } else if (order1 == 2) {
            printf("%d Coca Cola ordered.\n",beverageQuantity);
            price = 130;
        } else if (order1 == 3) {
            printf("%d Pepsi ordered.\n",beverageQuantity);
            price = 150;
        } else if (order1 == 4) {
            printf("%d Fanta ordered.\n",beverageQuantity);
            price = 160;
        } else {
            printf("\nInvalid choice.\n");
        }

        total = total + price*beverageQuantity;
        itemNumber = itemNumber + 1;
        noOfBeverages = noOfBeverages + beverageQuantity;

        printf("\n**********Item Number: %d. Your current total is Rs. %d\n", itemNumber, total);
        printf("\nDo you want to buy anything else?\n1.Yes\n2.No\n");
        scanf("%d",&continivity);

        if(continivity==1){
            buyMore();
        }else{
            exitOrder();

        }
    }else{
        printf("\nInvalid choice\n");
        buyMore();
    }
}

//Ordering more items
void buyMore(){
    printf("\nChoose what you need to buy.\n\n");
    printf("1.Vegetarian Pizza\n2.Non Vegetarian Pizza\n3.Beverages\n");
    scanf("%d",&preference);

    if(preference==1){
        vegType();
    }else if(preference==2){
        nonVegType();
    }else if(preference==3){
        beverages();
    }else{
        printf("\nInvalid choice\n");
        buyMore();
    }
}

//Completing the order and display the bill
void exitOrder() {
    int i;
    struct billing bills;
    FILE *fp;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int day = tm.tm_mday;
    int month = tm.tm_mon + 1;
    int year = tm.tm_year + 1900;
    int hours =  tm.tm_hour;
    int minutes = tm.tm_min;
    int seconds =  tm.tm_sec;

    printf("\n\n================================BILL====================================\n\n");
    printf("Date and time: %d-%02d-%02d %02d:%02d:%02d\n",day,month,year,hours, minutes, seconds);
    printf("Number of total items: %d\n", (noOfPizzas+noOfBeverages));
    printf("Number of pizzas ordered: %d\n", noOfPizzas);
    printf("Number of beverages ordered: %d\n", (noOfBeverages));

    if (validity == 0) {
        if (total >= 5000) {
            finalTotal = total - (total * 0.05);
            printf("\n***Your final total is Rs. %.2f***\n", finalTotal);
            printf("You have gained 5%% discount for your bill.\nThank you.......!\n");
            printf("========================================================================\n");
        } else {
            finalTotal = total;
            printf("\n***Your final total is Rs. %d***\n", finalTotal);
            printf("Thank you......!\n");
            printf("========================================================================\n");
        }
    } else {
        finalTotal = total - (total * 0.1);
        printf("\n***Your final total is Rs. %.2f***\n", finalTotal);
        printf("You have gained 10%% discount for your bill.\nThank you.......!\n");
        printf("========================================================================\n");
    }

    fp = fopen("billLists.txt","a");


    bills.day= day;
    bills.month = month;
    bills.year =year;
    bills.hours=hours;
    bills.minutes=minutes;
    bills.seconds=seconds;
    bills.membershipCardNum = membershipNumber;
    bills.itemCount = noOfPizzas+noOfBeverages;
    bills.pizzaCount = noOfPizzas;
    bills.beverageCount = noOfBeverages;
    bills.totalBill = finalTotal;
    strcpy(bills.typeOfOrder,typeOfOrder);

    fwrite(&bills,sizeof(struct billing),1,fp);
    fclose(fp);

    goBack();
}

//Displaying all saved records
void displayBills(){
    struct billing bills;
    FILE *fp;

    fp=fopen("billLists.txt","r");
    printf("\n\n=========================== Records ===========================\n\n");

    while(fread(&bills,sizeof(struct billing),1,fp)){
        printf("\n%s : %13d-%d-%d  %d:%d:%d\n%s : %5d\n%s : %18s\n%s : %15d\n%s : %11d\n%s : %8d\n%s : %25.2f\n\n","Date and Time",bills.day,bills.month,bills.year,bills.hours,bills.minutes,bills.seconds,"Membership Card Number",bills.membershipCardNum,"Type of Order",bills.typeOfOrder, "Item Count",bills.itemCount,"Pizza Quantity",bills.pizzaCount,"Beverage Quantity",bills.beverageCount,"Total",bills.totalBill);
    }

    fclose(fp);
}

//Returning back to the home page
void goBack(){
    int back;

    printf("\n\nPRESS 1 TO FINISH \n");
    scanf("%d",&back);
    if(back==1){
        printf("\n\n");
        system("cls");
        total=0;
        finalTotal=0.0;
        noOfPizzas=0;
        noOfBeverages=0;
        main();
    }
}
