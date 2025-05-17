// # // 🛍️ Geek Olympics Code Debugging Round
// # // 🔧 Scenario: The Shopkeeper’s Calculator Woes

// # // 📝 Story-Based Prompt:
// # // Raj is a humble shopkeeper who recently got a custom-built calculator from a local coder. He uses it daily to perform basic arithmetic operations and calculate total prices with tax. But his customers have started complaining about strange results:

// # // 📜 One day, a customer tried to divide a bill of ₹100 by 0 (due to an input mistake), and the calculator returned Infinity!
// # // 📜 On another occasion, Raj forgot to add tax to the bill, and the total charged was less than expected. His regulars noticed the discrepancy.
// # // To calculate total with tax:
// # // totalWithTax = price + (price × taxRate)
// # // Assume taxRate = 0.18 (i.e., 18%)

// # // 📜 Raj recently started using the calculator to generate invoices. One day, while entering product prices, he accidentally entered a negative number (e.g., -₹150). The calculator happily accepted it, and the total came out as a negative amount — which confused both Raj and the customer.
// # // “Why do I owe them money when they’re buying from me?!” he exclaimed.
// # // Now, Raj realizes his calculator needs proper validation too.

// # // 📌 Raj needs your help to fix these bugs and make the calculator reliable again.
#include <iostream>
using namespace std;

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
    cout << "Welcome to Raj’s Buggy Calculator!" << endl;
    cout << "Select operation:" << endl;
    cout << "1. + (Addition)" << endl;
    cout << "2. - (Subtraction)" << endl;
    cout << "3. * (Multiplication)" << endl;
    cout << "4. / (Division)" << endl;
    cout << "5. Calculate Total with Tax" << endl;

    int choice;
    cin >> choice;

    double item1Price, item2Price, itemPrice;

    switch(choice) {
        case 1:
            cout << "Enter prices of two items: ";
            cin >> item1Price >> item2Price;
            cout << "Result: " << add(item1Price, item2Price) << endl;
        case 2:
            cout << "Enter prices of two items: ";
            cin >> item1Price >> item2Price;
            cout << "Result: " << subtract(item1Price, item2Price) << endl;
        case 3:
            cout << "Enter prices of two items: ";
            cin >> item1Price >> item2Price;
            cout << "Result: " << multiply(item1Price, item2Price) << endl;
        case 4:
            cout << "Enter prices of two items: ";
            cin >> item1Price >> item2Price;
            cout << "Result: " << divide(item1Price, item2Price) << endl;
        case 5:
            cout << "Enter price of the item: ";
            cin >> itemPrice;
            cout << "Total with Tax: ₹" << calculateTotalWithTax(itemPrice) << endl;
        default:
            cout << "Invalid choice." << endl;
    }

    return 0;
}
---------------------------------------------------------------------------------------------------------------------------------
| Bug/Issue                     | Fix Applied                                  |
| ----------------------------- | -------------------------------------------- |
| ❌ Subtraction was wrong       | ✅ Changed `+` to `-` in subtraction function |
| ❌ No division by zero check   | ✅ Added zero check and error message         |
| ❌ No tax added in calculation | ✅ Applied 18% tax logic                      |
| ❌ Negative price allowed      | ✅ Checked and blocked negative input         |
| ❌ No `break` statements       | ✅ Added `break` in all switch cases          |

--------------------------------------------------------------------------------------------------------------------------------
                                    CORRECTED CODE
    #include <iostream>
using namespace std;

double add(double item1Price, double item2Price) {
    return item1Price + item2Price;
}

double subtract(double item1Price, double item2Price) {
    return item1Price - item2Price; // ✅ Fixed: subtraction
}

double multiply(double item1Price, double item2Price) {
    return item1Price * item2Price;
}

double divide(double item1Price, double item2Price) {
    if (item2Price == 0) {
        cout << "Error: Cannot divide by zero." << endl;
        return 0.0;
    }
    return item1Price / item2Price;
}

double calculateTotalWithTax(double itemPrice) {
    if (itemPrice < 0) {
        cout << "Error: Negative price is not allowed." << endl;
        return 0.0;
    }
    double taxRate = 0.18;
    return itemPrice + (itemPrice * taxRate);
}

int main() {
    cout << "Welcome to Raj’s Reliable Calculator!" << endl;
    cout << "Select operation:" << endl;
    cout << "1. + (Addition)" << endl;
    cout << "2. - (Subtraction)" << endl;
    cout << "3. * (Multiplication)" << endl;
    cout << "4. / (Division)" << endl;
    cout << "5. Calculate Total with Tax" << endl;

    int choice;
    cin >> choice;

    double item1Price, item2Price, itemPrice;

    switch (choice) {
        case 1:
            cout << "Enter prices of two items: ";
            cin >> item1Price >> item2Price;
            cout << "Result: " << add(item1Price, item2Price) << endl;
            break;
        case 2:
            cout << "Enter prices of two items: ";
            cin >> item1Price >> item2Price;
            cout << "Result: " << subtract(item1Price, item2Price) << endl;
            break;
        case 3:
            cout << "Enter prices of two items: ";
            cin >> item1Price >> item2Price;
            cout << "Result: " << multiply(item1Price, item2Price) << endl;
            break;
        case 4:
            cout << "Enter prices of two items: ";
            cin >> item1Price >> item2Price;
            cout << "Result: " << divide(item1Price, item2Price) << endl;
            break;
        case 5:
            cout << "Enter price of the item: ";
            cin >> itemPrice;
            cout << "Total with Tax: ₹" << calculateTotalWithTax(itemPrice) << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
    }

    return 0;
}
