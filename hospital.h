#ifndef HOSPITAL_H
#define HOSPITAL_H

// Structure to hold patient records
typedef struct {
    char name[50];
    int age;
    char gender[10];
    char disease[100];
} PatientRecord;

// Structure to hold doctor records
typedef struct {
    char name[50];
    char specialization[50];
} DoctorRecord;

// Function declarations
int login();
void displayMenu();
void addPatientRecord();
void viewPatientRecords();
void addDoctor();
void viewAllDoctors();

#endif  // HOSPITAL_H
