/*
 Name: Jaryd Remillard
 Assignment: Lab 4
 Description: 
 Date: 1-24-2017
*/

#include <iostream>
#include <cstring>
using namespace std;

#include "stringPkg.h"

int main()
{
    
    char tempName[50] = {'\0'};
    char fullName[50] = {'\0'};
    
    cin.getline(tempName, 50);
    
    // deblank array
    int spaces;
    for (int i = 0; i < stringLength(tempName); i++) {
        if (tempName[i] == ' ') {
            spaces++;
        }
    }
    
    for (int i = 0, j = 0; i < stringLength(tempName); i++, j++) {
        if (spaces > 1) {
            if (tempName[i] != ' ') {
                fullName[j] = tempName[i];
            } else {
                spaces--;
                j--;
            }
        } else {
            fullName[j] = tempName[i];
        }
    }
    
    char firstName[50] = {'\0'};
    char lastName[50] = {'\0'};
    
    int spacePos = stringFindchar(fullName, ' ') + 1;
    int findComma = stringFindchar(fullName, ',') - 1;
    
    stringSubstring(firstName, 50, fullName, spacePos);
    stringSubstring(lastName, 50, fullName, 0, findComma);
    
    cout << "Thank you " << firstName << " " << lastName << " for entering " << fullName << endl;
    
    int compareName = stringCompare(firstName, lastName);
    
    if (compareName == -1) {
        cout << "The First Name is less than the Last Name" << endl;
    } else if (compareName == 1) {
        cout << "The First Name is greater than the Last Name" << endl;
    } else {
        cout << "The First Name is equal too the Last Name" << endl;
    }
    
    return 0;
}
