#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long long w, h, n;
    cin >> w >> h >> n;

    long long low = 0;
    long long high = n*max(w,h);

    while (high - low >= 1) {
        long long mid = (low + high) / 2;

        if ((mid / w) * (mid / h) < n) {
            low = mid + 1;
        }
        else {
            high = mid;
        }
    }
    cout << high;
    return 0;
}
