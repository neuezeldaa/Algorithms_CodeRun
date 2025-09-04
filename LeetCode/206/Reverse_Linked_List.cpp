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
    ListNode* reverseList(ListNode* head) {
		ListNode* node = nullptr;

		while (head != nullptr) {
			ListNode* temp = head->next;
			head->next = node;
			node = head;
			head = temp;
		}
		return node;
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
	vector<int> list = { 1,2,3,4,5 };
  
	ListNode* numbers = MakeList(list);
	cout << solution.reverseList(numbers);

	return 0;
}
