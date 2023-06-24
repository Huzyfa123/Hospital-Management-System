/// Name : Md. Huzyfa
/// Id : 2311893642
/// Sec : 05
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "login.h"
#include "splash.h"
#include "hospital.h"


// NAME:: MD HUZYFA
// ID:: 2311893642


void handleChoice(int choice);

void handleChoice(int choice)
{
    switch (choice)
    {
    case 1:
        // Add Patient Record logic

        addPatientRecord();
        break;
    case 2:
        // View Patient Records logic
        viewPatientRecords();
        break;
    case 3:
        // Add Doctor logic
        addDoctor();
        break;
    case 4:
        // View All Doctors logic
        viewAllDoctors();
        break;
    case 0:
        printf("Exiting the program.\n");
        break;
    default:
        printf("Invalid choice. Please try again.\n");
        break;
    }
}


int main(void)
{
    displaySplashScreen();


    if (!login())
    {
        printf("\n PLEASE LOGIN FIRST \n");
        return 0;
    }

    int choice;
    do
    {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        handleChoice(choice);

    }
    while (choice != 0);


    return 0;
}
