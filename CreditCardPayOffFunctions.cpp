#include "CreditCardHeader.h"

using namespace std;

double MONTHS_IN_YEAR = 12;

// Prompt user for data
void promptUser(string message)
{
    cout << message << endl;
}

// Program Start Function
void creditCardPayOffTime()
{
    string userInput;

    promptUser("Do you have any data? (Y/N) ");
    cin >> userInput;

    // convert string into a char using first index of original string.
    char charCompare = tolower(userInput[0]);

    // Checks if input is either Y/N, y/n
    while(charCompare == 'y')
    {
        if(charCompare == 'y')
        {
            // Start of Calculation Process
            calculatePayOffTime();
            promptUser("Do you have any data? (Y/N) ");
            cin >> userInput;
            charCompare = static_cast<char>(tolower(userInput[0]));
        }
        else
        {
            return; // exit
        }
    }
}


// Calculate Credit Card Payoff Time in Months

void calculatePayOffTime()
{
    string firstName;
    double
            creditBalance,
            APR,
            aprConversion,
            monthlyPayment,
            increasePmtBy10Percent,
            MIRC,
            Ai_P,
            monthsUntilPayoff,
            monthsUntilPayoff10;

    promptUser("Please enter your first name: ");
    cin >> firstName;

    promptUser("Please enter your credit balance: ");
    cin >> creditBalance;

    while(creditBalance <= 0 || creditBalance >= 10000)
    {
        string response;
        char continueCheck;
        promptUser("Invalid Balance");
        promptUser("Do you have any data? (Y/N) ");
        cin >> response;
        // Sanitize user input convert string to char as lowercase of first character
        continueCheck = static_cast<char>(tolower(response[0]));

        if(continueCheck == 'y')
        {
            promptUser("Please enter a valid balance: ");
            cin >> creditBalance;
        }
        else
        {
            exitProgram();
        }
    }

    promptUser("Please enter the APR: ");
    cin >> APR;

    while(APR < 0 || APR > 22)
    {
        string response;
        char continueCheck;
        promptUser("Invalid APR");
        promptUser("Do you have any data? (Y/N) ");
        cin >> response;
        // Sanitize user input convert string to char as lowercase of first character
        continueCheck = static_cast<char>(tolower(response[0]));

        if(continueCheck == 'y')
        {
            promptUser("Please enter a valid APR: ");
            cin >> APR;
        }
        else
        {
            exitProgram();
        }
    }

    promptUser("Please enter the monthly payment: ");
    cin >> monthlyPayment;

    while(monthlyPayment <= 0 || monthlyPayment > creditBalance)
    {
        string response;
        char continueCheck;
        promptUser("Invalid Payment Amount");
        promptUser("Do you have any data? (Y/N) ");
        cin >> response;
        // Sanitize user input convert string to char as lowercase of first character
        continueCheck = static_cast<char>(tolower(response[0]));

        if(continueCheck == 'y')
        {
            promptUser("Please enter a valid payment: ");
            cin >> monthlyPayment;
        }
        else
        {
            exitProgram();
        }
    }


    // Conversions:
    aprConversion = APR / 100.0;
    //MonthlyInterestRateConversion (MIRC)
    MIRC = aprConversion / MONTHS_IN_YEAR;

    // Calculates 10% increase in payment scenario
    increasePmtBy10Percent += monthlyPayment + (monthlyPayment * .10);

    // Calculate months till payoff for given monthly payment
    double AIPREG, AIP10; // Regular Calculation & 10% Increase in payment calculation

    AIPREG = AiP(creditBalance, aprConversion, monthlyPayment);
    AIP10 = AiP(creditBalance, aprConversion, increasePmtBy10Percent);


    monthsUntilPayoff = round(-log(1-(AIPREG)) / log(1 + MIRC)); // Reg Calculation
    monthsUntilPayoff10 = round(-log(1-(AIP10)) / log(1 + MIRC)); // Assumes a 10% of inputed payment

    // Final Output:
    resultsOutput(creditBalance, aprConversion, monthlyPayment, monthsUntilPayoff, monthsUntilPayoff10, firstName);


}

//Amount of credit balance * (aprConversion / MONTHS_IN_YEAR) / monthlyPayment ### Ai_P
double AiP(double credCardBal, double monthlyAPR, double monthlyPmt)
{
    return credCardBal * (monthlyAPR / MONTHS_IN_YEAR) / monthlyPmt;
}

// Final results output
void resultsOutput(
        double credCardBal,
        double APR,
        double monthlyPmt,
        int pmtRemaining,
        int pmtRemaining10,
        string name)
{
    cout << "\n\n------------------------------------------------\n\n";
    cout << "Credit Card Payment Report for " << name;
    cout << "\n\n------------------------------------------------\n\n\n";

    // String output to user
    string line1 = "Current Credit Card Balance: ";
    string line2 = "Annual Percentage Rate (APR): ";
    string line3 = "Monthly Payment: ";
    string line4 = "Number of months needed: ";
    string line5 = "Recalculated months for +10% : ";

    int maxSpaceLength = 45;

    // Assists with width precision
    int widthFormat1 = widthFormatHelper(line1, maxSpaceLength);
    int widthFormat2 = widthFormatHelper(line2, maxSpaceLength);
    int widthFormat3 = widthFormatHelper(line3, maxSpaceLength);
    int widthFormat4 = widthFormatHelper(line4, maxSpaceLength);
    int widthFormat5 = widthFormatHelper(line5, maxSpaceLength);

    // Formatted string output
    cout << line1 << right << fixed << setw(widthFormat1) << setprecision(3) << credCardBal << endl;
    cout << line2 << right << fixed << setw(widthFormat2) << APR << endl;
    cout << line3 << right << fixed << setw(widthFormat3) << monthlyPmt << endl;
    cout << line4 << right << fixed << setw(widthFormat4) << pmtRemaining << endl;
    cout << line5 << right << fixed << setw(widthFormat5) << pmtRemaining10 << endl;
    cout << "\n------------------------------------------------\n\n";
}

// ensures the difference in length spacing is equal in relation to max width
int widthFormatHelper(string stringLine, int maxWidth)
{
    return maxWidth - stringLine.length(); // returns space count as an integer
}
// exits program when called
int exitProgram()
{
    exit(3);

    return 3;
}
