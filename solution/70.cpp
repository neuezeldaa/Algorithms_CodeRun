#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binary_search(vector<int> vec, int i)
{
    int low = 0;
    int high = vec.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int guess = vec[mid];
        if (guess == i) {
            return mid;
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

int main()
{
    int N, K;
    cin >> N;
    vector<int> mass;
    int num;
    for (int i = 0; i < N; i++) {
        cin >> num;
        mass.push_back(num);
    }
    cin >> K;
    if (binary_search(mass, K) != 0) {
        cout << K;
        return 0;
    }
    mass.push_back(K);
    sort(mass.begin(), mass.end());
    int pos = binary_search(mass, K);
    if (pos == 0) {
        cout << mass[pos + 1];
    }
    else if (pos == mass.size() - 1) {
        cout << mass[pos - 1];
    }
    else if (mass[pos] - mass[pos - 1] >= mass[pos + 1] - mass[pos]) {
        cout << mass[pos + 1];
    }
    else {
        cout << mass[pos - 1];
    }


    return 0;
}