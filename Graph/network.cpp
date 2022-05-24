#include <iostream>
#include <vector>
#include <queue>

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

int bfs(const vector<vector<int>> &computers, int n) {
    int answer = 0;
    vector<bool> visited(computers.size(), false);

    for (int i = 0; i < n; i++) {
        if (visited[i])
            continue;

        queue<int> q;
        q.push(i);

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            if (visited[v])
                continue;

            visited[v] = true;

            for (int a: computers[v])
                if (!visited[a])
                    q.push(a);
        }
        answer++;
    }

    return answer;
}

int main() {
//    vector<vector<int>> question = {
//            {1, 1, 0},
//            {1, 1, 0},
//            {0, 0, 1},
//    };
    vector<vector<int>> question = {
            {1, 1, 0},
            {1, 1, 1},
            {0, 1, 1},
    };

    vector<vector<int>> adj_list = get_adj_list(question);
    cout << bfs(adj_list, 3);
//    for (const auto &l: adj_list) {
//        for (auto n: l)
//            cout << n << ", ";
//
//        cout << endl;
//    }

    return 0;
}