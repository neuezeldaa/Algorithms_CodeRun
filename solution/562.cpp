#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    cin.ignore();

    unordered_set<string> stop_words;
    for (int i = 0; i < N; i++) {
        string word;
        getline(cin, word);
        transform(word.begin(), word.end(), word.begin(), ::tolower);

        stop_words.insert(word);
    }


    for (int i = 0; i < M; i++) {
        string sentence;
        getline(cin, sentence);
        transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower);

        bool stop_in_sentence = false;
        for (const string& word : stop_words) {
            if (sentence.find(word) != string::npos) {
                stop_in_sentence = true;
                break;
            }
        }

        cout << (stop_in_sentence ? "DELETE" : "KEEP") << endl;
    }

    return 0;
}