/*
Name: Jaryd Remillard
Assignment: Homework Lab 3
Description: Create a program that takes in phone numbers, and formats correctly. Check if it is an SPU number and print it
Date: 1-24-2017
*/

#include <iostream>
#include <cstring>

using namespace std;

int main() {

    while (true) {
        char phoneNumber[10] = {'0'};
        char areaCode[4], prefixCode[4], suffixCode[5];

        cout << "Enter phone number: ";

        cin.get(phoneNumber, 11);
        cin.ignore();

        char numberLength = strlen(phoneNumber);

        if (numberLength == 10) {
            for (int i = 0; i < 3; i++) {
                areaCode[i] = phoneNumber[i];
                areaCode[3] = 0;
            }

            for (int i = 0; i < 3; i++) {
                prefixCode[i] = phoneNumber[3 + i];
                prefixCode[3] = 0;
            }

            for (int i = 0; i < 4; i++) {
                suffixCode[i] = phoneNumber[6 + i];
                suffixCode[4] = 0;
            }

            cout << "Unformatted phone number: " << phoneNumber << endl;
            cout << "Formatted phone number: (" << areaCode << ")" << prefixCode << "-" << suffixCode << endl;

            if (areaCode[0] == '2' && areaCode[1] == '0' && areaCode[2] == '6') {
                if (prefixCode[0] == '2' && prefixCode[1] == '8' && prefixCode[2] == '1') {
                    cout << "This is an SPU phone number." << endl;
                } else if (prefixCode[0] == '2' && prefixCode[1] == '8' && prefixCode[2] == '6') {
                    cout << "This is an SPU phone number." << endl;
                }
            }

        } else if (numberLength == 7) {
            for (int i = 0; i < 3; i++) {
                prefixCode[i] = phoneNumber[i];
                prefixCode[3] = 0;
            }

            for (int i = 0; i < 4; i++) {
                suffixCode[i] = phoneNumber[3 + i];
                suffixCode[4] = 0;
            }

            cout << "Unformatted phone number: " << phoneNumber << endl;
            cout << "Formatted phone number: (206)" << prefixCode << "-" << suffixCode << endl;

            if (prefixCode[0] == '2' && prefixCode[1] == '8' && prefixCode[2] == '1') {
                cout << "This is an SPU phone number." << endl;
            } else if (prefixCode[0] == '2' && prefixCode[1] == '8' && prefixCode[2] == '6') {
                cout << "This is an SPU phone number." << endl;
            }
        } else if (phoneNumber[0] == '\0') {
            break;
        } else {
            cout << "Please enter a real phone number" << endl;
        }
    }

    return 0;
}