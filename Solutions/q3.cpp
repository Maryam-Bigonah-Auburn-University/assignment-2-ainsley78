#include <iostream>
#include <iomanip>

using namespace std;

double convertToMPH(int minutes, int seconds);
double convertToMPH(double kph);

int main() {
    int minutes = 0, seconds = 0;
    double kph = 0.0;

    // Prompt the user for pace 
    cout << "Enter your running pace:\n";
    cout << "Minutes: ";
    cin >> minutes;
    cout << "Seconds: ";
    cin >> seconds;
    // Convert pace to MPH
    double mphFromPace = convertToMPH(minutes, seconds);
    cout << fixed << setprecision(2); // Format to 2 decimal places
    cout << "Your pace in miles per hour: " << mphFromPace << " MPH" << endl;

    // Prompt the user for speed 
    cout << "Enter your speed in kilometers per hour: ";
    cin >> kph;

    // Convert KPH to MPH
    double mphFromKPH = convertToMPH(kph);
    cout << "Your speed in miles per hour: " << mphFromKPH << " MPH" << endl;

    return 0;
}

// Convert pace to miles per hour
double convertToMPH(int minutes, int seconds) {
    // Calculate total seconds and convert to hours
    double totalSeconds = (minutes * 60) + seconds;
    return (3600.0 / totalSeconds); // Return speed in MPH
}

// Convert from KPH to MPH
double convertToMPH(double kph) {
    return (kph / 1.61); 
}

