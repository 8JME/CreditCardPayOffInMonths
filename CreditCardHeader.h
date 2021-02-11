#pragma once

#include <cctype>
#include <string>
#include <iostream>
#include <iomanip>
using std::string;

void promptUser(string);
void calculatePayOffTime();
void creditCardPayOffTime();
double AiP(double, double, double);
void resultsOutput(
        double credCardBal,
        double APR,
        double monthlyPmt,
        int pmtRemaining,
        int pmtRemaining10,
        string name);
int widthFormatHelper(string, int);
int exitProgram();