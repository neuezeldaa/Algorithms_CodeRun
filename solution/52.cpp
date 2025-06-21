#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int N;
    cin >> N;
    map<string, string> dict;
    for (int i = 0; i < N; i++) {
        string synonym_1, synonym_2;
        cin >> synonym_1 >> synonym_2;
        dict.emplace(synonym_1, synonym_2);
        dict.emplace(synonym_2, synonym_1);
    }

    string word;
    cin >> word;
    cout << dict[word];


    return 0;
}