#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n, s;
    cin >> n >> s;

    if (s >= n) {
        cout << "INF";
        return 0;
    }

    vector<long long> times(n);
    for (long long i = 0; i < n; ++i)
        cin >> times[i];

    sort(times.begin(), times.end());

    long long low = 0;
    long long high = times[n-1] - times[0];
    long long answer = 0;

    while (low <= high) {
        long long mid = (low + high) / 2;
        bool valid = true;

        int j = 0;
        for (int i = 0; i < n; ++i) {
            while (j < n && times[j] < times[i] + mid) ++j;
            if (j - i > s) {
                valid = false;
                break;
            }
        }

        if (valid) {
            answer = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (answer == 0)
        cout << "Impossible";
    else
        cout << answer;

    return 0;
}
