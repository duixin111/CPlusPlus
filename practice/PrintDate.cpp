#include <iostream>
using namespace std;

#define isLeapYear(n) ((n%4==0 && n%100 !=0)|| n%400 == 0)
int leap_months[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
int avg_months[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

int main()
{
    int year;
    int days;
    while (cin >> year >> days) {
        int *months = isLeapYear(year)?leap_months:avg_months;
        int month=1;
        while (days > months[month-1]) {
            days = days-months[month-1];
            month++;
        }
        printf("%d-%02d-%02d\n",year,month,days);
    }
    return 0;
}
