#include <iostream>
#include <algorithm>

using namespace std;

bool can_place(long long N, long long a, long long b, long long w, long long h, long long d) {
    long long width = a + 2 * d;
    long long height = b + 2 * d;

    if (width > w || height > h)
        return false;

    long long cols = w / width;
    long long rows = h / height;

    return cols * rows >= N;
}

long long binary_search(long long N, long long a, long long b, long long w, long long h) {
    long long low = 0;
    long long max_d1 = (w - a) / 2;
    long long max_d2 = (h - b) / 2;
    long long high = min(max_d1, max_d2);

    if (high < 0)
        return -1;

    long long best = 0;

    while (low <= high) {
        long long mid = (low + high) / 2;

        if (can_place(N, a, b, w, h, mid)) {
            best = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return best;
}

int main() {
    long long N, a, b, w, h;
    cin >> N >> a >> b >> w >> h;

    long long res1 = binary_search(N, a, b, w, h); // Горизонтальный модуль
    long long res2 = binary_search(N, b, a, w, h); // Вертикальный модуль

    cout << max(res1, res2) << endl;

    return 0;
}