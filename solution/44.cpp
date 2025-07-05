#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

vector<string> GetNeighbor(string& curr) {
    vector<string> neighbors;

    if (curr[0] != '9') {
        string next = curr;
        next[0] += 1;
        neighbors.push_back(next);
    }

    if (curr[3] != '1') {
        string next = curr;
        next[3] -= 1;
        neighbors.push_back(next);
    }

    string NextToRight = curr;
    rotate(NextToRight.rbegin(), NextToRight.rbegin() + 1, NextToRight.rend());
    neighbors.push_back(NextToRight);

    string NextToLeft = curr;
    rotate(NextToLeft.begin(), NextToLeft.begin() + 1, NextToLeft.end());
    neighbors.push_back(NextToLeft);

    return neighbors;
}
 

vector<string> bfs(string& start, string& end) {
    
    queue<string> que;
    unordered_map<string, string> parent;
    unordered_map<string, bool> visit;

    que.push(start);
    visit[start] = true;
    parent[start] = "";

    while (!que.empty()) {
        string curr = que.front();
        que.pop();

        if (curr == end) {
            break;
        }

        for (string& neighbor : GetNeighbor(curr)) {
            if (!visit[neighbor]) {
                visit[neighbor] = true;
                parent[neighbor] = curr;
                que.push(neighbor);
            }
        }
    }

    vector<string> path;
    string curr = end;

    while (curr != start) {
        path.push_back(curr);
        curr = parent[curr];
    }

    path.push_back(start);

    reverse(path.begin(), path.end());

    return path;
}



int main() {
    string start, end;
    cin >> start >> end;

    vector<string> result = bfs(start, end);

    for (string curr : result) {
        cout << curr << endl;
    }
    return 0;
}
