#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> otrezki(N);
    int ma = 0;
    for (int i = 0; i < N; ++i) {
        cin >> otrezki[i];
        if (ma < otrezki[i]) {
            ma = otrezki[i];
        }
    }

    int left = 1;
    int right = ma;
    int result = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        long long total = 0;
        for (int l : otrezki) {
            total += l / mid;
            if (total >= K) {
                break;
            }
        }
        if (total >= K) {
            result = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    cout << result;
    return 0;
}