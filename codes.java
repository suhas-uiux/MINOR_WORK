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

import java.util.Scanner;

public class BuggyCalculator {

    public static double add(double item1Price, double item2Price) {
        return item1Price + item2Price;
    }

    public static double subtract(double item1Price, double item2Price) {
        return item1Price + item2Price;
    }

    public static double multiply(double item1Price, double item2Price) {
        return item1Price * item2Price;
    }

    public static double divide(double item1Price, double item2Price) {
        return item1Price / item2Price;
    }

    public static double calculateTotalWithTax(double itemPrice) {
        return itemPrice;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Welcome to Raj’s Buggy Calculator!");
        System.out.println("Select operation:");
        System.out.println("1. + (Addition)");
        System.out.println("2. - (Subtraction)");
        System.out.println("3. * (Multiplication)");
        System.out.println("4. / (Division)");
        System.out.println("5. Calculate Total with Tax");

        int choice = sc.nextInt();
        double item1Price, item2Price, itemPrice;

        switch (choice) {
            case 1:
                System.out.print("Enter prices of two items: ");
                item1Price = sc.nextDouble();
                item2Price = sc.nextDouble();
                System.out.println("Result: " + add(item1Price, item2Price));
            case 2:
                System.out.print("Enter prices of two items: ");
                item1Price = sc.nextDouble();
                item2Price = sc.nextDouble();
                System.out.println("Result: " + subtract(item1Price, item2Price));
            case 3:
                System.out.print("Enter prices of two items: ");
                item1Price = sc.nextDouble();
                item2Price = sc.nextDouble();
                System.out.println("Result: " + multiply(item1Price, item2Price));
            case 4:
                System.out.print("Enter prices of two items: ");
                item1Price = sc.nextDouble();
                item2Price = sc.nextDouble();
                System.out.println("Result: " + divide(item1Price, item2Price));
            case 5:
                System.out.print("Enter price of the item: ");
                itemPrice = sc.nextDouble();
                System.out.println("Total with Tax: ₹" + calculateTotalWithTax(itemPrice));
            default:
                System.out.println("Invalid choice.");
        }

        sc.close();
    }
}
---------------------------------------------------------------------------------------------------------------------------------
    | Bug                                             | Fix                                                              |
| ----------------------------------------------- | ---------------------------------------------------------------- |
| ❌ Subtraction used addition logic               | ✅ Changed `item1Price + item2Price` to `item1Price - item2Price` |
| ❌ No check for divide by zero                   | ✅ Added check to avoid dividing by zero                          |
| ❌ Tax function returned price as-is             | ✅ Implemented correct tax formula: `price + (price * 0.18)`      |
| ❌ Negative item prices allowed                  | ✅ Validation added to reject negative prices in tax calculation  |
| ❌ Missing case for multiplication               | ✅ Added `case 3:` with correct logic                             |
| ❌ Missing `break` statements caused fallthrough | ✅ Added `break` to each case                                     |

--------------------------------------------------------------------------------------------------------------------------------

                                            CORRECTED CODE
    
    import java.util.Scanner;

public class BuggyCalculator {

    // Correct addition method
    public static double add(double item1Price, double item2Price) {
        return item1Price + item2Price;
    }

    // Fixed subtraction: it was incorrectly doing addition earlier
    public static double subtract(double item1Price, double item2Price) {
        return item1Price - item2Price;
    }

    // Multiplication method is fine
    public static double multiply(double item1Price, double item2Price) {
        return item1Price * item2Price;
    }

    // Division with zero check to avoid Infinity or crash
    public static double divide(double item1Price, double item2Price) {
        if (item2Price == 0) {
            System.out.println("Error: Cannot divide by zero.");
            return Double.NaN; // Return NaN to indicate an invalid result
        }
        return item1Price / item2Price;
    }

    // Tax calculation with input validation
    public static double calculateTotalWithTax(double itemPrice) {
        if (itemPrice < 0) {
            System.out.println("Error: Negative price is not allowed.");
            return 0;
        }
        double taxRate = 0.18;
        return itemPrice + (itemPrice * taxRate);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Welcome to Raj’s Reliable Calculator!");
        System.out.println("Select operation:");
        System.out.println("1. + (Addition)");
        System.out.println("2. - (Subtraction)");
        System.out.println("3. * (Multiplication)");
        System.out.println("4. / (Division)");
        System.out.println("5. Calculate Total with Tax");

        int choice = sc.nextInt();
        double item1Price, item2Price, itemPrice;

        switch (choice) {
            case 1:
                System.out.print("Enter prices of two items: ");
                item1Price = sc.nextDouble();
                item2Price = sc.nextDouble();
                System.out.println("Result: " + add(item1Price, item2Price));
                break;

            case 2:
                System.out.print("Enter prices of two items: ");
                item1Price = sc.nextDouble();
                item2Price = sc.nextDouble();
                System.out.println("Result: " + subtract(item1Price, item2Price));
                break;

            case 3:
                System.out.print("Enter prices of two items: ");
                item1Price = sc.nextDouble();
                item2Price = sc.nextDouble();
                System.out.println("Result: " + multiply(item1Price, item2Price));
                break;

            case 4:
                System.out.print("Enter prices of two items: ");
                item1Price = sc.nextDouble();
                item2Price = sc.nextDouble();
                System.out.println("Result: " + divide(item1Price, item2Price));
                break;

            case 5:
                System.out.print("Enter price of the item: ");
                itemPrice = sc.nextDouble();
                System.out.println("Total with Tax: ₹" + calculateTotalWithTax(itemPrice));
                break;

            default:
                System.out.println("Invalid choice.");
        }

        sc.close();
    }
}

