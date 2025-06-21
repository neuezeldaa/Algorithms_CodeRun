#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
int main()
{
    vector<int> kubanya;
    vector<int> kuborya;
    vector<int> inter;

    vector<int> intanya, intborya;

    int cur = 0;
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < (N + M); i++) {
        cin >> cur;
        if (i < N) {
            kubanya.push_back(cur);
        }
        else {
            kuborya.push_back(cur);
        }
    }

    sort(kubanya.begin(), kubanya.end());
    sort(kuborya.begin(), kuborya.end());

    set_intersection(kubanya.begin(), kubanya.end(),
        kuborya.begin(), kuborya.end(),
        back_inserter(inter));

    set_difference(kubanya.begin(), kubanya.end(),
        inter.begin(), inter.end(),
        back_inserter(intanya));

    set_difference(kuborya.begin(), kuborya.end(),
        inter.begin(), inter.end(),
        back_inserter(intborya));


    cout << inter.size() << endl;
    for (int n : inter)
        cout << n << " ";
    cout << endl;
    cout << intanya.size() << endl;
    for (int n : intanya)
        cout << n << " ";
    cout << endl;
    cout << intborya.size() << endl;
    for (int n : intborya)
        cout << n << " ";



    return 0;
}