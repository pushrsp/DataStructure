#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_vec(const vector<int> &vec) {
    for (auto &e: vec)
        cout << e << " ";

    cout << endl;
}

void Perm(vector<int> &vec, int k) {
    if (k == vec.size() - 1) {
        print_vec(vec);
        return;
    }

    for (int i = k; i < vec.size(); ++i) {
        swap(vec[k], vec[i]);
        Perm(vec, k + 1);
        swap(vec[k], vec[i]);
    }
}