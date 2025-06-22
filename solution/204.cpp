#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<double> servers;
    double total_error = 0.0;

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        double prob = (a / 100.0) * (b / 100.0);
        servers.push_back(prob);
        total_error += prob;
    }

    for (double prob : servers) {
        printf("%.12f\n", prob / total_error);
    }

    return 0;
}