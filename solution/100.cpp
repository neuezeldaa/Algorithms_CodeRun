#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int binary_search(const vector<long long>& vec, long long i) {
    int low = 0;
    int high = vec.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        long long guess = vec[mid];
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

int lower_bound_custom(const vector<long long>& arr, long long x) {
    int low = 0;
    int high = arr.size();
    while (low < high) {
        int mid = (low + high) / 2;
        if (arr[mid] < x) {
            low = mid + 1;
        }
        else {
            high = mid;
        }
    }
    return low;
}


long long closest(const vector<long long>& arr, long long x) {
    int n = arr.size();
    if (n == 0) return 0;

    if (binary_search(arr, x)) {
        return x;
    }

    int pos = lower_bound_custom(arr, x);

    if (pos == 0) {
        return arr[0];
    }

    if (pos == n) {
        return arr[n - 1];
    }


    long long left_val = arr[pos - 1];
    long long right_val = arr[pos];

    if (abs(x - left_val) <= abs(x - right_val)) {
        return left_val;
    }
    else {
        return right_val;
    }
}

int main() {


    int N, K;
    cin >> N >> K;

    vector<long long> first_seq(N);
    for (int i = 0; i < N; ++i) {
        cin >> first_seq[i];
    }

    for (int i = 0; i < K; ++i) {
        long long num;
        cin >> num;
        cout << closest(first_seq, num) << '\n';
    }

    return 0;
}