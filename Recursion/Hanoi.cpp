#include <iostream>

using namespace std;

int hanoi(int n, int from, int to, int by) {
    if (n == 1) {
        cout << from << " -> " << to << endl;
    } else {
        hanoi(n - 1, from, by, to);
        cout << from << " -> " << to << endl;
        hanoi(n - 1, by, to, from);
    }
}