/*
 Author: Jaryd Remillard
 Assignment: Lab 1
 Description: Get user inputted array of values, and output the mean and standard deviation of the array.
 Date: 1-7-2017
*/

#include <iostream>
#include <cmath>

using namespace std;

// max array size
static const int MAX_ARR = 10;

// find the mean by returning value of the (sum of array / cout of the array)
double findMean(int count, double sum) {
    return (sum/(double)count);
}

// find the standard deviation by using the variance formula and returning
// the square root value of variance. Requires an array of values, the mean of the
// array and size of the array.
double findStDev(double userArr[], double mean, int count) {
    double variance = 0;
    for (int i = 0; i < count; i++) {
        variance += (userArr[i] - mean) * (userArr[i] - mean);
    }
    return sqrt(variance/(double)count);
}

int main() {
    double userArr[MAX_ARR];
    int count = 0;
    double sum = 0.0;

    for (int i = 0; i < MAX_ARR; i++) {
        cout << "Enter a number or enter 'q' to quit: " << endl;
        cin >> userArr[i];
        sum += userArr[i];
        count = i + 1;
        if (!cin) {
            break;
        }
    }

    double mean = findMean(count, sum);
    double stdev = findStDev(userArr, mean, count);
    cout << "Mean: " << mean << "\nStandard Dev: " << stdev << endl;

    return 0;
}