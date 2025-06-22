#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binary_search(vector<int>& vec, int i) {
    int low = 0;
    int high = vec.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int guess = vec[mid];
        if (guess == i) {
            return 1;
        }
        if (guess > i) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }

    }
    return 0;
}

int main()
{
    vector<int> N_vec;
    vector<int> K_vec;
    int N, K;
    cin >> N >> K;
    int num;
    for (int i = 0; i < (N + K); i++) {
        cin >> num;
        if (i < N) {
            N_vec.push_back(num);
        }
        else {
            K_vec.push_back(num);
        }
    }
    sort(N_vec.begin(), N_vec.end());



    for (int i : K_vec) {
        cout << (binary_search(N_vec, i) != 0 ? "YES" : "NO") << endl;
    }
    return 0;
}