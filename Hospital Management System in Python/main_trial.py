# main.py

import hospitalmodule as mm

def main_menu():
    while True:
        print("\n--- Hospital Management System ---")
        print("1. Patient Management")
        print("2. Doctor Management")
        print("3. Appointment Management")
        print("4. Billing Management")
        print("5. Pharmacy Management")
        print("6. Exit")

        choice = input("Enter your choice: ")
        if choice == '1':
            patient_management_menu()
        elif choice == '2':
            doctor_management_menu()
        elif choice == '3':
            appointment_management_menu()
        elif choice == '4':
            billing_management_menu()
        elif choice == '5':
            pharmacy_management_menu()
        elif choice == '6':
            mm.close_connection()  # Close the MySQL connection
            print("Goodbye!")
            break
        
def patient_management_menu():
    while True:
        print("\n--- Patient Management ---")
        print("1. Add Patient")
        print("2. Display Patients")
        print("3. Update Appointment")
        print("4. Admit Patient")
        print("5. Discharge Patient")
        print("6. List Inpatients")
        print("7. Go Back")

        choice = input("Enter your choice: ")

        if choice == '1':
            mm.add_patient()
        elif choice == '2':
            mm.display_patients()
        elif choice == '3':
            mm.update_appointment()
        elif choice == '4':
            mm.admit_patient()
        elif choice == '5':
            mm.discharge_patient()
        elif choice == '6':
            mm.list_inpatients()
        elif choice == '7':
            break
        else:
            print("Invalid choice, please try again.")

def doctor_management_menu():
    while True:
        print("\n--- Doctor Management ---")
        print("1. Add Doctor")
        print("2. Display Doctors")
        print("3. Go Back")

        choice = input("Enter your choice: ")

        if choice == '1':
            mm.add_doctor()
        elif choice == '2':
            mm.display_doctors()
        elif choice == '3':
            break
        else:
            print("Invalid choice, please try again.")

def appointment_management_menu():
    while True:
        print("\n--- Appointment Management ---")
        print("1. Create Appointment")
        print("2. Display Appointments")
        print("3. Go Back")

        choice = input("Enter your choice: ")
        if choice == '1':
            mm.create_appointment()
        elif choice == '2':
            mm.display_appointments()
        elif choice == '3':
            break
        else:
            print("Invalid choice, please try again.")

def billing_management_menu():
    while True:
        print("\n--- Billing Management ---")
        print("1. Generate Bill")
        print("2. View Bills")
        print("3. Go Back")

        choice = input("Enter your choice: ")

        if choice == '1':
            mm.generate_bill()
        elif choice == '2':
            mm.view_bills()
        elif choice == '3':
            break
        else:
            print("Invalid choice, please try again.")

def pharmacy_management_menu():
    while True:
        print("\n--- Pharmacy Management ---")
        print("1. Add Medicine")
        print("2. View Pharmacy Stock")
        print("3. Go Back")

        choice = input("Enter your choice: ")

        if choice == '1':
            mm.add_medicine()
        elif choice == '2':
            mm.view_pharmacy_stock()
        elif choice == '3':
            break
        else:1
print("Invalid choice, please try again.")

if __name__ == '__main__':
    main_menu()