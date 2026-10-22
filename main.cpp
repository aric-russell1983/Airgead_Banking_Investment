/*
 * main.cpp
 *
 * Author: Aric Russell
 * Date: 10/03/2026
 *
 * This program is designed to display and calculate accrued interest on an investment account
 * based on user input
 */
#include "investment.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Print spacer function
void printSpacer(int t_length, char t_spaceCharacter) {
	// For loop to print amount of times passed through to it
	for (int i = 0; i < t_length; i++) {
		cout << t_spaceCharacter;
	}
	// Newline
	cout << endl;
}

// Print header function
void printHeader(string t_title, int t_length, char t_spaceCharacter) {
	// Call on printSpacer and pass it the value stored in t_length
	printSpacer(t_length, t_spaceCharacter);
	// Calculate how many spaces are needed to center text
	int spaces = (t_length - t_title.length()) / 2;

	// For loop to output amount of spaces needed
	for (int i = 0; i < spaces; i++) {
		cout << " ";
	}
	// Output title followed by a new line
	cout << t_title << endl;
	// Call on printSpacer and pass it the value stored in t_length
	printSpacer(t_length, t_spaceCharacter);
}

// Check to ensure that the input made by the user is a positive number
double getValidInput(string t_prompt) {
	// Declare variable to be used within function
	double value;
	// Declare loop condition variable and set it's initial value
	// to false
	bool validInput = false;

	// While loop to loop until a positive number is entered
	while (!validInput) {
		// Output prompt to user
		cout << t_prompt;
		// Get input from user
		cin >> value;

		// If input is of the correct type and is positive then
		if (!cin.fail() && value > 0) {
			// Set validInput to true
			validInput = true;
		}
		else {
			// Otherwise output Please enter a positive number
			cout << "Please enter a positive number." << endl;
			cin.clear();	// Clear the error state
			cin.ignore(1000, '\n');	// // Clear the invalid input from the buffer
		}
	}

	// Return value
	return value;
}

// Check to ensure a positive year is input
int getValidYears() {

	// Declare variables to be used within function
	double value;
	// Declare loop condition variable and set it's initial value
	// to false
	bool validInput = false;

	// While loop to loop until a positive number is entered
	while (!validInput) {

		// Prompt user for number of years
		cout << "Number of Years: ";
		cin >> value;

		// If value entered by user is a number, positive, and a whole number
		if (!cin.fail() && value > 0 && value == static_cast<int>(value)) {
			// Set loop variable to true to exit loop
			validInput = true;
		}
		// Otherwise
		else {
			// Tell user to enter a positive number
			cout << "Please enter a positive whole number." << endl;
			cin.clear();	// Clear error state
			cin.ignore(1000, '\n');	// // Clear the invalid input from the buffer
		}
	}

	// Return value
	return value;
}

// Main driver of program
int main() {

	// Declaring variables
	double initialInvestment;
	double monthlyDeposit;
	double annualInterestRate;
	int numberOfYears;

	// Print header for start of program
	printHeader("Airgead Banking App", 70, '#');

	// Get user input and check for valid input
	initialInvestment = getValidInput("Initial Investment Amount: $");

	monthlyDeposit = getValidInput("Monthly Deposit: $");

	annualInterestRate = getValidInput("Annual Interest: %");

	numberOfYears = getValidYears();

	// Create investment object
	Investment investment(initialInvestment,
						  monthlyDeposit,
						  annualInterestRate,
						  numberOfYears);

	// Print header
	printHeader("Press any key to continue", 70, '#');

	cin.ignore(); // Consumes new line
	cin.get();	// Accepts next input from user

	// Print header
	printHeader("Balance and Interest Without Additional Monthly Deposits", 70, '#');
	// Output headers for columns in calculate methods
	cout << left
	     << setw(12) << "Year"
	     << setw(25) << "Year End Balance"
	     << "Interest Earned" << endl;
	// Print spacer
	printSpacer(70, '*');

	investment.calculateBalanceWithoutMonthlyDeposit();

	// Add 2 lines between tables
	cout << endl;
	cout << endl;

	// Print header
	printHeader("Balance and Interest with Additional Monthly Deposits", 70, '#');
	// Output headers for columns in calculate methods
	cout << left
		 << setw(12) << "Year"
		 << setw(25) << "Year End Balance"
		 << "Interest Earned" << endl;
	// Print spacer
	printSpacer(70, '*');

	investment.calculateBalanceWithMonthlyDeposit();

	// Add 2 lines between last table and end of program
	cout << endl;
	cout << endl;

	// Print End of program
	printHeader("End Program", 70, '#');

	return 0;

}
