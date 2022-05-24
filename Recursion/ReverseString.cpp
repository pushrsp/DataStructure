#include <iostream>

using namespace std;

string reverse(const string &s) {
    if (s.length() == 0)
        return "";
    else {
        cout << s.substr(1) << endl;
        return reverse(s.substr(1)) + s[0];
    }
}