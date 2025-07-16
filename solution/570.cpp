#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;


int main() {
    int p, n, k;
    cin >> p >> n >> k;

    vector<string> theme(p);
    vector<int> id(p);

    cin.ignore();    
    for (int i = 0; i < p; ++i) {
        string line;
        getline(cin, line); 
        theme[i] = line;
    }


    for (int i = 0; i < p; i++) {
        cin >> id[i];
    }

    unordered_map<string, int> counts_of_theme;
    vector<pair<string, int>> result_themes;

    for (int i = 0; i < p && result_themes.size() < n; i++) {
        string cur_theme = theme[i];
        if (counts_of_theme[cur_theme] < k) {
            result_themes.emplace_back(cur_theme, id[i]);
            counts_of_theme[cur_theme] += 1;
        }
    }
    
    for (const auto& pair : result_themes) {
        cout << pair.first << " #" << pair.second << "\n";
    }

    return 0;
}
