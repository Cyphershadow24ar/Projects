#include <stdio.h>
#include <stdbool.h>

#define MAX_CARS 10

// Function prototypes
void displayMenu();
void displayAvailableCars();
void rentCar();
void returnCar();
void displayRentalStatus();

// Global arrays
char carNames[MAX_CARS][50];
float carPrices[MAX_CARS];
bool carRented[MAX_CARS];

int main()
{
    // Initialize car data
    for (int i = 0; i < MAX_CARS; i++)
    {
        sprintf(carNames[i], "Car%d", i + 1);
        carPrices[i] = 700.0 + i * 50.0;
        carRented[i] = false;
    }

    int choice;
    do
    {
        displayMenu();

        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            displayAvailableCars();
            break;

        case 2:
            rentCar();
            break;

        case 3:
            returnCar();
            break;

        case 4:
            displayRentalStatus();
            break;

        case 5:
            printf("\n================================\n");
            printf("                                   \n");
            printf("Thank you for using RENT A CAR!\n");
            printf("Safe drive, save life");
            printf("                                    \n");
            printf("\n================================\n");
            break;
        default:
            printf("\n================================\n");
            printf("                                   \n");
            printf("\nInvalid choice. Please try again.\n");
            printf("                                   \n");
            printf("\n================================\n");
        }
    } while(choice != 5);

    return 0;
}
//Display Menu.
void displayMenu(){
    printf("\n=================== Car Rental System Menu =======================\n");
    printf("==                                                              ==\n");
    printf("==            Hello and Welcome to RENT A CAR                   ==\n");
    printf("==             Thank you for choosing us                        ==\n");
    printf("==                                                              ==\n");
    printf("==            1. Display Available Cars                         ==\n");
    printf("==            2. Rent a Car                                     ==\n");
    printf("==            3. Return a Car                                   ==\n");
    printf("==            4. Display Rental Status                          ==\n");
    printf("==            5. Exit                                           ==\n");
    printf("==================================================================\n");

}

//Display Available Cars.

void displayAvailableCars()
{
    printf("\n========== Available Cars ==========\n");
    for(int i=0; i<MAX_CARS; i++)
    {
        if(!carRented[i]){
            printf("%d. %s - Rs.%.2f per day\n", i+1, carNames[i], carPrices[i]);
        }
    }
    printf("=====================================\n");
}

//To Rent A Car.

void rentCar()
{
    int carNumber;
    printf("===============================================\n");
    printf("\nEnter the number of the car you want to rent: ");
    scanf("%d", &carNumber);

    if(carNumber >= 1 && carNumber <= MAX_CARS)
    {
        if(!carRented[carNumber - 1]){
            carRented[carNumber - 1] = true;
            int day;
            printf("\nEnter number of days: ");
            scanf("%d", &day);
            int bill=day*carPrices[carNumber -1];
            printf("\nPlease pay Rs.%d and enter 1 after payment: ", bill);
            int flag;
            scanf("%d",&flag);
            if (flag == 1)
               printf("\nYou have successful rented the Car. %s.\n", carNames[carNumber - 1]);
            else
               printf("\nPayment unsuccesful please try renting the Car Again.\n.");
            
        } else{
            printf("\nSorry, %s is already rented. Please choose another Car.\n", carNames[carNumber - 1]);
        }
    }else{
        printf("\nInvalid Car Number. Please try again.\n");
    }
}

// To Return A Car.

void returnCar()
{
  int carNumber;
  printf("\nEnter the number of the car you want to return: ");
  scanf("%d", &carNumber); 

  if(carNumber >= 1 && carNumber <= MAX_CARS)
  {
     if(carRented[carNumber - 1]){
        carRented[carNumber - 1] = false;
        printf("\nYou have Successfully Returned the Car. %s.\n", carNames[carNumber - 1]);

     } else {
        printf("\nThis Car is not currently rented. Please check the Car Number and try again.\n");
     }
  } else {
    printf("\nInvalid car number. Please try again.\n");
  }
}

// To Display Rental Status

void displayRentalStatus(){
    printf("\n===== Rental Status =====\n");
    for(int i = 0; i < MAX_CARS; i++)
    {
        printf("%d. %s - %s\n", i + 1, carNames[i], carRented[i] ? "Rented" : "Available");
    }
}