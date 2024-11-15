# pharmacy.py

pharmacy = []

# Function to add new medicine to pharmacy stock
def add_medicine():
    """Add a new medicine to pharmacy stock."""
    name = input("Enter Medicine Name: ").strip()
    quantity = int(input("Enter Quantity: "))
    price = float(input("Enter Price: "))
    pharmacy.append({'name': name, 'quantity': quantity, 'price': price})
    print(f"Medicine '{name}' added successfully!")

# Function to view all medicines in stock
def view_pharmacy_stock():
    """View all medicines currently in stock."""
    if pharmacy:
        print("\nPharmacy Stock:")
        for medicine in pharmacy:
            print(f"Name: {medicine['name']}, Quantity: {medicine['quantity']}, Price: {medicine['price']}")
    else:
        print("\nNo medicines in stock.")

# Function to search for a specific medicine
def search_medicine():
    """Search for a medicine in the stock by name."""
    name = input("Enter the Medicine Name to search: ").strip()
    for medicine in pharmacy:
        if medicine['name'].lower() == name.lower():
            print(f"Found Medicine: Name: {medicine['name']}, Quantity: {medicine['quantity']}, Price: {medicine['price']}")
            return
    print("Medicine not found!")

# Function to update the quantity of an existing medicine
def update_medicine_stock():
    """Update the stock (quantity) of an existing medicine."""
    name = input("Enter Medicine Name to update: ").strip()
    for medicine in pharmacy:
        if medicine['name'].lower() == name.lower():
            new_quantity = int(input("Enter new quantity: "))
            medicine['quantity'] = new_quantity
            print(f"Medicine '{name}' updated successfully!")
            return
    print("Medicine not found!")

# Function to remove a medicine from stock
def remove_medicine():
    """Remove a medicine from the pharmacy stock."""
    name = input("Enter Medicine Name to remove: ").strip()
    for medicine in pharmacy:
        if medicine['name'].lower() == name.lower():
            pharmacy.remove(medicine)
            print(f"Medicine '{name}' removed successfully!")
            return
    print("Medicine not found!")

# Main menu with options
def main_menu():
    print("\n=== Pharmacy Management System ===")
    print("1. Add Medicine")
    print("2. View Pharmacy Stock")
    print("3. Search Medicine")
    print("4. Update Medicine Stock")
    print("5. Remove Medicine")
    print("6. Exit")

# Main function to run the pharmacy management system
if __name__ == "__main__":
    while True:
        main_menu()
        choice = input("Choose an option: ").strip()

        if choice == '1':
            add_medicine()
        elif choice == '2':
            view_pharmacy_stock()
        elif choice == '3':
            search_medicine()
        elif choice == '4':
            update_medicine_stock()
        elif choice == '5':
            remove_medicine()
        elif choice == '6':
            print("Exiting Pharmacy Management System...")
            break
        else:
            print("Invalid choice! Please choose a valid option.")
