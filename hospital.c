#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hospital.h"

#define MAX_RECORDS 100
#define MAX_DOCTORS 100
#define DATA_SEPARATOR "|"


void addPatientRecord()
{
    PatientRecord record;

    printf("\n--- Add Patient Record ---\n");

    printf("Name: ");
    fflush(stdin);
    fgets(record.name, sizeof(record.name), stdin);

    printf("Age: ");
    scanf("%d", &record.age);

    printf("Gender: ");
    scanf("%s", record.gender);

    printf("Disease: ");
    fflush(stdin);
    fgets(record.disease, sizeof(record.disease), stdin);

    FILE* file = fopen("patient_records.txt", "a");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "%s|%d|%s|%s", record.name, record.age, record.gender, record.disease);

    fclose(file);

    printf("\nPatient record added successfully!\n\n");
}



void viewPatientRecords() {
    printf("\n--- Patient Records ---\n\n");

    FILE* file = fopen("patient_records.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    PatientRecord record;
    int count = 0;

    while (fscanf(file, "%[^|]|%d|%[^|]|%[^\n]\n", record.name, &record.age, record.gender, record.disease) == 4) {
        printf("Name: %s Age: %d, Gender: %s, Disease: %s\n", record.name, record.age,
               record.gender, record.disease);

        count++;
    }

    fclose(file);

    if (count == 0) {
        printf("No patient records found.\n");
    }

    printf("-----------------------\n\n");
}



void addDoctor()
{
    DoctorRecord doctor;

    printf("\n--- Add Doctor ---\n");

    printf("Name: ");
    fflush(stdin);
    fgets(doctor.name, sizeof(doctor.name), stdin);

    printf("Specialization: ");
    fflush(stdin);
    fgets(doctor.specialization, sizeof(doctor.specialization), stdin);

    FILE* file = fopen("doctors.txt", "a");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "%s|%s", doctor.name, doctor.specialization);

    fclose(file);

    printf("\nDoctor added successfully!\n\n");

}


void viewAllDoctors() {
    printf("\n--- Doctors List ---\n\n");

    FILE* file = fopen("doctors.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    DoctorRecord doctor;
    int count = 0;

    while (fscanf(file, "%[^|]|%[^\n]\n", doctor.name, doctor.specialization) == 2) {
        printf("Name: %s Specialization: %s\n", doctor.name, doctor.specialization);

        count++;
    }

    fclose(file);

    if (count == 0) {
        printf("No doctors found.\n");
    }

    printf("--------------------\n\n");
}
