#include <iostream>
#include <iomanip>
using namespace std;

int is_leap_year(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return 1;
    }
    return 0;
}

int is_end_of_year(int day, int month) {
    return (day == 31 && month == 12);
}

int is_end_of_month(int day, int month, int year) {
    if (day == 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)) {
        return 1;
    }
    if (day == 30 && (month == 4 || month == 6 || month == 9 || month == 11)) {
        return 1;
    }
    if (month == 2) {
        if (is_leap_year(year) && day == 29) {
            return 1;
        } else if (is_leap_year(year) == 0 && day == 28) {
            return 1;
        }
    }
    
    return 0;
}

int main(int argc, char *argv[]) {
    int year, month, day;
    char dash;
    while (cin >> year >> dash >> month >> dash >> day) {
        if (is_end_of_year(day, month)) {
            cout << year + 1 << "-01-01\n";
        } else if (is_end_of_month(day, month, year)) {
            cout << year << '-' << setw(2) << setfill('0') << month + 1 << '-' << "01" << '\n';
        } else {
            cout << year << '-' << setw(2) << setfill('0') << month << '-' << setw(2) << setfill('0') << day + 1 << '\n';
        }
    }
}
