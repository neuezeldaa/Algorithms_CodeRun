#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int k;
    cin >> k;
    double summa;
    for (int i = 1; i <= k; i++) {
        summa += pow(2, i - 1);
    }
    int su = int(summa);
    cout << su;
    return 0;
}