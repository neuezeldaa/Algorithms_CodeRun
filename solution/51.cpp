#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
using namespace std;
int main()
{
    map<string, int> dict;
    std::ifstream in("input.txt");

    if (in.is_open())
    {
        string str;
        while (in >> str)
        {
            if (dict.count(str) == 0) {
                dict.try_emplace(str, 0);
                cout << "0" << " ";
            }
            else {
                cout << dict[str] + 1 << " ";
                dict[str] += 1;
            }
        }
    }
    in.close();


    return 0;
}