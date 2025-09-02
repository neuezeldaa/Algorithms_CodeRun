#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int start = 0; 
        int end = n - 1;
        while (start <= end) {
            if (!isalnum(s[start])) {
                start++;
                continue;
            }
            if (!isalnum(s[end])) {
                end--;
                continue;
            }
            if (tolower(s[start]) != tolower(s[end])) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};

int main() {
    string s = "A man, a plan, a canal: Panama";
    Solution solution;
    cout << solution.isPalindrome(s);
	return 0;
}
