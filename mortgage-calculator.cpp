/*
   Name: Thanik Bharani
   Mortgage Calculator
   Calculates monthly mortgage payments and total housing cost
   using interest rate, loan duration, taxes, utilities, and insurance.
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define TAX_RATE 0.0125
#define UTILITIES 500.00
#define INSURANCE 703.00

// Function prototypes
void input(double& price, double& interestRate, double& years);
double calcMortgage(double price, double years, double interestRate, double& down, double& amt);
double calcTotal(double mortgage, double price);
void calcMonthlyCosts(double price, double years, double interestRate,
                      double& down, double& amt, double& mortgage, double& totalCost);
void output(double price, double down, double amt, double interestRate, double years,
            double mortgage, double totalCost);

int main()
{
   /*
      Pre: none
      Post: monthly house cost information is displayed
      Purpose: call input, calculation, and output functions for monthly house costs
   */

   double price, interestRate, years;
   double down, amt, mortgage, totalCost;

   input(price, interestRate, years);
   calcMonthlyCosts(price, years, interestRate, down, amt, mortgage, totalCost);
   output(price, down, amt, interestRate, years, mortgage, totalCost);

   cout << endl;
   cout << "Name: Thanik Bharani" << endl;
   cout << "Learned: I learned how functions can work together to solve one problem." << endl;

   return 0;
}

void input(double& price, double& interestRate, double& years)
{
   /*
      Pre: price, interestRate, and years are reference parameters
      Post: price, interestRate, and years contain user input values
      Purpose: prompt for and read the selling price, annual interest rate, and number of years
   */

   cout << "Enter selling price: ";
   cin >> price;

   cout << "Enter annual interest rate (decimal form): ";
   cin >> interestRate;

   cout << "Enter number of years for the loan: ";
   cin >> years;
}

double calcMortgage(double price, double years, double interestRate, double& down, double& amt)
{
   /*
      Pre: price - selling price of house
           years - number of years for the loan
           interestRate - annual interest rate
           down - reference parameter; stores down payment
           amt - reference parameter; stores amount of loan
      Post: returns monthly mortgage payment and updates down and amt
      Purpose: calculate down payment, amount of loan, and monthly mortgage payment
   */

   down = price * 0.20;
   amt = price - down;

   double i = interestRate / 12;
   double n = years * 12;

   return amt * i * pow(1 + i, n) / (pow(1 + i, n) - 1);
}

double calcTotal(double mortgage, double price)
{
   /*
      Pre: mortgage - monthly mortgage payment
           price - selling price of the house
      Post: returns total monthly house cost
      Purpose: calculate monthly cost including mortgage, utilities, property taxes, and insurance
   */

   double monthlyTaxes, monthlyInsurance;

   monthlyTaxes = (price * TAX_RATE) / 12;
   monthlyInsurance = INSURANCE / 12;

   return mortgage + UTILITIES + monthlyTaxes + monthlyInsurance;
}

void calcMonthlyCosts(double price, double years, double interestRate,
                      double& down, double& amt, double& mortgage, double& totalCost)
{
   /*
      Pre: price - selling price of house
           years - number of years for the loan
           interestRate - annual interest rate
           down, amt, mortgage, totalCost - reference parameters for calculated values
      Post: down, amt, mortgage, and totalCost contain completed calculations
      Purpose: calculate monthly mortgage values and total monthly house cost
   */

   mortgage = calcMortgage(price, years, interestRate, down, amt);
   totalCost = calcTotal(mortgage, price);
}

void output(double price, double down, double amt, double interestRate, double years,
            double mortgage, double totalCost)
{
   /*
      Pre: all parameters contain input and calculated values
      Post: formatted monthly house cost information is displayed
      Purpose: output the loan information and monthly payment breakdown
   */

   double propertyTaxes, monthlyInsurance;

   propertyTaxes = (price * TAX_RATE) / 12;
   monthlyInsurance = INSURANCE / 12;

   cout << endl;
   cout << "MONTHLY COST OF HOUSE" << endl << endl;

   cout << fixed << setprecision(2);

   cout << left << setw(30) << "SELLING PRICE" << right << setw(12) << price << endl;
   cout << left << setw(30) << "DOWN PAYMENT" << right << setw(12) << down << endl;
   cout << left << setw(30) << "AMOUNT OF LOAN" << right << setw(12) << amt << endl;
   cout << left << setw(30) << "INTEREST RATE" << right << setw(11) << interestRate * 100 << "%" << endl;
   cout << left << setw(30) << "TAX RATE" << right << setw(11) << TAX_RATE * 100 << "%" << endl;
   cout << left << setw(30) << "DURATION OF LOAN (YEARS)" << right << setw(12)
        << setprecision(0) << years << endl;

   cout << endl;
   cout << "MONTHLY PAYMENT" << endl << endl;

   cout << fixed << setprecision(2);

   cout << left << setw(30) << "MORTGAGE" << right << setw(12) << mortgage << endl;
   cout << left << setw(30) << "UTILITIES" << right << setw(12) << UTILITIES << endl;
   cout << left << setw(30) << "PROPERTY TAXES" << right << setw(12) << propertyTaxes << endl;
   cout << left << setw(30) << "INSURANCE" << right << setw(12) << monthlyInsurance << endl;
   cout << right << setw(42) << "------------" << endl;
   cout << right << setw(30) << "$ " << setw(10) << totalCost << endl;
}
