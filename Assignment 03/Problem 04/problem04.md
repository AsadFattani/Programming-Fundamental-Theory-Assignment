## A system to track employees perfomance using dynamic memory allocation

### Output cases
<img src = "../images/problem04(1).png" width = "60%" height = "auto">
<img src = "../images/problem04(2).png" width = "60%" height = "auto">

### Approach
1. Define the `Employee` structure with fields for ratings and totalScore.
2. Implement the `inputEmployees` function to input ratings for each employee and calculate their total score.
3. Implement the `displayPerformance` function to display the ratings of each employee.
4. Implement the `findEmployeeOfTheYear` function to find the employee with the highest total score.
5. Implement the `findHighestRatedPeriod` function to find the period with the highest total ratings.
6. Implement the `findWorstPerformingEmployee` function to find the employee with the lowest total score.
7. Dynamically allocate memory for the ratings and ensure proper memory management by freeing allocated memory after use.

### Conclusion
The system successfully tracks employee performance ratings over multiple evaluation periods, calculates the top-performing employee, the best-rated evaluation period, and the worst-performing employee. Proper memory management is ensured by dynamically allocating and freeing memory for the ratings.
