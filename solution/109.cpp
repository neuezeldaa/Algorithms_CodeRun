#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_count(const vector<int>& vec, int L) {
    return upper_bound(vec.begin(), vec.end(), L) - vec.begin();
}

int get_median(const vector<int>& first, const vector<int>& second, int L) {
    int low = min(first[0], second[0]);
    int high = max(first[L-1], second[L-1]);

    int result = low;

    while (low <= high) {
        int mid = (low + high) / 2;

        int count = get_count(first, mid) + get_count(second, mid);

        if (count >= L) {
            result = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return result;
}

vector<int> make_sequence(int L, int x1, int d1, int a, int c, int m) {
    vector<int> seq(L);
    vector<int> d(L);

    seq[0] = x1;
    d[0] = d1;
    
    for (int i = 1; i < L; i++) {
        d[i] = (a * d[i - 1] + c) % m;
        seq[i] = seq[i - 1] + d[i-1];
    }

    return seq;
}

int main() {
    
    int N, L;
    cin >> N >> L;
    
    vector<vector<int>> sequences(N);
    for (int i = 0; i < N; i++) {
        int x1, b1, a, c, m;
        cin >> x1 >> b1 >> a >> c >> m;
        sequences[i] = make_sequence(L, x1, b1, a, c, m);
    }

    
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int left_median = get_median(sequences[i], sequences[j], L);
            cout << left_median << endl;
        }
    }


    return 0;
}
