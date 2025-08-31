#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;

        if (nums.empty()) { return result; }

        int c = 0;

        result.push_back(to_string(nums[0]));

        string temp = to_string(nums[0]);
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] + 1 == nums[i + 1]) {
                result[c] = temp + "->" + to_string(nums[i+1]);
            }
            else {
                c++; 
                temp = to_string(nums[i+1]);
                result.push_back(temp);
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums{ 0,1,2,4,5,7 };
    Solution res;
    vector<string> res_vec = res.summaryRanges(nums);

    for (string n : res_vec) {
        cout << n << endl;
    }

	return 0;
}
