#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    int N, M, cou;
    string languages;
    vector<string> all_lang;
    vector<string> result_lang;
    set<string> poliglot;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> M;
        for (int j = 0; j < M; j++) {
            cin >> languages;
            poliglot.insert(languages);
            all_lang.push_back(languages);
        }
    }

    for (string n : poliglot) {
        if (count(all_lang.begin(), all_lang.end(), n) == N) {
            cou++;
            result_lang.push_back(n);
        }
    }
    cout << cou << endl;
    for (string n : result_lang)
        cout << n << endl;

    cout << poliglot.size() << endl;

    for (string n : poliglot)
        cout << n << endl;



    return 0;
}