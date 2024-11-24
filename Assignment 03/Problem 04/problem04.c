#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int* ratings;
    int totalScore;
} Employee;

void inputEmployees(Employee* employees, int numEmployees, int numPeriods){
    int i, j;
    for (i = 0; i < numEmployees; i++){
        employees[i].ratings = (int*)malloc(numPeriods * sizeof(int));
        employees[i].totalScore = 0;
        for (j = 0; j < numPeriods; j++){
            do{
                printf("Enter rating for employee %d for period %d: ", i + 1, j + 1);
                scanf("%d", &employees[i].ratings[j]);
            } while (employees[i].ratings[j] < 1 || employees[i].ratings[j] > 10);
            employees[i].totalScore += employees[i].ratings[j];
        }
    }
}

void displayPerformance(Employee* employees, int numEmployees, int numPeriods){
    int i, j;
    for (i = 0; i < numEmployees; i++){
        printf("Employee %d: ", i + 1);
        for (j = 0; j < numPeriods; j++){
            printf("%d ", employees[i].ratings[j]);
        }
        printf("\n");
    }
}

int findEmployeeOfTheYear(Employee* employees, int numEmployees, int numPeriods){
    int i, max_score = 0, employee = -1;
    for (i = 0; i < numEmployees; i++){
        if (employees[i].totalScore > max_score){
            max_score = employees[i].totalScore;
            employee = i;
        }
    }
    return employee;
}

int findHighestRatedPeriod(Employee* employees, int numEmployees, int numPeriods){
    int i, j, sum, max_sum = 0, period = -1;
    for (j = 0; j < numPeriods; j++){
        sum = 0;
        for (i = 0; i < numEmployees; i++){
            sum += employees[i].ratings[j];
        }
        if (sum > max_sum){
            max_sum = sum;
            period = j;
        }
    }
    return period;
}

int findWorstPerformingEmployee(Employee* employees, int numEmployees, int numPeriods){
    int i, min_score = 1000, employee = -1;
    for (i = 0; i < numEmployees; i++){
        if (employees[i].totalScore < min_score){
            min_score = employees[i].totalScore;
            employee = i;
        }
    }
    return employee;
}

int main(){
    int numEmployees, numPeriods, i;
    Employee* employees;

    printf("Enter number of employees: ");
    scanf("%d", &numEmployees);
    printf("Enter number of periods: ");
    scanf("%d", &numPeriods);
    
    employees = (Employee*)malloc(numEmployees * sizeof(Employee));

    inputEmployees(employees, numEmployees, numPeriods);
    displayPerformance(employees, numEmployees, numPeriods);

    printf("Employee of the year: %d\n", findEmployeeOfTheYear(employees, numEmployees, numPeriods) + 1);
    printf("Highest rated period: %d\n", findHighestRatedPeriod(employees, numEmployees, numPeriods) + 1);
    printf("Worst performing employee: %d\n", findWorstPerformingEmployee(employees, numEmployees, numPeriods) + 1);

    for (i = 0; i < numEmployees; i++){
        free(employees[i].ratings);
    }
    free(employees);
    return 0;
}



