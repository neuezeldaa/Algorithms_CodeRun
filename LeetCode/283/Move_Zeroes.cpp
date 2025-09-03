#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};

int main() {
    vector<int> nums{ 1, 0, 0, 0, 3, 2, 0 };

    Solution solution;
    solution.moveZeroes(nums);
    for (int n : nums) {
        cout << n << " ";
    }
	return 0;
}
