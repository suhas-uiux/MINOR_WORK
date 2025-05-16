

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
