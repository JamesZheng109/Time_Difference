#ifndef Time_Different_H
#define Time_Different_H
typedef struct date
{
    int month;
    int day;
    int year;
    int days_in_month;
    int is_leap_year;
    int success;
};
int leap_year_check(int *year);
struct date get_date(const char *date_str);
int date_difference(struct date start_date,struct date end_date);
int get_total_difference(char *start_date,char *end_date);
#endif