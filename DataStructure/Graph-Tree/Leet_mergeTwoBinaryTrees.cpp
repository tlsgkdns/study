
  struct TreeNode {
      int val;
      TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
	TreeNode* mergeTrees(TreeNode* r1, TreeNode* r2)
	{
		if (r1 == nullptr && r2 == nullptr) return nullptr;
		if (r1 == nullptr || r2 == nullptr)
		{
			TreeNode* ptr = (r1 == nullptr) ? r2 : r1;
			return ptr;
		}
		int v = r1->val + r2->val;
		TreeNode* ret = new TreeNode(v, mergeTrees(r1->left, r2->left), mergeTrees(r1->right, r2->right));
		return ret;
	}
};
// https://leetcode.com/problems/merge-two-binary-trees/