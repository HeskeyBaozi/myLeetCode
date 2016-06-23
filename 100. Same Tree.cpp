#include "TreeNode.h"
#include <iostream>

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution
{
public:
	bool isSameTree(TreeNode* p, TreeNode* q)
	{
		if (p == nullptr || q == nullptr) return (p == q);
		if (p->val == q->val
			&&isSameTree(p->left, q->left)
			&& isSameTree(p->right, q->right))
			return true;
		return false;
	}
};

void test_100()
{
	TreeNode root(0), c2(2), c5(5), c6(6), c7(7);
	root.right = &c2;
	c2.left = &c5;
	c2.right = &c6;
	c6.right = &c7;

	TreeNode rootq(0), c2q(2), c5q(5), c6q(6), c7q(7);
	rootq.right = &c2q;
	c2q.left = &c5q;
	c2q.right = &c6q;
	c6q.right = &c7q;

	/* solution */
	Solution sol;
	std::cout << sol.isSameTree(NULL, &c7q) << std::endl;

}
