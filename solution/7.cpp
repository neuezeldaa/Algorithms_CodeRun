#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
void dfs(int start, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& component) {
    visited[start] = true;
    component.push_back(start);

    for (int neighbour : graph[start]) {
        if (!visited[neighbour]) {
            dfs(neighbour, graph, visited, component);
        }
    }
}
int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N + 1);

    for (int i = 0; i < M; i++) {
        int first, second;
        cin >> first >> second;
        graph[first].push_back(second);
        graph[second].push_back(first);
    }

    vector<bool> visited(N + 1, false);
    vector<int> component;


    dfs(1, graph, visited, component);

    cout << component.size() << endl;
    sort(component.begin(), component.end());
    for (int n : component) {
        cout << n << " ";
    }


    return 0;
}