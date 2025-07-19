#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int i, vector<vector<int>>& graph, vector<bool>& visited, vector<vector<int>>& result, int& count) {
    visited[i] = true;
    result[count].push_back(i);
    for (int& v : graph[i]) {
        if (visited[v]) continue;
        dfs(v, graph, visited, result, count);
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N+1);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int count = 0;
    vector<bool> visited(N+11);
    vector<vector<int>> result(N+1);
    for (int i = 1; i <= N; i++) {
        if (visited[i]) continue;
        dfs(i, graph, visited, result, count);
        count++;
    }

    cout << count << endl;

    for (int n = 0; n < count; n++) {
        cout << result[n].size() << endl;
        for (int& i : result[n]) cout << i << " ";
        cout << endl;   
    }

    return 0;
}
