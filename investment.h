 /*
 * investment.h
 *
 * Author: Aric Russell
 * Date: 10/03/2026
 *
 * Header file for the Investment class declaration
 */

#ifndef AIRGEAD_BANKING_INVESTMENT_H_
#define AIRGEAD_BANKING_INVESTMENT_H_

// Investment Class

class Investment
{
public:
    Investment(double t_initialInvestment,
               double t_monthlyDeposit,
               double t_annualInterestRate,
               int t_numberOfYears);

    double calculateBalanceWithoutMonthlyDeposit();

    double calculateBalanceWithMonthlyDeposit();

    void printDetails(int t_year,
                      double t_balance,
                      double t_interestEarned);

private:
    double m_initialInvestment;
    double m_monthlyDeposit;
    double m_annualInterestRate;
    int m_numberOfYears;
};

#endif /* AIRGEAD_BANKING_INVESTMENT_H_ */
