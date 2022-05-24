#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> get_adj_list(const vector<vector<int>> &adj) {
    vector<vector<int>> adj_list(adj.size());

    for (int y = 0; y < adj.size(); ++y) {
        for (int x = 0; x < adj[y].size(); ++x) {
            if (adj[y][x] == 1)
                adj_list[y].push_back(x);
        }
    }

    return adj_list;
}

int main() {

    //인접 행렬
    vector<vector<int>> adj = {
            {0, 1, 0, 1, 1, 0},
            {1, 0, 1, 0, 1, 0},
            {0, 1, 0, 0, 0, 1},
            {1, 0, 0, 0, 1, 0},
            {1, 1, 0, 1, 0, 0},
            {0, 0, 1, 0, 0, 0}
    };

    vector<vector<int>> adj_list = get_adj_list(adj);
    for (const auto &l: adj_list) {
        for (auto n: l)
            cout << n << ", ";

        cout << endl;
    }
    return 0;
}