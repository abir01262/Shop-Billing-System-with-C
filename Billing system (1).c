#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>

int main()
{
    int productsid[8] = {1, 2, 3, 4, 5, 6, 7, 8};//list                                                                               
    char productnames[8][80] = {"Rice", "Sugar", "Milk", "Bread", "Eggs", "Coca-cola", "Noodles", "Mayonese"};
    float productprices[8] = {75.00, 80.00, 120.00, 50.00, 20.00, 130.00, 65.00, 125.00, 300.00};
    int cart[50];
    int quantityincart[50];
    int cartCount = 0;
    int choice, quantity;
    int receiptNo = 1001;                                                                                                     

    printf("Welcome to Super Shop Billing System...\n");                                                                                   
        
        printf("\nAvailable Products:\n");
        printf("ID\tNAME\t\t\tPRICE (Tk)\n");
        printf("-----------------------------------\n");
        for (int i = 0; i < 8; i++)
        {
            printf("%d\t%-15s\t%.2f Tk\n", productsid[i], productnames[i], productprices[i]);
        }
        printf("-----------------------------------\n");                                                                                        
    while (1)
    {
                                               
        printf("\nEnter product ID to add it to cart : ");                    
        scanf("%d", &choice);                                                                                      
        if (choice == 0)
        {
            break;
        }

        int productIndex = -1;                                                    
        for (int i = 0; i < 8; i++)   
        {
            if (productsid[i] == choice)                                         
            {
                productIndex = i;
                break;
            }
        }
                  
        if (productIndex != -1)                                
        {
            printf("Enter Quantity: ");                        
            scanf("%d", &quantity);
            if (quantity > 0)                                    
            {
                // Adding product to the cart
                cart[cartCount] = choice;                     
                quantityincart[cartCount] = quantity;                
                cartCount++;                                    
                printf("\nProduct added to the cart.\n");   
            }
            else
            {
                printf("\nInvalid quantity! Please try again.\n");
            }
        }
        else
        {
            printf("\nInvalid product ID input! Please try again.\n");
        }
    }                                                                                        
        //billing part  starts
    if (cartCount > 0)                       
    {
        float total = 0;
        printf("\n--- Super Shop Receipt ---\n");
        printf("Receipt No: %d\n", receiptNo);                      //recept numberr
        printf("---------------------------------------\n");
        printf("Product         Quantity    Price   Subtotal\n");
        printf("---------------------------------------\n");

        for (int i = 0; i < cartCount; i++)                 
        {
            int productIndex = -1;                           
            for (int k = 0; k < 8; k++)              //inner loop 
            {
                if (productsid[k] == cart[i])              
                {
                    productIndex = k;                
                    break;
                }
            }
            if (productIndex != -1)
            {
                float subtotal = productprices[productIndex] * quantityincart[i];
                total += subtotal;
                printf("%-15s\t%d\t\t%.2f\t%.2f\n", productnames[productIndex], quantityincart[i], productprices[productIndex], subtotal);
            }
        }
        printf("---------------------------------------\n");
        printf("Total Amount: %.2f Tk\n", total);
        printf("Thank you for shopping with us!\n");
        receiptNo++;
    }
    else
    {
        printf("\nNo items in the cart. Exiting...\n");
    }

    return 0;
}


