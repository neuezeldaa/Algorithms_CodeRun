#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int x, y, z, N;
    int c = 0;
    cin >> x >> y >> z >> N;
    set<int> digits;
    string str_N = to_string(N);
    for (int i = 0; i < size(str_N); i++) {
        digits.insert(N % 10);
        N /= 10;
    }

    for (int n : digits) {
        if (n == x or n == y or n == z) {
            continue;
        }
        else {
            c++;
        }
    }
    cout << c;

    return 0;
}