#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int N = 6;
bool visited[N] = {false,};

void dfs(const vector<vector<int>> &adj, int depth) {
    if (visited[depth])
        return;

    visited[depth] = true;
    cout << depth << ", ";

    for (auto v: adj[depth])
        dfs(adj, v);
}

vector<int> dfs_stack(const vector<vector<int>> &adj, int depth) {
    vector<bool> visit(adj.size(), false);
    vector<int> order;
    stack<int> stk;
    stk.push(depth);

    while (!stk.empty()) {
        int v = stk.top();
        stk.pop();

        if (visit[v])
            continue;

        visit[v] = true;
        order.push_back(v);

        for (int a: adj[v])
            if (!visit[a])
                stk.push(a);
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

    dfs(adj, 0);
    cout << endl;

    for (int a: dfs_stack(adj, 0)) {
        cout << a << ", ";
    }

    return 0;
}