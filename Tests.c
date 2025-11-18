#include <stdio.h>
#include "Time_Difference.h"

void main()
{
    printf("Testing leap_year_check()\n");
    int is_leap_year=2000;
    int not_leap_year=2020;
    printf("Passing in 2000\n");
    if(leap_year_check(&is_leap_year))
    {
        printf("Pass\n");
    }
    else
    {
        printf("Fail\n");
    }
    printf("Passing in 2020\n");
    if(!leap_year_check(&not_leap_year))
    {
        printf("Pass\n");
    }
    else
    {
        printf("Fail\n");
    }
    printf("Testing get_date()\n");
    const char *date1="11/12/2020";
    const char *date2="12/24/2020";
    const char *date3="11";
    const char *date4="LL/LL/LLLL";
    printf("Passing value 11/12/2020\n");
    struct date start=get_date(date1);
    printf("Passing value 12/24/2020\n");
    struct date end=get_date(date2);
    printf("Passing value 11\n");
    struct date fail=get_date(date3);
    printf("Passing value LL/LL/LLLL\n");
    struct date fail2=get_date(date4);
    printf("Testing date_difference()\n");
    printf("Passing value 11/12/2020 & 12/24/2020\n");
    int result=date_difference(start,end);
    printf("returns: %d\n",result);
    printf("Passing value 12/24/2020 & 11/12/2020\n");
    int result2=date_difference(end,start);
    printf("returns: %d\n",result2);
    printf("Testing get_total_difference()\n");
    char *date01="11/12/2020";
    char *date02="12/24/2020";
    char *date03="11";
    char *date04="LL/LL/LLLL";
    printf("Passing 11/12/2020 & 12/24/2020\n");
    int difference=get_total_difference(date01,date02);
    printf("returns: %d\n",difference);
    printf("Passing value 12/24/2020 & 11/12/2020\n");
    int difference2=get_total_difference(date02,date01);
    printf("returns: %d\n",difference2);
    printf("Passing value 11/12/2020 & 11\n");
    int difference3=get_total_difference(date01,date03);
    printf("returns: %d\n",difference3);
    printf("Passing value 11 & LL/LL/LLLL\n");
    int difference4=get_total_difference(date03,date04);
    printf("returns: %d\n",difference4);
}