/*
 Author: Jaryd Remillard
 Assignment: Lab 2
 Description: Create a program that takes in user input and stores them into an array. Manipulate the array to find statistics, and graph them in various ways.
 Date: 1-11-2017
*/

#include <iostream>
#include <iomanip>

using namespace std;

// iniialize max size of array
static const int SIZEOF_SCORES = 51;

void welcomeInfo() {
    cout << "Welcome to the Quiz Score Frequency Analyzer" << endl;
    cout << "Enter a list of pairs of values: \"QuizScoreValue ScoreCount\"" << endl;
    cout << "Enter -1 0 to end input" << endl;
}

int main() {
    welcomeInfo();

    // get input quiz scores
    int scoreFrequency[SIZEOF_SCORES] = {0};

    // store input quiz scores into array
    int a, b;
    for (int i = 0; i < SIZEOF_SCORES; i++) {
        cin >> a >> b;
        if (a == -1 && b == 0) {
            break;
        } else if (scoreFrequency[a] != 0) {
            scoreFrequency[a] = scoreFrequency[a] + b;
        } else {
            scoreFrequency[a] = b;
        }
    }

    // find biggest frequency
    int biggestFreq = 0;
    for (int x = 0; x < SIZEOF_SCORES; x++) {
        if (biggestFreq < scoreFrequency[x]) {
            biggestFreq = scoreFrequency[x];
        }
    }

    // find smalelst score
    int minScore = 0;
    for (int w = 0; w < SIZEOF_SCORES; w++) {
        if (scoreFrequency[w] != 0) {
            minScore = w;
            break;
        }
    }

    // find largest score
    int maxScore = 50;
    for (int y = 50; y >= 0; y--) {
        if (scoreFrequency[y] != 0) {
            maxScore = y;
            break;
        }
    }

    // tableData
    cout << setw(14) << "\n--- Input Data ---" << endl;
    cout << setw(14) << "Score: Frequency" << endl;

    for (int z = minScore; z <= maxScore; z++) {
        cout << setw(3) << z << ":" << setw(8) << scoreFrequency[z] << endl;
    }

    cout << "\nThe smallest score value is " << minScore << endl;
    cout << "The largest score value is " << maxScore << endl;
    cout << "The largest frequency count is " << biggestFreq << endl;

    //Score: Frequency Vertical Bar Chart 
    cout << "\nScore: Frequency Vertical Bar Chart" << endl;
    for (int v = minScore; v <= maxScore; v++) {
        cout << setw(3) << v << ": ";
        if (scoreFrequency[v] > 0) {
            for (int c = 1; c <= scoreFrequency[v]; c++) {
                cout << "*";
            }
        }
        cout << endl;
    }

    //Frequency: Score Horizontal Bar Chart 
    cout << "\nFrequency: Score Horizontal Bar Chart" << endl;

    for (int r = 0; r < biggestFreq; r++) {
        cout << " ^ " << biggestFreq - r << ":";
        for (int c = minScore; c <= maxScore; c++) {
            cout << "  " << (r + scoreFrequency[c] >= biggestFreq ? '*' : ' ');
        }
        cout << endl;
    }

    cout << "      ";
    for (int b = minScore; b <= maxScore; b++) {
        if (b < 10) {
            cout << " ";
        }
        cout << b << " ";
    }
    cout << endl;

    return 0;
}