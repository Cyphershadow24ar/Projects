#include<stdio.h>
#include<string.h>

int main()
{
    char from[30],to[30],date[30],holder[20],holderlastname;
    int cardnumber[20],UpiID[20];
    char ch,meals;
    int amount,fare,flight,seat,first,foodtype,da,m,y=2023,n,option,aa,bb,cc,x,z,HB,CB;  //HB:hand baggage and CB: check in baggage

    struct passenger{
        char firstname[25];
        char lastname[25];
        char passportnumber[20];
        int phonenumber;
        char email[50];
    };
    struct passenger P;
    printf("                                    AIRLINE RESERVATION SYSTEM\n\n");
    printf("                                     Welcome To CGU Airline\n\n");
    printf("                                 Start Planning Your Perfect Trip.\n\n");
    printf(" Why Choose CGU Airline\n");
    printf(" When you BOOK FLIGHT with CGU Airline, you fly \n on-time, ever time, daily, and non-stop.\n Get the lowest booking and cancellation \n fee, exclusive offers, add-ons and in-flight \n services that make your journey hasslefree. \n\n\n\n");
    printf("                                  Home-----------------Flight Booking\n");
    printf(" ENTER THE DATA-\n");
    printf(" From: ");
    scanf("%s",from);
    printf(" To: ");
    scanf("%s",to);
    printf(" ------Date(DD): ");
    scanf("%d",&da);
    printf(" ------Month(MM): ");
    scanf("%d",&m);
    printf("Travel Dates: ");
    printf(" %d / %d / %d \n", da, m, y);
    printf("                                          SEARCHING....\n\n");
    printf("                                    FASTEN YOUR SEATBELT\n\n");
    if((da>=22 && da<=25)&&(m==11 && m==9))
    {
    printf("NO SEATS AVAILABLE. \n We are extremely sorry for the inconvenience caused. \n Please change the search criteria.\n");
    }
    else{
    printf("                                 15:25----------05h 20m----------20:40\n\n");
    printf("                              -Select a fare and continue to make booking.\n");
printf("---------------------------------------------------------\n");
    printf(" 1. Rs15,150 + Hand Baggage(6kg) + Checkin Baggage    (15kg) \n\n");
    printf(" 2. Rs21,960 + Hand Baggage(8kg) + Checkin Baggage(20kg) \n\n");
    printf("---------------------------------------------------------\n");
    printf("CHOOSE YOUR OPTION (1-2): ");
    scanf("%d",&option);
    if(option != 1 && option !=2){
        printf("#INVALID OPTION#\n\n");
        printf("CHOOSE YOUR OPTION (1-2): ");
    scanf("%d",&option);
    }
    switch(option){
    case 1 : fare=15150;
    printf("                                 FARE:Rs15,150 and BAGGAGE:Hand Baggage(6kg) + Checkin Baggage(15kg)\n\n");
        printf("                                     --CONTACT DETAILS--\n\n");
        printf("Enter Mobile No.- ");
        scanf("%d",&P.phonenumber);
        printf("Enter Email ID- ");
        scanf("%s",P.email);
        printf("\n\n");
        printf("Step 1 of 3\n");
        printf("ENTER PASSENGER DETAILS\n\n");
        printf("Enter name as per Aadhaar card/ Passport or any Govt. ID\n\n");
        printf("First Name( & Middle Name, if any) -  ");
        scanf("%s",P.firstname);
        printf("Last Name - ");
        scanf("%s",P.lastname);
        printf("\n");
printf("                             Are You a first time Traveller?         --YES    --NO\n");
printf("                             *Press 1 for 'YES' and 2 for 'NO' - ");
scanf("%d",&first);
printf("\n");
if(first != 1 && first !=2){
    printf("#INVALID OPTION# \n\n");
      printf("                             *Press 1 for 'YES' and 2 for 'NO' - ");
      scanf("%d",&first);
        }
if(first==1){
    printf("We are glad that you chose CGU Airline for your first fly.\nWe will take you there.\nTo carry you higher.\n\n");
}else{
    printf( "We are glad that you chose CGU Airline for your fly.\nWe will take you there.\nTo carry you higher.\n\n");
}
printf("Choose 1 for First Class and 2 for Economic Class: ");
scanf("%d",&flight);
if(flight == 1){
   printf("FIRST CLASS\n");
   printf("Seats Available - 1,2,3,4,5,6\n");
   printf("Choose Seat: ");
   scanf("%d",&seat);
   printf("-------------------------\n");
   printf("Class- First Class\n");
   printf("Seat No.- %d\n",seat);
   printf("-------------------------\n");
}
else if(flight==2){
    printf("ECONOMIC CLASS\n");
   printf("Seats Available - 1,2,3,4,5,6\n");
   printf("Choose Seat: ");
   scanf("%d",&seat);
   printf("-------------------------\n");
   printf("Class- Economic Class\n");
   printf("Seat No.- %d\n",seat);
   printf("-------------------------\n");
}

printf("----------------------------------------------------------------------------------------------------------------------------\n\n");
printf("\n");
printf(" Step 2 of 3\n");
printf(" AVAILABLE CHOICES:\n");
printf("       a. 6E Eats \n Pre-book your favourite meal from our exclusive menu.\n\n");
printf("       b. Delayed and Lost Baggage Protection \n Get compensated for delayed or lost check-in baggage. Powered by Blue Ribbon Bags.\n\n");
printf("       c. Excess Baggage \n Save up to 20percent when you pre-book excess baggage.\n\n");
printf("\n");
printf("press 1 for 6E EATS:");
scanf("%d",&aa);

printf("                               6E EATS(Snack and Beverage *)\n\n");
printf("                Now, add up to 2 meals per passenger per sector, with Saver Fare.\n");
printf("                                    -Non Veg           -Veg\n");
printf("                          Press '1' for Non Veg and '2' for Veg meal- ");
scanf("%d",&meals);
if(meals==1){
    printf("                    ---------------------------------------------------\n");
    printf("                        *Non Veg meal has been successfully added.");
    printf("                    ---------------------------------------------------\n");
}else{
    printf("                    ---------------------------------------------------\n");
    printf("                        *Veg meal has been successfully added.");
    printf("                    ---------------------------------------------------\n");
}
printf("\n");
printf("\n");
printf("press 2 for DELAYED AND LOST BAGGAGE PROTECTION:");
scanf("%d",&bb);
printf("                             DELAYED AND LOST BAGGAGE PROTECTION\n\n");
printf("                    -------------------------------------------------------------\n");
printf("                      It tracks and expedites the return of the delayed baggage.\n");
printf("                             This product is powered by blue ribbon.");
printf("                    -------------------------------------------------------------\n");
printf("\n");
printf("\n");
printf("Press 3 for EXCESS BAGGAGE: ");
scanf("%d",&cc);
printf("                                **EXCESS BAGGAGE\n\n");
printf("Enter Hand Baggage Weight: ");
scanf("%dkg",&HB);
printf("Enter Check in Baggage Weight: ");
scanf("%dkg",&CB);
printf("\n");
printf("--------------------------------\n");
printf(">Pay Rs2000 for each extra kg!!\n\n");
printf("--------------------------------\n");
printf("\n");
printf(" Step 3 of 3\n");
printf("                                     PAYMENT\n\n");
printf("Payment Method:\n");
printf("1.Credit / Debit Card\n");
printf("2.UPI\n");
printf("choose(1-2): ");
scanf("%d",&z);
if(z==1){
   printf("Name on card: \nFirst name- ");
    scanf("%s",&holder);
    printf("Last name- ");
    scanf("%s",&holderlastname);
    printf("Card Number: ");
    scanf("%d",cardnumber);
    printf("\n\n");
    printf("I have read and understood all of the fare restrictions.I agree to the Terms and Conditions.\n");
    printf("TOTAL AMOUNT DUE: Rs%d",fare);
    printf("                    >Pay Now\n");
    printf("Enter your amount-Rs ");
    scanf("%d",&amount);
    printf("\n");
    printf("\n");
    printf("  Congratulations %s %s ,Your seat has been confirmed.\n",P.firstname,P.lastname);
    printf("Other informations will be provided to you through mail.\n");
     printf("                                                   :)");
}else{
    
    printf("UPI ID: ");
    scanf("%d",UpiID);
    printf("\n\n");
    printf("I have read and understood all of the fare restrictions.\nI agree to the Terms and Conditions.\n\n");
    printf("TOTAL AMOUNT DUE: Rs%d",fare);
    printf("                    Pay Now\n\n");
    printf("Enter your amount-Rs ");
    scanf("%d",&amount);
    printf("\n");
    printf("\n");
    printf("  Congratulations %s %s ,Your seat has been confirmed.\n",P.firstname,P.lastname);
    printf("Other informations will be provided to you through mail.\n");
    printf("                                                   :)");
}
break;
case 2 : fare=21960;
    printf("                             Rs21,960 + Hand Baggage(8kg) + Checkin Baggage(20kg)  \n\n");
        printf("                                     --CONTACT DETAILS--\n\n");
        printf("Enter Mobile No.- ");
        scanf("%d",&P.phonenumber);
        printf("Enter Email ID- ");
        scanf("%s",P.email);
        printf("\n\n");
        printf("Step 1 of 3\n");
        printf("ENTER PASSENGER DETAILS\n\n");
        printf("Enter name as per Aadhaar card/ Passport or any Govt. ID\n\n");
        printf("First Name( & Middle Name, if any) -  ");
        scanf("%s",P.firstname);
        printf("Last Name - ");
        scanf("%s",P.lastname);
        printf("\n");
printf("                             Are You a first time Traveller?         --YES    --NO\n");
printf("                             *Press 1 for 'YES' and 2 for 'NO' - ");
scanf("%d",&first);
printf("\n");
if(first != 1 && first !=2){
        printf("#INVALID OPTION# \n\n");
      printf("                             *Press 1 for 'YES' and 2 for 'NO' - ");
      scanf("%d",&first);
        }
if(first==1){
    printf("We are glad that you chose D4GH Airline for your first fly.\nWe will take you there.\nTo carry you higher.\n\n");
}else{
    printf( "We are glad that you chose D4GH Airline for your fly.\nWe will take you there.\nTo carry you higher.\n\n");
}
printf("Choose 1 for First Class and 2 for Economic Class: ");
scanf("%d",&flight);
if(flight == 1){
   printf("FIRST CLASS\n");
   printf("Seats Available - 1,2,3,4,5\n");
   printf("Choose Seat: ");
   scanf("%d",&seat);
   printf("-------------------------\n");
   printf("Class- First Class\n");
   printf("Seat No.- %d\n",seat);
   printf("-------------------------\n");
}
else if(flight==2){
    printf("ECONOMIC CLASS\n");
   printf("Seats Available - 1,2,3,4,5\n");
   printf("Choose Seat: ");
   scanf("%d",&seat);
   printf("-------------------------\n");
   printf("Class- Economic Class\n");
   printf("Seat No.- %d\n",seat);
   printf("-------------------------\n");
}

printf("----------------------------------------------------------------------------------------------------------------------------\n\n");
printf("\n");
printf(" Step 2 of 3\n");
printf(" AVAILABLE CHOICES:\n");
printf("       a. 6E Eats \n Pre-book your favourite meal from our exclusive menu.\n\n");
printf("       b. Delayed and Lost Baggage Protection \n Get compensated for delayed or lost check-in baggage. Powered by Blue Ribbon Bags.\n\n");
printf("       c. Excess Baggage \n Save up to 20percent when you pre-book excess baggage.\n\n");
printf("\n");
printf("press 1 for 6E EATS:");
scanf("%d",&aa);

printf("                               6E EATS(Snack and Beverage *)\n\n");
printf("                Now, add up to 2 meals per passenger per sector, with Saver Fare.\n");
printf("                                    -Non Veg           -Veg\n");
printf("                          Press '1' for Non Veg and '2' for Veg meal- ");
scanf("%d",&meals);
if(meals==1){
    printf("                    ---------------------------------------------------\n");
    printf("                        *Non Veg meal has been successfully added.\n");
    printf("                    ---------------------------------------------------"); }
    else{
    printf("                    ---------------------------------------------------\n");
    printf("                        *Veg meal has been successfully added.\n");
    printf("                    ---------------------------------------------------\n");
}
printf("\n");
printf("\n");
printf("press 2 for DELAYED AND LOST BAGGAGE PROTECTION:");
scanf("%d",&bb);
printf("                             DELAYED AND LOST BAGGAGE PROTECTION\n\n");
printf("                    -------------------------------------------------------------\n");
printf("                      It tracks and expedites the return of the delayed baggage.\n");
printf("                              This product is powered by Blue Ribbon.\n");
printf("                    -------------------------------------------------------------\n");
printf("\n");
printf("\n");
printf("Press 3 for EXCESS BAGGAGE: ");
scanf("%d",&cc);
printf("                                **EXCESS BAGGAGE\n\n");
printf("Enter Hand Baggage Weight: ");
scanf("%dkg",&HB);
printf("Enter Check in Baggage Weight: ");
scanf("%dkg",&CB);
printf("\n");
printf("--------------------------------\n");
printf(">Pay Rs2000 for each extra kg!!\n\n");
printf("--------------------------------\n");
printf("\n");
printf(" Step 3 of 3\n");
printf("                                     PAYMENT\n\n");
printf("Payment Method:\n");
printf("1.Credit / Debit Card\n");
printf("2.UPI\n");
printf("choose(1-2): ");
scanf("%d",&z);
if(z==1){
    printf("Name on card: \nFirst name- ");
    scanf("%s",&holder);
    printf("Last name- ");
    scanf("%s",&holderlastname);
    printf("Card Number: ");
    scanf("%d",cardnumber);
    printf("\n\n");
    printf("I have read and understood all of the fare restrictions.\nI agree to the Terms and Conditions.\n");
    printf("TOTAL AMOUNT DUE: Rs%d",fare);
    printf("                    >Pay Now\n");
    printf("Enter your amount-Rs ");
    scanf("%d",&amount);
    printf("\n");
    printf("_\n");
    printf("  Congratulations %s %s ,Your seat has been confirmed.\n",P.firstname,P.lastname);
    printf("Other informations will be provided to you through mail.\n");
    printf("                                                   :)");
}else{
    printf("UPI ID: ");
    scanf("%d",UpiID);
    printf("\n\n");
    printf("I have read and understood all of the fare restrictions.I agree to the Terms and Conditions.\n");
    printf("TOTAL AMOUNT DUE: Rs%d",fare);
    printf("                    Pay Now\n\n");
    printf("Enter your amount-Rs ");
    scanf("%d",&amount);
    printf("\n\n");
    printf(" \n");
    printf("_\n");
    printf("  Congratulations %s %s ,Your seat has been confirmed.\n",P.firstname,P.lastname);
    printf("Other informations will be provided to you through mail.\n");
    printf("                                                   :)");
}


    }
    
    }

    
}