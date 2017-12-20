//
//  main.cpp
//  Test
//
//  Created by admin on 3/15/17.
//  Copyright © 2017 Remillard Tech. All rights reserved.
//

#include <iostream>

using namespace std;

int f(char *s) {
    char *p = s;
    while (*p != 0) p = p + 1;
    return (p - s);
}

int main(int argc, const char * argv[]) {
    char buff[25] = "Computers Are Great";
    
    char *p;
    p = buff;
    
    cout << *p << endl;
    cout << p << endl;
    cout << p + 10 << endl;
    cout << *(p + 10) << endl;
    cout << &p[10] << endl;
    
    int x = f(buff);
    cout << x << endl;
    x = f(buff + 10);
    cout << x << endl;
    x = f(&buff[14]);
    cout << x << endl;
    
    buff[13] = 0;
    cout << &buff[14] << endl;
    
    return 0;
}
