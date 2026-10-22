/*
 * investment.cpp
 *
 * Author: Aric Russell
 * Date: 10/03/2026
 *
 * Investment class to calculate investment balance with and without monthly deposits
 */

#include "investment.h"

#include <iostream>
#include <iomanip>

using namespace std;

// Constructor
Investment::Investment(double t_initialInvestment,
					   double t_monthlyDeposit,
					   double t_annualInterestRate,
					   int t_numberOfYears)	{

	// Setting initial values for investment object
	m_initialInvestment = t_initialInvestment;
	m_monthlyDeposit = t_monthlyDeposit;
	m_annualInterestRate = t_annualInterestRate;
	m_numberOfYears = t_numberOfYears;
}


// Print function
void Investment::printDetails(int t_year, double t_balance, double t_interestEarned) {

	 cout << left
	         << setw(12) << t_year
	         << "$" << setw(24) << fixed << setprecision(2) << t_balance
	         << "$" << t_interestEarned << endl;
}

// Calculate balance without monthly deposit function
double Investment::calculateBalanceWithoutMonthlyDeposit() {

	// Initialize balance with the initial investment amount
	double balance = m_initialInvestment;

	// Calculate the monthly interest rate once
	double monthlyInterestRate = (m_annualInterestRate / 100.0) / 12.0;

	// For loop to loop the number of years entered by user
	for (int year = 1; year <= m_numberOfYears; year++) {

		// Store the total interest earned during the current year
		double interestEarnedThisYear = 0.0;

		// For loop to loop for each month in the year
		for (int month = 1; month <= 12; month++) {

			// Calculate the interest earned for the current month
			double monthlyInterest = balance * monthlyInterestRate;
			// Add interest accrued to the current balance
			balance += monthlyInterest;
			// Add monthly interest accrued to the total interest earned for the year
			interestEarnedThisYear += monthlyInterest;
		}

		// Print the Details
		printDetails(year, balance, interestEarnedThisYear);
	}

	// Return balance
	return balance;
}

// Calculate balance with monthly deposit function
double Investment::calculateBalanceWithMonthlyDeposit() {

	// Initialize balance with the initial investment amount
	double balance = m_initialInvestment;
	//  Calculate the monthly interest rate once
	double monthlyInterestRate = (m_annualInterestRate / 100.0) / 12.0;

	// For loop to loop the number of years entered by user
	for (int year = 1; year <= m_numberOfYears; year++) {
		// Store the total interest earned during the current year
		double interestEarnedThisYear = 0.0;
		// For loop to loop for each month in the year
		for (int month = 1; month <= 12; month++) {
			// Calculate the interest earned for the month
			double monthlyInterest = balance * monthlyInterestRate;
			// Add the interest to the balance
			balance += monthlyInterest;
			// Add the monthly deposit to the balance after interest has been added
			balance += m_monthlyDeposit;
			// Add the interest to the total interest earned for the year
			interestEarnedThisYear += monthlyInterest;
		}

		// Print the details
		printDetails(year, balance, interestEarnedThisYear);

	}

	// Return balance
	return balance;
}

