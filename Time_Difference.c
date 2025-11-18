#include <stdio.h>
#include <string.h>

struct date
{
    int month;
    int day;
    int year;
    int days_in_month;
    int is_leap_year;
    int success;
};
//Leap Year Check
int leap_year_check(int *year)
{
    //Leap Year Rules: is divisible by 4 and not 100 unless by 400
    int divisible_4=*year%4;
    int divisible_100=*year%100;
    int divisible_400=*year%400;
    return ((divisible_4==0)&&(divisible_100!=0||divisible_400==1));
}
//Returns date
struct date get_date(const char *date_str)
{   
    //Initalize struct tm to pass into _mkgmtime()
    struct date Sale_Date;
    Sale_Date.success=1;
    //Temporarily save dates to 3 int variables 
    int month,day,year;
    //Check if formatting is correct if anything but 3, fail
    int ret=sscanf(date_str,"%d/%d/%d",&month,&day,&year);
    printf("sscanf returned: %d\n", ret);
    //Print parsed output
    printf("Parsed: month=%d day=%d year=%d\n", month, day, year);
    if (ret!=3)
    {
        fprintf(stderr,"Error. Expected date format is mm/dd/yyyy.\n");
        Sale_Date.success=0;
    }
    //Validate Date
    ///Month
    if(month<0 || month>12)
    {
        printf("Month %d, is outside range. Expect: 1-12.\n",month);
        Sale_Date.success=0;
    }
    ///Year
    Sale_Date.is_leap_year=leap_year_check(&year);
    if(year<=0)
    {
        printf("Year %d, is outside range. Expect, value highter than 0.\n");
        Sale_Date.success=0;
    }
    ///Day limits:28,29,30,31
    ////Check for months with 31 days (Jan,Mar,May,Jul,Aug,Oct,Dec)
    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
    {
        if ((day<=0||day>31))
        {
            printf("Day %d, is outside range of month %d. Expect:1-31.\n",day,month);
            Sale_Date.success=0;
        }
        Sale_Date.days_in_month=31;
    }
    ////Check for months with 30 days (Apr,Jun,Sep,Nov)
    else if(month==4||month==6||month==9||month==11)
    {   if (day<=0||day>30)
        {
            printf("Day %d, is outside range of month %d. Expect:1-30.\n",day,month);
            Sale_Date.success=0;
        }
        Sale_Date.days_in_month=30;
    }
    ////Check for Feb for leap year
    else if(month==2)
    {
        if (day<=0)
        {
            printf("Day %d in %d must be greater than 0.\n",day,month);
            Sale_Date.success=0;
        }
        //If it is a leap year
        if(Sale_Date.is_leap_year)
        {
            if(day>29)
            {
                printf("Day %d, is outside leap year range of month 2.\n",day);
                Sale_Date.success=0;
            }
            Sale_Date.days_in_month=29;
        }
        else if(!Sale_Date.is_leap_year)
        {
            if (day>28)
            {
                printf("Day %d, is outside non-leap year range of month 2.\n",day);
                Sale_Date.success=0;
            }
           Sale_Date.days_in_month=28;
        }
    }
    ////Check for days without
    //Assign variables to Sale_Date (Subtract, since struct tm returns time since Jan 1, 1990)
    Sale_Date.month=month;
    Sale_Date.day=day;
    Sale_Date.year=year;
    printf("Is Leap year: %d.\n",Sale_Date.is_leap_year);
    printf("Day in month %d: %d.\n",Sale_Date.month,Sale_Date.days_in_month);
    return Sale_Date;
}
int date_difference(struct date start_date,struct date end_date)
{
    //Check if start date passed end date
    if ((start_date.year>end_date.year)||(start_date.month>end_date.month)||(start_date.month<=end_date.month)&&(start_date.day>end_date.day))
    {
        printf("Start date has passed end date.\n");
        return 0;
    }
    //Get days left in 1st date
    int date_1_remainder=start_date.days_in_month-start_date.day;
    //Get days passed in 2nd date
    int date_2_passed=end_date.day;
    //Get difference in year
    int years_pass=end_date.year-start_date.year;
    //Get days between start_date.year and end_date.year
    int days_passed_between_years=365*years_pass;
    //Account for leap years
    int leap_year_additions=0;
    for(int current_year=start_date.year;current_year!=end_date.year+1;current_year++)
    {
        if (current_year==start_date.year||current_year==end_date.year)
        {
            continue;
        }else if(leap_year_check(&current_year))
        {
            leap_year_additions++;
        }
    }
    int total=date_1_remainder+date_2_passed+days_passed_between_years+leap_year_additions;
    return total;
}
int get_total_difference(char *start_date,char *end_date)
{
    const char *date_1=start_date;
    const char *date_2=end_date;
    //Length check
    if (strlen(date_1)!=10||strlen(date_2)!=10)
    {
        printf("Error in command input. Please Check:\n");
        printf("1. 2 Dates where not provided.\n");
        printf("2. Date formatting: mm/dd/yyyy.\n");
        return 0;
    }
    struct date start=get_date(date_1);
    struct date end =get_date(date_2);
    if(!start.success||!end.success)
    {
        printf("Please double check both dates.\n");
        return 0;
    }
    else
    {
        int difference=date_difference(start,end);
        printf("Difference between %s & %s: %d days.\n",date_1,date_2,difference);
        return difference;
    }
}