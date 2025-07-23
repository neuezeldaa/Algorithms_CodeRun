#include <iostream>
#include <vector>

using namespace std;

bool in_line(int i, int j) {
    if ((i < 0) || (i > 7)) {
        return false;
    }
    if ((j < 0) || (j > 7)) {
        return false;
    }
    return true;
}

int can_stand(int& count, char curr_char, vector<vector<char>>& cf, int i, int j) {
    if (curr_char == '*') {
        return count;
    }

    if ((in_line(i + 1, j + 1) && in_line(i, j + 1) && in_line(i, j + 2))) {
        if (cf[i + 1][j + 1] == '.' && cf[i][j + 1] == '.' && cf[i][j + 2] == '.') { count += 1; }
    }
    if ((in_line(i - 1, j + 1) && in_line(i, j + 1) && in_line(i, j + 2))) {
        if (cf[i - 1][j + 1] == '.' && cf[i][j + 1] == '.' && cf[i][j + 2] == '.') { count += 1; }
    }
    if ((in_line(i + 1, j + 1) && in_line(i + 1, j) && in_line(i+2, j))) {
        if (cf[i + 1][j + 1] == '.' && cf[i + 1][j] == '.' && cf[i+2][j] == '.') { count += 1; }
    }
    if ((in_line(i + 1, j - 1) && in_line(i + 1, j) && in_line(i + 2, j))) {
        if (cf[i + 1][j - 1] == '.' && cf[i + 1][j] == '.' && cf[i + 2][j] == '.') { count += 1; }
    }

    return count;
}

int main() {
    vector<vector<char>> chess_field;
    for (int i = 0; i < 8; i++) {
        vector<char> temp;
        for (int j = 0; j < 8; j++) {
            char square;
            cin >> square;
            temp.push_back(square);
        }
        chess_field.push_back(temp);
        temp.clear();
    }

   
    int count = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            can_stand(count, chess_field[i][j], chess_field, i, j);
        }
    }

    cout << count;

    return 0;
}
