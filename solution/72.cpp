#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> numbers;
    int num;

    while (cin >> num) {
        numbers.push_back(num);
    }

    bool flag = true;

    for (size_t i = 1; i < numbers.size(); ++i) {
        if (numbers[i] <= numbers[i - 1]) {
            flag = false;
            break;
        }
    }

    cout << (flag ? "YES" : "NO") << endl;

    return 0;
}