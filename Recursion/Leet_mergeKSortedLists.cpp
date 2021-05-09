#include <vector>
#include <iostream>

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
	int n;
	ListNode* mergeTwo(ListNode* l1, ListNode* l2)
	{
		if (!l1) return l2;
		if (!l2) return l1;
		ListNode* node;
		if (l1->val < l2->val)
		{
			node->val = l1->val;
			node->next = mergeTwo(l1->next, l2);
		}
		else
		{
			node->val = l2->val;
			node->next = mergeTwo(l1, l2->next);
		}
		return node;
	}
	ListNode* solve(vector<ListNode*>& list, int l, int r)
	{
		int mid = (l + r) / 2;
		if (l == r) return list[mid];
		return mergeTwo(solve(list, l, mid), solve(list, mid + 1, r));
	}
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		n = lists.size();
		return solve(lists, 0, n - 1);
	}
};
// https://leetcode.com/problems/merge-k-sorted-lists/