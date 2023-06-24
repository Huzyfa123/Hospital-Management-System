#include <stdio.h>
#include <string.h>
#include "login.h"


int login()
{


    int authenticateUser(const char* username, const char* password)
    {
        FILE* file = fopen("users.txt", "r");
        if (file == NULL)
        {
            printf("Error opening file.\n");
            return 0;
        }

        char line[50];
        while (fgets(line, sizeof(line), file) != NULL)
        {
            char fileUsername[20];
            char filePassword[20];
            sscanf(line, "%s %s", fileUsername, filePassword);

            if (strcmp(fileUsername, username) == 0 && strcmp(filePassword, password) == 0)
            {
                fclose(file);
                return 1;
            }
        }

        fclose(file);
        return 0;
    }


    char username[20];
    char password[20];
    int loggedIn = 0;

    printf("\nHospital Management System\n");
    printf("------------LOGIN----------------\n");

    do
    {
        printf("Username: ");
        scanf("%s", username);

        printf("Password: ");
        scanf("%s", password);

        if (authenticateUser(username, password))
        {
            printf("\nLogin successful!\n");
            loggedIn = 1;
        }
        else
        {
            printf("\nInvalid credentials. Please try again.\n");
        }
    }
    while (!loggedIn);

    return 1;
}
