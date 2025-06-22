#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int B, W;
    cin >> B >> W;
    int b = (B + 4) / 2;
    int D = pow(b, 2) - 4 * (B + W);
    int number_1 = (-b + sqrt(D)) / 2;
    number_1 = abs(number_1);
    int number_2 = (-b - sqrt(D)) / 2;
    number_2 = abs(number_2);
    cout << (number_1 >= number_2 ? (to_string(number_1) + " " + to_string(number_2)) : (to_string(number_2) + " " + to_string(number_1)));


    return 0;
}