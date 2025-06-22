#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    int A, B, C, D, E;
    cin >> A >> B >> C >> D >> E;

    vector<int> brick_size{ A,B,C };
    vector<int> hole_size{ D,E };
    sort(brick_size.begin(), brick_size.end());
    sort(hole_size.begin(), hole_size.end());

    if (brick_size[0] <= hole_size[0] && brick_size[1] <= hole_size[1]) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }

    return 0;
}