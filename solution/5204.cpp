#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> A;
    vector<vector<int>> B;
    vector<vector<int>> C(n, vector<int>(k, 0));

    int num;
    vector<int> temp;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            cin >> num;
            temp.push_back(num);
        }
        A.push_back(temp);
        temp.clear();
    }

    for (size_t i = 0; i < m; i++) {
        for (size_t j = 0; j < k; j++) {
            cin >> num;
            temp.push_back(num);
        }
        B.push_back(temp);
        temp.clear();
    }

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < k; ++j) {
            for (size_t b = 0; b < m; ++b) {
                C[i][j] += A[i][b] * B[b][j];
            }
        }
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cout << C[j][i] << " ";
        }
        cout << endl;
    }


    return 0;
}