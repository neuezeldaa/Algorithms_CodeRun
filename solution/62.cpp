#include <set>
#include <iostream>

using namespace std;

int main()
{
    set<int> massive;
    int num;
    while (cin >> num) {
        massive.insert(num);
        if (cin.peek() == '\n') {
            break;
        }
    }
    cout << massive.size();
    return 0;
}