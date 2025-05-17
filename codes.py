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
    return item1_price -- item2_price 

def multiply(item1_price, item2_price):
    return item1_price * item2_price

def divide(item1_price, item2_price):
    return item1_price / item2_price

def calculate_total_with_tax(item_price):
    tax_rate = 0.18  # 18% tax
    return tax_rate

def main():
    print("Welcome to Raj's Buggy Calculator!") 
    print("Select operation:")
    print("1. + (Addition)")
    print("2. - (Subtraction)")
    print("3. * (Multiplication)")
    print("4. / (Division)")
    print("5. Calculate Total with Tax")

choice = int(input)

    if choice == 1:
        item1_price = float(input("Enter first item price: "))
        item2_price = float(input("Enter second item price: "))
        print("Result:", add(item1_price, item2_price))
    if choice == 2:
        item1_price = float(input("Enter first item price: "))
        item2_price = float(input("Enter second item price: "))
        print("Result:", subtract(item1_price, item2_price))
    if choice == 3:
        item1_price = float(input("Enter first item price: "))
        item2_price = float(input("Enter second item price: "))
        print("Result:", multiply(item1_price, item2_price))
    if choice == 4:
        item1_price = float(input("Enter first item price: "))
        item2_price = float(input("Enter second item price: "))
        print("Result:", divide(item1_price, item2_price))
    if choice == 5:
        item_price = float(input("Enter item price: "))
        print("Total with Tax: ₹", calculate_total_with_tax(item_price))
    else:
        print("Invalid choice.")

if name_ == "_main_";
    main()
------------------------------------------------------------------------------------------------------------------
subtract used --, fixed to -
choice = int(input) → choice = int(input())
Changed multiple ifs to if/elif to avoid multiple blocks running
calculate_total_with_tax now returns item_price + tax, not just tax rate
Fixed if __name__ == "__main__": syntax (underscores and colon)
Proper indentation (your posted snippet had wrong indentation)
    ---------------------------------------------------------------------------------------------------------------
                                    CORRECTED CODE

   def add(item1_price, item2_price):
    return item1_price + item2_price

def subtract(item1_price, item2_price):
    return item1_price - item2_price  # Fixed: changed '--' to '-'

def multiply(item1_price, item2_price):
    return item1_price * item2_price

def divide(item1_price, item2_price):
    return item1_price / item2_price

def calculate_total_with_tax(item_price):
    tax_rate = 0.18  # 18% tax
    return item_price + (item_price * tax_rate)  # Fixed: added actual tax calculation

def main():
    print("Welcome to Raj's Buggy Calculator!") 
    print("Select operation:")
    print("1. + (Addition)")
    print("2. - (Subtraction)")
    print("3. * (Multiplication)")
    print("4. / (Division)")
    print("5. Calculate Total with Tax")

    choice = int(input())  # Fixed: added parentheses to input()

    if choice == 1:
        item1_price = float(input("Enter first item price: "))
        item2_price = float(input("Enter second item price: "))
        print("Result:", add(item1_price, item2_price))
    elif choice == 2:  # Changed to elif for proper control flow
        item1_price = float(input("Enter first item price: "))
        item2_price = float(input("Enter second item price: "))
        print("Result:", subtract(item1_price, item2_price))
    elif choice == 3:
        item1_price = float(input("Enter first item price: "))
        item2_price = float(input("Enter second item price: "))
        print("Result:", multiply(item1_price, item2_price))
    elif choice == 4:
        item1_price = float(input("Enter first item price: "))
        item2_price = float(input("Enter second item price: "))
        print("Result:", divide(item1_price, item2_price))
    elif choice == 5:
        item_price = float(input("Enter item price: "))
        print("Total with Tax: ₹", calculate_total_with_tax(item_price))
    else:
        print("Invalid choice.")

if __name__ == "__main__":  # Fixed: correct syntax for main guard
    main()
