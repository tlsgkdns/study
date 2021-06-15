
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
	void rotate(ListNode* head)
	{
		ListNode* tail = head;
		while (tail->next != nullptr) tail = tail->next;
		while (head != tail)
		{
			int tmp = head->val;
			head->val = tail->val;
			tail->val = tmp;
			head = head->next;
		}
	}
	ListNode* rotateRight(ListNode* head, int k) {
		ListNode* node = head;
		int l = 0;
		while (node != nullptr)
		{
			l++;
			node = node->next;
		}
		if (l == 0) return nullptr;
		k = k % l;
		for (int i = 0; i < k; i++)
			rotate(head);
		return head;
	}
};

// https://leetcode.com/problems/rotate-list/