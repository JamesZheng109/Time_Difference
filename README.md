# Time_Difference Program
Program that displays the difference between 2 dates (mm/dd/yyyy).
# Structs Date
Struct to hold certain info either for storing or for making it easier to implement certain functions.
- int month: Stores numeric representation of a date's month
- int day: Stores numeric representation of a date's day
- int year: Stores numeric representation of a date's year
- int days_in_month: Stores how many days exists in the month
- int is_leap_year: Flag for whether the provided year is a leap year
- int success: Flag for whether struct was successfully filled without error
# Functions
## is_leap_year()
Returns an int base on whether a year fulfills the conditions of a leap year.
- int *year: Year that will be checked
## get_date()
Fills out and returns struct date based on a provided date.
- const char *date_str: Date that will be used
## date_difference()
Calculates and returns int based on how many days have passed
- struct date start_date: Start Date data
- struct date end_date: End Date data
## get_total_difference()
Runs the above functions all at once and returns an int based on the final results.
- char *start_date: Start Date
- char *end_date End Date

Some additional tests includes:
- Whether both dates matches the expected string length of 10
- Whether both struct date.success returns a success.
