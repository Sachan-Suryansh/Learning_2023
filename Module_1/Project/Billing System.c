#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Item {
    char name[20];
    float price;
    int quantity;
};

struct Order {
    char customer[50];
    char date[50];
    int numOfItems;
    struct Item items[50];
};

void generateBillHeader(const char* name, const char* date) {
    printf("\n\n");
    printf("\t    Odin. Restaurant");
    printf("\n\t   -----------------");
    printf("\nDate: %s", date);
    printf("\nInvoice To: %s", name);
    printf("\n");
    printf("---------------------------------------\n");
    printf("Items\t\t");
    printf("Qty\t\t");
    printf("Total\t\t");
    printf("\n---------------------------------------");
    printf("\n\n");
}

void generateBillBody(const char* itemName, int quantity, float price) {
    printf("%s\t\t", itemName);
    printf("%d\t\t", quantity);
    printf("%.2f\t\t", quantity * price);
    printf("\n");
}

void generateBillFooter(float total) {
    printf("\n");
    float discount = 0.1 * total;
    float netTotal = total - discount;
    float tax = 0.09 * netTotal;
    float grandTotal = netTotal + 2 * tax;
    printf("---------------------------------------\n");
    printf("Sub Total\t\t\t%.2f", total);
    printf("\nDiscount @10%%\t\t\t%.2f", discount);
    printf("\n\t\t\t\t-------");
    printf("\nNet Total\t\t\t%.2f", netTotal);
    printf("\nTax @9%%\t\t\t%.2f", tax);
    printf("\nTax @9%%\t\t\t%.2f", tax);
    printf("\n---------------------------------------");
    printf("\nGrand Total\t\t\t%.2f", grandTotal);
    printf("\n---------------------------------------\n");
}

void saveInvoice(const struct Order* order) {
    FILE* fp = fopen("RestaurantBill.dat", "a+");
    if (fp == NULL) {
        printf("Error opening file.");
        return;
    }
    fwrite(order, sizeof(struct Order), 1, fp);
    fclose(fp);
}

void printAllInvoices() {
    FILE* fp = fopen("RestaurantBill.dat", "r");
    if (fp == NULL) {
        printf("No invoices found.");
        return;
    }
    struct Order order;
    printf("\n  *****Your Previous Invoices*****\n");
    while (fread(&order, sizeof(struct Order), 1, fp)) {
        float total = 0;
        generateBillHeader(order.customer, order.date);
        for (int i = 0; i < order.numOfItems; i++) {
            generateBillBody(order.items[i].name, order.items[i].quantity, order.items[i].price);
            total += order.items[i].quantity * order.items[i].price;
        }
        generateBillFooter(total);
    }
    fclose(fp);
}

void searchInvoice(const char* customerName) {
    FILE* fp = fopen("RestaurantBill.dat", "r");
    if (fp == NULL) {
        printf("No invoices found.");
        return;
    }
    struct Order order;
    int invoiceFound = 0;
    printf("\t*****Invoice of %s*****", customerName);
    while (fread(&order, sizeof(struct Order), 1, fp)) {
        float total = 0;
        if (strcmp(order.customer, customerName) == 0) {
            generateBillHeader(order.customer, order.date);
            for (int i = 0; i < order.numOfItems; i++) {
                generateBillBody(order.items[i].name, order.items[i].quantity, order.items[i].price);
                total += order.items[i].quantity * order.items[i].price;
            }
            generateBillFooter(total);
            invoiceFound = 1;
            break;
        }
    }
    if (!invoiceFound) {
        printf("Sorry, the invoice for %s does not exist", customerName);
    }
    fclose(fp);
}

int main() {
    int option, numItems;
    struct Order order;
    char saveBill = 'y', continueFlag = 'y';

    while (continueFlag == 'y') {
        system("clear");
        float total = 0;
        printf("\t============ODIN RESTAURANT============");
        printf("\n\nPlease select your preferred operation");
        printf("\n\n1. Generate Invoice");
        printf("\n2. Show all Invoices");
        printf("\n3. Search Invoice");
        printf("\n4. Exit");

        printf("\n\nYour choice:\t");
        scanf("%d", &option);
        fflush(stdin);

        switch (option) {
            case 1:
                system("clear");
                printf("\nPlease enter the name of the customer:\t");
                scanf(" %[^\n]", order.customer);
                printf("\nPlease enter the number of items:\t");
                scanf("%d", &numItems);
                order.numOfItems = numItems;
                for (int i = 0; i < numItems; i++) {
                    printf("\n\n");
                    printf("Please enter item %d:\t", i + 1);
                    scanf(" %[^\n]", order.items[i].name);
                    printf("Please enter the quantity:\t");
                    scanf("%d", &order.items[i].quantity);
                    printf("Please enter the unit price:\t");
                    scanf("%f", &order.items[i].price);
                    total += order.items[i].quantity * order.items[i].price;
                }

                generateBillHeader(order.customer, __DATE__);
                for (int i = 0; i < order.numOfItems; i++) {
                    generateBillBody(order.items[i].name, order.items[i].quantity, order.items[i].price);
                }
                generateBillFooter(total);

                printf("\nDo you want to save the invoice [y/n]:\t");
                scanf(" %c", &saveBill);

                if (saveBill == 'y') {
                    saveInvoice(&order);
                    printf("\nSuccessfully saved");
                }
                break;

            case 2:
                system("clear");
                printAllInvoices();
                break;

            case 3:
                printf("Enter the name of the customer:\t");
                scanf(" %[^\n]", order.customer);
                system("clear");
                searchInvoice(order.customer);
                break;

            case 4:
                printf("\n\t\t Bye Bye :)\n\n");
                exit(0);
                break;

            default:
                printf("Sorry, invalid option");
                break;
        }

        printf("\nDo you want to perform another operation? [y/n]:\t");
        scanf(" %c", &continueFlag);
    }

    printf("\n\t\t Bye Bye :)\n\n");

    return 0;
}
