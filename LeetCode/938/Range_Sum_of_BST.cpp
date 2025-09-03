#include <iostream>
#include <functional>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	int rangeSumBST(TreeNode* root, int low, int high) {
		function<int(TreeNode*)> dfs = [&](TreeNode* root) {
			if (!root) {
				return 0;
			}
			int x = root->val;
			int ans = low <= x && x <= high ? x : 0;
			
			if (x > low) {
				ans += dfs(root->left);
			}
			if (x < high) {
				ans += dfs(root->right);
			}	
			return ans;
			};
		return dfs(root);
	}
};


TreeNode* MakeTree(const vector<int>& roots) {
	TreeNode* root = new TreeNode(roots[0]);
	queue<TreeNode*> q;
	q.push(root);

	int i = 1;
	while (!q.empty() && i < roots.size()) {
		TreeNode* current = q.front();
		q.pop();

		if (i < roots.size() && roots[i] != -1) {
			current->left = new TreeNode(roots[i]);
			q.push(current->left);
		}
		i++;

		if (i < roots.size() && roots[i] != -1) {
			current->right = new TreeNode(roots[i]);
			q.push(current->right);
		}
		i++;
	}
	return root;
}


int main() {
	Solution solution;

	vector<int> roots = { 10,5,15,3,7,-1,18 };
	TreeNode* root = MakeTree(roots);

	cout << solution.rangeSumBST(root, 7, 15) << endl;
	return 0;
}
