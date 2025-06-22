#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int N, M, K;;
    cin >> N >> M >> K;

    vector<vector<int>> matrix(N + 1, vector<int>(M + 1, 0));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin >> matrix[i][j];
        }
    }

    vector<vector<int>> pref_matrix(N + 1, vector<int>(M + 1, 0));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            pref_matrix[i][j] = matrix[i][j] + pref_matrix[i - 1][j] + pref_matrix[i][j - 1] - pref_matrix[i - 1][j - 1];
        }
    }

    while (K--) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int sum = pref_matrix[x2][y2] - pref_matrix[x1 - 1][y2] - pref_matrix[x2][y1 - 1] + pref_matrix[x1 - 1][y1 - 1];
        cout << sum << endl;
    }



    return 0;
}