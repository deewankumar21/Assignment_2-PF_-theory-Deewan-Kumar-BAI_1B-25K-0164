#include <stdio.h>
#include <string.h>

char product[][20] = {"Rice (5kg)", "Sugar (1kg)", "Cooking Oil", "Flour (10kg)", "Tea Pack", 
                      "Milk (1L)", "Bread", "Eggs (Dozen)", "Shampoo", "Soap (Bar)"};
int quantity[10] = {50, 100, 75, 40, 60, 120, 80, 90, 35, 150};
int price[10] = {1200, 180, 560, 950, 720, 220, 180, 350, 450, 120};

void displayProducts() {
    printf("\n=============== SUPERMARKET INVENTORY ===============\n");
    printf("| %-10s | %-15s | %-10s | %-10s |\n", "Product ID", "Product Name", "Quantity", "Price (Rs)");
    printf("---------------------------------------------------------\n");
    for(int i = 0; i < 10; i++)
        printf("| %-10d | %-15s | %-10d | %-10d |\n", i + 101, product[i], quantity[i], price[i]);
    printf("---------------------------------------------------------\n");
}

int UpdateInventory(int prodId, int qty) {
    int bill = 0;
    quantity[prodId] -= qty;
    bill += (price[prodId] * qty);
    return bill;
}

void Showinvoice(int bill, int discount, int chart[], int chartqty[], int cnt, char name[], char cnic[]) {
    printf("\n=============== INVOICE ===============\n");
    printf("Customer Name: %s\n", name);
    printf("CNIC Number: %s\n", cnic);
    printf("-----------------------------------------\n");
    printf("| %-10s | %-15s | %-10s | %-10s |\n", "Product ID", "Product Name", "Quantity", "Price (Rs)");
    printf("-----------------------------------------\n");
    for(int i = 0; i < cnt; i++)
        printf("| %-10d | %-15s | %-10d | %-10d |\n", 
               chart[i], product[chart[i] - 101], chartqty[i], price[chart[i] - 101]);
    printf("-----------------------------------------\n");
    printf("Total Bill: Rs. %-18d\n", bill);
    printf("Discount Applied: %-15d%%\n", discount);
    printf("Discount Amount: Rs. %-15d\n", (bill * discount) / 100);
    printf("-----------------------------------------\n");
    printf("Final Bill: Rs. %-18d\n", bill - ((bill * discount) / 100));
    printf("\nThank you for shopping with us! Please visit again!\n");
}

int main() {
    printf("===== WELCOME TO SUPERMARKET INVENTORY SYSTEM =====\n");
    
    while(1) {
        char cont;
        printf("\nDo you want to continue? (Y: Yes, N: No): ");
        scanf(" %c", &cont);
        
        if(cont == 'Y' || cont == 'y') {
            char name[100], cnic[14];
            printf("\nEnter Customer Name: ");
            scanf("%s", name);
            printf("Enter CNIC Number (without dashes): ");
            scanf("%s", cnic);
            
            int cnt = 0, chart[100], chartqty[100];
            int bill = 0, discount = 0;
            
            while(1) {
                int qty, prodId;
                displayProducts();
                printf("\nEnter Product ID and Quantity (Enter -1 -1 to finish shopping): ");
                scanf("%d %d", &prodId, &qty);
                
                if(prodId == -1 && qty == -1)
                    break;
                else if(prodId < 101 || prodId > 110)
                    printf("ERROR: Invalid Product ID! Please enter ID between 101-110.\n");
                else if(quantity[prodId - 101] < qty)
                    printf("ERROR: Insufficient stock! Only %d items available.\n", quantity[prodId - 101]);
                else {
                    bill += UpdateInventory(prodId - 101, qty);
                    chart[cnt] = prodId;
                    chartqty[cnt] = qty;
                    cnt++;
                    printf("SUCCESS: %d x %s added to cart!\n", qty, product[prodId - 101]);
                }
            }
            
            if(cnt > 0) {
                char promocode[10];
                printf("\nDo you have a promo code? (Enter 'Eid2025' for 25%% discount or -1 to skip): ");
                scanf("%s", promocode);
                
                if(strcmp(promocode, "Eid2025") == 0) {
                    discount = 25;
                    printf("SUCCESS: 25%% discount applied using promo code 'Eid2025'!\n");
                } else {
                    printf("No discount applied.\n");
                }
                
                Showinvoice(bill, discount, chart, chartqty, cnt, name, cnic);
            } else {
                printf("No items purchased. Thank you for visiting!\n");
            }
        } else {
            printf("\nThank you for using Supermarket System. Goodbye!\n");
            break;
        }
    }
    return 0;
}
