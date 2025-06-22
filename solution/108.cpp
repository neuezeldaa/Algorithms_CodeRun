#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, L;
    cin >> N >> L;

    vector<vector<int>> vectors;
    for (int i = 0; i < N; i++) {
        vector<int> temp;
        int num;
        for (int j = 0; j < L; j++) {
            cin >> num;
            temp.push_back(num);
        }
        vectors.push_back(temp);
    }

    vector<int> init;

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {

            for (int n : vectors[i]) {
                init.push_back(n);
            }


            for (int n : vectors[j]) {
                init.push_back(n);
            }

            sort(init.begin(), init.end());

            cout << init[L - 1] << endl;
            init.clear();
        }
    }

    return 0;
}