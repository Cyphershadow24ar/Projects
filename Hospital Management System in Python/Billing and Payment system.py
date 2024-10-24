# billing.py

bills = []

def generate_bill():
    """Generate a bill for a patient"""
    patient_id = input("Enter Patient ID: ").strip()
    amount = float(input("Enter Bill Amount: ").strip())
    bills.append({'patient_id': patient_id, 'amount': amount})
    print("Bill generated successfully!")

def view_bills():
    """View all bills"""
    if bills:
        print("\nBills List:")
        for bill in bills:
            print(f"Patient ID: {bill['patient_id']}, Amount: {bill['amount']}")
    else:
        print("No bills available.")

def search_bill():
    """Search for a bill by Patient ID"""
    patient_id = input("Enter Patient ID to search for bill: ").strip()
    for bill in bills:
        if bill['patient_id'] == patient_id:
            print(f"Bill found: Patient ID: {bill['patient_id']}, Amount: {bill['amount']}")
            return
    print("No bill found for the given Patient ID.")

def update_bill():
    """Update the bill amount for a specific patient"""
    patient_id = input("Enter Patient ID to update bill: ").strip()
    for bill in bills:
        if bill['patient_id'] == patient_id:
            new_amount = float(input("Enter new bill amount: ").strip())
            bill['amount'] = new_amount
            print("Bill updated successfully!")
            return
    print("No bill found for the given Patient ID.")

def remove_bill():
    """Remove a bill for a specific patient"""
    patient_id = input("Enter Patient ID to remove bill: ").strip()
    for i, bill in enumerate(bills):
        if bill['patient_id'] == patient_id:
            del bills[i]
            print("Bill removed successfully!")
            return
    print("No bill found for the given Patient ID.")

# If-Else Case to run billing functions
def billing_menu():
    while True:
        print("\n--- Billing and Payment System ---")
        print("1. Generate Bill")
        print("2. View Bills")
        print("3. Search Bill")
        print("4. Update Bill")
        print("5. Remove Bill")
        print("6. Go Back")

        choice = input("Choose an option: ").strip()

        if choice == '1':
            generate_bill()
        elif choice == '2':
            view_bills()
        elif choice == '3':
            search_bill()
        elif choice == '4':
            update_bill()
        elif choice == '5':
            remove_bill()
        elif choice == '6':
            print("Returning to main menu...")
            break
        else:
            print("Invalid choice! Please choose a valid option.")


# Main program to run the billing menu
if __name__ == "__main__":
    billing_menu()
