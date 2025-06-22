#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<int> stack;
    string command;
    int num;
    while (1) {
        cin >> command;
        if (command == "push") {
            cin >> num;
            stack.push_back(num);
            cout << "ok" << endl;
        }
        else if (command == "pop") {
            if (stack.size() == 0) {
                cout << "error" << endl;
                continue;
            }
            cout << *(--stack.end()) << endl;
            stack.pop_back();
        }
        else if (command == "back") {
            if (stack.size() == 0) {
                cout << "error" << endl;
                continue;
            }
            cout << *(--stack.end()) << endl;
        }
        else if (command == "size") {
            cout << stack.size() << endl;
        }
        else if (command == "clear") {
            stack.clear();
            cout << "ok" << endl;
        }
        else {
            cout << "bye" << endl;
            break;
        }
    }


    return 0;
}