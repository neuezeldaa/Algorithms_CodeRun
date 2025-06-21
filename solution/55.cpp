#include <iostream>
#include <set>
using namespace std;

int main()
{
    int N;
    int x, y;
    cin >> N;
    set<int> counts;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        counts.insert(x);
    }

    cout << counts.size();
    return 0;
}


