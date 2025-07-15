#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool can_stand(vector<long long> coordinates, long long k, long long l) {
    long long count = 1;
    long long curr_end = coordinates[0] + l;

    for (int i = 1; i < coordinates.size(); i++) {
        if (coordinates[i] > curr_end) {
            count += 1;
            curr_end = coordinates[i] + l;
        }
        if (count > k) {
            return false;
        }
    }
    return true;
}

int main() {
    long long n, k;
    cin >> n >> k;

    vector<long long> coordinates(n);
    for (int i = 0; i < n; i++) {
        cin >> coordinates[i];
    }
    sort(coordinates.begin(), coordinates.end());

    long long low = 0;
    long long high = coordinates[n - 1] - coordinates[0];

    while (low <= high) {
        long long mid = (low + high) / 2;

        if (can_stand(coordinates, k, mid)) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    cout << low;

    return 0;
}
