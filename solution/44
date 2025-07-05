#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;


// Функция для генерации соседей (следующих состояний) для текущего числа
vector<string> getNeighbors(const string &current) {
    vector<string> neighbors;
    if (current[0] != '9') {
        string next = current;
        next[0] += 1;
        neighbors.push_back(next);
    }

    if (current[3] != '1') {
        string next = current;
        next[3] -= 1;
        neighbors.push_back(next);
    }

    string nextRight = current;
    rotate(nextRight.rbegin(), nextRight.rbegin() + 1, nextRight.rend());
    neighbors.push_back(nextRight);

    string nextLeft = current;
    rotate(nextLeft.begin(), nextLeft.begin() + 1, nextLeft.end());
    neighbors.push_back(nextLeft);
    
    return neighbors;
}

// BFS для нахождения кратчайшего пути
vector<string> bfs(const string &start, const string &target) {
    queue<string> q;
    unordered_map<string, string> parent;
    unordered_map<string, bool> visited;
    
    q.push(start);
    visited[start] = true;
    parent[start] = "";
    
    while (!q.empty()) {
        string current = q.front();
        q.pop();
        
        if (current == target) {
            break;
        }
        
        for (const string &neighbor : getNeighbors(current)) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = current;
                q.push(neighbor);
            }
        }
    }
    
    // Восстановление пути
    vector<string> path;
    string current = target;
    
    while (current != start) {
        path.push_back(current);
        current = parent[current];
    }
    path.push_back(start);
    
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    int a, b;
    cin >> a >> b;
    
    string start = to_string(a);
    string target = to_string(b);
    
    vector<string> sequence = bfs(start, target);
    
    for (const string &num : sequence) {
        cout << num << endl;
    }
    
    return 0;
}
