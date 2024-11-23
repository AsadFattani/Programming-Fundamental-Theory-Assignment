#include <stdio.h>
#include <string.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Employee {
    int employeeCode;
    char employeeName[100];
    struct Date dateOfJoining;
};

void assignValues(struct Employee *emp, int code, const char *name, int day, int month, int year) {
    emp->employeeCode = code;
    strcpy(emp->employeeName, name);
    emp->dateOfJoining.day = day;
    emp->dateOfJoining.month = month;
    emp->dateOfJoining.year = year;
}

void calculateTenure(struct Employee employees[], int size) {
    struct Date currentDate;
    printf("Enter current date (day month year): ");
    scanf("%d %d %d", &currentDate.day, &currentDate.month, &currentDate.year);

    int count = 0;
    for (int i = 0; i < size; i++) {
        int tenureYears = currentDate.year - employees[i].dateOfJoining.year;
        if (currentDate.month < employees[i].dateOfJoining.month || 
            (currentDate.month == employees[i].dateOfJoining.month && currentDate.day < employees[i].dateOfJoining.day)) {
            tenureYears--;
        }

        if (tenureYears > 3) {
            printf("Employee Code: %d\n", employees[i].employeeCode);
            printf("Employee Name: %s", employees[i].employeeName); // fgets includes newline
            printf("Date of Joining: %02d-%02d-%04d\n", employees[i].dateOfJoining.day, employees[i].dateOfJoining.month, employees[i].dateOfJoining.year);
            printf("Tenure: %d years\n\n", tenureYears);
            count++;
        }
    }
    printf("Total employees with tenure more than 3 years: %d\n", count);
}

int main() {
    const int n = 4;
    struct Employee employees[n];

    // testing values
    // assignValues(&employees[0], 101, "Alice\n", 15, 5, 2019);
    // assignValues(&employees[1], 102, "Bob shmichael\n", 20, 8, 2022);
    // assignValues(&employees[2], 103, "Charlie dsouza\n", 25, 12, 2011);
    // assignValues(&employees[3], 104, "David\n", 30, 1, 2024);

    for (int i = 0; i < n; i++) {
        int code, day, month, year;
        char name[100];
        printf("Enter details for employee %d\n", i + 1);
        do{
        printf("Employee Code: ");
        scanf("%d", &code);
        } while (code <= 0);
        printf("Employee Name: ");
        while (getchar() != '\n'); // clear the input buffer
        fgets(name, 100, stdin);
        name[strcspn(name, "\n")] = '\0'; // Remove newline character
        printf("Date of Joining (day month year): ");
        scanf("%d %d %d", &day, &month, &year);
        assignValues(&employees[i], code, name, day, month, year);
    }

    printf("\n");
    calculateTenure(employees, n);
    printf("\n");

    return 0;
}
