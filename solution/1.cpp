#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int arg[3];
    for (int i = 0; i < 3; i++) {
        cin >> arg[i];
    }
    int temp;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3 - i - 1; j++) {
            if (arg[j] > arg[j + 1]) {
                temp = arg[j];
                arg[j] = arg[j + 1];
                arg[j + 1] = temp;
            }
        }

    }
    cout << arg[1];
    return 0;
}