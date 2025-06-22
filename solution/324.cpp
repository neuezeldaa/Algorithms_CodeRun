#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    if (N == 0 or M == 0) {
        cout << "0";
        return 0;
    }
    vector<int> Sell;
    vector<int> Buy;
    int cur = 0;
    long long sum = 0;
    for (int i = 0; i < (N + M); i++) {
        if (i < N) {
            cin >> cur;
            Sell.push_back(cur);
        }
        else {
            cin >> cur;
            Buy.push_back(cur);
        }
    }

    sort(begin(Sell), end(Sell));
    sort(begin(Buy), end(Buy));


    while (Sell[0] < Buy[Buy.size() - 1]) {
        auto begin = Sell.cbegin();
        sum += Buy[Buy.size() - 1] - Sell[0];
        Buy.pop_back();
        Sell.erase(begin);

        if (Sell.size() == 0 or Buy.size() == 0) {
            break;
        }
    }
    cout << sum;
    return 0;
}