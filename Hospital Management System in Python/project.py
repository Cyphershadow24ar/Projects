while (True):
    print("""
            ================================
            Welcome To CityHospital
            ================================
    """)
    # creating database connectivity
    import mysql.connector
    passwd = str(input("Enter the Password Please!!:"))

    mysql = mysql.connector.connect(
        host="localhost", user="root", passwd=passwd)
    mycursor = mysql.cursor()
    mycursor.execute("create database if not exists city_hospitals")
    mycursor.execute("use city_hospitals")
    # creating the tables we need
    mycursor.execute(
        "create table if not exists patient_detail(name varchar(30) primary key,sex varchar(15),age int(3),address varchar(50),contact varchar(15))")
    mycursor.execute("create table if not exists doctor_details(name varchar(30) primary key,specialisation varchar(40),age int(2),address varchar(30),contact varchar(15),fees int(10),monthly_salary int(10))")
    mycursor.execute(
        "create table if not exists nurse_details(name varchar(30) primary key,age int(2),address varchar(30),contact varchar(15),monthly_salary int(10))")
    mycursor.execute(
        "create table if not exists other_workers_details(name varchar(30) primary key,age int(2),address varchar(30),contact varchar(15),monthly_salary int(10))")

    # creating table for storing the username and password of the user
    mycursor.execute(
        "create table if not exists user_data(username varchar(30) primary key,password varchar(30) default'000')")

    while (True):
        print("""
                        1. Sign In
                        2. Registration
                                                            """)

        r = int(input("enter your choice:"))
        if r == 2:
            print("""

                =======================================
                !!!!!!!!!!Register Yourself!!!!!!!!
                =======================================
                                                    """)
            u = input("Input your username!!:")
            p = input("Input the password (Password must be strong!!!:")
            mycursor.execute(
                "insert into user_data values('" + u + "','" + p + "')")
            mysql.commit()

            print("""
                ============================================
                !!Well Done!!Registration Done Successfully!!
                ============================================
                                                    """)
            x = input("enter any key to continue:")
        # IF USER WANTS TO LOGIN
        elif r == 1:
            print("""
                    ==================================
                    !!!!!!!!  {{Sign In}}  !!!!!!!!!!
                    ==================================
                                                        """)
            un = input("Enter Username!!:")
            ps = input("Enter Password!!:")

            mycursor.execute(
                "select password from user_data where username='" + un + "'")
            row = mycursor.fetchall()
            for i in row:
                a = list(i)
                if a[0] == str(ps):
                    while (True):
                        print("""
                                1.Administration
                                2.Patient(Details)
                                3.Sign Out

                                                            """)

                        a = int(input("ENTER YOUR CHOICE:"))
                        if a == 1:
                            print("""
                                    1. Display the details
                                    2. Add a new member
                                    3. Delete a member
                                    4. Make an exit
                                                            """)
                            b = int(input("Enter your Choice:"))
                            # details
                            if b == 1:
                                print("""
                                        1. Doctors Details
                                        2. Nurse Details
                                        3. Others
                                                        """)

                                c = int(input("Enter your Choice:"))
                                if c == 1:
                                    mycursor.execute(
                                        "select * from doctor_details")
                                    row = mycursor.fetchall()
                                    for i in row:
                                        b = 0
                                        v = list(i)
                                        k = ["NAME", "SPECIALISATION", "AGE", "ADDRESS", "CONTACT", "FEES",
                                            "MONTHLY_SALARY"]
                                        d = dict(zip(k, v))
                                        print(d)
                                # displays nurses details
                                elif c == 2:
                                    mycursor.execute(
                                        "select * from nurse_details")
                                    row = mycursor.fetchall()
                                    for i in row:
                                        v = list(i)
                                        k = ["NAME", "SPECIALISATION", "AGE",
                                            "ADDRESS", "CONTACT", "MONTHLY_SALARY"]
                                        d = dict(zip(k, v))
                                        print(d)
                                # displays worker details
                                elif c == 3:
                                    mycursor.execute(
                                        "select * from other_workers_details")
                                    row = mycursor.fetchall()
                                    for i in row:
                                        v = list(i)
                                        k = ["NAME", "SPECIALISATION", "AGE",
                                            "ADDRESS", "CONTACT""MONTHLY_SALARY"]
                                        d = dict(zip(k, v))
                                        print(d)
                            # IF USER WANTS TO ENTER DETAILS
                            elif b == 2:
                                print("""

                                        1. Doctor Details
                                        2. Nurse Details
                                        3. Others
                                                                                    """)
                                c = int(input("ENTER YOUR CHOICE:"))
                                # enter doctor details
                                if c == 1:
                                    # ASKING THE DETAILS
                                    name = input("Enter the doctor's name")
                                    spe = input("Enter the specilization:")
                                    age = input("Enter the age:")
                                    add = input("Enter the address:")
                                    cont = input("Enter Contact Details:")
                                    fees = input("Enter the fees:")
                                    ms = input("Enter Monthly Salary:")
                                    # Inserting values in doctors details
                                    mycursor.execute("insert into doctor_details values('" + name + "','" + spe +
                                                    "','" + age + "','" + add + "','" + cont + "','" + fees + "','" + ms + "')")
                                    mysql.commit()
                                    print("SUCCESSFULLY ADDED")
                                # for nurse details
                                elif c == 2:
                                    # ASKING THE DETAILS
                                    name = input("Enter Nurse name:")
                                    age = input("Enter age:")
                                    add = input("Enter address:")
                                    cont = input("Enter Contact No:")
                                    ms = int(input("Enter Monthly Salary"))
                                    # INSERTING VALUES ENTERED TO THE TABLE
                                    mycursor.execute("insert into nurse_details values('" + name + "','" + age + "','" + add + "','" + cont + "','" + str(
                                        ms) + "')")
                                    mysql.commit()
                                    print("SUCCESSFULLY ADDED")
                                # for entering workers details
                                elif c == 3:
                                    # ASKING THE DETAILS
                                    name = input("Enter worker name:")
                                    age = input("Enter age:")
                                    add = input("Enter address:")
                                    cont = input("Enter Contact No.:")
                                    ms = input("Enter Monthly Salary:")
                                    # INSERTING VALUES ENTERED TO THE TABLE
                                    mycursor.execute("insert into other_workers_details values('" +
                                                    name + "','" + age + "','" + add + "','" + cont + "','" + ms + "')")
                                    mysql.commit()
                                    print("SUCCESSFULLY ADDED")
                            # to delete data
                            elif b == 3:
                                print("""
                                        1. Doctor Details
                                        2. Nurse Details
                                        3. Others
                                                                                    """)
                                c = int(input("Enter your Choice:"))
                                # deleting doctor's details
                                if c == 1:
                                    name = input("Enter Doctor's Name:")
                                    mycursor.execute(
                                        "select * from doctor_details where name='" + name + "'")
                                    row = mycursor.fetchall()
                                    print(row)
                                    p = input(
                                        "you really wanna delete this data? (y/n):")
                                    if p == "y":
                                        mycursor.execute(
                                            "delete from doctor_details where name='" + name + "'")
                                        mysql.commit()
                                        print("SUCCESSFULLY DELETED!!")
                                    else:
                                        print("NOT DELETED")

                                # deleting nurse details
                                elif c == 2:
                                    name = input("Enter Nurse Name:")
                                    mycursor.execute(
                                        "select * from nurse_details where name='" + name + "'")
                                    row = mycursor.fetchall()
                                    print(row)
                                    p = input(
                                        "you really wanna delete this data? (y/n):")
                                    if p == "y":
                                        mycursor.execute(
                                            "delete from nurse_details where name='" + name + "'")
                                        mysql.commit()
                                        print("SUCCESSFULLY DELETED!!")
                                    else:
                                        print("NOT DELETED")
                                # deleting other_workers details
                                elif c == 3:
                                    name = input("Enter the worker Name")
                                    mycursor.execute(
                                        "select * from workers_details where name='" + name + "'")
                                    row = mycursor.fetchall()
                                    print(row)
                                    p = input(
                                        "you really wanna delete this data? (y/n):")
                                    if p == "y":
                                        mycursor.execute(
                                            "delete from other_workers_details where name='" + name + "'")
                                        mysql.commit()
                                        print("SUCCESSFULLY DELETED!!")
                                    else:
                                        print("NOT DELETED")
                            elif b == 4:
                                break

                        # entering the patient details table
                        elif a == 2:

                            print("""
                                        1. Show Patients Info
                                        2. Add New Patient
                                        3. Discharge Summary
                                        4. Exit
                                                            """)
                            b = int(input("Enter your Choice:"))
                            # showing the existing details
                            # if user wants to see the details of PATIENT
                            if b == 1:
                                mycursor.execute(
                                    "select * from patient_detail")
                                row = mycursor.fetchall()
                                for i in row:
                                    b = 0
                                    v = list(i)
                                    k = ["NAME", "SEX", "AGE",
                                        "ADDRESS", "CONTACT"]
                                    d = dict(zip(k, v))
                                    print(d)

                            # adding new patient
                            elif b == 2:
                                name = input("Enter your name ")
                                sex = input("Enter the gender: ")
                                age = input("Enter age: ")
                                address = input("Enter address: ")
                                contact = input("Contact Details: ")
                                mycursor.execute("insert into patient_detail values('" + name + "','" + sex + "','" +
                                                age + "','" + address + "','" + contact + "')")
                                mysql.commit()
                                mycursor.execute(
                                    "select * from patient_detail")
                                for i in mycursor:
                                    v = list(i)
                                    k = ['NAME', 'SEX', 'AGE',
                                        'ADDRESS', 'CONTACT']
                                    print(dict(zip(k, v)))
                                    print("""
                                        ====================================
                                        !!!!!!!Registered Successfully!!!!!!
                                        ====================================
                                                        """)
                            # dischare process
                            elif b == 3:
                                name = input("Enter the Patient Name:")
                                mycursor.execute(
                                    "select * from patient_detail where name='" + name + "'")
                                row = mycursor.fetchall()
                                print(row)
                                bill = input(
                                    "Has he paid all the bills? (y/n):")
                                if bill == "y":
                                    mycursor.execute(
                                        "delete from patient_detail where name='" + name + "'")
                                    mysql.commit()
                            # if user wants to exit
                            elif b == 4:
                                break
                        # SIGN OUT

                        elif a == 3:
                            break

                # IF THE USERNAME AND PASSWORD IS NOT IN THE DATABASE
                else:
                    break
