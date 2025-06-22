#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool is_leap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main()
{
    int d;
    string M;
    int y;
    vector<string> DOTW{ "Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday" };

    vector<string> MONTH{ "January", "February", "March", "April", "May", "June",
                         "July", "August", "September", "October", "November", "December" };

    vector<int> DIM{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    map<string, int> month_index;
    for (int i = 0; i < 12; ++i) {
        month_index[MONTH[i]] = i;
    }

    const int base_leaps = 477;//Количество високосных лет до 1970 года

    while (cin >> d >> M >> y) {
        int m = month_index[M];

        int visok = (y - 1) / 4 - (y - 1) / 100 + (y - 1) / 400 - base_leaps;
        long total_days = (long)(y - 1970) * 365 + visok;

        for (int i = 0; i < m; i++) {
            total_days += DIM[i];
            if (i == 1 && is_leap(y)) total_days += 1;
        }
        total_days += d - 1;

        cout << DOTW[total_days % 7] << endl;
    }

    return 0;
}