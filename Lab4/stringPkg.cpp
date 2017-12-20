// stringPkg.cpp
// Written by: Jaryd Remillard
//
// Library implementation
// A library of ASCIIZ string functions.
// All functions in this library manipulate character arrays
// whose values are sequences of characters (string-values)
// utilizing the ASCIIZ format.

#include "stringPkg.h"

// -------------------------------------------------------------
// Return length of a string, length >= 0.
// Length is a count of the characters in the string-value,
//    not including the null at the end.
// An empty string ("") has length 0.
int stringLength(const char s[])
{
	int len = 0;
	while (s[len] != 0) ++len; // count chars until encounter null char
	// or while(s[len]) ++len;
	return(len);
}

// -------------------------------------------------------------
// Copy string src to string dest.
void stringCopy(char dest[], const int destBuffSize, const char src[])
{
	int len = stringLength(src);
	if (len >= destBuffSize)
	    len = destBuffSize - 1; // truncate if necessary, leave room for null

	for (int i = 0; i < len; ++i) // count through the string-value
	{
	    dest[i] = src[i]; // copy each character
	}
	dest[len] = 0; // append the ASCIIZ null at end
}

// -------------------------------------------------------------
// Concatenate string t to end of string dest
void stringConcatenate(char dest[], const int destBuffSize, const char t[])
{
	for (int i = 0; i <= stringLength(t); i++)
		dest[destBuffSize + i] = t[i];
	dest[destBuffSize + stringLength(t)] = 0;
}

// -------------------------------------------------------------
// Retrieve character from string s[position].
// Position must be between 0 and (stringLength-1).
// Return 0 if position is out of range.
char stringGetchar(const char s[], const int position)
{
	if (position >= 0 && position < stringLength(s))
		return s[position];
	return (0);
}

// ------------------------------------------------------------- STILL NEEDS WORK
// Find ch in string s starting at the 'startpos' array location.
// startpos must be non-negative and less than the string length.
// Return the 'found' position: 0 - (stringLength-1)
// Return -1 if ch not found in s.
int  stringFindchar(const char s[], const char ch, const int startpos)
{
	 if (startpos >= 0 && startpos < stringLength(s)) {
         for (int i = startpos; i < stringLength(s); i++) {
             if (ch == s[i]) {
                 //return (0 - (stringLength(s) - 1)); //"found position"
                 return (startpos + i); //actual found position
             }
         }
	 }
	return(-1);
}

// -------------------------------------------------------------
// Set resultString[] to a string value that is a copy of
//    a specified substring of original string s.
// If specified start position is not located within the string s,
//    then set resultString to the empty string ("").
// If specified len < 0, or if (start + len) > the length of s
//    then set resultString to the longest possible substring.
void stringSubstring(
	char resultString[],        // new string buffer
	const int resultBuffSize,   // result array buffer size
	const char s[],	            // the original string
	const int start,            // starting position of substring within s
	const int len)              // length of substring within s
	                            //   len<0: longest possible substring
{
    if (start > -1 || start < stringLength((s))) {
        if (len < 0 || (start + len) > stringLength(s)) {
            resultString[resultBuffSize] = {'\0'};
            for (int i = 0; i <= stringLength(s); i++) {
                resultString[i] = s[start + i];
            }
        } else {
            for (int i = 0; i <= len; i++) {
                resultString[i] = s[start + i];
            }
        }
    } else {
        resultString[resultBuffSize] = {' '};
    }
}

// -------------------------------------------------------------
// Alphabetically compare string s to string t, based on ASCII charset.
// Return an integer value < 0 if s <  t
// Return an integer value 0   if s == t
// Return an integer value > 0 if s >  t
int  stringCompare(const char s[], const char t[])
{
    // initialize var to find biggest number to loop
    int loopLength = 0;
    
    // get smallest loop length
    if (stringLength(s) < stringLength(t)) {
        loopLength = stringLength(s);
    } else if (stringLength(s) > stringLength(t)) {
        loopLength = stringLength(t);
    } else {
        loopLength = stringLength(s);
    }
    
    for (int i = 0; i < loopLength; i++) {
        if (s[i] > t[i]) { return (1); }
        if (s[i] < t[i]) { return (-1); }
    }
    
    // check which is a bigger string, and return it
    if (stringLength(s) < stringLength(t)) { return (-1); }
    if (stringLength(s) > stringLength(t)) { return (1); }
    
    return 0;
}

// -------------------------------------------------------------
