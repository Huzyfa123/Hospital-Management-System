#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "splash.h"

void delay(unsigned int seconds) {
    unsigned int milli_seconds = 1000 * seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

void displaySplashScreen() {
    FILE *file = fopen("splash.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Read and display the splash screen ASCII art
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);

    delay(2);  // Delay for 3 seconds

    printf("\n WELCOME TO MyHOSPITAL\n");
}
