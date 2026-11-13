#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string input;
size_t pos = 0;
bool error = false;

void skipSpaces() {
    while (pos < input.size() &&
           isspace((unsigned char)input[pos]))
        pos++;
}

void E();
void R();
void T();
void Y();
void F();  

void E() {
    T();
    R();
}

void R() {
    skipSpaces();
    if (pos < input.size() && input[pos] == '+') {
        pos++;
        T();
        R();
    }
}

void T() {
    F();
    Y();
}

void Y() {
    skipSpaces();
    if (pos < input.size() && input[pos] == '*') {
        pos++;
        F();
        Y();
    }
}

void F() {
    skipSpaces();

    if (pos < input.size() && input[pos] == '(') {
        pos++;
        E();
        skipSpaces();

        if (pos < input.size() && input[pos] == ')')
            pos++;
        else
            error = true;
    }
    else if (pos < input.size() &&
             (isalnum((unsigned char)input[pos]) ||
              input[pos] == '_')) {
        while (pos < input.size() &&
               (isalnum((unsigned char)input[pos]) ||
                input[pos] == '_'))
            pos++;
    }
    else {
        error = true;
    }
}

int main() {
    cout << "Enter arithmetic expression: ";
    getline(cin, input);

    E();
    skipSpaces();

    if (!error && pos == input.size())
        cout << "Expression is valid.\n";
    else
        cout << "Expression is invalid.\n";

    return 0;
}
