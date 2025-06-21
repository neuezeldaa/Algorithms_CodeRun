#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> first;
    vector<int> second;
    vector<int> intersec;
    int fir, sec;

    while (cin >> fir) {
        first.push_back(fir);
        if (cin.peek() == '\n') {
            cin.ignore();
            break;
        }
    }
    while (cin >> sec) {
        second.push_back(sec);
        if (cin.peek() == '\n') {
            break;
        }
    }
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());

    set_intersection(
        first.begin(), first.end(),
        second.begin(), second.end(),
        std::back_inserter(intersec)
    );

    for (int n : intersec) {
        cout << n << " ";
    }
    return 0;
}