#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode result;
		ListNode* tail = &result;
		int carry = 0;

		while (l1 != nullptr || l2 != nullptr || carry != 0) {
			int sum = carry;
			if (l1 != nullptr) {
				sum += l1->val;
				l1 = l1->next;
			}
			if (l2 != nullptr) {
				sum += l2->val;
				l2 = l2->next;
			}

			carry = sum / 10;
			tail->next = new ListNode(sum % 10);
			tail = tail->next;
		}

		return result.next;

	}
};

ListNode* MakeList(const vector<int>& list) {
	ListNode* numbers = new ListNode(list[0]);
	queue<ListNode*> q;
	q.push(numbers);

	int i = 1;
	while (!q.empty() && i < list.size()) {
		ListNode* current = q.front();
		q.pop();

		if (i < list.size()) {
			current->next = new ListNode(list[i]);
			q.push(current->next);
		}
		i++;
	}
	return numbers;


}

int main() {
	Solution solution;
	vector<int> L1 = { 2,4,3 };
	vector<int> L2 = { 5,6,4 };


	ListNode* l1 = MakeList(L1);
	ListNode* l2 = MakeList(L2);
		
	ListNode* res = solution.addTwoNumbers(l1, l2);

	return 0;
}
