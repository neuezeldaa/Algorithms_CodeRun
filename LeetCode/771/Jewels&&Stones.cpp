#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> every_jewels(jewels.begin(), jewels.end());
        int count = 0;
        for (char c : stones) {
            if (every_jewels.count(c)) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    string jewels = "a";
    string stones = "aaAbBBb";

    Solution solution;

    cout << solution.numJewelsInStones(jewels, stones);
	return 0;
}
