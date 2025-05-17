# // 🛍️ Geek Olympics Code Debugging Round
# // 🔧 Scenario: The Shopkeeper’s Calculator Woes

# // 📝 Story-Based Prompt:
# // Raj is a humble shopkeeper who recently got a custom-built calculator from a local coder. He uses it daily to perform basic arithmetic operations and calculate total prices with tax. But his customers have started complaining about strange results:

# // 📜 One day, a customer tried to divide a bill of ₹100 by 0 (due to an input mistake), and the calculator returned Infinity!
# // 📜 On another occasion, Raj forgot to add tax to the bill, and the total charged was less than expected. His regulars noticed the discrepancy.
# // To calculate total with tax:
# // totalWithTax = price + (price × taxRate)
# // Assume taxRate = 0.18 (i.e., 18%)

# // 📜 Raj recently started using the calculator to generate invoices. One day, while entering product prices, he accidentally entered a negative number (e.g., -₹150). The calculator happily accepted it, and the total came out as a negative amount — which confused both Raj and the customer.
# // “Why do I owe them money when they’re buying from me?!” he exclaimed.
# // Now, Raj realizes his calculator needs proper validation too.

# // 📌 Raj needs your help to fix these bugs and make the calculator reliable again.

def add(item1_price, item2_price):
    return item1_price + item2_price

def subtract(item1_price, item2_price):
    return item1_price + item2_price  # Bug: should subtract

def multiply(item1_price, item2_price):
    return item1_price * item2_price

def divide(item1_price, item2_price):
    return item1_price / item2_price  # No division by zero handling

def calculate_total_with_tax(item_price):
    return item_price  # Bug: tax not added

def main():
    print("Welcome to Raj’s Buggy Calculator!")
    print("Select operation:")
    print("1. + (Addition)")
    print("2. - (Subtraction)")
    print("3. * (Multiplication)")
    print("4. / (Division)")
    print("5. Calculate Total with Tax")

    choice = int(input())

    if choice == 1:
        item1_price = float(input("Enter prices of two items: ").split()[0])
        item2_price = float(input().split()[0])
        print("Result:", add(item1_price, item2_price))
    if choice == 2:
        item1_price = float(input("Enter prices of two items: ").split()[0])
        item2_price = float(input().split()[0])
        print("Result:", subtract(item1_price, item2_price))
    if choice == 3:
        item1_price = float(input("Enter prices of two items: ").split()[0])
        item2_price = float(input().split()[0])
        print("Result:", multiply(item1_price, item2_price))
    if choice == 4:
        item1_price = float(input("Enter prices of two items: ").split()[0])
        item2_price = float(input().split()[0])
        print("Result:", divide(item1_price, item2_price))
    if choice == 5:
        item_price = float(input("Enter price of the item: "))
        print("Total with Tax: ₹", calculate_total_with_tax(item_price))
    else:
        print("Invalid choice.")

if __name__ == "__main__":
    main()
------------------------------------------------------------------------------------------------------------------
| Issue                                           | Fix                                           |
| ----------------------------------------------- | --------------------------------------------- |
| ❌ Subtraction was using addition                | ✅ Corrected to `item1_price - item2_price`    |
| ❌ Division by zero allowed                      | ✅ Added check and returned error message      |
| ❌ Tax function didn't calculate tax             | ✅ Implemented `price + price * 0.18`          |
| ❌ Negative price accepted                       | ✅ Added validation in tax function            |
| ❌ Input parsing with `.split()` was unnecessary | ✅ Simplified with direct input and conversion |
| ❌ No `elif`, so all if-blocks executed          | ✅ Replaced with `elif` to prevent fallthrough |


    ---------------------------------------------------------------------------------------------------------------
                                    CORRECTED CODE

    def add(item1_price, item2_price):
    return item1_price + item2_price

def subtract(item1_price, item2_price):
    return item1_price - item2_price  # Fixed: corrected to subtraction

def multiply(item1_price, item2_price):
    return item1_price * item2_price

def divide(item1_price, item2_price):
    if item2_price == 0:
        print("Error: Cannot divide by zero.")
        return None  # Return None to indicate error
    return item1_price / item2_price

def calculate_total_with_tax(item_price):
    if item_price < 0:
        print("Error: Negative price is not allowed.")
        return None
    tax_rate = 0.18
    return item_price + (item_price * tax_rate)

def main():
    print("Welcome to Raj’s Reliable Calculator!")
    print("Select operation:")
    print("1. + (Addition)")
    print("2. - (Subtraction)")
    print("3. * (Multiplication)")
    print("4. / (Division)")
    print("5. Calculate Total with Tax")

    try:
        choice = int(input("Enter your choice (1-5): "))
    except ValueError:
        print("Invalid input. Please enter a number.")
        return

    if choice == 1:
        item1_price = float(input("Enter price of first item: "))
        item2_price = float(input("Enter price of second item: "))
        print("Result:", add(item1_price, item2_price))

    elif choice == 2:
        item1_price = float(input("Enter price of first item: "))
        item2_price = float(input("Enter price of second item: "))
        print("Result:", subtract(item1_price, item2_price))

    elif choice == 3:
        item1_price = float(input("Enter price of first item: "))
        item2_price = float(input("Enter price of second item: "))
        print("Result:", multiply(item1_price, item2_price))

    elif choice == 4:
        item1_price = float(input("Enter price of first item: "))
        item2_price = float(input("Enter price of second item: "))
        result = divide(item1_price, item2_price)
        if result is not None:
            print("Result:", result)

    elif choice == 5:
        item_price = float(input("Enter price of the item: "))
        result = calculate_total_with_tax(item_price)
        if result is not None:
            print("Total with Tax: ₹", result)

    else:
        print("Invalid choice.")

if __name__ == "__main__":
    main()

