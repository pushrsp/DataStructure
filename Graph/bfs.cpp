#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfs(const vector<vector<int>> &adj, int depth) {
    vector<bool> visited(adj.size(), false);
    vector<int> order;
    queue<int> q;
    q.push(depth);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (visited[v])
            continue;

        visited[v] = true;
        cout << v << ", ";
        order.push_back(v);

        for (int a: adj[v])
            if (!visited[a])
                q.push(a);
    }

    return order;
}

int main() {
    vector<vector<int>> adj = {
            {1, 3, 4},
            {0, 2, 4},
            {1, 5},
            {0, 4},
            {0, 1, 3},
            {2},
    };


    bfs(adj, 0);

    return 0;
}