#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

    vector<int> pressing;
    vector<int> sequence;
    int N, K;
    cin >> N;

    int cur;

    for (int i = 0; i < N; i++) {
        cin >> cur;
        pressing.push_back(cur);
    }

    cin >> K;
    for (int j = 0; j < K; j++) {
        cin >> cur;
        sequence.push_back(cur);
    }

    for (int i = 0; i < N; i++) {
        if (pressing[i] >= K) {
            cout << "NO" << endl;
            continue;
        }
        if (pressing[i] < count(sequence.begin(), sequence.end(), i + 1)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}


