#include <iostream>
#include <ctime>
#include <string.h>

using namespace std;

bool is_leap_year(int year);
int get_month_days(int mon, int year);
void print_calender(int first_day, int month_days);

int main()
{

    string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    string days[7] = {
        "Sunday",
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday",
    };

    // today's date
    time_t t = time(0);
    tm *atime = localtime(&t);

    // get the first date of the current month
    time_t month_first_date = time(0) - ((atime->tm_mday - 1) * 24 * 60 * 60);
    tm *ftime = localtime(&month_first_date);
    int first_day = ftime->tm_wday;

    int year = 1900 + ftime->tm_year;

    // month number of days
    int month_days = get_month_days(ftime->tm_mon, year);

    cout << "------------" + months[ftime->tm_mon].substr(0, 3) + "------------" << endl
         << endl;

    // print name of the days
    for (int i = 0; i < size(days); i++)
    {
        cout << days[i].substr(0, 3) << " ";
    };
    print_calender(first_day, month_days);

    return 0;
}

int get_month_days(int mon, int year)
{
    mon = mon + 1;
    if (mon % 2 == 0)
    {
        if (mon == 2)
        {
            if (is_leap_year(year))
            {
                return 29;
            }
            else
            {
                return 28;
            }
        }
        return 30;
    }
    else
    {
        return 31;
    }
}
bool is_leap_year(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}
void print_calender(int first_day, int month_days)
{
    int COLUMNS = 7;
    int ROWS = 6;

    int count = 1;

    cout << endl;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            if (i == 0)
            {
                if (j >= first_day)
                {
                    string t_c;
                    if (count < 10)
                    {
                        t_c = " " + to_string(count) + " ";
                    }
                    else
                    {
                        t_c = to_string(count) + " ";
                    }
                    cout << t_c << " ";
                    count += 1;
                }
                else
                {
                    cout << " - "
                         << " ";
                }
            }
            else
            {
                if (count <= month_days)
                {
                    string t_c;
                    if (count < 10)
                    {
                        t_c = " " + to_string(count) + " ";
                    }
                    else
                    {
                        t_c = to_string(count) + " ";
                    }
                    cout << t_c << " ";
                    count += 1;
                }
                else
                {
                    cout << " - "
                         << " ";
                }
            }
        }
        cout << "\n";
    }
}
