#include <stdio.h>
#include<time.h>

struct product
{
    int product_id;
    char product_name[20];
    int quantity;
    float price;
};

void inputProduct(struct product* item)
{
    printf("Enter product name : ");
    scanf("%s", item->product_name);
    printf("Enter quantity(packet[1 kg per packet]) : ");
    scanf("%d", &item->quantity);
    printf("Enter price : ");
    scanf("%f", &item->price);
}

void displayProduct(const struct product* item)
{
    printf("Product ID : %d\n", item->product_id);
    printf("Product name : %s\n", item->product_name);
    printf("Product quantity : %d\n", item->quantity);
    printf("Product price : %.2f $\n", item->price);
}

void current_date()
{
    time_t current_date = time(NULL);

    char date_string[20];
    strftime(date_string, 20, " %Y-%m-%d", localtime(&current_date));   //strftime function to format the current time into a string /// The localtime function is used to convert the current_time value (in seconds) into a struct tm structure representing the local time.

    printf("\t\t%s\t\t\t", date_string);

}

void current_time()
{
    time_t s, val = 1;
    struct tm* current_time;

    s = time(NULL);

    current_time = localtime(&s);

    printf("%d:%d:%d\n",current_time->tm_hour,current_time->tm_min,current_time->tm_sec);
}
int main()
{
    printf("\t\t\t ****** CASH RECEIPT ******\n");
    printf("\t\t Address: Inhan-12 gil, Bongchondong, Naksandae\n");
    printf("\t\t Telephone: 010--------\n");

    printf("\t---------------------------------------------------------------------\n");


    current_date();      //function to print current date
    current_time();      //function to print current time
    printf("\t---------------------------------------------------------------------\n");

    int choice;
    struct product inventory[100];
    int itemCount = 0;
    float subtotal = 0.0;
    float tax=0.0;
    float balance = 0.0;

    printf("\n        MENU : \n");
    printf("1. Add a product to inventory \n");
    printf("2. Display all product in inventory \n");
    printf("3. Calculate and generate total \n");
    printf("4. Exit \n");

    while(1)
    {
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        printf("\n");

        switch(choice)
        {
        case 1:
            if(itemCount<100)
            {
                printf("--- Enter details for new product ---- \n");
                inputProduct(&inventory[itemCount]);
                inventory[itemCount].product_id = itemCount+1;
                itemCount++;
                printf("Product added to the inventory \n");
            }
            else
            {
                printf("Inventory is full, cannot add new product ");
            }
            break;


        case 2:
            if(itemCount>0)
            {
                printf(" **Inventory products**\n");
                for(int i=0; i<itemCount; i++)
                {
                    printf("PRODUCT %d : \n", i+1);
                    displayProduct(&inventory[i]);
                    printf("\n");
                }
            }
            else
            {
                printf("Inventory is empty !");
            }
            break;

        case 3:
            if(itemCount>0)
            {
                for(int i=0; i<itemCount; i++)
                {
                    subtotal += inventory[i].price * inventory[i].quantity;
                }
                tax = 0.1*subtotal;
                balance = subtotal + tax;

                //receipt
                printf("Receipt : \n");
                printf("Subtotal : %.2f $\n", subtotal);
                printf("Tax : %.2f $\n", tax);
                printf("Balance to pay : %.2f $\n", balance);

                //calculate+display balance
//                float payment;
//                printf("Enter paymant amount : \n");
//                scanf("%f", &payment);
//                float balance = payment - subtotal;
//                printf("Balance: %.2f$\n", balance);
            }
            else
            {
                printf("Inventory is empty. Cannot generate a receipt.\n");
            }
            break;


        case 4:
            printf("Exiting the program.\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");

        }
    }

}

