#include <iostream>
#include <algorithm>

using namespace std;

long long both_print(long long N, long long x, long long y, long long result) {
    long long first_print = result / x;
    long long second_print = max(0ll, (result - x) / y);
    return first_print + second_print;
}


long long binary_search(long long N, long long x, long long y) {
    long long low = 0;
    long long high = N * max(x, y);

    while (high - low > 1) {
        long long mid = (low + high) / 2;

        if (both_print(N, x, y, mid) < N) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    return high;
}


int main() {
    long long N, x, y;
    cin >> N >> x >> y;
    if (x > y) {
        swap(x, y);
    }
    long long less_time = binary_search(N, x, y);
    cout << less_time;
    return 0;
}
