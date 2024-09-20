#include <iostream>
#include <string>

using namespace std;

bool isLeapYear(int year);
int getCenturyValue(int year);
int getYearValue(int year);
int getMonthValue(int month, int year);
string getDayOfWeek(int dayOfWeek);

int main() {
    int month, day, year;
    int dayOfWeekSum, dayOfWeek;

    // Prompt user for date
    cout << "Enter the date (MM/DD/YYYY): ";
    char slash; 
    cin >> month >> slash >> day >> slash >> year;

    // Validate month
    while (month < 1 || month > 12) {
        cout << "Please enter a valid month (1-12): ";
        cin >> month;
    }

    // Validate day based on month
    bool validDay = false;
    while (!validDay) {
        if (month == 2) { // February
            if (isLeapYear(year)) {
                validDay = (day >= 1 && day <= 29);
            } else {
                validDay = (day >= 1 && day <= 28);
            }
        } else if (month == 4 || month == 6 || month == 9 || month == 11) { // April, June, September, November
            validDay = (day >= 1 && day <= 30);
        } else { // January, March, May, July, August, October, December
            validDay = (day >= 1 && day <= 31);
        }
        
        if (!validDay) {
            cout << "Please enter a valid day for month " << month << ": ";
            cin >> day;
        }
    }

    // Calculate day of the week
    dayOfWeekSum = day + getMonthValue(month, year) + getYearValue(year) + getCenturyValue(year);
    dayOfWeek = dayOfWeekSum % 7;

    // Output day of the week
    cout << "The day of the week is: " << getDayOfWeek(dayOfWeek) << endl;

    return 0;
}

// Determine if a year is a leap year
bool isLeapYear(int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

// Century value
int getCenturyValue(int year) {
    int century = year / 100;
    return (3 - (century % 4)) * 2;
}

// Year value
int getYearValue(int year) {
    int lastTwoDigits = year % 100;
    return lastTwoDigits + (lastTwoDigits / 4); // leap year adjustment
}

// Month value based on month and year
int getMonthValue(int month, int year) {
    switch (month) {
        case 1: return isLeapYear(year) ? 6 : 0; // January
        case 2: return isLeapYear(year) ? 2 : 3; // February
        case 3: return 3; // March
        case 4: return 6; // April
        case 5: return 1; // May
        case 6: return 4; // June
        case 7: return 6; // July
        case 8: return 2; // August
        case 9: return 5; // September
        case 10: return 0; // October
        case 11: return 3; // November
        case 12: return 5; // December
        default: return 0; // Invalid month
    }
}

// Return day of the week
string getDayOfWeek(int dayOfWeek) {
    switch (dayOfWeek) {
        case 0: return "Sunday";
        case 1: return "Monday";
        case 2: return "Tuesday";
        case 3: return "Wednesday";
        case 4: return "Thursday";
        case 5: return "Friday";
        case 6: return "Saturday";
    }
}

