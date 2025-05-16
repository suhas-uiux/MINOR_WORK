// 🛍️ Geek Olympics Code Debugging Round
// 🔧 Scenario: The Shopkeeper’s Calculator Woes

// 📝 Story-Based Prompt:
// Raj is a humble shopkeeper who recently got a custom-built calculator from a local coder. He uses it daily to perform basic arithmetic operations and calculate total prices with tax. But his customers have started complaining about strange results:

// 📜 One day, a customer tried to divide a bill of ₹100 by 0 (due to an input mistake), and the calculator returned Infinity!
// 📜 On another occasion, Raj forgot to add tax to the bill, and the total charged was less than expected. His regulars noticed the discrepancy.
// To calculate total with tax:
// totalWithTax = price + (price × taxRate)
// Assume taxRate = 0.18 (i.e., 18%)

// 📜 Raj recently started using the calculator to generate invoices. One day, while entering product prices, he accidentally entered a negative number (e.g., -₹150). The calculator happily accepted it, and the total came out as a negative amount — which confused both Raj and the customer.
// “Why do I owe them money when they’re buying from me?!” he exclaimed.
// Now, Raj realizes his calculator needs proper validation too.

// 📌 Raj needs your help to fix these bugs and make the calculator reliable again.

#include <stdio.h>

double add(double item1Price, double item2Price) {
    return item1Price + item2Price;
}

double subtract(double item1Price, double item2Price) {
    return item1Price + item2Price; // Bug: Should be subtraction
}

double multiply(double item1Price, double item2Price) {
    return item1Price * item2Price;
}

double divide(double item1Price, double item2Price) {
    return item1Price / item2Price; // No division by zero handling
}

double calculateTotalWithTax(double itemPrice) {
    return itemPrice; // Bug: tax not added
}

int main() {
    int choice;
    double item1Price, item2Price, itemPrice;

    printf("Welcome to Raj’s Buggy Calculator!\n");
    printf("Select operation:\n");
    printf("1. + (Addition)\n");
    printf("2. - (Subtraction)\n");
    printf("3. * (Multiplication)\n");
    printf("4. / (Division)\n");
    printf("5. Calculate Total with Tax\n");

    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter prices of two items: ");
            scanf("%lf %lf", &item1Price, &item2Price);
            printf("Result: %lf\n", add(item1Price, item2Price));
        case 2:
            printf("Enter prices of two items: ");
            scanf("%lf %lf", &item1Price, &item2Price);
            printf("Result: %lf\n", subtract(item1Price, item2Price));
        case 3:
            printf("Enter prices of two items: ");
            scanf("%lf %lf", &item1Price, &item2Price);
            printf("Result: %lf\n", multiply(item1Price, item2Price));
        case 4:
            printf("Enter prices of two items: ");
            scanf("%lf %lf", &item1Price, &item2Price);
            printf("Result: %lf\n", divide(item1Price, item2Price));
        case 5:
            printf("Enter price of the item: ");
            scanf("%lf", &itemPrice);
            printf("Total with Tax: ₹%lf\n", calculateTotalWithTax(itemPrice));
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}
