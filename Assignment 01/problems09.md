
<!-- # -->


## IPO




## Flowchart

<img src="problem03.jpeg">

## Pseudocode

      START
          PRINT "Enter the date of birth (DD MM YYYY):"
          INPUT dobDay, dobMonth, dobYear
      
          // Validating month of date of birth
          WHILE dobMonth < 1 OR dobMonth > 12 DO
              PRINT "Invalid month in DOB. Please enter a month between 1 and 12."
              INPUT dobMonth
          END WHILE
      
          // Validating day of date of birth
          IF dobMonth = 2 THEN
              WHILE dobDay < 1 OR dobDay > 28 DO
                  PRINT "Invalid day for February in DOB. Please enter a day between 1 and 28."
                  INPUT dobDay
              END WHILE
          ELSE IF dobMonth = 4 OR dobMonth = 6 OR dobMonth = 9 OR dobMonth = 11 THEN
              WHILE dobDay < 1 OR dobDay > 30 DO
                  PRINT "Invalid day for the given month in DOB. Please enter a day between 1 and 30."
                  INPUT dobDay
              END WHILE
          ELSE
              WHILE dobDay < 1 OR dobDay > 31 DO
                  PRINT "Invalid day for the given month in DOB. Please enter a day between 1 and 31."
                  INPUT dobDay
              END WHILE
          END IF
      
          PRINT "Enter the current date (DD MM YYYY):"
          INPUT currDay, currMonth, currYear
      
          // Validating month of current date
          WHILE currMonth < 1 OR currMonth > 12 DO
              PRINT "Invalid month in current date. Please enter a month between 1 and 12."
              INPUT currMonth
          END WHILE
      
          // Validate day of current date
          IF currMonth = 2 THEN
              WHILE currDay < 1 OR currDay > 28 DO
                  PRINT "Invalid day for February in current date. Please enter a day between 1 and 28."
                  INPUT currDay
              END WHILE
          ELSE IF currMonth = 4 OR currMonth = 6 OR currMonth = 9 OR currMonth = 11 THEN
              WHILE currDay < 1 OR currDay > 30 DO
                  PRINT "Invalid day for the given month in current date. Please enter a day between 1 and 30."
                  INPUT currDay
              END WHILE
          ELSE
              WHILE currDay < 1 OR currDay > 31 DO
                  PRINT "Invalid day for the given month in current date. Please enter a day between 1 and 31."
                  INPUT currDay
              END WHILE
          END IF
      
          // Initialize variables for age calculation
          years = currYear - dobYear
          months = currMonth - dobMonth
          days = currDay - dobDay
      
          // Adjust days if necessary
          WHILE days < 0 DO
              days = days + 30 // Assuming 30 days in a month
              months = months - 1
          END WHILE
      
          // Adjust months if necessary
          WHILE months < 0 DO
              months = months + 12
              years = years - 1
          END WHILE
      
          // Output the calculated age
          PRINT "Exact age is: ", years, " years, ", months, " months, and ", days, " days."
      END

      
      
        
