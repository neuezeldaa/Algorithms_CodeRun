#include <iostream>

using namespace std;

class Solution {
public:
    int findClosest(int x, int y, int z) {
		int x_dist = abs(x - z), y_dist = abs(y - z);
		if (x_dist == y_dist) {
			return 0;
		}
		return (x_dist < y_dist) ? 1 : 2;
    }
};

int main() {
	Solution solution;
	int x = 1, y = 2, z = 3;
	
	cout << solution.findClosest(x, y, z);
	return 0;
}
