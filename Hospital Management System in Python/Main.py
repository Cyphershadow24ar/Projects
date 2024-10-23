# Hospital Management System - Complete Code

# Data storage for each module
patients = []
doctors = []
appointments = []
lab_results = []
patients_in_hospital = []
medical_reports = []
pharmacy = []
bills = []

# Patient Management
def add_patient():
    patient_id = input("Enter Patient ID: ")
    name = input("Enter Patient Name: ")
    age = int(input("Enter Patient Age: "))
    contact = input("Enter Patient Contact Number: ")
    address = input("Enter Patient Address: ")
    patients.append({'id': patient_id, 'name': name, 'age': age, 'contact': contact, 'address': address})
    print("Patient added successfully!")

def view_patients():
    if patients:
        print("Patient List:")
        for patient in patients:
            print(f"ID: {patient['id']}, Name: {patient['name']}, Age: {patient['age']}, Contact: {patient['contact']}, Address: {patient['address']}")
    else:
        print("No patients registered.")

def search_patient():
    patient_id = input("Enter Patient ID to search: ")
    for patient in patients:
        if patient['id'] == patient_id:
            print(f"Found Patient: Name: {patient['name']}, Age: {patient['age']}, Contact: {patient['contact']}, Address: {patient['address']}")
            return
    print("Patient not found!")

def update_patient():
    patient_id = input("Enter Patient ID to update: ")
    for patient in patients:
        if patient['id'] == patient_id:
            patient['name'] = input("Enter new Name: ")
            patient['age'] = int(input("Enter new Age: "))
            patient['contact'] = input("Enter new Contact: ")
            patient['address'] = input("Enter new Address: ")
            print("Patient updated successfully!")
            return
    print("Patient not found!")

def delete_patient():
    patient_id = input("Enter Patient ID to delete: ")
    for patient in patients:
        if patient['id'] == patient_id:
            patients.remove(patient)
            print("Patient deleted successfully!")
            return
    print("Patient not found!")


# Doctor Management
def add_doctor():
    doctor_id = input("Enter Doctor ID: ")
    name = input("Enter Doctor Name: ")
    specialty = input("Enter Specialty: ")
    contact = input("Enter Doctor Contact: ")
    doctors.append({'id': doctor_id, 'name': name, 'specialty': specialty, 'contact': contact})
    print("Doctor added successfully!")

def view_doctors():
    if doctors:
        print("Doctor List:")
        for doctor in doctors:
            print(f"ID: {doctor['id']}, Name: {doctor['name']}, Specialty: {doctor['specialty']}, Contact: {doctor['contact']}")
    else:
        print("No doctors registered.")


# Appointment Management
def schedule_appointment():
    patient_id = input("Enter Patient ID: ")
    doctor_id = input("Enter Doctor ID: ")
    date = input("Enter Appointment Date (YYYY-MM-DD): ")
    time = input("Enter Appointment Time (HH:MM): ")
    appointments.append({'patient_id': patient_id, 'doctor_id': doctor_id, 'date': date, 'time': time})
    print("Appointment scheduled successfully!")

def view_appointments():
    if appointments:
        print("Appointments List:")
        for appointment in appointments:
            print(f"Patient ID: {appointment['patient_id']}, Doctor ID: {appointment['doctor_id']}, Date: {appointment['date']}, Time: {appointment['time']}")
    else:
        print("No appointments scheduled.")


# Laboratory and Diagnostics
def add_lab_result():
    patient_id = input("Enter Patient ID: ")
    test_name = input("Enter Test Name: ")
    result = input("Enter Test Result: ")
    lab_results.append({'patient_id': patient_id, 'test_name': test_name, 'result': result})
    print("Lab result added successfully!")

def view_lab_results():
    if lab_results:
        print("Lab Results:")
        for result in lab_results:
            print(f"Patient ID: {result['patient_id']}, Test Name: {result['test_name']}, Result: {result['result']}")
    else:
        print("No lab results available.")


# Inpatient/Outpatient Management
def admit_patient():
    patient_id = input("Enter Patient ID: ")
    room_number = input("Enter Room Number: ")
    diagnosis = input("Enter Diagnosis: ")
    patients_in_hospital.append({'patient_id': patient_id, 'room_number': room_number, 'diagnosis': diagnosis})
    print("Patient admitted successfully!")

def discharge_patient():
    patient_id = input("Enter Patient ID to discharge: ")
    for patient in patients_in_hospital:
        if patient['patient_id'] == patient_id:
            patients_in_hospital.remove(patient)
            print("Patient discharged successfully!")
            return
    print("Patient not found in hospital.")

def view_inpatients():
    if patients_in_hospital:
        print("Inpatient List:")
        for patient in patients_in_hospital:
            print(f"Patient ID: {patient['patient_id']}, Room Number: {patient['room_number']}, Diagnosis: {patient['diagnosis']}")
    else:
        print("No inpatients in hospital.")


# Medical Report Management
def create_medical_report():
    patient_id = input("Enter Patient ID: ")
    diagnosis = input("Enter Diagnosis: ")
    treatment = input("Enter Treatment Given: ")
    report = f"Patient ID: {patient_id}, Diagnosis: {diagnosis}, Treatment: {treatment}"
    medical_reports.append(report)
    print("Medical report created successfully!")

def view_medical_reports():
    if medical_reports:
        print("Medical Reports:")
        for report in medical_reports:
            print(report)
    else:
        print("No medical reports available.")


# Pharmacy Management
def add_medicine():
    name = input("Enter Medicine Name: ")
    quantity = int(input("Enter Quantity: "))
    price = float(input("Enter Price: "))
    pharmacy.append({'name': name, 'quantity': quantity, 'price': price})
    print("Medicine added successfully!")

def view_pharmacy_stock():
    if pharmacy:
        print("Pharmacy Stock:")
        for medicine in pharmacy:
            print(f"Name: {medicine['name']}, Quantity: {medicine['quantity']}, Price: {medicine['price']}")
    else:
        print("No medicines in stock.")


# Billing and Payment System
def generate_bill():
    patient_id = input("Enter Patient ID: ")
    amount = float(input("Enter Bill Amount: "))
    bills.append({'patient_id': patient_id, 'amount': amount})
    print("Bill generated successfully!")

def view_bills():
    if bills:
        print("Bills List:")
        for bill in bills:
            print(f"Patient ID: {bill['patient_id']}, Amount: {bill['amount']}")
    else:
        print("No bills available.")


# Main Menu
def main_menu():
    print("\n=== Hospital Management System ===")
    print("1. Patient Management")
    print("2. Doctor Management")
    print("3. Appointment Management")
    print("4. Laboratory and Diagnostics")
    print("5. Inpatient/Outpatient Management")
    print("6. Medical Report")
    print("7. Pharmacy Management")
    print("8. Billing and Payment System")
    print("9. Exit")

if __name__ == "__main__":
    while True:
        main_menu()
        choice = input("Choose an option: ")
        
        if choice == '1':
            print("\n--- Patient Management ---")
            print("1. Add Patient")
            print("2. View Patients")
            print("3. Search Patient")
            print("4. Update Patient")
            print("5. Delete Patient")
            patient_choice = input("Choose an option: ")
            if patient_choice == '1':
                add_patient()
            elif patient_choice == '2':
                view_patients()
            elif patient_choice == '3':
                search_patient()
            elif patient_choice == '4':
                update_patient()
            elif patient_choice == '5':
                delete_patient()

        elif choice == '2':
            print("\n--- Doctor Management ---")
            print("1. Add Doctor")
            print("2. View Doctors")
            doctor_choice = input("Choose an option: ")
            if doctor_choice == '1':
                add_doctor()
            elif doctor_choice == '2':
                view_doctors()

        elif choice == '3':
            print("\n--- Appointment Management ---")
            print("1. Schedule Appointment")
            print("2. View Appointments")
            appointment_choice = input("Choose an option: ")
            if appointment_choice == '1':
                schedule_appointment()
            elif appointment_choice == '2':
                view_appointments()

        elif choice == '4':
            print("\n--- Laboratory and Diagnostics ---")
            print("1. Add Lab Result")
            print("2. View Lab Results")
            lab_choice = input("Choose an option: ")
            if lab_choice == '1':
                add_lab_result()
            elif lab_choice == '2':
                view_lab_results()

        elif choice == '5':
            print("\n--- Inpatient/Outpatient Management ---")
            print("1. Admit Patient")
            print("2. View Inpatients")
            print("3. Discharge Patient")
            in_out_choice = input("Choose an option: ")
            if in_out_choice == '1':
                admit_patient()
            elif in_out_choice == '2':
                view_inpatients()
            elif in_out_choice == '3':
                discharge_patient()

        elif choice == '6':
            print("\n--- Medical Report ---")
            print("1. Create Medical Report")
            print("2. View Medical Reports")
            report_choice = input("Choose an option: ")
            if report_choice == '1':
                create_medical_report()
            elif report_choice == '2':
                view_medical_reports()

        elif choice == '7':
            print("\n--- Pharmacy Management ---")
            print("1. Add Medicine")
            print("2. View Pharmacy Stock")
            pharmacy_choice = input("Choose an option: ")
            if pharmacy_choice == '1':
                add_medicine()
            elif pharmacy_choice == '2':
                view_pharmacy_stock()

        elif choice == '8':
            print("\n--- Billing and Payment System ---")
            print("1. Generate Bill")
            print("2. View Bills")
            billing_choice = input("Choose an option: ")
            if billing_choice == '1':
                generate_bill()
            elif billing_choice == '2':
                view_bills()

        elif choice == '9':
            print("Exiting...")
            break
        else:
            print("Invalid choice, please try again.")
