#include <iostream>
using namespace std;

void computeCoin(int coinValue, int& coinCount, int& remainingAmount);
void printCoinOutput(int coinValue, int coinCount);

int main() {
    char continueCalculating = 'N';
    int coinCount = 0;
    int remainingAmount = 0;

    do {
        // Prompt the user for an amount
        cout << "Enter the amount of change (1-99 cents): ";
        cin >> remainingAmount;

        // Validate input
        while (remainingAmount < 1 || remainingAmount > 99) {
            cout << "Please enter a value between 1 and 99: ";
            cin >> remainingAmount;
        }

        cout << "Change can be given as:" << endl;
        
        // Calculate and print the number of quarters
        computeCoin(25, coinCount, remainingAmount);
        printCoinOutput(25, coinCount);
        
        // Calculate and print the number of dimes
        computeCoin(10, coinCount, remainingAmount);
        printCoinOutput(10, coinCount);
        
        // Calculate and print the number of pennies
        computeCoin(1, coinCount, remainingAmount);
        printCoinOutput(1, coinCount);

        // Ask if the user wants to perform another 
        cout << "Do you want to make change again? (Y/N): ";
        cin >> continueCalculating;

    } while (continueCalculating == 'Y' || continueCalculating == 'y');

    return 0;
}

// Compute the number of coins
void computeCoin(int coinValue, int& coinCount, int& remainingAmount) {
    coinCount = remainingAmount / coinValue; // Determine the number of coins
    remainingAmount -= coinCount * coinValue; // Update coin remaining
}

// Print the output
void printCoinOutput(int coinValue, int coinCount) {
    cout << coinCount; // Output the number of coins
    switch (coinValue) {
        case 25:
            cout << " quarter(s)" << endl; // Quarters
            break;
        case 10:
            cout << " dime(s)" << endl; // Dimes
            break;
        case 1:
            cout << " penny(ies)" << endl; // Pennies
            break;
    }
}

