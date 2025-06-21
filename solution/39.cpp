#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
void dfs(int node, vector<bool>& visited, bool& reach, vector<vector<int>>& graph) {
    if (visited[node]) return;
    visited[node] = true;

    if (node == 1) {
        reach = true;
        return;
    }

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, reach, graph);
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N + 1);

    for (int i = 0; i < M; i++) {
        int from, where;
        cin >> from >> where;
        graph[from].push_back(where);
    }

    vector<int> result;

    //Проход по вершинам при помощи dfs
    for (int start = 1; start <= N; start++) {
        vector<bool> visited(N + 1, false);
        bool reach = false;

        dfs(start, visited, reach, graph);

        if (reach) {
            result.push_back(start);
        }
    }

    sort(result.begin(), result.end());

    for (int n : result) {
        cout << n << " ";
    }


    return 0;
}