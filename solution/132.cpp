#include <iostream>
#include <vector>
#include <set>
using namespace std;

int binary_search(int& num, vector<int>& numbers) {
    int low = 0;
    int high = numbers.size();

    while (high - low > 1) {

        int mid = (low + high) / 2;
        if (numbers[mid] < num) {
            low = mid;
        }
        else {
            high = mid;
        }   
    }

    if (numbers[low] >= num) {
        return 0;
    }
    return low+1;

}

int main() {
    int N;
    cin >> N;
    set<int> numbers;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        numbers.insert(num);
    }

    vector<int> numbers_vec;
    for (int n : numbers) {
        numbers_vec.push_back(n);
    }

    int K;
    cin >> K;
    for (int i = 0; i < K; i++) {
        int p_i;
        cin >> p_i;
        cout << binary_search(p_i, numbers_vec) << endl;
    }

    return 0;
}
