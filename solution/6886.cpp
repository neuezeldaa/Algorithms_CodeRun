#include <iostream>

using namespace std;

int Euler_Function(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n = n / i;
            }
            result -= result / i;
        }
    }
    if (n > 1) {
        result -= result / n;
    }
    return result;
}

int main() {
    int N;
    cin >> N;

    cout << Euler_Function(N);
    return 0;
}
